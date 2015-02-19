TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    testvector.cpp \
    date.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    testvector.h \
    date.h

