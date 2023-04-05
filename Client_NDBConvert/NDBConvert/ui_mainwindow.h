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

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QGridLayout *gridLayout_2;
    QLabel *labTitle;
    QLabel *labIcon;
    QSpacerItem *horizontalSpacer;
    QGridLayout *widget_BaseMenu;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QSpacerItem *verticalSpacer;
    QWidget *widget_MainMenu;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnMenu_change;
    QToolButton *btnMenu_setting;
    QStackedWidget *mainStackedWidget;
    QWidget *dataChange_window;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftMenu;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_dataInputBorder;
    QToolButton *btn_dataInput;
    QWidget *widget_dataNdbBorder;
    QToolButton *btn_dataNdb;
    QWidget *widget_dataDisplayBorder;
    QVBoxLayout *verticalLayout_4;
    QToolButton *btn_dataDisplay;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *changeStackedWidget;
    QWidget *dataInput;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *FilePathEdit;
    QPushButton *SelectPathButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widgetFileRemind;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *labFileImg;
    QSpacerItem *verticalSpacer_4;
    QLabel *labFileText;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ToNDBButton;
    QGroupBox *gBox_input;
    QVBoxLayout *verticalLayout_5;
    QWidget *gBox_input_widget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_p1;
    QLineEdit *lineEdit_p1;
    QLabel *label_p2;
    QLineEdit *lineEdit_p2;
    QLabel *label_p3;
    QLineEdit *lineEdit_p3;
    QLabel *label_p4;
    QLineEdit *lineEdit_p4;
    QWidget *gBox_input_widget2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_q0;
    QLineEdit *lineEdit_q0;
    QLabel *label_q1;
    QLineEdit *lineEdit_q1;
    QLabel *label_q2;
    QLineEdit *lineEdit_q2;
    QLabel *label_q3;
    QLineEdit *lineEdit_q3;
    QWidget *gBox_input_widget3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_q4;
    QLineEdit *lineEdit_q4;
    QLabel *label_q5;
    QLineEdit *lineEdit_q5;
    QLabel *label_q6;
    QLineEdit *lineEdit_q6;
    QLabel *label_q7;
    QLineEdit *lineEdit_q7;
    QWidget *dataDisplay;
    QWidget *dataNdb;
    QWidget *setting_window;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_saveSetting;
    QGroupBox *gBox_setting;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_setting_params;
    QLineEdit *lineEdit_setting_params;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_setting_num;
    QLineEdit *lineEdit_setting_num;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(875, 700);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(centralWidget);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        widgetTitle->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(widgetTitle);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setMinimumSize(QSize(400, 0));

        gridLayout_2->addWidget(labTitle, 0, 1, 1, 1);

        labIcon = new QLabel(widgetTitle);
        labIcon->setObjectName(QString::fromUtf8("labIcon"));
        labIcon->setMinimumSize(QSize(80, 60));
        labIcon->setMaximumSize(QSize(80, 60));
        labIcon->setPixmap(QPixmap(QString::fromUtf8(":/image/4.png")));
        labIcon->setScaledContents(true);
        labIcon->setAlignment(Qt::AlignCenter);
        labIcon->setIndent(-2);

        gridLayout_2->addWidget(labIcon, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

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

        widget_MainMenu = new QWidget(widgetTitle);
        widget_MainMenu->setObjectName(QString::fromUtf8("widget_MainMenu"));
        widget_MainMenu->setMinimumSize(QSize(40, 0));
        horizontalLayout_2 = new QHBoxLayout(widget_MainMenu);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu_change = new QToolButton(widget_MainMenu);
        btnMenu_change->setObjectName(QString::fromUtf8("btnMenu_change"));
        btnMenu_change->setMinimumSize(QSize(80, 100));
        btnMenu_change->setMaximumSize(QSize(80, 16777215));
        btnMenu_change->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMenu_change->setIcon(icon);
        btnMenu_change->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_change);

        btnMenu_setting = new QToolButton(widget_MainMenu);
        btnMenu_setting->setObjectName(QString::fromUtf8("btnMenu_setting"));
        btnMenu_setting->setMinimumSize(QSize(80, 100));
        btnMenu_setting->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\347\255\211\347\272\277\";\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/set.png"), QSize(), QIcon::Normal, QIcon::On);
        btnMenu_setting->setIcon(icon1);
        btnMenu_setting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(btnMenu_setting);


        gridLayout_2->addWidget(widget_MainMenu, 0, 3, 1, 1);


        verticalLayout->addWidget(widgetTitle);

        mainStackedWidget = new QStackedWidget(centralWidget);
        mainStackedWidget->setObjectName(QString::fromUtf8("mainStackedWidget"));
        mainStackedWidget->setMinimumSize(QSize(0, 600));
        dataChange_window = new QWidget();
        dataChange_window->setObjectName(QString::fromUtf8("dataChange_window"));
        horizontalLayout_3 = new QHBoxLayout(dataChange_window);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        leftMenu = new QWidget(dataChange_window);
        leftMenu->setObjectName(QString::fromUtf8("leftMenu"));
        leftMenu->setMinimumSize(QSize(0, 0));
        leftMenu->setMaximumSize(QSize(120, 16777215));
        verticalLayout_2 = new QVBoxLayout(leftMenu);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_dataInputBorder = new QWidget(leftMenu);
        widget_dataInputBorder->setObjectName(QString::fromUtf8("widget_dataInputBorder"));
        widget_dataInputBorder->setMinimumSize(QSize(0, 80));
        btn_dataInput = new QToolButton(widget_dataInputBorder);
        btn_dataInput->setObjectName(QString::fromUtf8("btn_dataInput"));
        btn_dataInput->setEnabled(true);
        btn_dataInput->setGeometry(QRect(0, 0, 120, 80));
        btn_dataInput->setMinimumSize(QSize(0, 80));
        btn_dataInput->setIconSize(QSize(30, 30));
        btn_dataInput->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(widget_dataInputBorder);

        widget_dataNdbBorder = new QWidget(leftMenu);
        widget_dataNdbBorder->setObjectName(QString::fromUtf8("widget_dataNdbBorder"));
        widget_dataNdbBorder->setMinimumSize(QSize(130, 80));
        btn_dataNdb = new QToolButton(widget_dataNdbBorder);
        btn_dataNdb->setObjectName(QString::fromUtf8("btn_dataNdb"));
        btn_dataNdb->setGeometry(QRect(0, 0, 120, 80));
        btn_dataNdb->setMinimumSize(QSize(120, 80));
        btn_dataNdb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(widget_dataNdbBorder);

        widget_dataDisplayBorder = new QWidget(leftMenu);
        widget_dataDisplayBorder->setObjectName(QString::fromUtf8("widget_dataDisplayBorder"));
        widget_dataDisplayBorder->setMinimumSize(QSize(0, 80));
        verticalLayout_4 = new QVBoxLayout(widget_dataDisplayBorder);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        btn_dataDisplay = new QToolButton(widget_dataDisplayBorder);
        btn_dataDisplay->setObjectName(QString::fromUtf8("btn_dataDisplay"));
        btn_dataDisplay->setMinimumSize(QSize(120, 80));
        btn_dataDisplay->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_4->addWidget(btn_dataDisplay);


        verticalLayout_2->addWidget(widget_dataDisplayBorder);

        verticalSpacer_2 = new QSpacerItem(20, 300, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(leftMenu);

        changeStackedWidget = new QStackedWidget(dataChange_window);
        changeStackedWidget->setObjectName(QString::fromUtf8("changeStackedWidget"));
        dataInput = new QWidget();
        dataInput->setObjectName(QString::fromUtf8("dataInput"));
        gridLayout = new QGridLayout(dataInput);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 0, 1, 1);

        widget = new QWidget(dataInput);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        FilePathEdit = new QLineEdit(widget);
        FilePathEdit->setObjectName(QString::fromUtf8("FilePathEdit"));
        FilePathEdit->setMinimumSize(QSize(450, 0));

        horizontalLayout_4->addWidget(FilePathEdit);

        SelectPathButton = new QPushButton(widget);
        SelectPathButton->setObjectName(QString::fromUtf8("SelectPathButton"));
        SelectPathButton->setMinimumSize(QSize(20, 0));
        SelectPathButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(SelectPathButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addWidget(widget, 2, 0, 1, 3);

        widgetFileRemind = new QWidget(dataInput);
        widgetFileRemind->setObjectName(QString::fromUtf8("widgetFileRemind"));
        widgetFileRemind->setMaximumSize(QSize(16777215, 260));
        verticalLayout_3 = new QVBoxLayout(widgetFileRemind);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        labFileImg = new QLabel(widgetFileRemind);
        labFileImg->setObjectName(QString::fromUtf8("labFileImg"));
        labFileImg->setMinimumSize(QSize(0, 0));
        labFileImg->setMaximumSize(QSize(16777215, 240));
        labFileImg->setPixmap(QPixmap(QString::fromUtf8(":/img/empty.png")));
        labFileImg->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labFileImg);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        labFileText = new QLabel(widgetFileRemind);
        labFileText->setObjectName(QString::fromUtf8("labFileText"));
        labFileText->setMaximumSize(QSize(2000, 20));
        labFileText->setMidLineWidth(-3);
        labFileText->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labFileText);


        gridLayout->addWidget(widgetFileRemind, 1, 0, 1, 3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 2, 1, 1);

        widget_2 = new QWidget(dataInput);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 60));
        widget_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ToNDBButton = new QPushButton(widget_2);
        ToNDBButton->setObjectName(QString::fromUtf8("ToNDBButton"));
        ToNDBButton->setMaximumSize(QSize(100, 16777215));
        ToNDBButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(ToNDBButton);


        gridLayout->addWidget(widget_2, 4, 1, 1, 1);

        gBox_input = new QGroupBox(dataInput);
        gBox_input->setObjectName(QString::fromUtf8("gBox_input"));
        gBox_input->setMaximumSize(QSize(600, 200));
        gBox_input->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_5 = new QVBoxLayout(gBox_input);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gBox_input_widget1 = new QWidget(gBox_input);
        gBox_input_widget1->setObjectName(QString::fromUtf8("gBox_input_widget1"));
        horizontalLayout_5 = new QHBoxLayout(gBox_input_widget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_p1 = new QLabel(gBox_input_widget1);
        label_p1->setObjectName(QString::fromUtf8("label_p1"));

        horizontalLayout_5->addWidget(label_p1);

        lineEdit_p1 = new QLineEdit(gBox_input_widget1);
        lineEdit_p1->setObjectName(QString::fromUtf8("lineEdit_p1"));

        horizontalLayout_5->addWidget(lineEdit_p1);

        label_p2 = new QLabel(gBox_input_widget1);
        label_p2->setObjectName(QString::fromUtf8("label_p2"));

        horizontalLayout_5->addWidget(label_p2);

        lineEdit_p2 = new QLineEdit(gBox_input_widget1);
        lineEdit_p2->setObjectName(QString::fromUtf8("lineEdit_p2"));

        horizontalLayout_5->addWidget(lineEdit_p2);

        label_p3 = new QLabel(gBox_input_widget1);
        label_p3->setObjectName(QString::fromUtf8("label_p3"));

        horizontalLayout_5->addWidget(label_p3);

        lineEdit_p3 = new QLineEdit(gBox_input_widget1);
        lineEdit_p3->setObjectName(QString::fromUtf8("lineEdit_p3"));

        horizontalLayout_5->addWidget(lineEdit_p3);

        label_p4 = new QLabel(gBox_input_widget1);
        label_p4->setObjectName(QString::fromUtf8("label_p4"));

        horizontalLayout_5->addWidget(label_p4);

        lineEdit_p4 = new QLineEdit(gBox_input_widget1);
        lineEdit_p4->setObjectName(QString::fromUtf8("lineEdit_p4"));

        horizontalLayout_5->addWidget(lineEdit_p4);


        verticalLayout_5->addWidget(gBox_input_widget1);

        gBox_input_widget2 = new QWidget(gBox_input);
        gBox_input_widget2->setObjectName(QString::fromUtf8("gBox_input_widget2"));
        horizontalLayout_6 = new QHBoxLayout(gBox_input_widget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_q0 = new QLabel(gBox_input_widget2);
        label_q0->setObjectName(QString::fromUtf8("label_q0"));

        horizontalLayout_6->addWidget(label_q0);

        lineEdit_q0 = new QLineEdit(gBox_input_widget2);
        lineEdit_q0->setObjectName(QString::fromUtf8("lineEdit_q0"));

        horizontalLayout_6->addWidget(lineEdit_q0);

        label_q1 = new QLabel(gBox_input_widget2);
        label_q1->setObjectName(QString::fromUtf8("label_q1"));

        horizontalLayout_6->addWidget(label_q1);

        lineEdit_q1 = new QLineEdit(gBox_input_widget2);
        lineEdit_q1->setObjectName(QString::fromUtf8("lineEdit_q1"));

        horizontalLayout_6->addWidget(lineEdit_q1);

        label_q2 = new QLabel(gBox_input_widget2);
        label_q2->setObjectName(QString::fromUtf8("label_q2"));

        horizontalLayout_6->addWidget(label_q2);

        lineEdit_q2 = new QLineEdit(gBox_input_widget2);
        lineEdit_q2->setObjectName(QString::fromUtf8("lineEdit_q2"));

        horizontalLayout_6->addWidget(lineEdit_q2);

        label_q3 = new QLabel(gBox_input_widget2);
        label_q3->setObjectName(QString::fromUtf8("label_q3"));

        horizontalLayout_6->addWidget(label_q3);

        lineEdit_q3 = new QLineEdit(gBox_input_widget2);
        lineEdit_q3->setObjectName(QString::fromUtf8("lineEdit_q3"));

        horizontalLayout_6->addWidget(lineEdit_q3);


        verticalLayout_5->addWidget(gBox_input_widget2);

        gBox_input_widget3 = new QWidget(gBox_input);
        gBox_input_widget3->setObjectName(QString::fromUtf8("gBox_input_widget3"));
        horizontalLayout_7 = new QHBoxLayout(gBox_input_widget3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_q4 = new QLabel(gBox_input_widget3);
        label_q4->setObjectName(QString::fromUtf8("label_q4"));

        horizontalLayout_7->addWidget(label_q4);

        lineEdit_q4 = new QLineEdit(gBox_input_widget3);
        lineEdit_q4->setObjectName(QString::fromUtf8("lineEdit_q4"));

        horizontalLayout_7->addWidget(lineEdit_q4);

        label_q5 = new QLabel(gBox_input_widget3);
        label_q5->setObjectName(QString::fromUtf8("label_q5"));

        horizontalLayout_7->addWidget(label_q5);

        lineEdit_q5 = new QLineEdit(gBox_input_widget3);
        lineEdit_q5->setObjectName(QString::fromUtf8("lineEdit_q5"));

        horizontalLayout_7->addWidget(lineEdit_q5);

        label_q6 = new QLabel(gBox_input_widget3);
        label_q6->setObjectName(QString::fromUtf8("label_q6"));

        horizontalLayout_7->addWidget(label_q6);

        lineEdit_q6 = new QLineEdit(gBox_input_widget3);
        lineEdit_q6->setObjectName(QString::fromUtf8("lineEdit_q6"));

        horizontalLayout_7->addWidget(lineEdit_q6);

        label_q7 = new QLabel(gBox_input_widget3);
        label_q7->setObjectName(QString::fromUtf8("label_q7"));

        horizontalLayout_7->addWidget(label_q7);

        lineEdit_q7 = new QLineEdit(gBox_input_widget3);
        lineEdit_q7->setObjectName(QString::fromUtf8("lineEdit_q7"));

        horizontalLayout_7->addWidget(lineEdit_q7);


        verticalLayout_5->addWidget(gBox_input_widget3);


        gridLayout->addWidget(gBox_input, 3, 1, 1, 1);

        changeStackedWidget->addWidget(dataInput);
        dataDisplay = new QWidget();
        dataDisplay->setObjectName(QString::fromUtf8("dataDisplay"));
        changeStackedWidget->addWidget(dataDisplay);
        dataNdb = new QWidget();
        dataNdb->setObjectName(QString::fromUtf8("dataNdb"));
        changeStackedWidget->addWidget(dataNdb);

        horizontalLayout_3->addWidget(changeStackedWidget);

        mainStackedWidget->addWidget(dataChange_window);
        setting_window = new QWidget();
        setting_window->setObjectName(QString::fromUtf8("setting_window"));
        gridLayout_3 = new QGridLayout(setting_window);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 0, 2, 1, 1);

        widget_3 = new QWidget(setting_window);
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


        gridLayout_3->addWidget(widget_3, 2, 1, 1, 1);

        gBox_setting = new QGroupBox(setting_window);
        gBox_setting->setObjectName(QString::fromUtf8("gBox_setting"));
        gBox_setting->setMinimumSize(QSize(600, 400));
        gBox_setting->setMaximumSize(QSize(16777215, 300));
        gBox_setting->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_8 = new QHBoxLayout(gBox_setting);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_setting_params = new QLabel(gBox_setting);
        label_setting_params->setObjectName(QString::fromUtf8("label_setting_params"));

        horizontalLayout_8->addWidget(label_setting_params);

        lineEdit_setting_params = new QLineEdit(gBox_setting);
        lineEdit_setting_params->setObjectName(QString::fromUtf8("lineEdit_setting_params"));

        horizontalLayout_8->addWidget(lineEdit_setting_params);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        label_setting_num = new QLabel(gBox_setting);
        label_setting_num->setObjectName(QString::fromUtf8("label_setting_num"));

        horizontalLayout_8->addWidget(label_setting_num);

        lineEdit_setting_num = new QLineEdit(gBox_setting);
        lineEdit_setting_num->setObjectName(QString::fromUtf8("lineEdit_setting_num"));

        horizontalLayout_8->addWidget(lineEdit_setting_num);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        gridLayout_3->addWidget(gBox_setting, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 1, 1, 1, 1);

        mainStackedWidget->addWidget(setting_window);

        verticalLayout->addWidget(mainStackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        mainStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labTitle->setText(QApplication::translate("MainWindow", "\351\232\220\347\247\201\344\277\235\346\212\244\350\264\237\346\225\260\346\215\256\345\272\223\347\263\273\347\273\237", nullptr));
        labIcon->setText(QString());
        btnMenu_Max->setText(QString());
        btnMenu_Min->setText(QString());
        btnMenu_Close->setText(QString());
        btnMenu_change->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\275\254\345\214\226", nullptr));
        btnMenu_setting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        btn_dataInput->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\350\276\223\345\205\245", nullptr));
        btn_dataNdb->setText(QApplication::translate("MainWindow", "\350\264\237\346\225\260\346\215\256\345\272\223", nullptr));
        btn_dataDisplay->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\216\213\347\274\251", nullptr));
        SelectPathButton->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        labFileImg->setText(QString());
        labFileText->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201 .png;.jpg;.txt;.csv \346\240\274\345\274\217\347\232\204\346\226\207\344\273\266(\345\217\257\346\213\226\346\213\275)", nullptr));
        ToNDBButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\350\275\254\346\215\242", nullptr));
        gBox_input->setTitle(QApplication::translate("MainWindow", "\347\241\256\345\256\232\344\275\215\345\217\226\345\217\215\346\246\202\347\216\207\350\256\276\347\275\256", nullptr));
        label_p1->setText(QApplication::translate("MainWindow", "p1:", nullptr));
        lineEdit_p1->setText(QApplication::translate("MainWindow", "0.9", nullptr));
        label_p2->setText(QApplication::translate("MainWindow", "p2:", nullptr));
        lineEdit_p2->setText(QApplication::translate("MainWindow", "0.02", nullptr));
        label_p3->setText(QApplication::translate("MainWindow", "p3:", nullptr));
        lineEdit_p3->setText(QApplication::translate("MainWindow", "0.03", nullptr));
        label_p4->setText(QApplication::translate("MainWindow", "p4:", nullptr));
        lineEdit_p4->setText(QApplication::translate("MainWindow", "0.05", nullptr));
        label_q0->setText(QApplication::translate("MainWindow", "q0:", nullptr));
        lineEdit_q0->setText(QApplication::translate("MainWindow", "0.05", nullptr));
        label_q1->setText(QApplication::translate("MainWindow", "q1:", nullptr));
        lineEdit_q1->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q2->setText(QApplication::translate("MainWindow", "q2:", nullptr));
        lineEdit_q2->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q3->setText(QApplication::translate("MainWindow", "q3:", nullptr));
        lineEdit_q3->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q4->setText(QApplication::translate("MainWindow", "q4:", nullptr));
        lineEdit_q4->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q5->setText(QApplication::translate("MainWindow", "q5:", nullptr));
        lineEdit_q5->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q6->setText(QApplication::translate("MainWindow", "q6:", nullptr));
        lineEdit_q6->setText(QApplication::translate("MainWindow", "0.1", nullptr));
        label_q7->setText(QApplication::translate("MainWindow", "q7:", nullptr));
        lineEdit_q7->setText(QApplication::translate("MainWindow", "0.35", nullptr));
        btn_saveSetting->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        gBox_setting->setTitle(QApplication::translate("MainWindow", "\350\264\237\346\225\260\346\215\256\345\272\223\350\275\254\345\214\226\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_setting_params->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\216\247\345\210\266\345\217\202\346\225\260:", nullptr));
        lineEdit_setting_params->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_setting_num->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232\344\275\215\344\270\252\346\225\260:", nullptr));
        lineEdit_setting_num->setText(QApplication::translate("MainWindow", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
