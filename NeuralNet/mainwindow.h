#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QGraphicsScene>
#include "neuralnetwork.h"

using namespace NeuralNET;

typedef vector<pair<vector<float>,vector<int > > > DataVector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QApplication* app, QWidget *parent = 0);
    ~MainWindow();
    
private:
    QApplication * app;
    Ui::MainWindow *ui;
    NeuralNetwork *net;
    const int dimension, out_dimension;
    DataVector trainData;
    DataVector testData;
    QGraphicsScene *errorImageScene;    
    float lastError;
    bool stop;

    void loadData(QString fname, DataVector* target, QListWidget *widget);
    void drawTrainDataImage();
    void drawDataImage();
    void drawError(int step, int max_step, float error, float max_error);

public slots:
    void createNN();
    void loadW();
    void saveW();
    void loadTrainData();
    void loadTestData();
    void runTraining();
    void stopTraining();
    void runTesting();


};

#endif // MAINWINDOW_H
