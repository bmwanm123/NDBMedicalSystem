#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"getoridata.h"
#include"tobstring.h"
#include"tondb.h"
#include"global.h"
#include<QTcpSocket>
#include<QtNetwork>
#include<progress.h>
#define MAXFILE_NUM 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void showNdb(QList<NDB>nDBs,int length,int K);
    void showDis(QList<NDB>nDBs,int length);
   // QString orifilepath;   //原数据路径

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;

private:
    QString orifilepath;   //原数据路径
    QList<QString> str_pic_list;
    QList<QString>PictureName;
    //定义对象
    GetOriData getoridata;
    ToBString BString;
    ToNDB toNDB;
    // 拖拽窗口变量
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;

    Progress *Pro;


protected:
    QStringList allFilePath;
    QString settingParams;
    QString settingNum;
    QString FileType;

    //拖拽文件
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

    //拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void ToNDBButton_clicked();     //开始转化按钮
    void SelectFile_clicked();      //原数据选择
    void btnMenu_Close_clicked();   //程序关闭
    void btnMenu_Max_clicked();     //程序最大化
    void btnMenu_Min_clicked();     //程序最小化

    // 主菜单
    void btnMenu_setting_clicked(); //点击数据展示
    void btnMenu_change_clicked();   //点击数据输入

    // 数据转化左侧栏菜单
    void btn_dataDisplay_clicked(); //点击数据展示
    void btn_dataInput_clicked();   //点击数据输入
    void btn_dataNdb_clicked();   //点击数据输入
    void btn_saveSetting_clicked();

    void connect_slot();    //连接服务器
    void send_slot(); //发送数据
    void recv_slot();       //接收数据


};

#endif // MAINWINDOW_H
