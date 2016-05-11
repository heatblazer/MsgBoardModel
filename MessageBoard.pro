#-------------------------------------------------
#
# Project created by Ilian Zapryanov (mrbitmap)  2016-05-10T14:28:56
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MessageBoard
TEMPLATE = app


SOURCES += main.cpp \
    msgboardmodel.cpp \
    modelfactory.cpp \
    userapi.cpp \
    userapiimpl.cpp \
    msgboardview.cpp \
    types.cpp


HEADERS  += \
    msgboardmodel.h \
    modelfactory.h \
    types.h \
    userapi.h \
    usrapiimpl.h \
    msgboardveiw.h

FORMS    +=

#remove it later it`s for reference card
RESOURCES += info.txt
