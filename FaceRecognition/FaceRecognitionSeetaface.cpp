/*
## ������ʶ����ʮ�˽�ȫ����ѧ����������������ʶ��demo

## ����ʱ�䣺2017-11-16

## ������������������ʶ��������

## ��������
[Windows10+VS2015+Qt5.6+opencv2.4.11]
**��������C++**
**���뻷����x64֮��**

## ��������
**����opencv2.4.11�Ļ���**
**����Qt5.6+VS2015�Ļ���**
**��Ŀ����-VC++Ŀ¼-����Ŀ¼ ��Ҫ���../include/include_x���������ļ�**
**��Ŀ����-������-����-���������� ��Ҫ���lib�ļ�

## ����֧��
(http://www.greenorbs.com/)
*/

#include "FaceRecognitionSeetaface.h"
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>

DetectorSeetaface::DetectorSeetaface(const char* model_name) :seeta::FaceDetection(model_name)
{
	//��ز������ã������С����size���÷���ֵ�������ṹ��ɨ�贰��
	this->SetMinFaceSize(40);
	this->SetScoreThresh(2.f);
	this->SetImagePyramidScaleFactor(0.8f);
	this->SetWindowStep(4, 4);
}
//--------------------------------��������ʶ��ģ��----------------------------------------//
FaceRecognitionSeetaface::FaceRecognitionSeetaface()
{
	this->detector = new DetectorSeetaface("model/seeta_fd_frontal_v1.0.bin");
	this->face_recognizer = new seeta::FaceIdentification("model/seeta_fr_v1.0.bin");
}
//--------------------------------�������----------------------------------------//
void FaceRecognitionSeetaface::Detect(FaceStruct& face_struct)
{
	face_struct.image = cv::imread(face_struct.fileName, 1);
	cv::Mat src_img_color = face_struct.image;
	//convert to ImageData type
	seeta::ImageData src_img_data_color(src_img_color.cols, src_img_color.rows, src_img_color.channels());
	src_img_data_color.data = src_img_color.data;
	//convert to gray
	cv::Mat src_img_gray;
	cv::cvtColor(src_img_color, src_img_gray, CV_BGR2GRAY);
	
	//convert to ImageData type
	seeta::ImageData src_img_data_gray(src_img_gray.cols, src_img_gray.rows, src_img_gray.channels());
	src_img_data_gray.data = src_img_gray.data;

	//Detect faces
	std::vector<seeta::FaceInfo> faces = this->detector->Detect(src_img_data_gray);
	int32_t face_num = static_cast<int32_t>(faces.size());

	cv::Rect rect;
	for (int32_t i = 0; i < face_num; i++)
	{
			seeta::FaceInfo facelast;
			facelast.bbox = faces[i].bbox;
			rect.x = facelast.bbox.x;
			rect.y = facelast.bbox.y;
			rect.width = facelast.bbox.width;
			rect.height = facelast.bbox.height;	
			face_struct.faceRect.push_back(rect);

			cv::Mat Src_Img_Crop_Mat = src_img_color(rect);
			cv::resize(Src_Img_Crop_Mat, Src_Img_Crop_Mat, cv::Size(face_recognizer->crop_height(), face_recognizer->crop_width()));

			//convert to ImageData type
			seeta::ImageData src_img_crop(Src_Img_Crop_Mat.cols, Src_Img_Crop_Mat.rows, Src_Img_Crop_Mat.channels());
			src_img_crop.data = Src_Img_Crop_Mat.data;

			float* feat = new float[this->face_recognizer->feature_size()];
			this->face_recognizer->ExtractFeature(src_img_crop, feat); 
			face_struct.feats.push_back(feat);
	}
}
//--------------------------------��ȡѵ�����Ͳ��Լ��������ȶ�----------------------------------------//
std::vector<std::vector<float>> FaceRecognitionSeetaface::Recongnize(std::vector<FaceStruct>& face_struct_train,
	FaceStruct& face_struct_test)
{
	std::vector<float*> train_feats;
	for(int i = 0; i < face_struct_train.size(); i++)
	{
		Detect(face_struct_train[i]);
		if (face_struct_train[i].faceRect.size() > 0)
			train_feats.push_back(face_struct_train[i].feats[0]);//ѵ������һ������
		else
			face_struct_train.erase(face_struct_train.begin() + i);
	}
	
	return SimCalc(train_feats, face_struct_test);
}
//--------------------------------���ƶȼ���----------------------------------------//
std::vector<std::vector<float>> FaceRecognitionSeetaface::SimCalc(std::vector<float*> train_feats,
	FaceStruct& face_struct_test)
{
	std::vector<std::vector<float>> result;
	Detect(face_struct_test);
	if(face_struct_test.feats.size() > 0)
	{
		std::vector<float*> test_feats = face_struct_test.feats;
		
		for (auto i = 0; i < test_feats.size(); i++)
		{
			std::vector<float> single_result;
			for (auto j = 0; j < train_feats.size(); j++)
			{
				float* feat1 = test_feats[i];
				float* feat2 = train_feats[j];
				float sim = this->face_recognizer->CalcSimilarity(feat1, feat2);
				single_result.push_back(sim);
			}
			result.push_back(single_result);
		}
		return result;
	}
}
