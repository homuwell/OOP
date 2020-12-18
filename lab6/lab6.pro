QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Circle.cpp \
    CreateTriangle.cpp \
    Rectangle.cpp \
    ShapeAccumulator.cc \
    Square.cpp \
    Triangle.cpp \
    createcircle.cpp \
    createsquare.cpp \
    main.cpp \
    mainwindow.cpp \
    newrectangle.cpp

HEADERS += \
    Circle.h \
    CreateTriangle.h \
    Figure.h \
    Rectangle.h \
    ShapeAccumulator.h \
    Square.h \
    Triangle.h \
    createcircle.h \
    createsquare.h \
    mainwindow.h \
    newrectangle.h

FORMS += \
    CreateTriangle.ui \
    createcircle.ui \
    createsquare.ui \
    mainwindow.ui \
    newrectangle.ui

LIBS += \
       -lboost_system\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

