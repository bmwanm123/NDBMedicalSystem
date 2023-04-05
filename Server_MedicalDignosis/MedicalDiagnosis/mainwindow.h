#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include<QHBoxLayout>

#include"getoridata.h"
#include"tobstring.h"
#include"tondb.h"
#include"heart_knn.h"



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

   // QString orifilepath;   //原数据路径

private:
    Ui::MainWindow *ui;

private:
    QString orifilepath;   //原数据路径
    //定义对象
    GetOriData getoridata;
    ToBString BString;
    ToNDB toNDB;
    // 拖拽窗口变量
    bool m_bDrag;
    QPoint mouseStartPoint;
    QPoint windowTopLeftPoint;

    HEART_KNN Knn;   //knn算法对象

    //存储所选文件路径
    QList<QString> xzb_str_list;
    QString xzb_NDBPath;

    QString ResultPath;
    QString bnzResultPath;
    ResultData resdata;


protected:
    QStringList allFilePath;
    QString settingParams;
    QString settingNum;



    void rxa_showTrain();
    void rxa_showPredict(QString resultpath);     //乳腺癌诊断结果
    void bnz_showTrain();
    void bnz_showPredict(QString resultpath);
    void xzb_showResult(map<string, vector<int>> result);
//    void xzb_showPrecision();
    void xzb_knn();

    void fy_showTrain();
    void fy_showPredict(QString resultpath);


    //拖拽文件
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

    //拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    // 选择文件与开始转化
    void rxa_go_clicked();     
    void rxa_SelectFile_clicked();      
    void bnz_go_clicked();     
    void bnz_SelectFile_clicked();      
    void xzb_go_clicked();     
    void xzb_SelectFile_clicked();
    void fy_go_clicked();
    void fy_SelectFile_clicked();


    void btnMenu_Close_clicked();   //程序关闭
    void btnMenu_Max_clicked();     //程序最大化
    void btnMenu_Min_clicked();     //程序最小化

    // 主菜单
    void btnMenu_setting_clicked(); //点击数据展示
    void btnMenu_fy_clicked();      //点击肺炎
    void btnMenu_rxa_clicked();   //点击乳腺癌
    void btnMenu_bnz_clicked();   //点击白内障
    void btnMenu_xzb_clicked();   //点击心脏病

    // 数据转化左侧栏菜单
    void rxa_init_clicked();
    void rxa_train_clicked();
    void rxa_predict_clicked();
    void xzb_showPrecision();

    void bnz_init_clicked();
    void bnz_train_clicked();
    void bnz_predict_clicked();

    void xzb_init_clicked();
    void xzb_result_clicked();
    void xzb_precision_clicked();

    void fy_init_clicked();
    void fy_train_clicked();
    void fy_predict_clicked();



    void btn_saveSetting_clicked();


};

#endif // MAINWINDOW_H
