/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *mainStack;
    QWidget *page_2;
    QPushButton *UnDir_Graph;
    QPushButton *Dir_Graph;
    QLabel *label_2;
    QLabel *label_43;
    QLabel *label;
    QWidget *page_18;
    QLabel *label_31;
    QPushButton *New_Graph;
    QPushButton *Current_Graph;
    QWidget *page_19;
    QLabel *label_32;
    QDoubleSpinBox *GSpeed;
    QPushButton *displaygraph;
    QPushButton *edge;
    QLabel *label_33;
    QPushButton *exit;
    QPushButton *sHistory;
    QLabel *label_34;
    QStackedWidget *Qstack;
    QWidget *page_20;
    QTextEdit *text_City;
    QPushButton *addTown;
    QPushButton *deleteTown;
    QLabel *label_35;
    QWidget *page;
    QLabel *label_41;
    QPushButton *startDFS;
    QTextEdit *textCityTraversal;
    QPushButton *startBFS;
    QWidget *page_21;
    QLabel *label_36;
    QTextEdit *fCityEdge;
    QTextEdit *sCityEdge;
    QPushButton *AddEdge;
    QPushButton *DeleteEdge;
    QLabel *label_37;
    QTextEdit *dEdge;
    QLabel *label_38;
    QWidget *page_22;
    QLabel *label_39;
    QLabel *label_40;
    QTextEdit *firstShort;
    QTextEdit *secondShort;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radio_Dijkstra;
    QRadioButton *radio_Bellman;
    QPushButton *startShort;
    QLabel *test_1;
    QLabel *mindistance;
    QListWidget *graphText_2;
    QPushButton *shortpath;
    QPushButton *town;
    QPushButton *traversal;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *graph_gra;
    QRadioButton *graph_text;
    QLabel *test_;
    QListWidget *log;
    QPushButton *undo;
    QListWidget *Console;
    QListWidget *theme;
    QLabel *label_42;
    QPushButton *Back;
    QPushButton *Console_btn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1226, 644);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainStack = new QStackedWidget(centralwidget);
        mainStack->setObjectName("mainStack");
        mainStack->setGeometry(QRect(-40, -10, 1271, 677));
        mainStack->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 255, 255);\n"
"background-color: rgb(255, 220, 130);"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        UnDir_Graph = new QPushButton(page_2);
        UnDir_Graph->setObjectName("UnDir_Graph");
        UnDir_Graph->setGeometry(QRect(670, 530, 241, 61));
        UnDir_Graph->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        Dir_Graph = new QPushButton(page_2);
        Dir_Graph->setObjectName("Dir_Graph");
        Dir_Graph->setGeometry(QRect(380, 530, 241, 61));
        Dir_Graph->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 460, 401, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font-size:32px;"));
        label_43 = new QLabel(page_2);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(400, 50, 631, 391));
        label_43->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/logo.png);\n"
""));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 30, 401, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font-size:32px;"));
        mainStack->addWidget(page_2);
        page_18 = new QWidget();
        page_18->setObjectName("page_18");
        label_31 = new QLabel(page_18);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(410, 50, 631, 391));
        label_31->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/logo.png);\n"
""));
        New_Graph = new QPushButton(page_18);
        New_Graph->setObjectName("New_Graph");
        New_Graph->setGeometry(QRect(450, 510, 171, 51));
        New_Graph->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 148, 33);\n"
"\n"
"\n"
"font: 700 14pt \"Terminal\";\n"
"border:1px solid rgb(255, 250, 244);\n"
"border-radius: 35px;\n"
"margin-left: 10px; border-radius: 25px; background:  rgb(38, 148, 33); color: white;\n"
"background-color: rgb(255, 170, 0);\n"
"background-color: #EC6408;\n"
"color: rgb(195, 195, 195);\n"
"color: rgb(255, 250, 244);"));
        Current_Graph = new QPushButton(page_18);
        Current_Graph->setObjectName("Current_Graph");
        Current_Graph->setGeometry(QRect(670, 510, 171, 51));
        Current_Graph->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 148, 33);\n"
