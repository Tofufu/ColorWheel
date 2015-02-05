//  Created by Donna Chow on 1/23/15.
//  Copyright (c) 2015 Donna Chow. All rights reserved.
//

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#define w 500
#define threefourths ((3*w)/4)
#define onefourth (w/4)
#define onehalf (w/2)

//lower right diagonals
#define testingx ( onehalf + (.86602540378*onefourth)) //30 degrees X-Value (sqrt3/2)
#define testingy (onehalf + (.5*onefourth))    //30 degrees Y-Value (1/2)

//lower left diagonals
#define testingx2 (onehalf - (.5*onefourth))
#define testingx22 (onehalf - (.86602540378*onefourth))


using namespace cv;


void MyFilledCircle( Mat img, Point center, Scalar color );

int main( void ){
    
    /// Windows names
    char atom_window[] = "Drawing 1: Atom";
   
    /// Create black empty images... this presents the canvas
    // Will have Mat header (Width, Height, Channel Type)...We're using a 3 channel = RGB!
    //This is filling in Mat object that already is all zeros
    Mat atom_image = Mat::zeros( w, w, CV_8UC3 );
    
    
    //BGR NOT RGB!!
    
    //horizontal
    MyFilledCircle( atom_image, Point( w/4, w/2), Scalar(0,69,200) );    //left orange
    MyFilledCircle( atom_image, Point( threefourths, w/2), Scalar(170,178,32) ); //teal
    
    //center
    MyFilledCircle( atom_image, Point( w/2, w/2), Scalar(255,255,255) ); //white

    
    //lower right diagonals
    MyFilledCircle( atom_image, Point( testingx, testingy), Scalar(205,0,0) ); //upper blue
    MyFilledCircle( atom_image, Point( testingy, testingx), Scalar(112,25,25) ); //lower dark blue
    
   //lower left diagonals
    MyFilledCircle( atom_image, Point( testingx2, testingx), Scalar(211,0,148) ); //lower magenta purple
    MyFilledCircle( atom_image, Point( testingx22, testingy), Scalar(0,0,255) ); //upper red
    
    //upper left diagonals
    MyFilledCircle( atom_image, Point( testingx2, testingx22), Scalar(0,200,255) ); //upper yellow orange
    MyFilledCircle( atom_image, Point( testingx22, testingx2), Scalar(0,140,255) ); //lower bright orange
    
    //upper right diagonals
    MyFilledCircle( atom_image, Point( testingy, testingx22), Scalar(0,255,0) ); //upper bright green
    MyFilledCircle( atom_image, Point( testingx, testingx2), Scalar(0,128,0) ); //lower green
    
    
    //vertical
    MyFilledCircle( atom_image, Point( w/2, w/4), Scalar(0,255,255) ); //upper yellow
    MyFilledCircle( atom_image, Point( w/2, threefourths), Scalar(130,0,75) ); //lower dark purple
    
    
    
    
    
      imshow( atom_window, atom_image );
    
    //we need this or else nothing will be drawn or displayed because highgui::imshow
    waitKey( 0 ); //used because of highgui... wait for key forever... when it does arrive shuts down
    return(0);
}


void MyFilledCircle( Mat img, Point center, Scalar color )
{
    int thickness = -1;
    int lineType = 8;
    
    circle( img,    //Mat object displayed on
           center,  //center passed in as point (x,y)
           26,    //radius of the circle
           color, //color of circle
           thickness,           //thickness = -1 which means filled
           lineType );          //type of line
}

