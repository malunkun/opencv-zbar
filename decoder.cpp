#include<string.h>
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<zbar.h>
#include"decoder.h"

using namespace std;
using namespace cv;
using namespace zbar;

int decoder(int carame_num,struct code_msg* code_msg)
{
	Mat image;
	VideoCapture capture(carame_num);
	int flag = 0; 

	if(!capture.isOpened())
	{
		cout<<"摄像头打开失败"<<endl;
		return -1;
	}
	cout << "打开摄像头"<<endl;

	while(!flag)
	{
		capture >> image;//读取视频帧
		if(!image.empty())
		{
		//	cout << "读取到摄像头视频帧"<<endl;
		

#if 0 //置1打开图形窗口进行对焦等操作
			imshow("source",image);
#endif
			cvtColor(image,image,CV_RGB2GRAY);//灰度图
		//	imshow("imageGray",image);
		//	cout << "灰度图转换成功"<<endl;

			//zbar解码
			int width = image.cols;
			int heigth = image.rows;
			uchar *raw = (uchar *)image.data;
			Image imagezbar(width,heigth,"Y800",raw,width*heigth);
			ImageScanner scanner;
			scanner.scan(imagezbar);
			Image::SymbolIterator symbol = imagezbar.symbol_begin();
			for(;symbol != imagezbar.symbol_end();++symbol)//解码成功
			{
				//cout << "type:" <<symbol->get_type_name()<<endl;
				strcpy(code_msg->get_type_name,symbol->get_type_name().c_str());
				//cout << "data:" <<symbol->get_data()<<endl;
				strcpy(code_msg->get_data,symbol->get_data().c_str());
				flag = 1;
			}

		}
		//if(waitKey(10) == 0x0d)
		//	break;
	}
	return 0;
}