"\n"
"\n"
"font: 700 14pt \"Terminal\";\n"
"border:1px solid rgb(255, 250, 244);\n"
"border-radius: 35px;\n"
"margin-left: 10px; border-radius: 25px; background:  rgb(38, 148, 33); color: white;\n"
"background-color: rgb(255, 170, 0);\n"
"background-color: #EC6408;\n"
"color: rgb(195, 195, 195);\n"
"color: rgb(255, 250, 244);"));
        mainStack->addWidget(page_18);
        page_19 = new QWidget();
        page_19->setObjectName("page_19");
        label_32 = new QLabel(page_19);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(790, 70, 61, 21));
        label_32->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));
        GSpeed = new QDoubleSpinBox(page_19);
        GSpeed->setObjectName("GSpeed");
        GSpeed->setGeometry(QRect(730, 68, 51, 31));
        GSpeed->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)\n"
""));
        GSpeed->setDecimals(5);
        GSpeed->setMinimum(-100.000000000000000);
        GSpeed->setValue(0.500000000000000);
        displaygraph = new QPushButton(page_19);
        displaygraph->setObjectName("displaygraph");
        displaygraph->setGeometry(QRect(570, 532, 191, 61));
        displaygraph->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        edge = new QPushButton(page_19);
        edge->setObjectName("edge");
        edge->setGeometry(QRect(350, 532, 201, 61));
        edge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);"));
        edge->setIconSize(QSize(20, 20));
        label_33 = new QLabel(page_19);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(610, 40, 161, 21));
        label_33->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));
        exit = new QPushButton(page_19);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(1160, 30, 81, 61));
        exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        sHistory = new QPushButton(page_19);
        sHistory->setObjectName("sHistory");
        sHistory->setGeometry(QRect(50, 42, 201, 61));
        sHistory->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);"));
        sHistory->setIconSize(QSize(20, 20));
        sHistory->setCheckable(false);
        label_34 = new QLabel(page_19);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(290, 40, 121, 21));
        label_34->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));
        Qstack = new QStackedWidget(page_19);
        Qstack->setObjectName("Qstack");
        Qstack->setGeometry(QRect(410, 142, 491, 351));
        Qstack->setFont(font);
        Qstack->setStyleSheet(QString::fromUtf8("background-color: rgb(236, 100, 8);\n"
"drawRoundedRect :(rect, 15, 15);\n"
"background-color:rgb(0, 85, 0);\n"
" border-radius: 25px;\n"
"\n"
""));
        page_20 = new QWidget();
        page_20->setObjectName("page_20");
        text_City = new QTextEdit(page_20);
        text_City->setObjectName("text_City");
        text_City->setGeometry(QRect(160, 140, 171, 41));
        text_City->setFont(font);
        text_City->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);\n"
""));
        addTown = new QPushButton(page_20);
        addTown->setObjectName("addTown");
        addTown->setGeometry(QRect(40, 220, 151, 51));
        addTown->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
""));
        deleteTown = new QPushButton(page_20);
        deleteTown->setObjectName("deleteTown");
        deleteTown->setGeometry(QRect(300, 220, 151, 51));
        deleteTown->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;"));
        label_35 = new QLabel(page_20);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(190, 70, 121, 41));
        label_35->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
"border-radius:10px;\n"
"font: 700 20pt \"Terminal\";\n"
"font: 700 18pt \"Perpetua Titling MT\";\n"
""));
        label_35->setFrameShape(QFrame::Box);
        Qstack->addWidget(page_20);
        page = new QWidget();
        page->setObjectName("page");
        label_41 = new QLabel(page);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(190, 70, 121, 41));
        label_41->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
"border-radius:10px;\n"
"font: 700 20pt \"Terminal\";\n"
"font: 700 18pt \"Perpetua Titling MT\";\n"
""));
        label_41->setFrameShape(QFrame::Box);
        startDFS = new QPushButton(page);
        startDFS->setObjectName("startDFS");
        startDFS->setGeometry(QRect(300, 220, 151, 51));
        startDFS->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;"));
        textCityTraversal = new QTextEdit(page);
        textCityTraversal->setObjectName("textCityTraversal");
        textCityTraversal->setGeometry(QRect(160, 140, 171, 41));
        textCityTraversal->setFont(font);
        textCityTraversal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);"));
        startBFS = new QPushButton(page);
        startBFS->setObjectName("startBFS");
        startBFS->setGeometry(QRect(40, 220, 151, 51));
        startBFS->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
