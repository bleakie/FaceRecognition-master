/*
## ������ʶ����ʮ�˽�ȫ����ѧ����������������ʶ��demo

## ����ʱ�䣺2017-11-16

## �㷨�������������ڿ�Դ������ʶ��API��seetaface������������⡢�������롢����ʶ��

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

#include "FaceRecognition.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FaceRecognition w;
	w.show();
	return a.exec();
}
