#pragma once
#include <opencv2/opencv.hpp>

using namespace std;

//��Ҫ������ݵĽṹ��
struct FaceStruct
{
	string fileName;
	cv::Mat image;
	std::vector<cv::Rect> faceRect;//bounding box
	std::vector<float*> feats;
	cv::Mat drawImg;//���ƺõ���������ת��mat�ṹ
};