#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QLabel>
#include <QPixmap>
#include <QInputDialog>
#include <QLayout>
#include <QFileDialog>
#include "Select_RGB.h"
#include "Sepia.h"
#include "Threshold.h"
#include "Vertical_Mirror.h"
#include "Horizontal_Mirror.h"
#include "HV_Mirror.h"
#include "Rotate.h"
#include "Low_pass.h"
#include "High_pass.h"
#include "Histogram.h"
#include "SaturationRGB.h"
#include "HSV_color_model_operations.h"
#include "Brightness.h"
#include "contrast.h"
#include "Negative.h"
#include "Grayscale.h"
#include "bitmap.h"
#include "filter.h"
#include "image.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
     Bitmap bmp;
     QPixmap image;
     int height, width;
     int label_w,label_h;
     vector<uint8_t> data;
     vector<uint8_t> aux;
     Ui::MainWindow *ui;

     QPixmap stdVectorPixmap(vector <uint8_t> data);

private slots:


    void on_Threshold_clicked();

    void on_Negative_clicked();

    void on_Low_pass_Median_clicked();

    void on_Low_pass_smoothing_clicked();

    void on_Gaussian_Blur_clicked();

    void on_Box_Blur_clicked();

    void on_Rotate_clicked();

    void on_SaturationRGB_clicked();

    void on_Select_RGB_clicked();

    void on_Sepia_clicked();

    void on_HV_Mirror_clicked();

    void on_Horizontal_Mirror_clicked();

    void on_High_pass_clicked();

    void on_Brightness_clicked();

    void on_Histogram_clicked();

    void on_Grayscale_clicked();

    void on_Contrast_clicked();

    void on_Vertical_Mirror_clicked();

    void on_Load_clicked();

    void on_Close_clicked();

    void on_Save_clicked();

    void on_HSV_Saturation_clicked();

    void on_HSV_Brightness_clicked();

    void on_Delete_clicked();

    void on_Filtered_Image_clicked();

    void on_Original_Image_clicked();

    void set_initial_labels();

    void MainWindow_variables_attributions();

    void update_labels();

};
#endif // MAINWINDOW_H
