#pragma once
#include <string>
#include <Util.h>
#include "FaceRecognitionSeetaface.h"

using namespace std;

class FaceRecognitionFun
{
	FaceRecognitionSeetaface seeta_face;
	std::vector<float*> seetaface_train;

	cv::Mat Draw(FaceStruct face_struct, cv::Mat src);

public:
	bool isLoadTrain;
	int detector_num, alignment_num, reconition_num;
	std::vector<FaceStruct> face_struct_train_frame;
	std::vector<FaceStruct> face_struct_train_seetaface;

	void Init();
	void DrawResult(FaceStruct& face_struct, int index, string argmaxName);
	void DrawProcessedFace(std::vector<FaceStruct>& face_struct);
	void Recognition(const std::vector<string> train_path_list, const string test_path,
		std::vector<FaceStruct>& face_struct_train, FaceStruct& face_struct_test, std::vector<std::vector<float>>& result);
};