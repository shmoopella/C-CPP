QT += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/main.cc \
    View/mainwindow.cc \
    qcustomplot.cc \
    Model/calculator_model.cc

HEADERS += \
    View/mainwindow.h \
    qcustomplot.h \
    Model/calculator_model.h \
    Controller/calculator_controller.h

FORMS += \
    View/mainwindow.ui

TARGET = mycalculator

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
