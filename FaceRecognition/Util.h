#pragma once
#include <opencv2/opencv.hpp>

using namespace std;

//需要输出数据的结构体
struct FaceStruct
{
	string fileName;
	cv::Mat image;
	std::vector<cv::Rect> faceRect;//bounding box
	std::vector<float*> feats;
	cv::Mat drawImg;//绘制好的人脸，已转成mat结构
};