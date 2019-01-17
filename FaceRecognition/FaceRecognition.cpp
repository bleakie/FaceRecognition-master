/*
## 创建标识：第五届全国大学生物联网大赛人脸识别demo

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

#include "FaceRecognition.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QTimer>
#include <QDesktopServices>
#include <QSignalMapper>
#include "ImageWidget.h"
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <ctime>

FaceRecognition::FaceRecognition(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.uploadButton1, SIGNAL(clicked()), this, SLOT(UploadClick1()));
	connect(ui.uploadButton2, SIGNAL(clicked()), this, SLOT(UploadClick2()));
	connect(ui.faceCompare, SIGNAL(clicked()), this, SLOT(FaceCompare()));

	connect(ui.detection, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectAlgorithm()));
	connect(ui.alignment, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectAlgorithm()));
	connect(ui.featureExtraction, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectAlgorithm()));
	//connect(ui.moreButton, SIGNAL(clicked()), this, SLOT(MoreClick()));

	fun.Init();
}

QImage Mat2QImage(cv::Mat const& src)
{
	cv::Mat temp; // make the same cv::Mat
	cv::cvtColor(src, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
	QImage dest((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits(); // enforce deep copy, see documentation 
				 // of QImage::QImage ( const uchar * data, int width, int height, Format format )
	return dest;
}

void ShowScaledImg(QString path, QLabel* qLabel)
{
	QImage *qImage = new QImage(path);
	QImage qScaledImage;
	QSize qImageSize = qImage->size();
	QSize qLabelSize = qLabel->size();
	double dWidthRatio = 1.0*qImageSize.width() / qLabelSize.width();
	double dHeightRatio = 1.0*qImageSize.height() / qLabelSize.height();
	if (dWidthRatio > dHeightRatio)
	{
		qScaledImage = qImage->scaledToWidth(qLabelSize.width());
	}
	else
	{
		qScaledImage = qImage->scaledToHeight(qLabelSize.height());
	}

	qLabel->setPixmap(QPixmap::fromImage(qScaledImage));
	qLabel->setAlignment(Qt::AlignCenter);
	qLabel->show();
}

void ShowProcessedImg(cv::Mat const& src, QLabel* qLabel)
{
	QImage qImage = Mat2QImage(src);

	QImage qScaledImage;
	QSize qImageSize = qImage.size();
	QSize qLabelSize = qLabel->size();
	double dWidthRatio = 1.0*qImageSize.width() / qLabelSize.width();
	double dHeightRatio = 1.0*qImageSize.height() / qLabelSize.height();
	if (dWidthRatio > dHeightRatio)
	{

		qScaledImage = qImage.scaledToWidth(qLabelSize.width());
	}
	else
	{
		qScaledImage = qImage.scaledToHeight(qLabelSize.height());
	}

	qLabel->setPixmap(QPixmap::fromImage(qScaledImage));
	qLabel->setAlignment(Qt::AlignCenter);
	qLabel->show();
}

void FaceRecognition::UploadClick1()
{
	QFileDialog dialog(this);
	dialog.setDirectory(".");
	dialog.setFileMode(QFileDialog::ExistingFiles);
	dialog.setNameFilter(trUtf8("image Files(*.jpg *.png)"));
	QStringList fileNames;
	if (dialog.exec())
		fileNames = dialog.selectedFiles();

	if (fileNames.length() == 0) {
		ui.resultBrowser->append("You didn't select any files.");
		return;
	}
	path1.clear();
	ui.imglistWidget->clear();

	int icon_width = 102, icon_height = 126;
	ui.imglistWidget->setIconSize(QSize(icon_width, icon_height));
	ui.imglistWidget->setResizeMode(QListView::Adjust);
	ui.imglistWidget->setViewMode(QListView::IconMode);
	ui.imglistWidget->setMovement(QListView::Static);
	ui.imglistWidget->setSpacing(10);

	QSignalMapper *mapper = new QSignalMapper(this);
	connect(mapper, SIGNAL(mapped(QString)), this, SLOT(DelImg(QString)));

	for (int i = 0; i < fileNames.length(); i++)
	{
		path1.push_back(fileNames[i].toStdString());

		QListWidgetItem *item = new QListWidgetItem();
		item->setSizeHint(QSize(icon_width + 30, icon_height));
		ui.imglistWidget->addItem(item);

		ImageWidget* widget = new ImageWidget();
		QPixmap *pixmap = new QPixmap(fileNames[i]);
		widget->setPixmap(*pixmap);
		widget->setText(fileNames[i]);

		ui.imglistWidget->setItemWidget(item, widget);

		connect(widget->getRemoveBtn(), SIGNAL(clicked()), mapper, SLOT(map()));
		mapper->setMapping(widget->getRemoveBtn(), fileNames[i]);
	}
}

void FaceRecognition::UploadClick2()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open image"), ".", tr("image Files(*.jpg *.png)"));
	if (path.length() == 0) {
		ui.resultBrowser->append("You didn't select any files.");
	}
	else {
		if (videocapTimer.isActive())
		{
			videocapTimer.stop();
			videoCap.release();
			//ui.videocaptureButton->setText(QString::fromLocal8Bit("打开摄像头"));
		}

		ShowScaledImg(path, ui.imglabel2);

		ui.resultBrowser->append("You selected: " + path);
		path2 = path.toStdString();
	}
}
//--------------------------------人脸比对----------------------------------------//
void FaceRecognition::FaceCompare()
{
	double time_Start = (double)clock();

	if (path2.length() == 0) {
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未选择文件/文件夹"));
		return;
	}
	if (path1.capacity() == 0)
	{
		//select no file
		QMessageBox::information(NULL, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("未选择文件/文件夹"));
		return;
	}

	ui.faceCompare->setDisabled(true);
	qApp->processEvents();

	std::vector<FaceStruct> result1;
	FaceStruct result2;
	std::vector<std::vector<float>> sim;

	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

	fun.Recognition(path1, path2, result1, result2, sim);

	for (int i = 0; i < sim.size(); i++)
	{
		std::vector<float> OneFaceSim = sim[i];
		if (OneFaceSim.size() == 0)
			continue;
		int argmax = std::distance(OneFaceSim.begin(), std::max_element(OneFaceSim.begin(), OneFaceSim.end()));//找到最大相似度的序号
		string argmaxName = result1[argmax].fileName;
		float score = OneFaceSim[argmax];
		if (score < THRESHOLD)
			continue;
		fun.DrawResult(result2, i, argmaxName);//标记测试得到的label
		ui.resultBrowser->append("Most similarity image is :" + QString::fromStdString(argmaxName) + " @ Similarity = " + QString::number(100 * score) + "%");
	}
	QApplication::restoreOverrideCursor();

	if (result1.size() > 0)
	{
		//clear first, and then show
		ui.imglistWidget->clear();
	}
	for (int i = 0; i < result1.size(); i++)
	{
		if (!result1[i].drawImg.data)
			continue;
		QImage img = Mat2QImage(result1[i].drawImg);
		QPixmap pixmap = QPixmap::fromImage(img);
		QListWidgetItem *pItem = new QListWidgetItem(QIcon(pixmap), NULL);
		//设置单元项的宽度和高度 
		int icon_width = 102, icon_height = 126;
		pItem->setSizeHint(QSize(icon_width, icon_height));
		ui.imglistWidget->insertItem(i, pItem);
	}


	if (result2.faceRect.size() == 0)
	{
		ui.resultBrowser->append(QString::fromStdString(path2) + " => [No face detected.]");
	}
	if(result2.drawImg.data)
		ShowProcessedImg(result2.drawImg, ui.imglabel2);


	ui.faceCompare->setDisabled(false);

	//calc time
	QString str;
	str.sprintf("Time elapsed : %.2fms", (double)clock() - time_Start);
	ui.resultBrowser->append(str);
}
