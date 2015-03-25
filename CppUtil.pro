TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    CppUtil/src/date.cpp \
    CppUtil/src/environment.cpp \
    CppUtil/src/helper.cpp \
    CppUtil/src/logger.cpp \
    CppUtil/src/main.cpp \
    CppUtil/src/point2d.cpp \
    CppUtil/src/singleton.cpp \
    CppUtil/src/testvector.cpp \
    TestCppUtil/main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    CppUtil/inc/date.h \
    CppUtil/inc/environment.h \
    CppUtil/inc/helper.h \
    CppUtil/inc/logger.h \
    CppUtil/inc/point2d.h \
    CppUtil/inc/singleton.h \
    CppUtil/inc/testvector.h

INCLUDEPATH += CppUtil/inc \
    CppUtil/inc

