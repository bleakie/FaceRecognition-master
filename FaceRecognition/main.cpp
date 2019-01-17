/*
## 创建标识：第十八届全国大学生物联网大赛人脸识别demo

## 创建时间：2017-11-16

## 算法功能描述：基于开源的人脸识别API：seetaface，包含人脸检测、人脸对齐、人脸识别

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

#include "FaceRecognition.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FaceRecognition w;
	w.show();
	return a.exec();
}
