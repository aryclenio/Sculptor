#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T07:22:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sculptor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
		sculptor.cpp \
    painter.cpp \
    planedialogo.cpp
		

HEADERS  += mainwindow.h \
			sculptor.h \
    painter.h \
    planedialogo.h

FORMS    += mainwindow.ui \
    planedialogo.ui

RESOURCES += \
    images.qrc
