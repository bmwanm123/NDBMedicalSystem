/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtcharts_qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *widgetTitle;
    QGridLayout *gridLayout_2;
    QWidget *widget_MainMenu;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnMenu_fy;
    QToolButton *btnMenu_rxa;
    QToolButton *btnMenu_bnz;
    QToolButton *btnMenu_xzb;
    QToolButton *btnMenu_setting;
    QSpacerItem *horizontalSpacer;
    QLabel *labIcon;
    QLabel *labTitle;
    QGridLayout *widget_BaseMenu;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QSpacerItem *verticalSpacer;
    QStackedWidget *mainStackedWidget;
    QWidget *window_rxa;
    QHBoxLayout *horizontalLayout_3;
    QWidget *rxa_leftMenu;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_rxa_init;
    QToolButton *btn_rxa_init;
    QWidget *widget_rxa_train;
    QToolButton *btn_rxa_train;
    QWidget *widget_rxa_predict;
    QVBoxLayout *verticalLayout_4;
    QToolButton *btn_rxa_predict;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *rxa_StackedWidget;
    QWidget *rxa_init;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_8;
    QWidget *rxa_init_filePath;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *rxa_FilePathEdit;
    QPushButton *rxa_SelectPathButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *rxa_init_fileRemind;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *labFileImg;
    QSpacerItem *verticalSpacer_4;
    QLabel *labFileText;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *rxa_go;
    QGroupBox *gBox_rxa_init;
    QVBoxLayout *verticalLayout_5;
    QWidget *gBox_rxa_init_widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *rxa_p1;
    QLineEdit *rxa_lineEdit_p1;
    QSpacerItem *horizontalSpacer_2;
    QLabel *rxa_p2;
    QLineEdit *rxa_lineEdit_p2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *rxa_train;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_11;
    QWidget *rxa_predict;
    QWidget *window_bnz;
    QHBoxLayout *horizontalLayout_8;
    QWidget *bnz_leftMenu;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_bnz_init;
    QVBoxLayout *verticalLayout_9;
    QToolButton *btn_bnz_init;
    QWidget *widget_bnz_train;
    QVBoxLayout *verticalLayout_10;
    QToolButton *btn_bnz_train;
    QWidget *widget_bnz_predict;
    QVBoxLayout *verticalLayout_11;
    QToolButton *btn_bnz_predict;
    QSpacerItem *verticalSpacer_8;
    QStackedWidget *bnz_StackedWidget;
    QWidget *bnz_init;
    QGridLayout *gridLayout_4;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *bnz_go;
    QWidget *bnz_init_fileRemind;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_10;
    QLabel *label_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *bnz_FilePathEdit;
    QPushButton *bnz_SelectPathButton;
    QSpacerItem *horizontalSpacer_15;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_16;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_13;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_17;
    QWidget *bnz_train;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_12;
    QWidget *bnz_predict;
    QWidget *window_xzb;
    QHBoxLayout *horizontalLayout_15;
    QWidget *xzb_leftMenu;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget_xzb_init;
    QHBoxLayout *horizontalLayout_18;
    QToolButton *btn_xzb_init;
    QWidget *widget_xzb_result;
    QHBoxLayout *horizontalLayout_17;
    QToolButton *btn_xzb_result;
    QWidget *widget_xzb_precision;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *btn_xzb_precision;
    QSpacerItem *verticalSpacer_11;
    QStackedWidget *xzb_StackedWidget;
    QWidget *xzb_init;
    QVBoxLayout *verticalLayout_15;
    QWidget *xzb_init_fileRemind;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_13;
    QLabel *label_8;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_20;
    QLineEdit *xzb_FilePathEdit;
    QPushButton *xzb_SelectPathButton;
    QSpacerItem *horizontalSpacer_21;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_22;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_17;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_21;
    QLabel *xzb_p1;
    QLineEdit *xzb_lineEdit_p1;
    QSpacerItem *horizontalSpacer_24;
    QLabel *xzb_p2;
    QLineEdit *xzb_lineEdit_p2;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_23;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *xzb_go;
    QWidget *xzb_result;
    QWidget *xzb_precision;
    QHBoxLayout *horizontalLayout_23;
    QtCharts::QChartView *xzb_graph;
    QWidget *window_fy;
    QHBoxLayout *horizontalLayout_26;
    QWidget *fy_leftMenu;
    QVBoxLayout *verticalLayout;
    QWidget *widget_fy_init;
    QVBoxLayout *verticalLayout_19;
    QToolButton *btn_fy_init;
    QWidget *widget_fy_train;
    QVBoxLayout *verticalLayout_18;
    QToolButton *btn_fy_train;
    QWidget *widget_fy_predict;
    QHBoxLayout *horizontalLayout_27;
    QToolButton *btn_fy_predict;
    QSpacerItem *verticalSpacer_14;
    QStackedWidget *fy_StackedWidget;
    QWidget *fy_init;
    QVBoxLayout *verticalLayout_20;
    QWidget *fy_init_fileRemind;
    QVBoxLayout *verticalLayout_21;
    QSpacerItem *verticalSpacer_16;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_15;
    QLabel *label_16;
    QWidget *fy_init_filePath;
    QHBoxLayout *horizontalLayout_28;
    QSpacerItem *horizontalSpacer_28;
    QLineEdit *fy_FilePathEdit;
    QPushButton *fy_SelectPathButton;
    QSpacerItem *horizontalSpacer_29;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_29;
    QSpacerItem *horizontalSpacer_30;
    QGroupBox *gBox_fy_init;
    QVBoxLayout *verticalLayout_22;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_17;
    QLineEdit *lineEdit_8;
    QSpacerItem *horizontalSpacer_32;
    QLabel *label_18;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *horizontalSpacer_31;
    QWidget *fy_init_go;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *fy_go;
    QWidget *fy_train;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_14;
    QWidget *fy_predict;
    QWidget *window_setting;
    QGridLayout *gridLayout_3;
    QGroupBox *gBox_setting;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_setting_params;
    QLineEdit *lineEdit_setting_params;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_setting_num;
    QLineEdit *lineEdit_setting_num;
    QSpacerItem *horizontalSpacer_12;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer_27;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_saveSetting;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(875, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(centralWidget);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        widgetTitle->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(widgetTitle);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_MainMenu = new QWidget(widgetTitle);
        widget_MainMenu->setObjectName(QString::fromUtf8("widget_MainMenu"));
        widget_MainMenu->setMinimumSize(QSize(40, 0));
        horizontalLayout_2 = new QHBoxLayout(widget_MainMenu);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 20);
        btnMenu_fy = new QToolButton(widget_MainMenu);
        btnMenu_fy->setObjectName(QString::fromUtf8("btnMenu_fy"));
        btnMenu_fy->setMinimumSize(QSize(80, 100));
        btnMenu_fy->setMaximumSize(QSize(80, 100));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/fy.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_fy->setIcon(icon);
        btnMenu_fy->setIconSize(QSize(25, 25));
        btnMenu_fy->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_fy);

        btnMenu_rxa = new QToolButton(widget_MainMenu);
        btnMenu_rxa->setObjectName(QString::fromUtf8("btnMenu_rxa"));
        btnMenu_rxa->setMinimumSize(QSize(80, 100));
        btnMenu_rxa->setMaximumSize(QSize(80, 16777215));
        btnMenu_rxa->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/rxa.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_rxa->setIcon(icon1);
        btnMenu_rxa->setIconSize(QSize(25, 25));
        btnMenu_rxa->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_rxa);

        btnMenu_bnz = new QToolButton(widget_MainMenu);
        btnMenu_bnz->setObjectName(QString::fromUtf8("btnMenu_bnz"));
        btnMenu_bnz->setMinimumSize(QSize(80, 100));
        btnMenu_bnz->setMaximumSize(QSize(80, 16777215));
        btnMenu_bnz->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/bnz.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_bnz->setIcon(icon2);
        btnMenu_bnz->setIconSize(QSize(25, 25));
        btnMenu_bnz->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_bnz);

        btnMenu_xzb = new QToolButton(widget_MainMenu);
        btnMenu_xzb->setObjectName(QString::fromUtf8("btnMenu_xzb"));
        btnMenu_xzb->setMinimumSize(QSize(80, 100));
        btnMenu_xzb->setMaximumSize(QSize(80, 100));
        btnMenu_xzb->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\347\255\211\347\272\277\";"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/xzb.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_xzb->setIcon(icon3);
        btnMenu_xzb->setIconSize(QSize(25, 25));
        btnMenu_xzb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_xzb);

        btnMenu_setting = new QToolButton(widget_MainMenu);
        btnMenu_setting->setObjectName(QString::fromUtf8("btnMenu_setting"));
        btnMenu_setting->setMinimumSize(QSize(80, 100));
        btnMenu_setting->setStyleSheet(QString::fromUtf8("font: 75 9.5pt \"\347\255\211\347\272\277\";\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/set.png"), QSize(), QIcon::Normal, QIcon::On);
        btnMenu_setting->setIcon(icon4);
        btnMenu_setting->setIconSize(QSize(25, 25));
        btnMenu_setting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_setting);


        gridLayout_2->addWidget(widget_MainMenu, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        labIcon = new QLabel(widgetTitle);
        labIcon->setObjectName(QString::fromUtf8("labIcon"));
        labIcon->setMinimumSize(QSize(80, 60));
        labIcon->setMaximumSize(QSize(80, 60));
        labIcon->setPixmap(QPixmap(QString::fromUtf8(":/image/md.png")));
        labIcon->setScaledContents(true);
        labIcon->setAlignment(Qt::AlignCenter);
        labIcon->setIndent(-2);

        gridLayout_2->addWidget(labIcon, 0, 0, 1, 1);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setMinimumSize(QSize(250, 0));
        labTitle->setMaximumSize(QSize(250, 16777215));
        labTitle->setMargin(10);

        gridLayout_2->addWidget(labTitle, 0, 1, 1, 1);

        widget_BaseMenu = new QGridLayout();
        widget_BaseMenu->setSpacing(6);
        widget_BaseMenu->setObjectName(QString::fromUtf8("widget_BaseMenu"));
        widget_BaseMenu->setHorizontalSpacing(0);
        widget_BaseMenu->setVerticalSpacing(7);
        btnMenu_Max = new QPushButton(widgetTitle);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        btnMenu_Max->setEnabled(true);
        btnMenu_Max->setMinimumSize(QSize(35, 35));

        widget_BaseMenu->addWidget(btnMenu_Max, 0, 1, 1, 1);

        btnMenu_Min = new QPushButton(widgetTitle);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        btnMenu_Min->setMinimumSize(QSize(35, 35));

        widget_BaseMenu->addWidget(btnMenu_Min, 0, 0, 1, 1);

        btnMenu_Close = new QPushButton(widgetTitle);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        btnMenu_Close->setMinimumSize(QSize(35, 35));

        widget_BaseMenu->addWidget(btnMenu_Close, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(134, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        widget_BaseMenu->addItem(verticalSpacer, 1, 0, 1, 3);


        gridLayout_2->addLayout(widget_BaseMenu, 0, 4, 1, 1);


        verticalLayout_6->addWidget(widgetTitle);

        mainStackedWidget = new QStackedWidget(centralWidget);
        mainStackedWidget->setObjectName(QString::fromUtf8("mainStackedWidget"));
        mainStackedWidget->setMinimumSize(QSize(0, 600));
        window_rxa = new QWidget();
        window_rxa->setObjectName(QString::fromUtf8("window_rxa"));
        horizontalLayout_3 = new QHBoxLayout(window_rxa);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        rxa_leftMenu = new QWidget(window_rxa);
        rxa_leftMenu->setObjectName(QString::fromUtf8("rxa_leftMenu"));
        rxa_leftMenu->setMinimumSize(QSize(0, 0));
        rxa_leftMenu->setMaximumSize(QSize(120, 16777215));
        verticalLayout_2 = new QVBoxLayout(rxa_leftMenu);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_rxa_init = new QWidget(rxa_leftMenu);
        widget_rxa_init->setObjectName(QString::fromUtf8("widget_rxa_init"));
        widget_rxa_init->setMinimumSize(QSize(0, 80));
        btn_rxa_init = new QToolButton(widget_rxa_init);
        btn_rxa_init->setObjectName(QString::fromUtf8("btn_rxa_init"));
        btn_rxa_init->setEnabled(true);
        btn_rxa_init->setGeometry(QRect(0, 0, 120, 80));
        btn_rxa_init->setMinimumSize(QSize(0, 80));
        btn_rxa_init->setIconSize(QSize(30, 30));
        btn_rxa_init->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(widget_rxa_init);

        widget_rxa_train = new QWidget(rxa_leftMenu);
        widget_rxa_train->setObjectName(QString::fromUtf8("widget_rxa_train"));
        widget_rxa_train->setMinimumSize(QSize(130, 80));
        btn_rxa_train = new QToolButton(widget_rxa_train);
        btn_rxa_train->setObjectName(QString::fromUtf8("btn_rxa_train"));
        btn_rxa_train->setGeometry(QRect(0, 0, 120, 80));
        btn_rxa_train->setMinimumSize(QSize(120, 80));
        btn_rxa_train->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(widget_rxa_train);

        widget_rxa_predict = new QWidget(rxa_leftMenu);
        widget_rxa_predict->setObjectName(QString::fromUtf8("widget_rxa_predict"));
        widget_rxa_predict->setMinimumSize(QSize(0, 80));
        verticalLayout_4 = new QVBoxLayout(widget_rxa_predict);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_rxa_predict = new QToolButton(widget_rxa_predict);
        btn_rxa_predict->setObjectName(QString::fromUtf8("btn_rxa_predict"));
        btn_rxa_predict->setMinimumSize(QSize(120, 80));
        btn_rxa_predict->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_4->addWidget(btn_rxa_predict);


        verticalLayout_2->addWidget(widget_rxa_predict);

        verticalSpacer_2 = new QSpacerItem(20, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(rxa_leftMenu);

        rxa_StackedWidget = new QStackedWidget(window_rxa);
        rxa_StackedWidget->setObjectName(QString::fromUtf8("rxa_StackedWidget"));
        rxa_init = new QWidget();
        rxa_init->setObjectName(QString::fromUtf8("rxa_init"));
        gridLayout = new QGridLayout(rxa_init);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 0, 1, 1);

        rxa_init_filePath = new QWidget(rxa_init);
        rxa_init_filePath->setObjectName(QString::fromUtf8("rxa_init_filePath"));
        rxa_init_filePath->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_4 = new QHBoxLayout(rxa_init_filePath);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        rxa_FilePathEdit = new QLineEdit(rxa_init_filePath);
        rxa_FilePathEdit->setObjectName(QString::fromUtf8("rxa_FilePathEdit"));
        rxa_FilePathEdit->setMinimumSize(QSize(450, 0));

        horizontalLayout_4->addWidget(rxa_FilePathEdit);

        rxa_SelectPathButton = new QPushButton(rxa_init_filePath);
        rxa_SelectPathButton->setObjectName(QString::fromUtf8("rxa_SelectPathButton"));
        rxa_SelectPathButton->setMinimumSize(QSize(20, 0));
        rxa_SelectPathButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(rxa_SelectPathButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addWidget(rxa_init_filePath, 2, 0, 1, 3);

        rxa_init_fileRemind = new QWidget(rxa_init);
        rxa_init_fileRemind->setObjectName(QString::fromUtf8("rxa_init_fileRemind"));
        rxa_init_fileRemind->setMaximumSize(QSize(16777215, 260));
        verticalLayout_3 = new QVBoxLayout(rxa_init_fileRemind);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        labFileImg = new QLabel(rxa_init_fileRemind);
        labFileImg->setObjectName(QString::fromUtf8("labFileImg"));
        labFileImg->setMinimumSize(QSize(0, 0));
        labFileImg->setMaximumSize(QSize(16777215, 240));
        labFileImg->setPixmap(QPixmap(QString::fromUtf8(":/img/empty.png")));
        labFileImg->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labFileImg);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        labFileText = new QLabel(rxa_init_fileRemind);
        labFileText->setObjectName(QString::fromUtf8("labFileText"));
        labFileText->setMaximumSize(QSize(2000, 20));
        labFileText->setMidLineWidth(-3);
        labFileText->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labFileText);


        gridLayout->addWidget(rxa_init_fileRemind, 1, 0, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 2, 1, 1);

        widget_2 = new QWidget(rxa_init);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 20);
        rxa_go = new QPushButton(widget_2);
        rxa_go->setObjectName(QString::fromUtf8("rxa_go"));
        rxa_go->setMaximumSize(QSize(100, 16777215));
        rxa_go->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(rxa_go);


        gridLayout->addWidget(widget_2, 4, 1, 1, 1);

        gBox_rxa_init = new QGroupBox(rxa_init);
        gBox_rxa_init->setObjectName(QString::fromUtf8("gBox_rxa_init"));
        gBox_rxa_init->setMaximumSize(QSize(600, 150));
        gBox_rxa_init->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_5 = new QVBoxLayout(gBox_rxa_init);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gBox_rxa_init_widget = new QWidget(gBox_rxa_init);
        gBox_rxa_init_widget->setObjectName(QString::fromUtf8("gBox_rxa_init_widget"));
        horizontalLayout_5 = new QHBoxLayout(gBox_rxa_init_widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        rxa_p1 = new QLabel(gBox_rxa_init_widget);
        rxa_p1->setObjectName(QString::fromUtf8("rxa_p1"));

        horizontalLayout_5->addWidget(rxa_p1);

        rxa_lineEdit_p1 = new QLineEdit(gBox_rxa_init_widget);
        rxa_lineEdit_p1->setObjectName(QString::fromUtf8("rxa_lineEdit_p1"));

        horizontalLayout_5->addWidget(rxa_lineEdit_p1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        rxa_p2 = new QLabel(gBox_rxa_init_widget);
        rxa_p2->setObjectName(QString::fromUtf8("rxa_p2"));

        horizontalLayout_5->addWidget(rxa_p2);

        rxa_lineEdit_p2 = new QLineEdit(gBox_rxa_init_widget);
        rxa_lineEdit_p2->setObjectName(QString::fromUtf8("rxa_lineEdit_p2"));

        horizontalLayout_5->addWidget(rxa_lineEdit_p2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_5->addWidget(gBox_rxa_init_widget);


        gridLayout->addWidget(gBox_rxa_init, 3, 1, 1, 1);

        rxa_StackedWidget->addWidget(rxa_init);
        rxa_train = new QWidget();
        rxa_train->setObjectName(QString::fromUtf8("rxa_train"));
        horizontalLayout_25 = new QHBoxLayout(rxa_train);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_11 = new QLabel(rxa_train);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/rxa_result")));
        label_11->setScaledContents(true);

        horizontalLayout_25->addWidget(label_11);

        rxa_StackedWidget->addWidget(rxa_train);
        rxa_predict = new QWidget();
        rxa_predict->setObjectName(QString::fromUtf8("rxa_predict"));
        rxa_StackedWidget->addWidget(rxa_predict);

        horizontalLayout_3->addWidget(rxa_StackedWidget);

        mainStackedWidget->addWidget(window_rxa);
        window_bnz = new QWidget();
        window_bnz->setObjectName(QString::fromUtf8("window_bnz"));
        horizontalLayout_8 = new QHBoxLayout(window_bnz);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        bnz_leftMenu = new QWidget(window_bnz);
        bnz_leftMenu->setObjectName(QString::fromUtf8("bnz_leftMenu"));
        bnz_leftMenu->setMinimumSize(QSize(120, 0));
        verticalLayout_8 = new QVBoxLayout(bnz_leftMenu);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_bnz_init = new QWidget(bnz_leftMenu);
        widget_bnz_init->setObjectName(QString::fromUtf8("widget_bnz_init"));
        verticalLayout_9 = new QVBoxLayout(widget_bnz_init);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        btn_bnz_init = new QToolButton(widget_bnz_init);
        btn_bnz_init->setObjectName(QString::fromUtf8("btn_bnz_init"));
        btn_bnz_init->setMinimumSize(QSize(120, 80));
        btn_bnz_init->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_9->addWidget(btn_bnz_init);


        verticalLayout_8->addWidget(widget_bnz_init);

        widget_bnz_train = new QWidget(bnz_leftMenu);
        widget_bnz_train->setObjectName(QString::fromUtf8("widget_bnz_train"));
        verticalLayout_10 = new QVBoxLayout(widget_bnz_train);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        btn_bnz_train = new QToolButton(widget_bnz_train);
        btn_bnz_train->setObjectName(QString::fromUtf8("btn_bnz_train"));
        btn_bnz_train->setMinimumSize(QSize(120, 80));
        btn_bnz_train->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_10->addWidget(btn_bnz_train);


        verticalLayout_8->addWidget(widget_bnz_train);

        widget_bnz_predict = new QWidget(bnz_leftMenu);
        widget_bnz_predict->setObjectName(QString::fromUtf8("widget_bnz_predict"));
        widget_bnz_predict->setMinimumSize(QSize(120, 0));
        verticalLayout_11 = new QVBoxLayout(widget_bnz_predict);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        btn_bnz_predict = new QToolButton(widget_bnz_predict);
        btn_bnz_predict->setObjectName(QString::fromUtf8("btn_bnz_predict"));
        btn_bnz_predict->setMinimumSize(QSize(120, 80));
        btn_bnz_predict->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_11->addWidget(btn_bnz_predict);


        verticalLayout_8->addWidget(widget_bnz_predict);

        verticalSpacer_8 = new QSpacerItem(20, 357, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_8);


        horizontalLayout_8->addWidget(bnz_leftMenu);

        bnz_StackedWidget = new QStackedWidget(window_bnz);
        bnz_StackedWidget->setObjectName(QString::fromUtf8("bnz_StackedWidget"));
        bnz_init = new QWidget();
        bnz_init->setObjectName(QString::fromUtf8("bnz_init"));
        gridLayout_4 = new QGridLayout(bnz_init);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(bnz_init);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 60));
        widget_7->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_12 = new QHBoxLayout(widget_7);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        bnz_go = new QPushButton(widget_7);
        bnz_go->setObjectName(QString::fromUtf8("bnz_go"));
        bnz_go->setMinimumSize(QSize(100, 0));
        bnz_go->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_12->addWidget(bnz_go);


        gridLayout_4->addWidget(widget_7, 3, 0, 1, 1);

        bnz_init_fileRemind = new QWidget(bnz_init);
        bnz_init_fileRemind->setObjectName(QString::fromUtf8("bnz_init_fileRemind"));
        bnz_init_fileRemind->setMinimumSize(QSize(0, 260));
        bnz_init_fileRemind->setMaximumSize(QSize(16777215, 260));
        verticalLayout_12 = new QVBoxLayout(bnz_init_fileRemind);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_9);

        label_3 = new QLabel(bnz_init_fileRemind);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 200));
        label_3->setMaximumSize(QSize(16777215, 200));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/empty.png")));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_3);

        verticalSpacer_10 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_10);

        label_4 = new QLabel(bnz_init_fileRemind);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 15));
        label_4->setMaximumSize(QSize(16777215, 15));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_4);


        gridLayout_4->addWidget(bnz_init_fileRemind, 0, 0, 1, 1);

        widget_6 = new QWidget(bnz_init);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 60));
        widget_6->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_14 = new QSpacerItem(82, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_14);

        bnz_FilePathEdit = new QLineEdit(widget_6);
        bnz_FilePathEdit->setObjectName(QString::fromUtf8("bnz_FilePathEdit"));
        bnz_FilePathEdit->setMinimumSize(QSize(450, 0));
        bnz_FilePathEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_10->addWidget(bnz_FilePathEdit);

        bnz_SelectPathButton = new QPushButton(widget_6);
        bnz_SelectPathButton->setObjectName(QString::fromUtf8("bnz_SelectPathButton"));

        horizontalLayout_10->addWidget(bnz_SelectPathButton);

        horizontalSpacer_15 = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);


        gridLayout_4->addWidget(widget_6, 1, 0, 1, 1);

        widget = new QWidget(bnz_init);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 150));
        widget->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(600, 150));
        groupBox->setMaximumSize(QSize(600, 150));
        horizontalLayout_13 = new QHBoxLayout(groupBox);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        widget_8 = new QWidget(groupBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_14 = new QHBoxLayout(widget_8);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_14->addWidget(label_5);

        lineEdit_3 = new QLineEdit(widget_8);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_14->addWidget(lineEdit_3);

        horizontalSpacer_18 = new QSpacerItem(26, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_18);

        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_14->addWidget(label_6);

        lineEdit_4 = new QLineEdit(widget_8);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_14->addWidget(lineEdit_4);

        horizontalSpacer_19 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_19);


        horizontalLayout_13->addWidget(widget_8);


        horizontalLayout_11->addWidget(groupBox);

        horizontalSpacer_17 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_17);


        gridLayout_4->addWidget(widget, 2, 0, 1, 1);

        bnz_StackedWidget->addWidget(bnz_init);
        bnz_train = new QWidget();
        bnz_train->setObjectName(QString::fromUtf8("bnz_train"));
        verticalLayout_13 = new QVBoxLayout(bnz_train);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_12 = new QLabel(bnz_train);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/image/accloss.jpg")));
        label_12->setScaledContents(true);

        verticalLayout_13->addWidget(label_12);

        bnz_StackedWidget->addWidget(bnz_train);
        bnz_predict = new QWidget();
        bnz_predict->setObjectName(QString::fromUtf8("bnz_predict"));
        bnz_StackedWidget->addWidget(bnz_predict);

        horizontalLayout_8->addWidget(bnz_StackedWidget);

        mainStackedWidget->addWidget(window_bnz);
        window_xzb = new QWidget();
        window_xzb->setObjectName(QString::fromUtf8("window_xzb"));
        horizontalLayout_15 = new QHBoxLayout(window_xzb);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        xzb_leftMenu = new QWidget(window_xzb);
        xzb_leftMenu->setObjectName(QString::fromUtf8("xzb_leftMenu"));
        xzb_leftMenu->setMinimumSize(QSize(120, 0));
        verticalLayout_14 = new QVBoxLayout(xzb_leftMenu);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        widget_xzb_init = new QWidget(xzb_leftMenu);
        widget_xzb_init->setObjectName(QString::fromUtf8("widget_xzb_init"));
        horizontalLayout_18 = new QHBoxLayout(widget_xzb_init);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        btn_xzb_init = new QToolButton(widget_xzb_init);
        btn_xzb_init->setObjectName(QString::fromUtf8("btn_xzb_init"));
        btn_xzb_init->setMinimumSize(QSize(120, 80));
        btn_xzb_init->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_18->addWidget(btn_xzb_init);


        verticalLayout_14->addWidget(widget_xzb_init);

        widget_xzb_result = new QWidget(xzb_leftMenu);
        widget_xzb_result->setObjectName(QString::fromUtf8("widget_xzb_result"));
        horizontalLayout_17 = new QHBoxLayout(widget_xzb_result);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        btn_xzb_result = new QToolButton(widget_xzb_result);
        btn_xzb_result->setObjectName(QString::fromUtf8("btn_xzb_result"));
        btn_xzb_result->setMinimumSize(QSize(120, 80));
        btn_xzb_result->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_17->addWidget(btn_xzb_result);


        verticalLayout_14->addWidget(widget_xzb_result);

        widget_xzb_precision = new QWidget(xzb_leftMenu);
        widget_xzb_precision->setObjectName(QString::fromUtf8("widget_xzb_precision"));
        horizontalLayout_16 = new QHBoxLayout(widget_xzb_precision);
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        btn_xzb_precision = new QToolButton(widget_xzb_precision);
        btn_xzb_precision->setObjectName(QString::fromUtf8("btn_xzb_precision"));
        btn_xzb_precision->setMinimumSize(QSize(120, 80));
        btn_xzb_precision->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_16->addWidget(btn_xzb_precision);


        verticalLayout_14->addWidget(widget_xzb_precision);

        verticalSpacer_11 = new QSpacerItem(20, 357, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_14->addItem(verticalSpacer_11);


        horizontalLayout_15->addWidget(xzb_leftMenu);

        xzb_StackedWidget = new QStackedWidget(window_xzb);
        xzb_StackedWidget->setObjectName(QString::fromUtf8("xzb_StackedWidget"));
        xzb_init = new QWidget();
        xzb_init->setObjectName(QString::fromUtf8("xzb_init"));
        verticalLayout_15 = new QVBoxLayout(xzb_init);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        xzb_init_fileRemind = new QWidget(xzb_init);
        xzb_init_fileRemind->setObjectName(QString::fromUtf8("xzb_init_fileRemind"));
        xzb_init_fileRemind->setMinimumSize(QSize(0, 260));
        xzb_init_fileRemind->setMaximumSize(QSize(16777215, 260));
        verticalLayout_16 = new QVBoxLayout(xzb_init_fileRemind);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_12 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_12);

        label_7 = new QLabel(xzb_init_fileRemind);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 200));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/img/empty.png")));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_7);

        verticalSpacer_13 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_13);

        label_8 = new QLabel(xzb_init_fileRemind);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_8);


        verticalLayout_15->addWidget(xzb_init_fileRemind);

        widget_13 = new QWidget(xzb_init);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        widget_13->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_19 = new QHBoxLayout(widget_13);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_20 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_20);

        xzb_FilePathEdit = new QLineEdit(widget_13);
        xzb_FilePathEdit->setObjectName(QString::fromUtf8("xzb_FilePathEdit"));
        xzb_FilePathEdit->setMinimumSize(QSize(450, 0));

        horizontalLayout_19->addWidget(xzb_FilePathEdit);

        xzb_SelectPathButton = new QPushButton(widget_13);
        xzb_SelectPathButton->setObjectName(QString::fromUtf8("xzb_SelectPathButton"));

        horizontalLayout_19->addWidget(xzb_SelectPathButton);

        horizontalSpacer_21 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_21);


        verticalLayout_15->addWidget(widget_13);

        widget_14 = new QWidget(xzb_init);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        widget_14->setMinimumSize(QSize(0, 150));
        widget_14->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_20 = new QHBoxLayout(widget_14);
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_22 = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_22);

        groupBox_2 = new QGroupBox(widget_14);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(600, 150));
        groupBox_2->setMaximumSize(QSize(600, 150));
        verticalLayout_17 = new QVBoxLayout(groupBox_2);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        widget_12 = new QWidget(groupBox_2);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_21 = new QHBoxLayout(widget_12);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        xzb_p1 = new QLabel(widget_12);
        xzb_p1->setObjectName(QString::fromUtf8("xzb_p1"));

        horizontalLayout_21->addWidget(xzb_p1);

        xzb_lineEdit_p1 = new QLineEdit(widget_12);
        xzb_lineEdit_p1->setObjectName(QString::fromUtf8("xzb_lineEdit_p1"));

        horizontalLayout_21->addWidget(xzb_lineEdit_p1);

        horizontalSpacer_24 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_24);

        xzb_p2 = new QLabel(widget_12);
        xzb_p2->setObjectName(QString::fromUtf8("xzb_p2"));

        horizontalLayout_21->addWidget(xzb_p2);

        xzb_lineEdit_p2 = new QLineEdit(widget_12);
        xzb_lineEdit_p2->setObjectName(QString::fromUtf8("xzb_lineEdit_p2"));

        horizontalLayout_21->addWidget(xzb_lineEdit_p2);

        horizontalSpacer_25 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_25);


        verticalLayout_17->addWidget(widget_12);


        horizontalLayout_20->addWidget(groupBox_2);

        horizontalSpacer_23 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_23);


        verticalLayout_15->addWidget(widget_14);

        widget_15 = new QWidget(xzb_init);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        widget_15->setMinimumSize(QSize(0, 60));
        widget_15->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_22 = new QHBoxLayout(widget_15);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        xzb_go = new QPushButton(widget_15);
        xzb_go->setObjectName(QString::fromUtf8("xzb_go"));
        xzb_go->setMinimumSize(QSize(100, 0));
        xzb_go->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_22->addWidget(xzb_go);


        verticalLayout_15->addWidget(widget_15);

        xzb_StackedWidget->addWidget(xzb_init);
        xzb_result = new QWidget();
        xzb_result->setObjectName(QString::fromUtf8("xzb_result"));
        xzb_StackedWidget->addWidget(xzb_result);
        xzb_precision = new QWidget();
        xzb_precision->setObjectName(QString::fromUtf8("xzb_precision"));
        horizontalLayout_23 = new QHBoxLayout(xzb_precision);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        xzb_graph = new QtCharts::QChartView(xzb_precision);
        xzb_graph->setObjectName(QString::fromUtf8("xzb_graph"));

        horizontalLayout_23->addWidget(xzb_graph);

        xzb_StackedWidget->addWidget(xzb_precision);

        horizontalLayout_15->addWidget(xzb_StackedWidget);

        mainStackedWidget->addWidget(window_xzb);
        window_fy = new QWidget();
        window_fy->setObjectName(QString::fromUtf8("window_fy"));
        horizontalLayout_26 = new QHBoxLayout(window_fy);
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalLayout_26->setContentsMargins(0, 0, 0, 0);
        fy_leftMenu = new QWidget(window_fy);
        fy_leftMenu->setObjectName(QString::fromUtf8("fy_leftMenu"));
        fy_leftMenu->setMinimumSize(QSize(120, 600));
        verticalLayout = new QVBoxLayout(fy_leftMenu);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_fy_init = new QWidget(fy_leftMenu);
        widget_fy_init->setObjectName(QString::fromUtf8("widget_fy_init"));
        widget_fy_init->setMinimumSize(QSize(120, 80));
        verticalLayout_19 = new QVBoxLayout(widget_fy_init);
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        btn_fy_init = new QToolButton(widget_fy_init);
        btn_fy_init->setObjectName(QString::fromUtf8("btn_fy_init"));
        btn_fy_init->setMinimumSize(QSize(120, 80));
        btn_fy_init->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_19->addWidget(btn_fy_init);


        verticalLayout->addWidget(widget_fy_init);

        widget_fy_train = new QWidget(fy_leftMenu);
        widget_fy_train->setObjectName(QString::fromUtf8("widget_fy_train"));
        widget_fy_train->setMinimumSize(QSize(120, 80));
        verticalLayout_18 = new QVBoxLayout(widget_fy_train);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        btn_fy_train = new QToolButton(widget_fy_train);
        btn_fy_train->setObjectName(QString::fromUtf8("btn_fy_train"));
        btn_fy_train->setMinimumSize(QSize(120, 80));
        btn_fy_train->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_18->addWidget(btn_fy_train);


        verticalLayout->addWidget(widget_fy_train);

        widget_fy_predict = new QWidget(fy_leftMenu);
        widget_fy_predict->setObjectName(QString::fromUtf8("widget_fy_predict"));
        widget_fy_predict->setMinimumSize(QSize(120, 80));
        horizontalLayout_27 = new QHBoxLayout(widget_fy_predict);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        btn_fy_predict = new QToolButton(widget_fy_predict);
        btn_fy_predict->setObjectName(QString::fromUtf8("btn_fy_predict"));
        btn_fy_predict->setMinimumSize(QSize(120, 80));
        btn_fy_predict->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_27->addWidget(btn_fy_predict);


        verticalLayout->addWidget(widget_fy_predict);

        verticalSpacer_14 = new QSpacerItem(20, 357, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_14);


        horizontalLayout_26->addWidget(fy_leftMenu);

        fy_StackedWidget = new QStackedWidget(window_fy);
        fy_StackedWidget->setObjectName(QString::fromUtf8("fy_StackedWidget"));
        fy_init = new QWidget();
        fy_init->setObjectName(QString::fromUtf8("fy_init"));
        verticalLayout_20 = new QVBoxLayout(fy_init);
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        fy_init_fileRemind = new QWidget(fy_init);
        fy_init_fileRemind->setObjectName(QString::fromUtf8("fy_init_fileRemind"));
        fy_init_fileRemind->setMinimumSize(QSize(0, 260));
        fy_init_fileRemind->setMaximumSize(QSize(16777215, 260));
        verticalLayout_21 = new QVBoxLayout(fy_init_fileRemind);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_16 = new QSpacerItem(20, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_16);

        label_13 = new QLabel(fy_init_fileRemind);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/img/empty.png")));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_13);

        verticalSpacer_15 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_15);

        label_16 = new QLabel(fy_init_fileRemind);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_21->addWidget(label_16);


        verticalLayout_20->addWidget(fy_init_fileRemind);

        fy_init_filePath = new QWidget(fy_init);
        fy_init_filePath->setObjectName(QString::fromUtf8("fy_init_filePath"));
        fy_init_filePath->setMinimumSize(QSize(0, 60));
        fy_init_filePath->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_28 = new QHBoxLayout(fy_init_filePath);
        horizontalLayout_28->setSpacing(7);
        horizontalLayout_28->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_28 = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_28);

        fy_FilePathEdit = new QLineEdit(fy_init_filePath);
        fy_FilePathEdit->setObjectName(QString::fromUtf8("fy_FilePathEdit"));
        fy_FilePathEdit->setMinimumSize(QSize(450, 0));
        fy_FilePathEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_28->addWidget(fy_FilePathEdit);

        fy_SelectPathButton = new QPushButton(fy_init_filePath);
        fy_SelectPathButton->setObjectName(QString::fromUtf8("fy_SelectPathButton"));

        horizontalLayout_28->addWidget(fy_SelectPathButton);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_29);


        verticalLayout_20->addWidget(fy_init_filePath);

        widget_10 = new QWidget(fy_init);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setMinimumSize(QSize(0, 150));
        widget_10->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_29 = new QHBoxLayout(widget_10);
        horizontalLayout_29->setSpacing(0);
        horizontalLayout_29->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_29->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_30 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_30);

        gBox_fy_init = new QGroupBox(widget_10);
        gBox_fy_init->setObjectName(QString::fromUtf8("gBox_fy_init"));
        gBox_fy_init->setMinimumSize(QSize(600, 150));
        gBox_fy_init->setMaximumSize(QSize(600, 150));
        verticalLayout_22 = new QVBoxLayout(gBox_fy_init);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        widget_11 = new QWidget(gBox_fy_init);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_30 = new QHBoxLayout(widget_11);
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        label_17 = new QLabel(widget_11);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_30->addWidget(label_17);

        lineEdit_8 = new QLineEdit(widget_11);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_30->addWidget(lineEdit_8);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_32);

        label_18 = new QLabel(widget_11);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_30->addWidget(label_18);

        lineEdit_9 = new QLineEdit(widget_11);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_30->addWidget(lineEdit_9);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_33);


        verticalLayout_22->addWidget(widget_11);


        horizontalLayout_29->addWidget(gBox_fy_init);

        horizontalSpacer_31 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_31);


        verticalLayout_20->addWidget(widget_10);

        fy_init_go = new QWidget(fy_init);
        fy_init_go->setObjectName(QString::fromUtf8("fy_init_go"));
        fy_init_go->setMinimumSize(QSize(0, 60));
        fy_init_go->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_31 = new QHBoxLayout(fy_init_go);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        fy_go = new QPushButton(fy_init_go);
        fy_go->setObjectName(QString::fromUtf8("fy_go"));
        fy_go->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_31->addWidget(fy_go);


        verticalLayout_20->addWidget(fy_init_go);

        fy_StackedWidget->addWidget(fy_init);
        fy_train = new QWidget();
        fy_train->setObjectName(QString::fromUtf8("fy_train"));
        horizontalLayout_32 = new QHBoxLayout(fy_train);
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        label_14 = new QLabel(fy_train);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix2/image/duibi3.jpg")));
        label_14->setScaledContents(true);

        horizontalLayout_32->addWidget(label_14);

        fy_StackedWidget->addWidget(fy_train);
        fy_predict = new QWidget();
        fy_predict->setObjectName(QString::fromUtf8("fy_predict"));
        fy_StackedWidget->addWidget(fy_predict);

        horizontalLayout_26->addWidget(fy_StackedWidget);

        mainStackedWidget->addWidget(window_fy);
        window_setting = new QWidget();
        window_setting->setObjectName(QString::fromUtf8("window_setting"));
        gridLayout_3 = new QGridLayout(window_setting);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gBox_setting = new QGroupBox(window_setting);
        gBox_setting->setObjectName(QString::fromUtf8("gBox_setting"));
        gBox_setting->setMinimumSize(QSize(600, 300));
        gBox_setting->setMaximumSize(QSize(16777215, 300));
        gBox_setting->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_7 = new QVBoxLayout(gBox_setting);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_5 = new QWidget(gBox_setting);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        lineEdit = new QLineEdit(widget_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_7->addWidget(lineEdit_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);


        verticalLayout_7->addWidget(widget_5);

        widget_4 = new QWidget(gBox_setting);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_setting_params = new QLabel(widget_4);
        label_setting_params->setObjectName(QString::fromUtf8("label_setting_params"));

        horizontalLayout_6->addWidget(label_setting_params);

        lineEdit_setting_params = new QLineEdit(widget_4);
        lineEdit_setting_params->setObjectName(QString::fromUtf8("lineEdit_setting_params"));

        horizontalLayout_6->addWidget(lineEdit_setting_params);

        horizontalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        label_setting_num = new QLabel(widget_4);
        label_setting_num->setObjectName(QString::fromUtf8("label_setting_num"));

        horizontalLayout_6->addWidget(label_setting_num);

        lineEdit_setting_num = new QLineEdit(widget_4);
        lineEdit_setting_num->setObjectName(QString::fromUtf8("lineEdit_setting_num"));

        horizontalLayout_6->addWidget(lineEdit_setting_num);

        horizontalSpacer_12 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);


        verticalLayout_7->addWidget(widget_4);

        widget_9 = new QWidget(gBox_setting);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_24 = new QHBoxLayout(widget_9);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_9 = new QLabel(widget_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_24->addWidget(label_9);

        lineEdit_5 = new QLineEdit(widget_9);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_24->addWidget(lineEdit_5);

        horizontalSpacer_26 = new QSpacerItem(55, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_26);

        label_10 = new QLabel(widget_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_24->addWidget(label_10);

        lineEdit_6 = new QLineEdit(widget_9);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_24->addWidget(lineEdit_6);

        horizontalSpacer_27 = new QSpacerItem(55, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_27);


        verticalLayout_7->addWidget(widget_9);


        gridLayout_3->addWidget(gBox_setting, 1, 1, 1, 1);

        widget_3 = new QWidget(window_setting);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_9 = new QHBoxLayout(widget_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btn_saveSetting = new QPushButton(widget_3);
        btn_saveSetting->setObjectName(QString::fromUtf8("btn_saveSetting"));
        btn_saveSetting->setMaximumSize(QSize(100, 30));

        horizontalLayout_9->addWidget(btn_saveSetting);


        gridLayout_3->addWidget(widget_3, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 4, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 1, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 1, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_7, 0, 1, 1, 1);

        mainStackedWidget->addWidget(window_setting);

        verticalLayout_6->addWidget(mainStackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        mainStackedWidget->setCurrentIndex(3);
        fy_StackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnMenu_fy->setText(QApplication::translate("MainWindow", "\346\226\260\345\206\240\350\257\212\346\226\255", nullptr));
        btnMenu_rxa->setText(QApplication::translate("MainWindow", "\344\271\263\350\205\272\347\231\214\350\257\212\346\226\255", nullptr));
        btnMenu_bnz->setText(QApplication::translate("MainWindow", "\347\234\274\347\226\276\350\257\212\346\226\255", nullptr));
        btnMenu_xzb->setText(QApplication::translate("MainWindow", "\345\277\203\350\204\217\347\227\205\350\257\212\346\226\255", nullptr));
        btnMenu_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        labIcon->setText(QString());
        labTitle->setText(QApplication::translate("MainWindow", "\345\214\273\347\226\227\350\257\212\346\226\255\347\263\273\347\273\237", nullptr));
        btnMenu_Max->setText(QString());
        btnMenu_Min->setText(QString());
        btnMenu_Close->setText(QString());
        btn_rxa_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        btn_rxa_train->setText(QApplication::translate("MainWindow", "\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        btn_rxa_predict->setText(QApplication::translate("MainWindow", "\351\242\204\346\265\213\347\273\223\346\236\234", nullptr));
        rxa_SelectPathButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        labFileImg->setText(QString());
        labFileText->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201 .jpg;.png \346\240\274\345\274\217\347\232\204\346\226\207\344\273\266(\345\217\257\346\213\226\346\213\275)", nullptr));
        rxa_go->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\212\346\226\255", nullptr));
        gBox_rxa_init->setTitle(QApplication::translate("MainWindow", "\344\271\263\350\205\272\347\231\214\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        rxa_p1->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        rxa_lineEdit_p1->setText(QApplication::translate("MainWindow", "300", nullptr));
        rxa_p2->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\345\215\240\346\257\224:", nullptr));
        rxa_lineEdit_p2->setText(QApplication::translate("MainWindow", "0.2", nullptr));
        label_11->setText(QString());
        btn_bnz_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        btn_bnz_train->setText(QApplication::translate("MainWindow", "\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        btn_bnz_predict->setText(QApplication::translate("MainWindow", "\351\242\204\346\265\213\347\273\223\346\236\234", nullptr));
        bnz_go->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\212\346\226\255", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201 .jpg;.png \346\240\274\345\274\217\347\232\204\346\226\207\344\273\266(\345\217\257\346\213\226\346\213\275)", nullptr));
        bnz_SelectPathButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\231\275\345\206\205\351\232\234\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260:", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "300", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\345\215\240\346\257\224:", nullptr));
        lineEdit_4->setText(QApplication::translate("MainWindow", "0.2", nullptr));
        label_12->setText(QString());
        btn_xzb_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        btn_xzb_result->setText(QApplication::translate("MainWindow", "\345\210\206\347\261\273\347\273\223\346\236\234", nullptr));
        btn_xzb_precision->setText(QApplication::translate("MainWindow", "\345\210\206\347\261\273\347\262\276\345\272\246", nullptr));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201 .txt;.csv \346\240\274\345\274\217\347\232\204\346\226\207\344\273\266(\345\217\257\346\213\226\346\213\275)", nullptr));
        xzb_SelectPathButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\277\203\350\204\217\347\227\205\345\217\202\346\225\260", nullptr));
        xzb_p1->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\345\215\240\346\257\224:", nullptr));
        xzb_lineEdit_p1->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        xzb_p2->setText(QApplication::translate("MainWindow", "K\345\200\274:", nullptr));
        xzb_lineEdit_p2->setText(QApplication::translate("MainWindow", "9", nullptr));
        xzb_go->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\210\206\347\261\273", nullptr));
        btn_fy_init->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        btn_fy_train->setText(QApplication::translate("MainWindow", "\350\256\255\347\273\203\347\273\223\346\236\234", nullptr));
        btn_fy_predict->setText(QApplication::translate("MainWindow", "\351\242\204\346\265\213\347\273\223\346\236\234", nullptr));
        label_13->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201 .jpg;.png \346\240\274\345\274\217\347\232\204\346\226\207\344\273\266(\345\217\257\346\213\226\346\213\275)", nullptr));
        fy_SelectPathButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        gBox_fy_init->setTitle(QApplication::translate("MainWindow", "\346\226\260\345\206\240\350\202\272\347\202\216\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
        lineEdit_8->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\345\255\246\344\271\240\347\216\207\357\274\232", nullptr));
        lineEdit_9->setText(QApplication::translate("MainWindow", "0.0001", nullptr));
        fy_go->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\257\212\346\226\255", nullptr));
        label_14->setText(QString());
        gBox_setting->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "batch_size:", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "16", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\210\206\347\261\273\344\270\252\346\225\260:", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "2", nullptr));
        label_setting_params->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\225\260\346\215\256\345\215\240\346\257\224:", nullptr));
        lineEdit_setting_params->setText(QApplication::translate("MainWindow", "0.25", nullptr));
        label_setting_num->setText(QApplication::translate("MainWindow", "K:", nullptr));
        lineEdit_setting_num->setText(QApplication::translate("MainWindow", "7", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\344\274\230\345\214\226\345\231\250\357\274\232", nullptr));
        lineEdit_5->setText(QApplication::translate("MainWindow", "SGD", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\255\246\344\271\240\347\216\207\357\274\232", nullptr));
        lineEdit_6->setText(QApplication::translate("MainWindow", "0.001", nullptr));
        btn_saveSetting->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
