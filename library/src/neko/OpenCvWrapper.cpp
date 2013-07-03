// Video Image PSNR and SSIM
#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion

#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace std;
using namespace cv;

double getPSNR ( const Mat& I1, const Mat& I2);
Scalar getMSSIM( const Mat& I1, const Mat& I2);

void help()
{
        // ����� ������ � ������ ��������
        int height = 620;
        int width = 440;
        // ����� ����� ��� ������ ������
        CvPoint pt = cvPoint( height/4, width/2 );
        // ������ 8-������, 3-��������� ��������
        IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
        // �������� �������� ������ ������
        cvSet(hw,cvScalar(0,0,0));
        // ������������� ������
        CvFont font;
        cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);
        // ��������� ����� ������� �� �������� �����
        cvPutText(hw, "OpenCV Step By Step", pt, &font, CV_RGB(150, 0, 150) );

        // ������ ������
        cvNamedWindow("Hello World", 0);
        // ���������� �������� � ��������� ����
        cvShowImage("Hello World", hw);
        // ��� ������� �������
        cvWaitKey(0);
        
        // ����������� �������
        cvReleaseImage(&hw);
        cvDestroyWindow("Hello World");
}