""));
        Qstack->addWidget(page);
        page_21 = new QWidget();
        page_21->setObjectName("page_21");
        label_36 = new QLabel(page_21);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(20, 40, 161, 31));
        label_36->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
" color: rgb(255, 250, 244);\n"
"font: 700 14pt \"Perpetua Titling MT\";\n"
"\n"
""));
        fCityEdge = new QTextEdit(page_21);
        fCityEdge->setObjectName("fCityEdge");
        fCityEdge->setGeometry(QRect(210, 40, 181, 31));
        fCityEdge->setFont(font);
        fCityEdge->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);"));
        sCityEdge = new QTextEdit(page_21);
        sCityEdge->setObjectName("sCityEdge");
        sCityEdge->setGeometry(QRect(210, 90, 181, 31));
        sCityEdge->setFont(font);
        sCityEdge->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);"));
        AddEdge = new QPushButton(page_21);
        AddEdge->setObjectName("AddEdge");
        AddEdge->setGeometry(QRect(40, 220, 151, 51));
        AddEdge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;"));
        DeleteEdge = new QPushButton(page_21);
        DeleteEdge->setObjectName("DeleteEdge");
        DeleteEdge->setGeometry(QRect(280, 220, 151, 51));
        DeleteEdge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;"));
        label_37 = new QLabel(page_21);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(20, 90, 161, 31));
        label_37->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
" color: rgb(255, 250, 244);\n"
"font: 700 14pt \"Terminal\";\n"
"font: 700 12pt \"Perpetua Titling MT\";"));
        dEdge = new QTextEdit(page_21);
        dEdge->setObjectName("dEdge");
        dEdge->setGeometry(QRect(210, 140, 181, 31));
        dEdge->setFont(font);
        dEdge->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);\n"
""));
        label_38 = new QLabel(page_21);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(20, 140, 161, 31));
        label_38->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
" color: rgb(255, 250, 244);\n"
"font: 700 14pt \"Terminal\";\n"
"font: 700 12pt \"Perpetua Titling MT\";"));
        Qstack->addWidget(page_21);
        page_22 = new QWidget();
        page_22->setObjectName("page_22");
        label_39 = new QLabel(page_22);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(20, 40, 171, 31));
        label_39->setStyleSheet(QString::fromUtf8(" color: rgb(255, 250, 244);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
"font: 700 16pt \"Perpetua Titling MT\";"));
        label_40 = new QLabel(page_22);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(20, 100, 171, 31));
        label_40->setStyleSheet(QString::fromUtf8("background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
"font: 700 14pt \"Terminal\";\n"
"font: 700 14pt \"Perpetua Titling MT\";\n"
""));
        firstShort = new QTextEdit(page_22);
        firstShort->setObjectName("firstShort");
        firstShort->setGeometry(QRect(210, 40, 161, 31));
        firstShort->setFont(font);
        firstShort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);"));
        secondShort = new QTextEdit(page_22);
        secondShort->setObjectName("secondShort");
        secondShort->setGeometry(QRect(210, 100, 161, 31));
        secondShort->setFont(font);
        secondShort->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 244);\n"
"color: rgb(0, 0, 0);"));
        verticalLayoutWidget_4 = new QWidget(page_22);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(120, 150, 231, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        radio_Dijkstra = new QRadioButton(verticalLayoutWidget_4);
        radio_Dijkstra->setObjectName("radio_Dijkstra");
        radio_Dijkstra->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"font: 700 14pt \"Terminal\";\n"
"\n"
"color: rgb(255, 250, 244);"));
        radio_Dijkstra->setChecked(true);

        verticalLayout_4->addWidget(radio_Dijkstra);

        radio_Bellman = new QRadioButton(verticalLayoutWidget_4);
        radio_Bellman->setObjectName("radio_Bellman");
        radio_Bellman->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"font: 700 14pt \"Terminal\";\n"
