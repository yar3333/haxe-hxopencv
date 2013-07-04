#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>

#include <neko.h>

#define STRINGIFY(x) #x
#define val_match_or_fail(v, t) if(!val_is_##t(v)) { failure("Excepted "#t" in `"__FILE__"' at line "STRINGIFY(__LINE__)"."); }

DEFINE_KIND(k_IplImage);

void neko_cvReleaseImage(value image);

value neko_cvLoadImage(value fileName, value p)
{
	val_check(fileName, string);
	val_check(p, int);

	IplImage *image = cvLoadImage(val_string(fileName), val_int(p));
	value r = alloc_abstract(k_IplImage, image);
	val_gc(r, neko_cvReleaseImage);
	return r;
}
DEFINE_PRIM(neko_cvLoadImage, 2);

void neko_cvReleaseImage(value image)
{
	IplImage *temp = (IplImage *)val_data(image);
	cvReleaseImage(&(temp));
}
DEFINE_PRIM(neko_cvReleaseImage, 1);

void neko_cvTest()
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
	cvReleaseImage(&hw);
	cvDestroyWindow("Hello World");
}
DEFINE_PRIM(neko_cvTest, 0);
