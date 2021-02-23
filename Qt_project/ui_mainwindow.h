/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Load;
    QPushButton *Gaussian_Blur;
    QLabel *Last_filter;
    QPushButton *Horizontal_Mirror;
    QPushButton *Threshold;
    QPushButton *HSV_Saturation;
    QPushButton *Close;
    QPushButton *Grayscale;
    QPushButton *Filtered_Image;
    QPushButton *Histogram;
    QPushButton *Contrast;
    QPushButton *Brightness;
    QPushButton *Select_RGB;
    QPushButton *HV_Mirror;
    QPushButton *Delete;
    QPushButton *Vertical_Mirror;
    QLabel *Preview_img;
    QPushButton *Negative;
    QPushButton *High_pass;
    QPushButton *Rotate;
    QPushButton *Save;
    QPushButton *SaturationRGB;
    QPushButton *Original_Image;
    QPushButton *Box_Blur;
    QPushButton *Sepia;
    QPushButton *Low_pass_smoothing;
    QPushButton *Low_pass_Median;
    QLabel *Original_img;
    QPushButton *HSV_Brightness;
    QLabel *Original_img_label;
    QLabel *Filtered_img_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1070, 765);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(150,150, 150);\n"
""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Load = new QPushButton(centralwidget);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Load, 3, 0, 1, 1);

        Gaussian_Blur = new QPushButton(centralwidget);
        Gaussian_Blur->setObjectName(QString::fromUtf8("Gaussian_Blur"));
        Gaussian_Blur->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Gaussian_Blur, 8, 4, 1, 2);

        Last_filter = new QLabel(centralwidget);
        Last_filter->setObjectName(QString::fromUtf8("Last_filter"));
        Last_filter->setEnabled(true);
        Last_filter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0)"));

        gridLayout->addWidget(Last_filter, 9, 0, 1, 1);

        Horizontal_Mirror = new QPushButton(centralwidget);
        Horizontal_Mirror->setObjectName(QString::fromUtf8("Horizontal_Mirror"));
        Horizontal_Mirror->setEnabled(true);
        Horizontal_Mirror->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Horizontal_Mirror, 5, 1, 1, 2);

        Threshold = new QPushButton(centralwidget);
        Threshold->setObjectName(QString::fromUtf8("Threshold"));
        Threshold->setEnabled(true);
        Threshold->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Threshold, 6, 1, 1, 2);

        HSV_Saturation = new QPushButton(centralwidget);
        HSV_Saturation->setObjectName(QString::fromUtf8("HSV_Saturation"));
        HSV_Saturation->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(HSV_Saturation, 7, 0, 1, 1);

        Close = new QPushButton(centralwidget);
        Close->setObjectName(QString::fromUtf8("Close"));
        Close->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Close, 9, 5, 1, 1);

        Grayscale = new QPushButton(centralwidget);
        Grayscale->setObjectName(QString::fromUtf8("Grayscale"));
        Grayscale->setEnabled(true);
        Grayscale->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Grayscale, 6, 3, 1, 1);

        Filtered_Image = new QPushButton(centralwidget);
        Filtered_Image->setObjectName(QString::fromUtf8("Filtered_Image"));
        Filtered_Image->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Filtered_Image, 1, 5, 1, 1);

        Histogram = new QPushButton(centralwidget);
        Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Histogram->setEnabled(true);
        Histogram->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Histogram, 4, 4, 1, 2);

        Contrast = new QPushButton(centralwidget);
        Contrast->setObjectName(QString::fromUtf8("Contrast"));
        Contrast->setEnabled(true);
        Contrast->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Contrast, 4, 1, 1, 2);

        Brightness = new QPushButton(centralwidget);
        Brightness->setObjectName(QString::fromUtf8("Brightness"));
        Brightness->setEnabled(true);
        Brightness->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Brightness, 7, 3, 1, 1);

        Select_RGB = new QPushButton(centralwidget);
        Select_RGB->setObjectName(QString::fromUtf8("Select_RGB"));
        Select_RGB->setEnabled(true);
        Select_RGB->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Select_RGB, 4, 3, 1, 1);

        HV_Mirror = new QPushButton(centralwidget);
        HV_Mirror->setObjectName(QString::fromUtf8("HV_Mirror"));
        HV_Mirror->setEnabled(true);
        HV_Mirror->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(HV_Mirror, 5, 4, 1, 2);

        Delete = new QPushButton(centralwidget);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Delete, 9, 2, 1, 2);

        Vertical_Mirror = new QPushButton(centralwidget);
        Vertical_Mirror->setObjectName(QString::fromUtf8("Vertical_Mirror"));
        Vertical_Mirror->setEnabled(true);
        Vertical_Mirror->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Vertical_Mirror, 5, 3, 1, 1);

        Preview_img = new QLabel(centralwidget);
        Preview_img->setObjectName(QString::fromUtf8("Preview_img"));
        Preview_img->setAutoFillBackground(false);
        Preview_img->setMargin(0);

        gridLayout->addWidget(Preview_img, 2, 3, 1, 3);

        Negative = new QPushButton(centralwidget);
        Negative->setObjectName(QString::fromUtf8("Negative"));
        Negative->setEnabled(true);
        Negative->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Negative, 6, 0, 1, 1);

        High_pass = new QPushButton(centralwidget);
        High_pass->setObjectName(QString::fromUtf8("High_pass"));
        High_pass->setEnabled(true);
        High_pass->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(High_pass, 4, 0, 1, 1);

        Rotate = new QPushButton(centralwidget);
        Rotate->setObjectName(QString::fromUtf8("Rotate"));
        Rotate->setEnabled(true);
        Rotate->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Rotate, 5, 0, 1, 1);

        Save = new QPushButton(centralwidget);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Save, 3, 3, 1, 1);

        SaturationRGB = new QPushButton(centralwidget);
        SaturationRGB->setObjectName(QString::fromUtf8("SaturationRGB"));
        SaturationRGB->setEnabled(true);
        SaturationRGB->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(SaturationRGB, 7, 4, 1, 2);

        Original_Image = new QPushButton(centralwidget);
        Original_Image->setObjectName(QString::fromUtf8("Original_Image"));
        Original_Image->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Original_Image, 1, 2, 1, 1);

        Box_Blur = new QPushButton(centralwidget);
        Box_Blur->setObjectName(QString::fromUtf8("Box_Blur"));
        Box_Blur->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Box_Blur, 8, 3, 1, 1);

        Sepia = new QPushButton(centralwidget);
        Sepia->setObjectName(QString::fromUtf8("Sepia"));
        Sepia->setEnabled(true);
        Sepia->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Sepia, 6, 4, 1, 2);

        Low_pass_smoothing = new QPushButton(centralwidget);
        Low_pass_smoothing->setObjectName(QString::fromUtf8("Low_pass_smoothing"));
        Low_pass_smoothing->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Low_pass_smoothing, 8, 0, 1, 1);

        Low_pass_Median = new QPushButton(centralwidget);
        Low_pass_Median->setObjectName(QString::fromUtf8("Low_pass_Median"));
        Low_pass_Median->setEnabled(true);
        Low_pass_Median->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(Low_pass_Median, 8, 1, 1, 2);

        Original_img = new QLabel(centralwidget);
        Original_img->setObjectName(QString::fromUtf8("Original_img"));
        Original_img->setStyleSheet(QString::fromUtf8("border-color: rgb(193, 193, 193);"));

        gridLayout->addWidget(Original_img, 2, 0, 1, 3);

        HSV_Brightness = new QPushButton(centralwidget);
        HSV_Brightness->setObjectName(QString::fromUtf8("HSV_Brightness"));
        HSV_Brightness->setEnabled(true);
        HSV_Brightness->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        gridLayout->addWidget(HSV_Brightness, 7, 1, 1, 2);

        Original_img_label = new QLabel(centralwidget);
        Original_img_label->setObjectName(QString::fromUtf8("Original_img_label"));
        Original_img_label->setEnabled(true);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        Original_img_label->setFont(font);

        gridLayout->addWidget(Original_img_label, 1, 0, 1, 3);

        Filtered_img_label = new QLabel(centralwidget);
        Filtered_img_label->setObjectName(QString::fromUtf8("Filtered_img_label"));
        Filtered_img_label->setFont(font);

        gridLayout->addWidget(Filtered_img_label, 1, 3, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        Original_img_label->raise();
        Rotate->raise();
        Grayscale->raise();
        Original_Image->raise();
        Low_pass_smoothing->raise();
        Original_img->raise();
        Negative->raise();
        Gaussian_Blur->raise();
        Last_filter->raise();
        HSV_Saturation->raise();
        SaturationRGB->raise();
        Load->raise();
        High_pass->raise();
        Box_Blur->raise();
        Close->raise();
        Delete->raise();
        Horizontal_Mirror->raise();
        Vertical_Mirror->raise();
        HV_Mirror->raise();
        Filtered_img_label->raise();
        Sepia->raise();
        Select_RGB->raise();
        HSV_Brightness->raise();
        Save->raise();
        Low_pass_Median->raise();
        Contrast->raise();
        Threshold->raise();
        Brightness->raise();
        Histogram->raise();
        Preview_img->raise();
        Filtered_Image->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BMP filter editor", nullptr));
        Load->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        Gaussian_Blur->setText(QCoreApplication::translate("MainWindow", "Gaussian_Blur", nullptr));
        Last_filter->setText(QCoreApplication::translate("MainWindow", " Last filter: No filter used", nullptr));
        Horizontal_Mirror->setText(QCoreApplication::translate("MainWindow", "Horizontal_Mirror", nullptr));
        Threshold->setText(QCoreApplication::translate("MainWindow", "Threshold", nullptr));
        HSV_Saturation->setText(QCoreApplication::translate("MainWindow", "HSV_Saturation", nullptr));
        Close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        Grayscale->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        Filtered_Image->setText(QCoreApplication::translate("MainWindow", "Original size output image", nullptr));
        Histogram->setText(QCoreApplication::translate("MainWindow", "Eq_Histogram", nullptr));
        Contrast->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        Brightness->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        Select_RGB->setText(QCoreApplication::translate("MainWindow", "Select_RGB", nullptr));
        HV_Mirror->setText(QCoreApplication::translate("MainWindow", "HV_Mirror", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "Delete Filters", nullptr));
        Vertical_Mirror->setText(QCoreApplication::translate("MainWindow", "Vertical_Mirror", nullptr));
        Preview_img->setText(QString());
        Negative->setText(QCoreApplication::translate("MainWindow", "Negative", nullptr));
        High_pass->setText(QCoreApplication::translate("MainWindow", "High_pass", nullptr));
        Rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "Save Image", nullptr));
        SaturationRGB->setText(QCoreApplication::translate("MainWindow", "Saturation_RGB", nullptr));
        Original_Image->setText(QCoreApplication::translate("MainWindow", "Original size input image", nullptr));
        Box_Blur->setText(QCoreApplication::translate("MainWindow", "Box_Blur", nullptr));
        Sepia->setText(QCoreApplication::translate("MainWindow", "Sepia", nullptr));
        Low_pass_smoothing->setText(QCoreApplication::translate("MainWindow", "Low_pass_Smoothing", nullptr));
        Low_pass_Median->setText(QCoreApplication::translate("MainWindow", "Low_pass_Median", nullptr));
        Original_img->setText(QString());
        HSV_Brightness->setText(QCoreApplication::translate("MainWindow", "HSV_Brightness", nullptr));
        Original_img_label->setText(QString());
        Filtered_img_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