"color: rgb(255, 250, 244);"));

        verticalLayout_4->addWidget(radio_Bellman);

        startShort = new QPushButton(page_22);
        startShort->setObjectName("startShort");
        startShort->setGeometry(QRect(160, 270, 151, 51));
        startShort->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color:  rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color: rgb(255, 250, 244);\n"
"background-color:  rgb(236, 100, 8);\n"
"color:white;\n"
""));
        test_1 = new QLabel(page_22);
        test_1->setObjectName("test_1");
        test_1->setGeometry(QRect(70, 240, 121, 16));
        test_1->setStyleSheet(QString::fromUtf8(""));
        mindistance = new QLabel(page_22);
        mindistance->setObjectName("mindistance");
        mindistance->setGeometry(QRect(230, 240, 121, 16));
        mindistance->setStyleSheet(QString::fromUtf8(""));
        graphText_2 = new QListWidget(page_22);
        graphText_2->setObjectName("graphText_2");
        graphText_2->setGeometry(QRect(280, -170, 191, 181));
        QFont font1;
        font1.setPointSize(12);
        graphText_2->setFont(font1);
        graphText_2->setStyleSheet(QString::fromUtf8(" border-radius: 25px;\n"
"background-color: rgb(255, 220, 130);\n"
"background-color: rgb(255, 220, 102);\n"
"background-color:rgb(0, 85, 0);\n"
"padding:20px;"));
        Qstack->addWidget(page_22);
        shortpath = new QPushButton(page_19);
        shortpath->setObjectName("shortpath");
        shortpath->setGeometry(QRect(780, 532, 191, 61));
        shortpath->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        town = new QPushButton(page_19);
        town->setObjectName("town");
        town->setGeometry(QRect(130, 532, 201, 61));
        town->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);"));
        town->setIconSize(QSize(20, 20));
        town->setCheckable(false);
        traversal = new QPushButton(page_19);
        traversal->setObjectName("traversal");
        traversal->setGeometry(QRect(990, 530, 191, 61));
        traversal->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        verticalLayoutWidget_5 = new QWidget(page_19);
        verticalLayoutWidget_5->setObjectName("verticalLayoutWidget_5");
        verticalLayoutWidget_5->setGeometry(QRect(340, 70, 271, 62));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        graph_gra = new QRadioButton(verticalLayoutWidget_5);
        graph_gra->setObjectName("graph_gra");
        graph_gra->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));
        graph_gra->setChecked(true);

        verticalLayout_5->addWidget(graph_gra);

        graph_text = new QRadioButton(verticalLayoutWidget_5);
        graph_text->setObjectName("graph_text");
        graph_text->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));

        verticalLayout_5->addWidget(graph_text);

        test_ = new QLabel(page_19);
        test_->setObjectName("test_");
        test_->setGeometry(QRect(650, 510, 191, 16));
        test_->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        log = new QListWidget(page_19);
        log->setObjectName("log");
        log->setGeometry(QRect(60, 130, 191, 371));
        log->setFont(font1);
        log->setStyleSheet(QString::fromUtf8(" border-radius: 25px;\n"
"background-color: rgb(255, 220, 130);\n"
"background-color: rgb(255, 220, 102);\n"
"background-color:rgb(0, 85, 0);\n"
"padding:20px;\n"
"color: rgb(255, 255, 255);"));
        undo = new QPushButton(page_19);
        undo->setObjectName("undo");
        undo->setGeometry(QRect(1050, 110, 191, 61));
        undo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        Console = new QListWidget(page_19);
        Console->setObjectName("Console");
        Console->setGeometry(QRect(940, 190, 301, 281));
        Console->setFont(font1);
        Console->setStyleSheet(QString::fromUtf8(" border-radius: 25px;\n"
"background-color: rgb(255, 220, 130);\n"
"background-color: rgb(255, 220, 102);\n"
"background-color:rgb(0, 85, 0);\n"
"padding:20px;\n"
"color: rgb(255, 255, 255);"));
        theme = new QListWidget(page_19);
        new QListWidgetItem(theme);
        new QListWidgetItem(theme);
        new QListWidgetItem(theme);
        theme->setObjectName("theme");
        theme->setGeometry(QRect(930, 70, 111, 101));
        QFont font2;
        theme->setFont(font2);
        theme->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"color: rgb(0, 0, 0);"));
        label_42 = new QLabel(page_19);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(880, 40, 71, 21));
        label_42->setStyleSheet(QString::fromUtf8("color:rgb(3, 3, 3)"));
        Back = new QPushButton(page_19);
        Back->setObjectName("Back");
        Back->setGeometry(QRect(1060, 30, 81, 61));
        Back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        Console_btn = new QPushButton(page_19);
        Console_btn->setObjectName("Console_btn");
        Console_btn->setGeometry(QRect(40, 630, 20, 20));
        Console_btn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"margin-left: 10px; border-radius: 25px;; color: white;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(236, 100, 8);\n"
