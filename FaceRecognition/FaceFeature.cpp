/*
## 创建标识：第五届全国高校物联网应用创新大赛（命题赛）人脸识别demo

## 创建时间：2017-12-20

## 函数功能描述：人脸识别控件

## 开发环境
[Windows10+VS2015+Qt5.6+opencv2.4.11]
**开发语言C++**
**编译环境x64**

## 环境配置
**配置opencv2.4.11的环境**
**配置Qt5.6+VS2015的环境**
**项目属性-链接器-输入-附加依赖项 需要添加相关lib文件

## 技术支持
(http://www.greenorbs.com/)
*/

#include "FaceFeature.h"
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>

//--------------------------------人脸检测----------------------------------------//
void FaceFeature::Detect(FaceStruct& face_struct)
{
	face_struct.image = cv::imread(face_struct.fileName, 1);
	cv::Mat src_img_color = face_struct.image;
	cv::Mat src_img_gray;
	cv::cvtColor(src_img_color, src_img_gray, CV_BGR2GRAY);

	int * pResults = NULL;
	unsigned char * pBuffer = (unsigned char *)malloc(DETECT_BUFFER_SIZE);
	if (!pBuffer)
	{
		fprintf(stderr, "Can not alloc buffer.\n");
		return;
	}
	pResults = facedetect_multiview_reinforce(pBuffer, (unsigned char*)(src_img_gray.ptr(0)), 
		src_img_gray.cols, src_img_gray.rows, (int)src_img_gray.step, 1.2f, 2, 80, 0, 0);
	int peopleNUM = (pResults ? *pResults : 0);//几张人脸
	for (int i = 0; i < peopleNUM; i++)
	{
		short * p = ((short*)(pResults + 1)) + 142 * i;
		float area = p[2] * p[3];
		cv::Rect rect(p[0], p[1], p[2], p[3]);
		face_struct.faceRect.push_back(rect);

		cv::Mat Src_Img_Crop_Mat = src_img_color(rect);
		cv::resize(Src_Img_Crop_Mat, Src_Img_Crop_Mat, cv::Size(64, 64));
		cv::Mat train; cv::cvtColor(Src_Img_Crop_Mat, train, CV_BGR2GRAY);

		cv::HOGDescriptor * hog = new cv::HOGDescriptor(cvSize(64, 64), cvSize(16, 16), cvSize(8, 8), cvSize(8, 8), 9);//定义hog特征参数
		std::vector<float>descriptor;
		hog->compute(train, descriptor, cv::Size(8, 8));//提取hog特征
		int descriptorDim = descriptor.size();
		cv::Mat feat = cv::Mat::zeros(1, descriptorDim, CV_32FC1);
		for (int j = 0; j < descriptorDim; j++)//将特征向量复制到矩阵中
		{
			feat.at<float>(0, j) = descriptor[j];
		}
		descriptor.clear();
		face_struct.feats.push_back(feat);
	}
}
//--------------------------------提取训练集和测试集特征并比对----------------------------------------//
std::vector<std::vector<float>> FaceFeature::Recongnize(std::vector<FaceStruct>& face_struct_train,
	FaceStruct& face_struct_test)
{
	std::vector<cv::Mat> train_feats;
	for (int i = 0; i < face_struct_train.size(); i++)
	{
		Detect(face_struct_train[i]);
		if (face_struct_train[i].faceRect.size() > 0)
			train_feats.push_back(face_struct_train[i].feats[0]);//训练仅有一张人脸
		else
			face_struct_train.erase(face_struct_train.begin() + i);
	}

	return SimCalc(train_feats, face_struct_test);
}
//--------------------------------相似度计算----------------------------------------//
std::vector<std::vector<float>> FaceFeature::SimCalc(std::vector<cv::Mat> train_feats,
	FaceStruct& face_struct_test)
{
	std::vector<std::vector<float>> result;
	Detect(face_struct_test);
	if (face_struct_test.feats.size() > 0)
	{
		std::vector<cv::Mat> test_feats = face_struct_test.feats;

		for (auto i = 0; i < test_feats.size(); i++)
		{
			std::vector<float> single_result;
			for (auto j = 0; j < train_feats.size(); j++)
			{
				cv::Mat feat1 = test_feats[i];
				cv::Mat feat2 = train_feats[j];
				double sim = 1 / (1 + norm(feat1, feat2, CV_L2));
				single_result.push_back(sim);
			}
			result.push_back(single_result);
		}
		return result;
	}
}
