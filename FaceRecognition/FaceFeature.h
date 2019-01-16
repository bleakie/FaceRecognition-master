#pragma once
#include <string>
#include "Util.h"
#include <vector>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "facedetect-dll.h"

using std::string;
#define DETECT_BUFFER_SIZE 0x20000

class FaceFeature{
	
	void FaceFeature::Detect(FaceStruct& face_struct);
public:
	vector<std::vector<float>> Recongnize(std::vector<FaceStruct>& face_struct_train, FaceStruct& face_struct_test);
	std::vector<std::vector<float>> SimCalc(std::vector<cv::Mat> train_feats, FaceStruct& face_struct_test);
};

