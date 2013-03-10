#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <QDebug>
#include <iostream>

using namespace std;

#define FRAMES 1

MainWindow::MainWindow(QApplication *app, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    net(NULL),
    dimension(2),
    out_dimension(3),
    stop(true),
    lastError(-1),
    app(app)

{
    ui->setupUi(this);


    errorImageScene = new QGraphicsScene();
    ui->errorGW->setScene(errorImageScene);

    connect(ui->createPB,SIGNAL(clicked()),this,SLOT(createNN()));
    connect(ui->loadTrainDataPB,SIGNAL(clicked()),this,SLOT(loadTrainData()));
    connect(ui->loadTestDataPB,SIGNAL(clicked()),this,SLOT(loadTestData()));
    connect(ui->runPB,SIGNAL(clicked()),this,SLOT(runTraining()));
    connect(ui->stopPB,SIGNAL(clicked()),this,SLOT(stopTraining()));
    connect(ui->runTestingPB,SIGNAL(clicked()),this,SLOT(runTesting()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNN()
{    
    float alpha = (float)ui->alphaSB->value();
    QString params = ui->neteorkParamsTE->toPlainText();
    QStringList paramsArray = params.split("\n");
    while(!paramsArray.empty() and paramsArray.back()=="") paramsArray.pop_back();
    unsigned sizes[paramsArray.size()+1];
    for(int i = 0;i<paramsArray.size();i++)
    {        
        sizes[i] = paramsArray[i].toUInt();
    }    
    sizes[paramsArray.size()] = out_dimension;
    if (net != NULL) delete net;
    net = new NeuralNetwork(paramsArray.size()+1,sizes,dimension,alpha);
}

void MainWindow::loadW()
{

}

void MainWindow::saveW()
{

}

void MainWindow::loadData(QString fname, DataVector *target, QListWidget* widget)
{
    ifstream ifs(fname.toStdString().c_str());
    string line;
    widget->clear();
    getline(ifs,line);
    while(getline(ifs,line))
    {
        widget->addItem(QString(line.c_str()));
        istringstream iss(line);
        target->resize(target->size()+1);
        for(int i = 0; i < dimension;i++)
        {
            float f;
            iss >> f;
            (*target)[target->size()-1].first.push_back(f);
        }
        for(int i = 0; i < out_dimension;i++)
        {
            float f;
            iss >> f;
            (*target)[target->size()-1].second.push_back(f);
        }
    }
}

void MainWindow::loadTrainData()
{
    loadData(QString("train.dat"),&trainData,ui->trainDataLW);
    drawTrainDataImage();
}

void MainWindow::loadTestData()
{
    loadData(QString("test.dat"),&testData,ui->testDataLW);
}

void MainWindow::runTraining()
{
    int rounds = ui->roundsSB->value();
    ui->progressBar->setValue(0);
    errorImageScene->clear();

    float E = 0;

    stop = false;
    for(int i = 0;i< rounds;i++)
    {
        if(stop) break;
        random_shuffle(trainData.begin(),trainData.end());
        E = 0;
        for(int j = 0; j<trainData.size();j++)
        {
//            vector<float> c = net->classify(trainData[i].first);
            float e = net->train(trainData[j].first,trainData[j].second);
            E += e;
        }
        ui->progressBar->setValue(round(100*(i+1)/rounds));
        if(!(i%FRAMES))
            drawDataImage();
        drawError(i,rounds+2,E,400);
        app->processEvents();
    }
    lastError = -1;
    drawDataImage();
    ui->progressBar->setValue(100);
    ui->trainResLbl->setText("Result: " + QString::number(E) );
    cout << E << endl;
}

int findMax(vector<float> &v)
{
    float m = v[0];
    int maxi = 0;
    for(int i = 1;i<v.size();i++)
    {
        if(v[i]>m)
        {
            m = v[i];
            maxi = i;
        }
    }
    return maxi;
}

void MainWindow::runTesting()
{
    float succ = 0, E = 0;

    for(int j = 0; j<testData.size();j++)
    {
        vector<float> c = net->classify(trainData[j].first);
        float e = 0;
        for(int i = 0;i<c.size();i++)
        {
            e+=(c[i]-testData[j].second[i])*(c[i]-testData[j].second[i])/2.0;
        }
        if(testData[j].second[findMax(c)] == 1) succ++;
        E += e;
    }
    ui->testResLbl->setText("Result: " + QString::number(E) + "\nSuccess: " + QString::number(100*succ/testData.size()) + "%"  );

}

void MainWindow::stopTraining()
{
    stop = true;
}

void MainWindow::drawTrainDataImage()
{
    QGraphicsScene *scene = new QGraphicsScene();
    ui->trainDataGW->setScene(scene);
    scene->clear();

    QImage img(100,100,QImage::Format_RGB32);
    img.fill(Qt::black);

    for(unsigned i = 0; i<trainData.size();i++)
    {
        int x = floor((5+trainData[i].first[0])*10);
        int y = floor((5+trainData[i].first[1])*10);

        QColor c(Qt::black);
        if(trainData[i].second[0]) c = Qt::red;
        if(trainData[i].second[1]) c = Qt::green;
        if(trainData[i].second[2]) c = Qt::blue;

        img.setPixel(x,y,(uint)c.rgb());
    }
    QPixmap pm(100,100);
    scene->addPixmap(pm.fromImage(img));
}

void MainWindow::drawDataImage()
{
    QGraphicsScene *scene = new QGraphicsScene();
    ui->dataGW->setScene(scene);
    scene->clear();

    QImage img(100,100,QImage::Format_RGB32);
    img.fill(Qt::black);

    for(unsigned x = 0; x<100;x++)
    {
        for(unsigned y = 0; y<100;y++)
        {
            vector<float> in(2);
            in[0] = (x/10.0)-5.0;
            in[1] = (y/10.0)-5.0;
            vector<float> out = net->classify(in);

            QColor c(Qt::blue);
            if(out[1] > out[2]) c = Qt::green;
            if(out[0]> out[1] && out[0] > out[2]) c = Qt::red;

            img.setPixel(x,y,(uint)c.rgb());
        }
    }
    QPixmap pm(100,100);
    scene->addPixmap(pm.fromImage(img));
}

void MainWindow::drawError(int step, int max_step, float error, float max_error)
{
    if(lastError == -1) lastError = max_error;
    float x = ((float)(step*ui->errorGW->width())/max_step);
    float lastX = ((float)((step-1)*ui->errorGW->width())/max_step);
    float y = ui->errorGW->height() - ((error*ui->errorGW->height())/max_error);
    float lastY = ui->errorGW->height() - ((lastError*ui->errorGW->height())/max_error);

    /*qDebug() << "Error:" << error;
    qDebug() << "GW height:" << ui->errorGW->height();
    qDebug() << "y:" << y;*/

    errorImageScene->addLine(lastX,lastY,x,y,QPen(Qt::blue));

    lastError = error;
}


