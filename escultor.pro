TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cutbox.cpp \
    sculptor.cpp \
    putbox.cpp \
    putsphere.cpp \
    cutsphere.cpp \
    putellipsoid.cpp \
    cutellipsoid.cpp

HEADERS += \
    voxel.h \
    cutbox.h \
    figurageometrica.h \
    putbox.h \
    sculptor.h \
    putsphere.h \
    cutsphere.h \
    putellipsoid.h \
    cutellipsoid.h
