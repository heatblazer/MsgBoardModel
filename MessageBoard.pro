#-------------------------------------------------
#
# Project created by Ilian Zapryanov (mrbitmap)  2016-05-10T14:28:56
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MessageBoard
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -Wextra -pedantic -Wmissing-braces \
-Wparentheses -Wsequence-point -Wswitch -Wuninitialized -Wcast-qual \
-Wlogical-op -Wnormalized=nfkc


SOURCES += main.cpp \
    msgboardmodel.cpp \
    userapi.cpp \
    userapiimpl.cpp \
    msgboardview.cpp \
    types.cpp \
    deleteme.cpp


HEADERS  += \
    msgboardmodel.h \
    types.h \
    userapi.h \
    usrapiimpl.h \
    msgboardveiw.h \
    deleteme.h

FORMS    +=


