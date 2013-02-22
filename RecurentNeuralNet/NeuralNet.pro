#-------------------------------------------------
#
# Project created by QtCreator 2011-03-24T17:36:52
#
#-------------------------------------------------
TARGET = NeuralNet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    perceptron.cpp \
    continuous_perceptron.cpp \
    neurallayer.cpp \    
    neuralnetwork.cpp \
    elmannetwork.cpp

HEADERS += \
    perceptron.h \    
    continuous_perceptron.h \
    neurallayer.h \
    neuralnetwork.h \
    elmannetwork.h

QMAKE_CXXFLAGS_RELEASE += -O3
