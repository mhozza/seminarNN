/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Feb 17 21:12:21 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QPushButton *createPB;
    QPushButton *pbLoadW;
    QPushButton *pbSaveW;
    QDoubleSpinBox *alphaSB;
    QLabel *label;
    QPlainTextEdit *neteorkParamsTE;
    QGroupBox *groupBox_3;
    QSpinBox *roundsSB;
    QLabel *label_2;
    QPushButton *runPB;
    QGraphicsView *trainDataGW;
    QLabel *label_3;
    QPushButton *loadTrainDataPB;
    QProgressBar *progressBar;
    QListWidget *trainDataLW;
    QPushButton *stopPB;
    QGroupBox *groupBox_4;
    QPushButton *loadTestDataPB;
    QPushButton *pushButton_5;
    QListWidget *testDataLW;
    QGroupBox *groupBox;
    QGraphicsView *dataGW;
    QGraphicsView *errorGW;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(645, 509);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(16, 8, 185, 153));
        createPB = new QPushButton(groupBox_2);
        createPB->setObjectName(QString::fromUtf8("createPB"));
        createPB->setGeometry(QRect(80, 24, 98, 27));
        pbLoadW = new QPushButton(groupBox_2);
        pbLoadW->setObjectName(QString::fromUtf8("pbLoadW"));
        pbLoadW->setGeometry(QRect(80, 56, 98, 27));
        pbSaveW = new QPushButton(groupBox_2);
        pbSaveW->setObjectName(QString::fromUtf8("pbSaveW"));
        pbSaveW->setGeometry(QRect(80, 88, 98, 27));
        alphaSB = new QDoubleSpinBox(groupBox_2);
        alphaSB->setObjectName(QString::fromUtf8("alphaSB"));
        alphaSB->setGeometry(QRect(80, 120, 62, 27));
        alphaSB->setDecimals(3);
        alphaSB->setSingleStep(0.05);
        alphaSB->setValue(0.25);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(16, 128, 49, 17));
        neteorkParamsTE = new QPlainTextEdit(groupBox_2);
        neteorkParamsTE->setObjectName(QString::fromUtf8("neteorkParamsTE"));
        neteorkParamsTE->setGeometry(QRect(16, 29, 57, 89));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(216, 16, 265, 281));
        roundsSB = new QSpinBox(groupBox_3);
        roundsSB->setObjectName(QString::fromUtf8("roundsSB"));
        roundsSB->setGeometry(QRect(8, 176, 121, 27));
        roundsSB->setMaximum(10000);
        roundsSB->setSingleStep(10);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 152, 57, 17));
        runPB = new QPushButton(groupBox_3);
        runPB->setObjectName(QString::fromUtf8("runPB"));
        runPB->setGeometry(QRect(8, 232, 121, 27));
        trainDataGW = new QGraphicsView(groupBox_3);
        trainDataGW->setObjectName(QString::fromUtf8("trainDataGW"));
        trainDataGW->setGeometry(QRect(16, 48, 100, 100));
        trainDataGW->setFrameShape(QFrame::NoFrame);
        trainDataGW->setLineWidth(0);
        trainDataGW->setSceneRect(QRectF(0, 0, 100, 100));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(8, 24, 66, 17));
        loadTrainDataPB = new QPushButton(groupBox_3);
        loadTrainDataPB->setObjectName(QString::fromUtf8("loadTrainDataPB"));
        loadTrainDataPB->setGeometry(QRect(144, 16, 98, 27));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(8, 208, 121, 23));
        progressBar->setValue(100);
        trainDataLW = new QListWidget(groupBox_3);
        trainDataLW->setObjectName(QString::fromUtf8("trainDataLW"));
        trainDataLW->setGeometry(QRect(144, 48, 105, 177));
        stopPB = new QPushButton(groupBox_3);
        stopPB->setObjectName(QString::fromUtf8("stopPB"));
        stopPB->setGeometry(QRect(144, 232, 98, 27));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(496, 8, 129, 281));
        loadTestDataPB = new QPushButton(groupBox_4);
        loadTestDataPB->setObjectName(QString::fromUtf8("loadTestDataPB"));
        loadTestDataPB->setGeometry(QRect(16, 24, 98, 27));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(16, 240, 98, 27));
        testDataLW = new QListWidget(groupBox_4);
        testDataLW->setObjectName(QString::fromUtf8("testDataLW"));
        testDataLW->setGeometry(QRect(16, 56, 97, 177));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(24, 160, 113, 129));
        dataGW = new QGraphicsView(groupBox);
        dataGW->setObjectName(QString::fromUtf8("dataGW"));
        dataGW->setGeometry(QRect(8, 24, 100, 100));
        dataGW->setFrameShape(QFrame::NoFrame);
        dataGW->setSceneRect(QRectF(0, 0, 100, 100));
        errorGW = new QGraphicsView(centralwidget);
        errorGW->setObjectName(QString::fromUtf8("errorGW"));
        errorGW->setGeometry(QRect(32, 296, 585, 177));
        errorGW->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "NeuralNet Architecture", 0, QApplication::UnicodeUTF8));
        createPB->setText(QApplication::translate("MainWindow", "Create", 0, QApplication::UnicodeUTF8));
        pbLoadW->setText(QApplication::translate("MainWindow", "LoadW", 0, QApplication::UnicodeUTF8));
        pbSaveW->setText(QApplication::translate("MainWindow", "SaveW", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Training", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Rounds", 0, QApplication::UnicodeUTF8));
        runPB->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "TrainData", 0, QApplication::UnicodeUTF8));
        loadTrainDataPB->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        stopPB->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Testing", 0, QApplication::UnicodeUTF8));
        loadTestDataPB->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "DataView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
