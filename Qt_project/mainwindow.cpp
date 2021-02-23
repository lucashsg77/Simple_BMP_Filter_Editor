#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Threshold_clicked()
{
    if(data.size()!=0){

        bool ok;
        int value = QInputDialog::getInt(this, tr("Threshold"),tr("Threshold value:"), 128, 0, 255, 1, &ok);
        if(ok){
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Threshold threshold(aux);
            threshold.threshold_filter(value);//this input controls the value from which it will start to do the binarization of the pixels
            aux=threshold.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }
    }
}

void MainWindow::on_Negative_clicked()
{
    if(data.size()!=0){
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        Negative negative(aux);
        negative.negative_filter();
        aux=negative.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }
}

void MainWindow::on_Low_pass_Median_clicked()
{
    if(data.size()!=0){
        Low_pass low_pass(height, width, aux);
        bool ok;
        int radius = QInputDialog::getInt(this, tr("Low_Pass_Median"),tr("Depeding on the size of the image and radius this can take a long time\nRadius:"), 2, 0, 2147483647, 1, &ok);
        if(ok){
            low_pass.median(radius);//this  input is the radius for the filter
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            aux=low_pass.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }
    }

}

void MainWindow::on_Low_pass_smoothing_clicked(){
    if(data.size()!=0){
        Low_pass low_pass(height, width, aux);
        low_pass.smoothing();
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        aux = low_pass.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }
}

void MainWindow::on_Gaussian_Blur_clicked(){
    if(data.size()!=0){

        bool ok;
        int radius = QInputDialog::getInt(this, tr("Gaussian_Blur"),tr("Depeding on the size of the image and radius this can take a long time\nRadius:"), 2, 0, 2147483647, 1, &ok);
        if(ok){
            Low_pass low_pass(height, width, aux);
            low_pass.gaussian_blur(radius);//this  input is the radius for the filter
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            aux=low_pass.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }
    }
}

void MainWindow::on_Box_Blur_clicked(){
    if(data.size()!=0){

        bool ok;
        int radius = QInputDialog::getInt(this, tr("Box_Blur"),tr("Depending on the size of the image and radius this can take a long time\nRadius:"), 2, 0, 2147483647, 1,&ok);

        if(ok){


            Low_pass low_pass(height, width, aux);
            low_pass.box_blur(radius);//this  input is the radius for the filter
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            aux=low_pass.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }

    }
}

void MainWindow::on_Rotate_clicked()
{
    if(data.size()!=0){


        bool ok;
        double degree = QInputDialog::getDouble(this, tr("Rotate"), tr("Increase percentage:"), 0, -360, 360, 2, &ok);
        if(ok){

            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Rotate rotate(height, width, aux);
            rotate.rotate_filter(degree);// this is the angle that the image will be rotated
            aux = rotate.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }

    }
}

void MainWindow::on_SaturationRGB_clicked()
{
    if(data.size()!=0){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Saturation_RGB"), tr("Channel(red,green or blue):"), QLineEdit::Normal,"",&ok);
        if(ok){
            string channel = text.toLocal8Bit().constData();
            int i = QInputDialog::getInt(this, tr("SaturationRGB"),tr("Increase value:"), 0, 0, 255, 1);
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

            SaturationRGB saturationRGB(aux);
            saturationRGB.saturationRGB (channel,i); //to use it input the name of the channel to saturate and the value you want to saturate it with
            aux=saturationRGB.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }
    }

}

void MainWindow::on_Select_RGB_clicked()
{
    if(data.size()!=0){
        bool ok;
        QString text = QInputDialog::getText(this, tr("Select_RGB"), tr("Channel(red,green or blue):"), QLineEdit::Normal,"",&ok);
        if(ok){
            string channel = text.toLocal8Bit().constData();

            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Select_RGB selectRGB(aux);
            selectRGB.selectRGB_filter (channel);//this input controls channel that will be selected
            aux=selectRGB.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }

    }
}

