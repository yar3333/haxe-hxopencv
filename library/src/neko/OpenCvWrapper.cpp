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
        // задаЄм высоту и ширину картинки
        int height = 620;
        int width = 440;
        // задаЄм точку дл€ вывода текста
        CvPoint pt = cvPoint( height/4, width/2 );
        // —оздаЄи 8-битную, 3-канальную картинку
        IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
        // заливаем картинку чЄрным цветом
        cvSet(hw,cvScalar(0,0,0));
        // инициализаци€ шрифта
        CvFont font;
        cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);
        // использу€ шрифт выводим на картинку текст
        cvPutText(hw, "OpenCV Step By Step", pt, &font, CV_RGB(150, 0, 150) );

        // создаЄм окошко
        cvNamedWindow("Hello World", 0);
        // показываем картинку в созданном окне
        cvShowImage("Hello World", hw);
        // ждЄм нажати€ клавиши
        cvWaitKey(0);
        
        // освобождаем ресурсы
        cvReleaseImage(&hw);
        cvDestroyWindow("Hello World");
}
