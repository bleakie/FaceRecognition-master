/*
## 创建标识：第十八届全国大学生物联网大赛人脸识别demo

## 创建时间：2017-11-16

## 函数功能描述：人脸识别控件index

## 开发环境
[Windows10+VS2015+Qt5.6+opencv2.4.11]
**开发语言C++**
**编译环境在x64之下**

## 环境配置
**配置opencv2.4.11的环境**
**配置Qt5.6+VS2015的环境**
**项目属性-VC++目录-包含目录 需要添加../include/include_x三个包含文件**
**项目属性-链接器-输入-附加依赖项 需要添加lib文件

## 技术支持
(http://www.greenorbs.com/)
*/

#include "FaceRecognitionFun.h"

void FaceRecognitionFun::Init()
{
	isLoadTrain = false;
}
//--------------------------------绘制人脸检测框----------------------------------------//
cv::Mat FaceRecognitionFun::Draw(FaceStruct face_struct, cv::Mat src)
{
	std::vector<cv::Rect> rect = face_struct.faceRect;
	for (int i = 0; i < rect.size(); i++)
		cv::rectangle(src, rect[i], cv::Scalar(0, 0, 255), 2);

	return src;
}
//标记结果
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

//--------------------------------识别调用公式----------------------------------------//
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

	//人脸识别
	result = seeta_face.Recongnize(face_struct_train, face_struct_test);
	DrawProcessedFace(face_struct_train);
}
