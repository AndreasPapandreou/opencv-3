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

int main( int argc, char** argv )
{
	if (argc < 3)
	{
		std::cout << "Please specify two images." << std::endl;
		return -1;
	}
	double alpha = 0.5; double beta; double input;
	cv::Mat src1, src2, dst;

	/// Ask the user enter alpha
	std::cout << " Simple Linear Blender " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "* Enter alpha [0-1]: ";
	std::cin >> input;

	/// We use the alpha provided by the user iff it is between 0 and 1
	if( alpha >= 0 && alpha <= 1 )
	{
		alpha = input;
	}

	/// Read image ( same size, same type )
	src1 = cv::imread(argv[1]);
	src2 = cv::imread(argv[2]);
	if(!src1.data)
	{
		std::cout << "Error loading src1." << std::endl;
		return -1;
	}
	if(!src2.data)
	{
		std::cout << "Error loading src2." << std::endl;
		return -1;
	}

	if (src1.size() != src2.size())
	{
		std::cout << "Size of two images are different, please provide two images with the same size." << std::endl;
		return -1;
	}

	/// Create Windows
	cv::namedWindow("Linear Blend", 1);
	beta = ( 1.0 - alpha );
	cv::addWeighted( src1, alpha, src2, beta, 0.0, dst);
	cv::imshow( "Linear Blend", dst );
	cv::waitKey(0);
	return 0;
}

