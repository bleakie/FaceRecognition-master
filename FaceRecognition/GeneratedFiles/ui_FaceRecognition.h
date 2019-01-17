/********************************************************************************
** Form generated from reading UI file 'FaceRecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNITION_H
#define UI_FACERECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognitionClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_11;
    QPushButton *uploadButton1;
    QListWidget *imglistWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *uploadButton2;
    QLabel *imglabel2;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *detection;
    QComboBox *alignment;
    QComboBox *featureExtraction;
    QPushButton *faceCompare;
    QVBoxLayout *verticalLayout_2;
    QLabel *resultLabel;
    QTextBrowser *resultBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FaceRecognitionClass)
    {
        if (FaceRecognitionClass->objectName().isEmpty())
            FaceRecognitionClass->setObjectName(QStringLiteral("FaceRecognitionClass"));
        FaceRecognitionClass->resize(1312, 900);
        centralWidget = new QWidget(FaceRecognitionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        uploadButton1 = new QPushButton(centralWidget);
        uploadButton1->setObjectName(QStringLiteral("uploadButton1"));
        uploadButton1->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(16);
        uploadButton1->setFont(font);

        verticalLayout_11->addWidget(uploadButton1, 0, Qt::AlignHCenter);

        imglistWidget = new QListWidget(centralWidget);
        imglistWidget->setObjectName(QStringLiteral("imglistWidget"));
        imglistWidget->setEnabled(true);
        imglistWidget->setMinimumSize(QSize(640, 360));
        imglistWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_11->addWidget(imglistWidget);


        horizontalLayout->addLayout(verticalLayout_11);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        uploadButton2 = new QPushButton(centralWidget);
        uploadButton2->setObjectName(QStringLiteral("uploadButton2"));
        uploadButton2->setMaximumSize(QSize(180, 16777215));
        uploadButton2->setFont(font);

        horizontalLayout_4->addWidget(uploadButton2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        imglabel2 = new QLabel(centralWidget);
        imglabel2->setObjectName(QStringLiteral("imglabel2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imglabel2->sizePolicy().hasHeightForWidth());
        imglabel2->setSizePolicy(sizePolicy);
        imglabel2->setMinimumSize(QSize(640, 360));
        imglabel2->setMaximumSize(QSize(16777215, 16777215));
        imglabel2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        verticalLayout_7->addWidget(imglabel2);


        horizontalLayout->addLayout(verticalLayout_7);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 10, -1, -1);
        detection = new QComboBox(centralWidget);
        detection->setObjectName(QStringLiteral("detection"));
        detection->setMaximumSize(QSize(220, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(12);
        detection->setFont(font1);
        detection->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_7->addWidget(detection);

        alignment = new QComboBox(centralWidget);
        alignment->setObjectName(QStringLiteral("alignment"));
        alignment->setMaximumSize(QSize(220, 16777215));
        alignment->setFont(font1);

        horizontalLayout_7->addWidget(alignment);

        featureExtraction = new QComboBox(centralWidget);
        featureExtraction->setObjectName(QStringLiteral("featureExtraction"));
        featureExtraction->setMaximumSize(QSize(220, 16777215));
        featureExtraction->setFont(font1);

        horizontalLayout_7->addWidget(featureExtraction);

        faceCompare = new QPushButton(centralWidget);
        faceCompare->setObjectName(QStringLiteral("faceCompare"));
        faceCompare->setMaximumSize(QSize(200, 16777215));
        faceCompare->setFont(font);
        faceCompare->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(faceCompare);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        resultLabel->setTextFormat(Qt::AutoText);

        verticalLayout_2->addWidget(resultLabel);

        resultBrowser = new QTextBrowser(centralWidget);
        resultBrowser->setObjectName(QStringLiteral("resultBrowser"));
        resultBrowser->setFont(font1);

        verticalLayout_2->addWidget(resultBrowser);


        gridLayout_2->addLayout(verticalLayout_2, 2, 0, 1, 1);

        FaceRecognitionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FaceRecognitionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1312, 23));
        FaceRecognitionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FaceRecognitionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FaceRecognitionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FaceRecognitionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FaceRecognitionClass->setStatusBar(statusBar);

        retranslateUi(FaceRecognitionClass);

        QMetaObject::connectSlotsByName(FaceRecognitionClass);
    } // setupUi

    void retranslateUi(QMainWindow *FaceRecognitionClass)
    {
        FaceRecognitionClass->setWindowTitle(QApplication::translate("FaceRecognitionClass", "FaceRecognition", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        uploadButton1->setToolTip(QApplication::translate("FaceRecognitionClass", "\351\200\211\346\213\251\344\270\200\345\274\240\346\210\226\345\207\240\345\274\240\345\233\276\347\211\207\344\275\234\344\270\272\344\272\272\350\204\270\345\272\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        uploadButton1->setText(QApplication::translate("FaceRecognitionClass", "\350\257\267\351\200\211\346\213\251\344\270\200\345\274\240\346\210\226\345\244\232\345\274\240\345\233\276\347\211\207", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        uploadButton2->setToolTip(QApplication::translate("FaceRecognitionClass", "\351\200\211\346\213\251\344\270\200\345\274\240\345\233\276\347\211\207\344\270\216\345\257\271\344\272\272\350\204\270\345\272\223\346\257\224\350\276\203", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        uploadButton2->setText(QApplication::translate("FaceRecognitionClass", "\350\257\267\351\200\211\346\213\251\344\270\200\345\274\240\345\233\276\347\211\207", Q_NULLPTR));
        imglabel2->setText(QString());
        detection->clear();
        detection->insertItems(0, QStringList()
         << QApplication::translate("FaceRecognitionClass", "\344\272\272\350\204\270\346\243\200\346\265\213", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        detection->setToolTip(QApplication::translate("FaceRecognitionClass", "\344\272\272\350\204\270\346\243\200\346\265\213\347\256\227\346\263\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        alignment->clear();
        alignment->insertItems(0, QStringList()
         << QApplication::translate("FaceRecognitionClass", "\344\272\272\350\204\270\345\257\271\351\275\220", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        alignment->setToolTip(QApplication::translate("FaceRecognitionClass", "\344\272\272\350\204\270\345\257\271\351\275\220\347\256\227\346\263\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        featureExtraction->clear();
        featureExtraction->insertItems(0, QStringList()
         << QApplication::translate("FaceRecognitionClass", "\347\211\271\345\276\201\346\217\220\345\217\226", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        featureExtraction->setToolTip(QApplication::translate("FaceRecognitionClass", "\347\211\271\345\276\201\346\217\220\345\217\226\347\256\227\346\263\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        faceCompare->setText(QApplication::translate("FaceRecognitionClass", "\345\274\200\345\247\213\344\272\272\350\204\270\346\257\224\345\257\271", Q_NULLPTR));
        resultLabel->setText(QApplication::translate("FaceRecognitionClass", "\350\276\223\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognitionClass: public Ui_FaceRecognitionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNITION_H
