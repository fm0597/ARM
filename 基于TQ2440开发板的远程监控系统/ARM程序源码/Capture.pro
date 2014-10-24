# -------------------------------------------------
# Project created by QtCreator 2014-04-30T15:39:28
# -------------------------------------------------
QT += core \
    gui
QT += network

# greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
LIBS += -L. \
    -lTQInputMethod

# INCLUDEPATH += /usr/local/include/opencv \
# /usr/local/include/opencv2
# LIBS += /usr/local/lib/libopencv_core.so.2.3.0 \
# /usr/local/lib/libopencv_highgui.so.2.3.0 \
# /usr/local/lib/libopencv_ml.so.2.3.0 \
# INCLUDEPATH += /usr/local/opencv_arm/include/opencv \
# /usr/local/opencv_arm/include/opencv2
# LIBS += /usr/local/opencv_arm/lib/libopencv_core.so \
# /usr/local/opencv_arm/lib/libopencv_highgui.so \
# /usr/local/opencv_arm/lib/libopencv_ml.so \
TARGET = Capture
TEMPLATE = app
SOURCES += main.cpp \
    capture.cpp \
    qextserialbase.cpp \
    posix_qextserialport.cpp
HEADERS += capture.h \
    video.h \
    TQInputMethod.h \
    qextserialbase.h \
    posix_qextserialport.h
FORMS += capture.ui \
    form.ui
HEADERS += photos.h
SOURCES += photos.cpp
FORMS += photos.ui
RESOURCES += Image.qrc
HEADERS += mainwindow.h
SOURCES += mainwindow.cpp
FORMS += mainwindow.ui
