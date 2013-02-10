#-------------------------------------------------
#
# Project created by QtCreator 2011-03-24T17:36:52
#
#-------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NeuralNet
TEMPLATE = app

SOURCES += \    
    perceptron.cpp \
    continuous_perceptron.cpp \
    neurallayer.cpp \    
    neuralnetwork.cpp \
    picture.cpp \
    mainwindow.cpp \
    main.cpp \
    train.cpp

HEADERS += \
    perceptron.h \
    continuous_perceptron.h \
    neurallayer.h \
    neuralnetwork.h \
    mainwindow.h

QMAKE_CXXFLAGS_RELEASE += -O3

FORMS += \
    mainwindow.ui