"font: 700 14pt \"Terminal\";\n"
"background-color:rgb(0, 85, 0);\n"
"font-size:12px;\n"
"margin-left: 10px; border-radius: 25px;; color: white;"));
        mainStack->addWidget(page_19);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        mainStack->setCurrentIndex(1);
        Qstack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        UnDir_Graph->setText(QCoreApplication::translate("MainWindow", "UnDirected Graph", nullptr));
        Dir_Graph->setText(QCoreApplication::translate("MainWindow", "Directed Graph", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Please Choose Graph Type", nullptr));
        label_43->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Welcome To Mini-Wasalny", nullptr));
        label_31->setText(QString());
        New_Graph->setText(QCoreApplication::translate("MainWindow", "New Graph", nullptr));
        Current_Graph->setText(QCoreApplication::translate("MainWindow", "Current Graph", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "/second", nullptr));
        GSpeed->setSpecialValueText(QCoreApplication::translate("MainWindow", "0.1", nullptr));
        displaygraph->setText(QCoreApplication::translate("MainWindow", "Display Graph", nullptr));
        edge->setText(QCoreApplication::translate("MainWindow", "Edge", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Visited Nodes Speed :", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        sHistory->setText(QCoreApplication::translate("MainWindow", "Show History", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Graph Style :", nullptr));
        text_City->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Noto Sans';\"><br /></p></body></html>", nullptr));
        addTown->setText(QCoreApplication::translate("MainWindow", "Add Town", nullptr));
        deleteTown->setText(QCoreApplication::translate("MainWindow", "Delete Town", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "  Town", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "  Town", nullptr));
        startDFS->setText(QCoreApplication::translate("MainWindow", "Start DFS", nullptr));
        startBFS->setText(QCoreApplication::translate("MainWindow", "Start BFS", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "  First Town", nullptr));
        AddEdge->setText(QCoreApplication::translate("MainWindow", "Add Edge", nullptr));
        DeleteEdge->setText(QCoreApplication::translate("MainWindow", "Remove Edge", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "  Second Town", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "  DISTANCE", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "      Source", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "  Destination", nullptr));
        radio_Dijkstra->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        radio_Bellman->setText(QCoreApplication::translate("MainWindow", "Bellman Ford", nullptr));
        startShort->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        test_1->setText(QCoreApplication::translate("MainWindow", "Min Distance :", nullptr));
        mindistance->setText(QCoreApplication::translate("MainWindow", "00", nullptr));
        shortpath->setText(QCoreApplication::translate("MainWindow", "Short Path", nullptr));
        town->setText(QCoreApplication::translate("MainWindow", "Town", nullptr));
        traversal->setText(QCoreApplication::translate("MainWindow", "Traversal", nullptr));
        graph_gra->setText(QCoreApplication::translate("MainWindow", "Graphfics", nullptr));
        graph_text->setText(QCoreApplication::translate("MainWindow", "Text ", nullptr));
        test_->setText(QString());
        undo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));

        const bool __sortingEnabled = theme->isSortingEnabled();
        theme->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = theme->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Dark Blue", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = theme->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Ment Green", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = theme->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Discord", nullptr));
        theme->setSortingEnabled(__sortingEnabled);

        label_42->setText(QCoreApplication::translate("MainWindow", "Theme:", nullptr));
        Back->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        Console_btn->setText(QCoreApplication::translate("MainWindow", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
