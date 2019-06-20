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
    planedialog.cpp \
		sculptor.cpp \
    painter.cpp \
    setsize.cpp
		

HEADERS  += mainwindow.h \
    planedialog.h \
			sculptor.h \
    painter.h \
    setsize.h

FORMS    += mainwindow.ui \
    planedialog.ui
