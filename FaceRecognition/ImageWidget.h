#pragma once

#include <QWidget>
#include "ui_ImageWidget.h"

class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	ImageWidget(QWidget *parent = Q_NULLPTR);
	~ImageWidget();
	void setPixmap(QPixmap& pixmap);
	void setText(QString);
	QPushButton* getRemoveBtn();

private:
	Ui::ImageWidget ui;
	QString text;

signals:
	void remove();
};
