/*
 * This project is to demonstrate all kinds of opencv
 * functionality. If you find any bugs or have any questions,
 * please feel free to email me.
 *
 * Date: 18/11/2012
 * Author: ycshao
 * Email: ycshao0402@gmail.com
 */

#include <cv.h>
#include <highgui.h>
#include <iostream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Please specify an image." << std::endl;
		return -1;
	}
	cv::Mat image;
	image = cv::imread(argv[1], 1);
	if (!image.data)
	{
		std::cout << "Image is not loaded." << std::endl;;
		return -1;
	}
	cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	cv::imshow("Display Image", image);

	cv::waitKey(0);

	return 0;
}


