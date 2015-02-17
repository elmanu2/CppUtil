TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    testvector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    testvector.h