void MainWindow::on_Sepia_clicked()
{
    if(data.size()!=0){

        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        Sepia sepia(aux);
        sepia.sepia_filter();
        aux=sepia.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }
}

void MainWindow::on_HV_Mirror_clicked()
{
    //Horizontal e Vertical
    if(data.size()!=0){

        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        HV_Mirror hv_mirror (height, width, aux);
        hv_mirror.hv_mirror_filter();
        aux=hv_mirror.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }
}

void MainWindow::on_Horizontal_Mirror_clicked()
{
    if(data.size()!=0){

        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        Horizontal_Mirror horizontal_mirror (height, width, aux);
        horizontal_mirror.horizontal_mirror_filter();
        aux=horizontal_mirror.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();

    }
}

void MainWindow::on_High_pass_clicked()
{
    if(data.size()!=0){

        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        int radius = 1;
        High_pass high_pass(height,width,aux);
        high_pass.high_pass(radius);//this  input is the radius for the filter, if bigger than 1 the image can get distorted!
        aux=high_pass.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }


}

void MainWindow::on_Brightness_clicked()
{
    if(data.size()!=0){
        bool ok;
        int value = QInputDialog::getInt(this, tr("Brightness"),tr("Increase value:"), 0, -255, 255, 1, &ok);

        if(ok){
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

            Brightness brightness(aux);
            brightness.brightness_filter(value);//this input is the value that will be summed to every channel of every pixel in the image, therefore enhancing the brightness
            aux=brightness.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();

        }
    }
}

void MainWindow::on_Histogram_clicked()
{
    if(data.size()!=0){
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
        Histogram histogram(aux);
        histogram.eq_histogram();
        aux=histogram.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();
    }
}

void MainWindow::on_Grayscale_clicked()
{
    if(data.size()!=0){
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

        Grayscale grayscale(aux);
        grayscale.grayscale_filter();
        aux=grayscale.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();

    }
}

void MainWindow::on_Contrast_clicked()
{
    if(data.size()!=0){
        bool ok;
        double value = QInputDialog::getDouble(this, tr("Contrast"),tr("Between 0 and 1 decreases contrast from 1 up increases contrast\n Value:"), 0,0, 255, 1, &ok);
        if(ok){

            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
            Contrast contrast(aux);
            contrast.contrast_filter(value);//this input will decrease contrast if euquals to any value between 0 and 1, from 1 up it will increase the contrast
            aux=contrast.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();
        }
    }
}

void MainWindow::on_Vertical_Mirror_clicked()
{
    if(data.size()!=0){
        QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

        Vertical_Mirror vertical_mirror (height, width, aux);
        vertical_mirror.vertical_mirror_filter();
        aux=vertical_mirror.filtered_pixel_data();
        image = stdVectorPixmap(aux);
        update_labels();

    }
}

void MainWindow::on_HSV_Saturation_clicked()
{
    if(data.size()!=0){

        bool ok;
        double increase_percentage = QInputDialog::getDouble(this, tr("HSV_Saturation"), tr("Increase percentage:"), 0, -1000, 1000, 2,&ok);
        if(ok){
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

            HSV hsv_model(aux);
            increase_percentage /= 100.0;
            hsv_model.saturationHSV(increase_percentage);//to use it input the percentage you want to increase the brightness, values from -1 to 1, for example -1 would take all the brighness away, 1 would double the brightness, 0 the brightness stays the same.
            aux=hsv_model.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();

        }
    }
}

void MainWindow::on_HSV_Brightness_clicked()
{
    if(data.size()!=0){
        bool ok;
        double increase_percentage = QInputDialog::getDouble(this, tr("HSV_Brightness"), tr("Increase percentage:"), 0, -1000, 1000, 2, &ok);
        if(ok){
            QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

            HSV hsv_model(aux);
            increase_percentage /= 100.0;
            hsv_model.brightnessHSV(increase_percentage);//to use it input the percentage you want to increase the brightness, values from -1 to 1, for example -1 would take all the brighness away, 1 would double the brightness, 0 the brightness stays the same.
            aux=hsv_model.filtered_pixel_data();
            image = stdVectorPixmap(aux);
            update_labels();

        }
    }
}

