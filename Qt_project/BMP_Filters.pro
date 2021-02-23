QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Brightness.cpp \
    Convolution.cpp \
    Grayscale.cpp \
    HSV_color_model_operations.cpp \
    HV_Mirror.cpp \
    High_pass.cpp \
    Histogram.cpp \
    Horizontal_Mirror.cpp \
    Low_pass.cpp \
    Negative.cpp \
    Rotate.cpp \
    SaturationRGB.cpp \
    Select_RGB.cpp \
    Sepia.cpp \
    Threshold.cpp \
    Vertical_Mirror.cpp \
    bitmap.cpp \
    contrast.cpp \
    filter.cpp \
    image.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Brightness.h \
    Convolution.h \
    Grayscale.h \
    HSV_color_model_operations.h \
    HV_Mirror.h \
    High_pass.h \
    Histogram.h \
    Horizontal_Mirror.h \
    Low_pass.h \
    Negative.h \
    Rotate.h \
    SaturationRGB.h \
    Select_RGB.h \
    Sepia.h \
    Threshold.h \
    Vertical_Mirror.h \
    bitmap.h \
    contrast.h \
    filter.h \
    image.h \
    mainwindow.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
