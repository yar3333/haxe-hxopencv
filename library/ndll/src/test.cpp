#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <neko.h>

////////////////////////////////////////////////////////////////////

value neko_test()
{
	// задаём высоту и ширину картинки
	int height = 620;
	int width = 440;
	// задаём точку для вывода текста
	CvPoint pt = cvPoint( height/4, width/2 );
	// Создаёи 8-битную, 3-канальную картинку
	IplImage* hw = cvCreateImage(cvSize(height, width), 8, 3);
	// заливаем картинку чёрным цветом
	cvSet(hw,cvScalar(0,0,0));
	// инициализация шрифта
	CvFont font;
	cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);
	// используя шрифт выводим на картинку текст
	cvPutText(hw, "OpenCV Step By Step", pt, &font, CV_RGB(150, 0, 150) );

	// создаём окошко
	cvNamedWindow("Hello World", 0);
	// показываем картинку в созданном окне
	cvShowImage("Hello World", hw);
	// ждём нажатия клавиши
	cvWaitKey(0);
	
	// освобождаем ресурсы
	//cvReleaseImage(&hw);
	//cvDestroyWindow("Hello World");
	
	return val_null;
}
DEFINE_PRIM(neko_test, 0);

//---------------------------------------------------

