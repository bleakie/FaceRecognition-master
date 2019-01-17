/*
## ������ʶ����ʮ�˽�ȫ����ѧ����������������ʶ��demo

## ����ʱ�䣺2017-11-16

## ������������������ʶ��ؼ�index

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

#include "FaceRecognitionFun.h"

void FaceRecognitionFun::Init()
{
	isLoadTrain = false;
}
//--------------------------------������������----------------------------------------//
cv::Mat FaceRecognitionFun::Draw(FaceStruct face_struct, cv::Mat src)
{
	std::vector<cv::Rect> rect = face_struct.faceRect;
	for (int i = 0; i < rect.size(); i++)
		cv::rectangle(src, rect[i], cv::Scalar(0, 0, 255), 2);

	return src;
}
//��ǽ��
void FaceRecognitionFun::DrawResult(FaceStruct& face_struct, int index, string argmaxName)
{
	face_struct.drawImg = face_struct.image;
	cv::rectangle(face_struct.drawImg, face_struct.faceRect[index], cv::Scalar(0, 0, 255), 2);
	cv::Point origin; origin.x = face_struct.faceRect[index].x; origin.y = face_struct.faceRect[index].y;
	string label(argmaxName.substr(argmaxName.length()-6, 6));
	cv::putText(face_struct.drawImg, label, origin, cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 255, 255), 1, 8, 0);
}

void FaceRecognitionFun::DrawProcessedFace(std::vector<FaceStruct>& face_struct) {
	for (int i = 0; i < face_struct.size(); i++)
	{
		face_struct[i].drawImg = Draw(face_struct[i], face_struct[i].image);
	}
}

//--------------------------------ʶ����ù�ʽ----------------------------------------//
void FaceRecognitionFun::Recognition(const std::vector<string> train_path_list, const string test_path,
	std::vector<FaceStruct>& face_struct_train, FaceStruct& face_struct_test, std::vector<std::vector<float>>& result)
{
	for (auto i = 0; i < train_path_list.size(); i++)
	{
		FaceStruct face_struct_new;
		face_struct_new.fileName = train_path_list[i];
		face_struct_train.push_back(face_struct_new);
	}
	face_struct_test.fileName = test_path;

	//����ʶ��
	result = seeta_face.Recongnize(face_struct_train, face_struct_test);
	DrawProcessedFace(face_struct_train);
}
