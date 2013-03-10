/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
    QLabel *trainResLbl;
    QGroupBox *groupBox_4;
    QPushButton *loadTestDataPB;
    QPushButton *runTestingPB;
    QListWidget *testDataLW;
    QLabel *testResLbl;
    QGroupBox *groupBox;
    QGraphicsView *dataGW;
    QGraphicsView *errorGW;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(645, 509);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(16, 8, 185, 153));
        createPB = new QPushButton(groupBox_2);
        createPB->setObjectName(QStringLiteral("createPB"));
        createPB->setGeometry(QRect(80, 24, 98, 27));
        pbLoadW = new QPushButton(groupBox_2);
        pbLoadW->setObjectName(QStringLiteral("pbLoadW"));
        pbLoadW->setGeometry(QRect(80, 56, 98, 27));
        pbSaveW = new QPushButton(groupBox_2);
        pbSaveW->setObjectName(QStringLiteral("pbSaveW"));
        pbSaveW->setGeometry(QRect(80, 88, 98, 27));
        alphaSB = new QDoubleSpinBox(groupBox_2);
        alphaSB->setObjectName(QStringLiteral("alphaSB"));
        alphaSB->setGeometry(QRect(80, 120, 62, 27));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        alphaSB->setFont(font);
        alphaSB->setLocale(QLocale(QLocale::Slovak, QLocale::Slovakia));
        alphaSB->setDecimals(3);
        alphaSB->setSingleStep(0.05);
        alphaSB->setValue(0.25);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 128, 49, 17));
        neteorkParamsTE = new QPlainTextEdit(groupBox_2);
        neteorkParamsTE->setObjectName(QStringLiteral("neteorkParamsTE"));
        neteorkParamsTE->setGeometry(QRect(16, 29, 57, 89));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(210, 0, 265, 291));
        roundsSB = new QSpinBox(groupBox_3);
        roundsSB->setObjectName(QStringLiteral("roundsSB"));
        roundsSB->setGeometry(QRect(10, 170, 121, 27));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        roundsSB->setFont(font1);
        roundsSB->setLocale(QLocale(QLocale::Slovak, QLocale::Slovakia));
        roundsSB->setMaximum(10000);
        roundsSB->setSingleStep(10);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(8, 152, 57, 17));
        runPB = new QPushButton(groupBox_3);
        runPB->setObjectName(QStringLiteral("runPB"));
        runPB->setGeometry(QRect(10, 230, 121, 27));
        trainDataGW = new QGraphicsView(groupBox_3);
        trainDataGW->setObjectName(QStringLiteral("trainDataGW"));
        trainDataGW->setGeometry(QRect(16, 48, 100, 100));
        trainDataGW->setFrameShape(QFrame::NoFrame);
        trainDataGW->setLineWidth(0);
        trainDataGW->setSceneRect(QRectF(0, 0, 100, 100));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(8, 24, 66, 17));
        loadTrainDataPB = new QPushButton(groupBox_3);
        loadTrainDataPB->setObjectName(QStringLiteral("loadTrainDataPB"));
        loadTrainDataPB->setGeometry(QRect(144, 16, 98, 27));
        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 200, 121, 23));
        progressBar->setValue(100);
        trainDataLW = new QListWidget(groupBox_3);
        trainDataLW->setObjectName(QStringLiteral("trainDataLW"));
        trainDataLW->setGeometry(QRect(144, 48, 105, 171));
        stopPB = new QPushButton(groupBox_3);
        stopPB->setObjectName(QStringLiteral("stopPB"));
        stopPB->setGeometry(QRect(150, 230, 98, 27));
        trainResLbl = new QLabel(groupBox_3);
        trainResLbl->setObjectName(QStringLiteral("trainResLbl"));
        trainResLbl->setGeometry(QRect(10, 260, 231, 16));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(496, 8, 129, 281));
        loadTestDataPB = new QPushButton(groupBox_4);
        loadTestDataPB->setObjectName(QStringLiteral("loadTestDataPB"));
        loadTestDataPB->setGeometry(QRect(16, 24, 98, 27));
        runTestingPB = new QPushButton(groupBox_4);
        runTestingPB->setObjectName(QStringLiteral("runTestingPB"));
        runTestingPB->setGeometry(QRect(10, 200, 98, 27));
        testDataLW = new QListWidget(groupBox_4);
        testDataLW->setObjectName(QStringLiteral("testDataLW"));
        testDataLW->setGeometry(QRect(16, 56, 97, 141));
        testResLbl = new QLabel(groupBox_4);
        testResLbl->setObjectName(QStringLiteral("testResLbl"));
        testResLbl->setGeometry(QRect(10, 245, 101, 31));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(24, 160, 113, 129));
        dataGW = new QGraphicsView(groupBox);
        dataGW->setObjectName(QStringLiteral("dataGW"));
        dataGW->setGeometry(QRect(8, 24, 100, 100));
        dataGW->setFrameShape(QFrame::NoFrame);
        dataGW->setSceneRect(QRectF(0, 0, 100, 100));
        errorGW = new QGraphicsView(centralwidget);
        errorGW->setObjectName(QStringLiteral("errorGW"));
        errorGW->setGeometry(QRect(32, 296, 585, 177));
        errorGW->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "NeuralNet Architecture", 0));
        createPB->setText(QApplication::translate("MainWindow", "Create", 0));
        pbLoadW->setText(QApplication::translate("MainWindow", "LoadW", 0));
        pbSaveW->setText(QApplication::translate("MainWindow", "SaveW", 0));
        label->setText(QApplication::translate("MainWindow", "Alpha", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Training", 0));
        label_2->setText(QApplication::translate("MainWindow", "Rounds", 0));
        runPB->setText(QApplication::translate("MainWindow", "Run", 0));
        label_3->setText(QApplication::translate("MainWindow", "TrainData", 0));
        loadTrainDataPB->setText(QApplication::translate("MainWindow", "Load", 0));
        stopPB->setText(QApplication::translate("MainWindow", "Stop", 0));
        trainResLbl->setText(QApplication::translate("MainWindow", "Result: ", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Testing", 0));
        loadTestDataPB->setText(QApplication::translate("MainWindow", "Load", 0));
        runTestingPB->setText(QApplication::translate("MainWindow", "Test", 0));
        testResLbl->setText(QApplication::translate("MainWindow", "Result: ", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "DataView", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
