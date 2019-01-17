/*
## 创建标识：第十八届全国大学生物联网大赛人脸识别demo

## 创建时间：2017-11-16

## 函数功能描述：人脸识别界面

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