void MainWindow::on_Load_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.bmp)"));
    if(!name.isEmpty()){
        string text = name.toLocal8Bit().constData();

        const char* img = text.data();

        bmp.read(img);

        MainWindow_variables_attributions();

        set_initial_labels();
    }

}

void MainWindow::on_Close_clicked()
{
    QMessageBox::StandardButton question=QMessageBox::question(this,"","Do you want close the program?",QMessageBox::Yes|QMessageBox::No);
    if (question==QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else{

    }
}

void MainWindow::on_Save_clicked()
{
    if(!data.empty()){
        QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "untitled.bmp", tr("Images (*.bmp )"));
        string text = filename.toLocal8Bit().constData();
        const char* img =text.data();
        bmp.write(img, aux);
    }
}

void MainWindow::on_Delete_clicked()
{
    if(!data.empty()){
        ui->Preview_img->clear();
        ui->Filtered_img_label->clear();
        aux = data;
        image = stdVectorPixmap(aux);
        ui->Last_filter->setText("Last filter: Deleted filter");
    }

}

void MainWindow::on_Filtered_Image_clicked()
{
    if(aux.size()!=0 && !image.isNull()){
        QLabel * label_img = new QLabel (this);
        label_img->setWindowFlags(Qt::Window);
        label_img->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
        label_img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label_img->showMaximized();
    }
}

void MainWindow::on_Original_Image_clicked()
{
    if(data.size()!=0){
        QLabel * label_img = new QLabel (this);
        QVector<uint8_t> buffer= QVector<uint8_t>(data.begin(), data.end());
        QImage image(buffer.data(), width, height, QImage::Format_BGR888);
        image=image.mirrored(false, true);
        QPixmap pixmap = QPixmap::fromImage(image);
        label_img->setWindowFlags(Qt::Window);
        label_img->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio));
        label_img->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label_img->showMaximized();
    }
}

QPixmap MainWindow::stdVectorPixmap(vector <uint8_t> data)
{
    QVector<uint8_t> buffer=QVector<uint8_t>(data.begin(),data.end());
    QImage image(buffer.data(), width, height, QImage::Format_BGR888);
    image=image.mirrored(false,true);
    QPixmap pixmap = QPixmap::fromImage(image);
    return pixmap;
}

void MainWindow::update_labels()
{
    ui->Preview_img->setPixmap(image.scaled(label_w,label_h,Qt::KeepAspectRatio));
    ui->Preview_img->setScaledContents(true);
    ui->Filtered_img_label->setStyleSheet("font: 18pt;font-weight: bold;");
    ui->Filtered_img_label->setText("Filtered Image");
    QPushButton* buttonClicked = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    ui->Last_filter->setText("Last filter: " + buttonClicked->text());
    QApplication::restoreOverrideCursor();
}

void MainWindow::set_initial_labels()
{
    ui->Original_img->setPixmap(image.scaled(label_w,label_h,Qt::KeepAspectRatio));
    ui->Original_img->setScaledContents(true);
    ui->Filtered_img_label->setText("");
    ui->Preview_img->clear();
    ui->Original_img_label->setStyleSheet("font: 18pt;font-weight: bold;");
    ui->Original_img_label->setText("Original Image");
    ui->Original_img_label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->Original_img_label->setGeometry(20,65,501,41);
}

void MainWindow::MainWindow_variables_attributions()
{
    height = bmp.img_height();
    width = bmp.img_width();
    data = bmp.img_pixel_data();
    image = stdVectorPixmap(data);
    aux = data;
    label_w = ui->Original_img->width();
    label_h = ui->Original_img->height();
}
