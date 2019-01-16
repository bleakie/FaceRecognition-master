#pragma once
#include <string>
#include <opencv/highgui.h>
#include "face_detection.h"
#include "face_alignment.h"
#include "face_identification.h"
#include "Util.h"

using std::string;

class DetectorSeetaface : public seeta::FaceDetection {
public:
	DetectorSeetaface(const char * model_name);
};

class FaceRecognitionSeetaface{
	DetectorSeetaface* detector;
	seeta::FaceIdentification* face_recognizer;

	void FaceRecognitionSeetaface::Detect(FaceStruct& face_struct);
public:
	FaceRecognitionSeetaface();
	std::vector<std::vector<float>> Recongnize(std::vector<FaceStruct>& face_struct_train, FaceStruct& face_struct_test);
	std::vector<std::vector<float>> SimCalc(std::vector<float*> train_feats, FaceStruct& face_struct_test);
};

