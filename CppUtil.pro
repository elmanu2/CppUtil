TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    testvector.cpp \
    date.cpp \
    logger.cpp \
    singleton.cpp \
    environment.cpp \
    helper.cpp \
    point2d.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    testvector.h \
    date.h \
    logger.h \
    singleton.h \
    environment.h \
    helper.h \
    point2d.h

