/*
## ������ʶ����ʮ�˽�ȫ����ѧ����������������ʶ��demo

## ����ʱ�䣺2017-11-16

## ������������������ʶ�����

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

#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.removeButton->setIcon(QIcon("icon\\cross.png"));
	ui.removeButton->setIconSize(QSize(30, 30));
	ui.removeButton->setFixedSize(ui.removeButton->iconSize());
	ui.removeButton->setFlat(true);
}

ImageWidget::~ImageWidget()
{
}

void ImageWidget::setPixmap(QPixmap& pixmap)
{

	QSize qImageSize = pixmap.size();
	QSize qLabelSize = ui.label->size();
	double dWidthRatio = 1.0*qImageSize.width() / qLabelSize.width();
	double dHeightRatio = 1.0*qImageSize.height() / qLabelSize.height();
	if (dWidthRatio > dHeightRatio)
	{
		pixmap = pixmap.scaledToWidth(qLabelSize.width());
	}
	else
	{
		pixmap = pixmap.scaledToHeight(qLabelSize.height());
	}

	ui.label->setPixmap(pixmap);
	ui.label->setAlignment(Qt::AlignCenter);
	ui.label->show();
}

void ImageWidget::setText(QString qstring)
{
	text = qstring;
}

QPushButton* ImageWidget::getRemoveBtn()
{
	return ui.removeButton;
}

