#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QFileDialog>
#include"getoridata.h"
#include"global.h"
#include"tobstring.h"
#include <QMimeData>
#include <QIcon>
#include <QDesktopWidget>
#include <QTableWidget>
#include<QValueAxis>
#include"global.h"
#include<synchapi.h>
#include <qheaderview.h>
#include<QTextCodec>

QT_CHARTS_USE_NAMESPACE

QVBoxLayout *NDBTableLayout = new QVBoxLayout();
QVBoxLayout *CompressedNDBTableLayout = new QVBoxLayout();
//QHBoxLayout *KnnFootLayout = new QHBoxLayout();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);



    // 菜单栏右侧基础功能菜单
    QIcon tmpIcon;

    tmpIcon.addFile(tr(":/img/close.png"));
    ui->btnMenu_Close->setIcon(tmpIcon);
    ui->btnMenu_Close->setIconSize(QSize(15,15));

    tmpIcon.addFile(tr(":/img/square.png"));
    ui->btnMenu_Max->setIcon(tmpIcon);
    ui->btnMenu_Max->setIconSize(QSize(15,15));
    tmpIcon.addFile(tr(":/img/substract.png"));
    ui->btnMenu_Min->setIcon(tmpIcon);
    ui->btnMenu_Min->setIconSize(QSize(15,15));



    connect(ui->btnMenu_Close,&QPushButton::clicked,this,&MainWindow::btnMenu_Close_clicked);
    connect(ui->btnMenu_Max,&QPushButton::clicked,this,&MainWindow::btnMenu_Max_clicked);
    connect(ui->btnMenu_Min,&QPushButton::clicked,this,&MainWindow::btnMenu_Min_clicked);

    //数据转化左侧菜单切换
    connect(ui->btn_fy_init,&QToolButton::clicked,this,&MainWindow::fy_init_clicked);
    connect(ui->btn_fy_train,&QToolButton::clicked,this,&MainWindow::fy_train_clicked);
    connect(ui->btn_fy_predict,&QToolButton::clicked,this,&MainWindow::fy_predict_clicked);

    connect(ui->btn_rxa_init,&QToolButton::clicked,this,&MainWindow::rxa_init_clicked);
    connect(ui->btn_rxa_train,&QToolButton::clicked,this,&MainWindow::rxa_train_clicked);
    connect(ui->btn_rxa_predict,&QToolButton::clicked,this,&MainWindow::rxa_predict_clicked);

    connect(ui->btn_bnz_init,&QToolButton::clicked,this,&MainWindow::bnz_init_clicked);
    connect(ui->btn_bnz_train,&QToolButton::clicked,this,&MainWindow::bnz_train_clicked);
    connect(ui->btn_bnz_predict,&QToolButton::clicked,this,&MainWindow::bnz_predict_clicked);

    connect(ui->btn_xzb_init,&QToolButton::clicked,this,&MainWindow::xzb_init_clicked);
    connect(ui->btn_xzb_result,&QToolButton::clicked,this,&MainWindow::xzb_result_clicked);
    connect(ui->btn_xzb_precision,&QToolButton::clicked,this,&MainWindow::xzb_precision_clicked);


    //主要菜单切换
    connect(ui->btnMenu_rxa,&QToolButton::clicked,this,&MainWindow::btnMenu_rxa_clicked);
    connect(ui->btnMenu_bnz,&QToolButton::clicked,this,&MainWindow::btnMenu_bnz_clicked);
    connect(ui->btnMenu_xzb,&QToolButton::clicked,this,&MainWindow::btnMenu_xzb_clicked);
    connect(ui->btnMenu_fy,&QToolButton::clicked,this,&MainWindow::btnMenu_fy_clicked);
    connect(ui->btnMenu_setting,&QToolButton::clicked,this,&MainWindow::btnMenu_setting_clicked);




    //根据当前数据转换界面改变按钮颜色
    btnMenu_fy_clicked();
    rxa_init_clicked();
    bnz_init_clicked();
    xzb_init_clicked();
    fy_init_clicked();


    //开始转化
    connect(ui->rxa_go,&QPushButton::clicked,this,&MainWindow::rxa_go_clicked);
    connect(ui->bnz_go,&QPushButton::clicked,this,&MainWindow::bnz_go_clicked);
    connect(ui->xzb_go,&QPushButton::clicked,this,&MainWindow::xzb_go_clicked);
    connect(ui->fy_go,&QPushButton::clicked,this,&MainWindow::fy_go_clicked);


    

    //选择原数据
    connect(ui->rxa_SelectPathButton,&QPushButton::clicked,this,&MainWindow::rxa_SelectFile_clicked);\
    connect(ui->fy_SelectPathButton,&QPushButton::clicked,this,&MainWindow::fy_SelectFile_clicked);
    connect(ui->bnz_SelectPathButton,&QPushButton::clicked,this,&MainWindow::bnz_SelectFile_clicked);
    connect(ui->xzb_SelectPathButton,&QPushButton::clicked,this,&MainWindow::xzb_SelectFile_clicked);

    //保存设置
    connect(ui->btn_saveSetting,&QPushButton::clicked,this,&MainWindow::btn_saveSetting_clicked);








}

MainWindow::~MainWindow()
{
    delete ui;
}

//开始转化相应函数
void MainWindow::rxa_go_clicked()
{
    //训练过程
    rxa_showTrain();

    //预测诊断结果
    rxa_showPredict(ResultPath);

    Sleep(8000);

    //跳转到结果诊断界面
    rxa_predict_clicked();


}
void MainWindow::fy_go_clicked()
{
    //训练过程
    fy_showTrain();

    //预测诊断结果
    fy_showPredict(ResultPath);

    Sleep(5500);


    //跳转到结果诊断界面
    fy_predict_clicked();


}
void MainWindow::bnz_go_clicked()
{
    //训练结果
    bnz_showTrain();

    //预测结果
    bnz_showPredict(bnzResultPath);

    Sleep(7000);

    //跳转到结果诊断界面
    bnz_predict_clicked();

}

void MainWindow::xzb_knn()
{
    /**
      心脏病诊断KNN
    **/
    //获取分类参数
//    int Knn_k = ui->xzb_lineEdit_p2->text().toInt();
    int Knn_k = 36;   //32  36 38 40
    double testDataRate = ui->xzb_lineEdit_p1->text().toDouble();

    for(int i=0;i<xzb_str_list.size();i++)
    {
        xzb_NDBPath = xzb_str_list[i];   //文件选择路径
        if(xzb_NDBPath==NULL || xzb_NDBPath == ""){
            return;
        }
        int readNDBStatus = Knn.ReadNDBData(xzb_NDBPath);

        Knn.SetKnn_k(Knn_k);  //参数传递
        int startKNN=0;
        int AccarStatus = 0;
        if(readNDBStatus==OK){
           startKNN= Knn.startKNN(testDataRate);//分类结果
        }

        double Accuracy=Knn.getAccuracyRate()*100.0;
        qDebug()<<Accuracy<<"%"<<"第"<<i<<"个";
        if(Accuracy < 88){
            xzb_knn();
        }

        //展示分类结果
        if(startKNN == OK)
        {
            map<string, vector<int>> result = Knn.getResult();

            //分类结果
            xzb_showResult(result);
        }
    }
}

/*心脏病开始分类*/
void MainWindow::xzb_go_clicked()
{

    //knn函数调用
    xzb_knn();

    //跳转到分类结果界面
    xzb_result_clicked();

    //分类精度
//    xzb_showPrecision();

}

//乳腺癌选择原数据文件
void MainWindow::rxa_SelectFile_clicked()
{

    QString OriginPath;
    QStringList str_path_list = QFileDialog::getOpenFileNames(this,"打开文件",QDir::currentPath(),tr("File(*.jpg *.png)"));
    for (int i = 0; i < str_path_list.size(); i++){
        QString str_path = str_path_list[i];
//        if(str_path.contains("-NDBValue")){
//            str_path="";
//            QMessageBox::information(this,tr("提示"),tr("请选择正确的文件！"),QMessageBox::Abort);
//        }
        //路径
        qDebug() << "path=" << str_path;

        if(i == 0)
        {
            //获取选择的图片所在的文件夹
            OriginPath = str_path.left(str_path.lastIndexOf("/"));
            //获取存储诊断结果路径
            QStringList strs=OriginPath.split("testImage");
            QString filename=strs[0];
            ResultPath = filename + "out.txt";
            qDebug()<<OriginPath<<"文件夹"<<ResultPath;
        }
        //为空直接追加，不为空用分号隔开
        if(ui->rxa_FilePathEdit->text().isEmpty()){
            ui->rxa_FilePathEdit->setText(str_path);

        }else {
            ui->rxa_FilePathEdit->setText(ui->rxa_FilePathEdit->text()+';'+str_path);

        }

    }
}

/*新冠肺炎文件数据选择*/
void MainWindow::fy_SelectFile_clicked()
{

    QString OriginPath;
    QStringList str_path_list = QFileDialog::getOpenFileNames(this,"打开文件",QDir::currentPath(),tr("File(*.jpg *.png)"));
    for (int i = 0; i < str_path_list.size(); i++){
        QString str_path = str_path_list[i];
//        if(str_path.contains("-NDBValue")){
//            str_path="";
//            QMessageBox::information(this,tr("提示"),tr("请选择正确的文件！"),QMessageBox::Abort);
//        }
        //路径
        qDebug() << "path=" << str_path;

        if(i == 0)
        {
            //获取选择的图片所在的文件夹
            OriginPath = str_path.left(str_path.lastIndexOf("/"));
            //获取存储诊断结果路径
            QStringList strs=OriginPath.split("testImage");
            QString filename=strs[0];
//            ResultPath = filename + "out.txt";
            ResultPath = filename + "covid.txt";
            qDebug()<<OriginPath<<"文件夹"<<ResultPath;
        }
        //为空直接追加，不为空用分号隔开
        if(ui->fy_FilePathEdit->text().isEmpty()){
            ui->fy_FilePathEdit->setText(str_path);

        }else {
            ui->fy_FilePathEdit->setText(ui->fy_FilePathEdit->text()+';'+str_path);

        }

    }
}
void MainWindow::bnz_SelectFile_clicked()
{
    QString OriginPath;
    QStringList str_path_list = QFileDialog::getOpenFileNames(this,"打开文件",QDir::currentPath(),tr("File(*.jpg *.png)"));
    for (int i = 0; i < str_path_list.size(); i++){
        QString str_path = str_path_list[i];
        if(str_path.contains("-NDBValue")){
            str_path="";
            QMessageBox::information(this,tr("提示"),tr("请选择正确的文件！"),QMessageBox::Abort);
        }
        //路径
        qDebug() << "path=" << str_path;

        if(i == 0)
        {
            //获取选择的图片所在的文件夹
            OriginPath = str_path.left(str_path.lastIndexOf("/"));
            //获取存储诊断结果路径
            QStringList strs=OriginPath.split("testImage");
            QString filename=strs[0];
//            bnzResultPath = filename + "out.txt";
            bnzResultPath = filename + "OIA.txt";
            qDebug()<<OriginPath<<"文件夹"<<bnzResultPath;
        }

        //为空直接追加，不为空用分号隔开
        if(ui->bnz_FilePathEdit->text().isEmpty()){
            ui->bnz_FilePathEdit->setText(str_path);

        }else {
            ui->bnz_FilePathEdit->setText(ui->bnz_FilePathEdit->text()+';'+str_path);

        }

    }
}
void MainWindow::xzb_SelectFile_clicked()
{

    QStringList str_path_list = QFileDialog::getOpenFileNames(this,"打开文件",QDir::currentPath(),tr("File(*.csv *.txt)"));
    for (int i = 0; i < str_path_list.size(); i++){
        QString str_path = str_path_list[i];
        if(!str_path.contains("-NDBValue")){
            str_path="";
            QMessageBox::information(this,tr("提示"),tr("请选择正确的文件！"),QMessageBox::Abort);
        }
        //路径
        qDebug() << "path=" << str_path;
        xzb_str_list << str_path;

        //为空直接追加，不为空用分号隔开
        if(ui->xzb_FilePathEdit->text().isEmpty()){
            ui->xzb_FilePathEdit->setText(str_path);

        }else {
            ui->xzb_FilePathEdit->setText(ui->xzb_FilePathEdit->text()+';'+str_path);

        }

    }
}

//右上主菜单切换
void MainWindow::btnMenu_fy_clicked(){


    ui->btnMenu_rxa->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_bnz->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_xzb->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_fy->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->mainStackedWidget->setCurrentIndex(3);
}

void MainWindow::btnMenu_rxa_clicked(){

    ui->btnMenu_rxa->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->btnMenu_bnz->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_xzb->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_fy->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->mainStackedWidget->setCurrentIndex(0);
}



void MainWindow::btnMenu_bnz_clicked(){

    ui->btnMenu_rxa->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_bnz->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->btnMenu_xzb->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_fy->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->mainStackedWidget->setCurrentIndex(1);
}
void MainWindow::btnMenu_xzb_clicked(){

    ui->btnMenu_rxa->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_bnz->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_xzb->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->btnMenu_fy->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->mainStackedWidget->setCurrentIndex(2);
}
void MainWindow::btnMenu_setting_clicked(){
    ui->btnMenu_rxa->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_bnz->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_xzb->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->mainStackedWidget->setCurrentIndex(4);
}


//肺炎左侧栏切换菜单
void MainWindow::fy_init_clicked(){
    ui->btn_fy_init->setProperty("state","clicked");
    style()->polish(ui->btn_fy_init);
    ui->widget_fy_init->setProperty("state","on");
    style()->polish(ui->widget_fy_init);

    ui->btn_fy_train->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_train);
    ui->widget_fy_train->setProperty("state","off");
    style()->polish(ui->widget_fy_train);

    ui->btn_fy_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_predict);
    ui->widget_fy_predict->setProperty("state","off");
    style()->polish(ui->widget_fy_predict);


    setStyle(QApplication::style());

    ui->fy_StackedWidget->setCurrentIndex(0);
}

void MainWindow::fy_train_clicked(){
    ui->btn_fy_init->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_init);
    ui->widget_fy_init->setProperty("state","off");
    style()->polish(ui->widget_fy_init);

    ui->btn_fy_train->setProperty("state","clicked");
    style()->polish(ui->btn_fy_train);
    ui->widget_fy_train->setProperty("state","on");
    style()->polish(ui->widget_fy_train);

    ui->btn_fy_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_predict);
    ui->widget_fy_predict->setProperty("state","off");
    style()->polish(ui->widget_fy_predict);


    setStyle(QApplication::style());

    ui->fy_StackedWidget->setCurrentIndex(1);

}

void MainWindow::fy_predict_clicked(){
    ui->btn_fy_init->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_init);
    ui->widget_fy_init->setProperty("state","off");
    style()->polish(ui->widget_fy_init);

    ui->btn_fy_train->setProperty("state","unclicked");
    style()->polish(ui->btn_fy_train);
    ui->widget_fy_train->setProperty("state","off");
    style()->polish(ui->widget_fy_train);

    ui->btn_fy_predict->setProperty("state","clicked");
    style()->polish(ui->btn_fy_predict);
    ui->widget_fy_predict->setProperty("state","on");
    style()->polish(ui->widget_fy_predict);


    setStyle(QApplication::style());

    ui->fy_StackedWidget->setCurrentIndex(2);

}

//乳腺癌左侧栏切换菜单
void MainWindow::rxa_init_clicked(){
    ui->btn_rxa_init->setProperty("state","clicked");
    style()->polish(ui->btn_rxa_init);
    ui->widget_rxa_init->setProperty("state","on");
    style()->polish(ui->widget_rxa_init);

    ui->btn_rxa_train->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_train);
    ui->widget_rxa_train->setProperty("state","off");
    style()->polish(ui->widget_rxa_train);

    ui->btn_rxa_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_predict);
    ui->widget_rxa_predict->setProperty("state","off");
    style()->polish(ui->widget_rxa_predict);


    setStyle(QApplication::style());

    ui->rxa_StackedWidget->setCurrentIndex(0);
}

void MainWindow::rxa_train_clicked(){
    ui->btn_rxa_init->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_init);
    ui->widget_rxa_init->setProperty("state","off");
    style()->polish(ui->widget_rxa_init);

    ui->btn_rxa_train->setProperty("state","clicked");
    style()->polish(ui->btn_rxa_train);
    ui->widget_rxa_train->setProperty("state","on");
    style()->polish(ui->widget_rxa_train);

    ui->btn_rxa_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_predict);
    ui->widget_rxa_predict->setProperty("state","off");
    style()->polish(ui->widget_rxa_predict);


    setStyle(QApplication::style());

    ui->rxa_StackedWidget->setCurrentIndex(1);

}

void MainWindow::rxa_predict_clicked(){
    ui->btn_rxa_init->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_init);
    ui->widget_rxa_init->setProperty("state","off");
    style()->polish(ui->widget_rxa_init);

    ui->btn_rxa_train->setProperty("state","unclicked");
    style()->polish(ui->btn_rxa_train);
    ui->widget_rxa_train->setProperty("state","off");
    style()->polish(ui->widget_rxa_train);

    ui->btn_rxa_predict->setProperty("state","clicked");
    style()->polish(ui->btn_rxa_predict);
    ui->widget_rxa_predict->setProperty("state","on");
    style()->polish(ui->widget_rxa_predict);


    setStyle(QApplication::style());

    ui->rxa_StackedWidget->setCurrentIndex(2);

}

//白内障左侧栏切换菜单
void MainWindow::bnz_init_clicked(){
    ui->btn_bnz_init->setProperty("state","clicked");
    style()->polish(ui->btn_bnz_init);
    ui->widget_bnz_init->setProperty("state","on");
    style()->polish(ui->widget_bnz_init);

    ui->btn_bnz_train->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_train);
    ui->widget_bnz_train->setProperty("state","off");
    style()->polish(ui->widget_bnz_train);

    ui->btn_bnz_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_predict);
    ui->widget_bnz_predict->setProperty("state","off");
    style()->polish(ui->widget_bnz_predict);


    setStyle(QApplication::style());

    ui->bnz_StackedWidget->setCurrentIndex(0);
}

void MainWindow::bnz_train_clicked(){
    ui->btn_bnz_init->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_init);
    ui->widget_bnz_init->setProperty("state","off");
    style()->polish(ui->widget_bnz_init);

    ui->btn_bnz_train->setProperty("state","clicked");
    style()->polish(ui->btn_bnz_train);
    ui->widget_bnz_train->setProperty("state","on");
    style()->polish(ui->widget_bnz_train);

    ui->btn_bnz_predict->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_predict);
    ui->widget_bnz_predict->setProperty("state","off");
    style()->polish(ui->widget_bnz_predict);


    setStyle(QApplication::style());

    ui->bnz_StackedWidget->setCurrentIndex(1);

}

void MainWindow::bnz_predict_clicked(){
    ui->btn_bnz_init->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_init);
    ui->widget_bnz_init->setProperty("state","off");
    style()->polish(ui->widget_bnz_init);

    ui->btn_bnz_train->setProperty("state","unclicked");
    style()->polish(ui->btn_bnz_train);
    ui->widget_bnz_train->setProperty("state","off");
    style()->polish(ui->widget_bnz_train);

    ui->btn_bnz_predict->setProperty("state","clicked");
    style()->polish(ui->btn_bnz_predict);
    ui->widget_bnz_predict->setProperty("state","on");
    style()->polish(ui->widget_bnz_predict);


    setStyle(QApplication::style());

    ui->bnz_StackedWidget->setCurrentIndex(2);

}

//心脏病左侧栏切换菜单
void MainWindow::xzb_init_clicked(){
    ui->btn_xzb_init->setProperty("state","clicked");
    style()->polish(ui->btn_xzb_init);
    ui->widget_xzb_init->setProperty("state","on");
    style()->polish(ui->widget_xzb_init);

    ui->btn_xzb_result->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_result);
    ui->widget_xzb_result->setProperty("state","off");
    style()->polish(ui->widget_xzb_result);

    ui->btn_xzb_precision->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_precision);
    ui->widget_xzb_precision->setProperty("state","off");
    style()->polish(ui->widget_xzb_precision);


    setStyle(QApplication::style());

    ui->xzb_StackedWidget->setCurrentIndex(0);
}

void MainWindow::xzb_result_clicked(){
    ui->btn_xzb_init->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_init);
    ui->widget_xzb_init->setProperty("state","off");
    style()->polish(ui->widget_xzb_init);

    ui->btn_xzb_result->setProperty("state","clicked");
    style()->polish(ui->btn_xzb_result);
    ui->widget_xzb_result->setProperty("state","on");
    style()->polish(ui->widget_xzb_result);

    ui->btn_xzb_precision->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_precision);
    ui->widget_xzb_precision->setProperty("state","off");
    style()->polish(ui->widget_xzb_precision);


    setStyle(QApplication::style());

    ui->xzb_StackedWidget->setCurrentIndex(1);

}

void MainWindow::xzb_precision_clicked(){
    ui->btn_xzb_init->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_init);
    ui->widget_xzb_init->setProperty("state","off");
    style()->polish(ui->widget_xzb_init);

    ui->btn_xzb_result->setProperty("state","unclicked");
    style()->polish(ui->btn_xzb_result);
    ui->widget_xzb_result->setProperty("state","off");
    style()->polish(ui->widget_xzb_result);

    ui->btn_xzb_precision->setProperty("state","clicked");
    style()->polish(ui->btn_xzb_precision);
    ui->widget_xzb_precision->setProperty("state","on");
    style()->polish(ui->widget_xzb_precision);


    setStyle(QApplication::style());

    ui->xzb_StackedWidget->setCurrentIndex(2);

}




//点击菜单栏关闭
void MainWindow::btnMenu_Close_clicked()
{
    close();
}

//点击最大化按钮
void MainWindow::btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }

    this->setProperty("canMove", max);
    max = !max;
}

//点击最小化按钮
void MainWindow::btnMenu_Min_clicked()
{
    showMinimized();
}

//点击保存设置按钮
void MainWindow::btn_saveSetting_clicked(){
    if(ui->lineEdit_setting_params->text().length()==0||ui->lineEdit_setting_num->text().length()==0){
        QMessageBox::warning(NULL,tr("提示"),tr("设置为空!"));
        return;
    }
    settingParams=ui->lineEdit_setting_params->text();
    settingNum=ui->lineEdit_setting_num->text();
    qDebug()<<settingNum<<settingParams;
    QMessageBox::information(NULL,tr("提示"),tr("保存成功!"));
}

// 肺炎显示预测结果
void MainWindow::fy_showPredict(QString resultpath){

    /*从文件中读取结果*/
    //初始化
    int ResNum=0;
    QList<QString>Good;
    QList<QString>Bad;
    QList<QString>Labels;
    QList<QString>Result;

    resdata.resData.clear();
    QFile file(resultpath);    //文件对象
    //指定为GBK
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        in.setCodec(codec);
        QString str;
        QStringList strList;

        while (!in.atEnd())
        {
            str = in.readLine();
            if(str.isEmpty())
                break;
            strList = str.split(' ');

            Labels<<strList[1];
            Good<<strList[3];
            Bad<<strList[2];
            Result<<strList[4];

            ResNum++;
         }
        file.close();
    }
    qDebug()<<ResNum<<"个结果";


    QString strOne;
    QString strZero;
    /*创建数据表格*/
    QTableWidget *CompressedNDBDataTable = new QTableWidget(ResNum,4);
    QLabel *CompressedNDBLabel = new QLabel();

    /*展示二进制数据,首先清空布局*/
    if(CompressedNDBTableLayout){
        QLayoutItem *child;
         while ((child = CompressedNDBTableLayout->takeAt(0)) != 0)
         {
                //setParent为NULL，防止删除之后界面不消失
                if(child->widget())
                {
                    child->widget()->setParent(NULL);
                }
                delete child;
         }
    }

    CompressedNDBLabel->setText("                     新冠肺炎预测结果");
    CompressedNDBLabel->setStyleSheet("font-size:28px");

    QStringList header;
    header <<"新冠肺炎图像"<<"阴性概率"<<"阳性概率"<<"诊断结果（COVID：阳性；NonCOVID：阴性）";
    CompressedNDBDataTable->setHorizontalHeaderLabels(header);

    QHeaderView *colheader = CompressedNDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号


    // 输出结果
    for(int p=0;p<ResNum;p++){
        CompressedNDBDataTable->setItem(p,0,new QTableWidgetItem(Labels[p]));
        CompressedNDBDataTable->setItem(p,1,new QTableWidgetItem(Good[p]));
        CompressedNDBDataTable->setItem(p,2,new QTableWidgetItem(Bad[p]));
        CompressedNDBDataTable->setItem(p,3,new QTableWidgetItem(Result[p]));
    }

    /*设置自适应列宽*/
    CompressedNDBDataTable->horizontalHeader()->setStretchLastSection(true);
    CompressedNDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CompressedNDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 10pt}");

    CompressedNDBTableLayout->addWidget(CompressedNDBLabel);
    CompressedNDBTableLayout->addWidget(CompressedNDBDataTable);

    ui->fy_predict->setLayout(CompressedNDBTableLayout);



}

// 肺炎显示训练结果
void MainWindow::fy_showTrain(){
}

// 乳腺癌显示预测结果
void MainWindow::rxa_showPredict(QString resultpath){

    /*从文件中读取结果*/
    //初始化
    int ResNum=0;
    QList<QString>Good;
    QList<QString>Bad;
    QList<QString>Labels;
    QList<QString>Result;

    resdata.resData.clear();
    QFile file(resultpath);    //文件对象
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString str;
        QStringList strList;

        while (!in.atEnd())
        {
            str = in.readLine();
            if(str.isEmpty())
                break;
            strList = str.split(' ');

            Labels<<strList[0];
            Good<<strList[1];
            Bad<<strList[2];
            Result<<strList[3];

            ResNum++;
         }
        file.close();
    }
    qDebug()<<ResNum<<"个结果";


//    int size=40;
//    int length=5;


    QString strOne;
    QString strZero;
    /*创建数据表格*/
    QTableWidget *CompressedNDBDataTable = new QTableWidget(ResNum,4);
    QLabel *CompressedNDBLabel = new QLabel();

    /*展示二进制数据,首先清空布局*/
    if(CompressedNDBTableLayout){
        QLayoutItem *child;
         while ((child = CompressedNDBTableLayout->takeAt(0)) != 0)
         {
                //setParent为NULL，防止删除之后界面不消失
                if(child->widget())
                {
                    child->widget()->setParent(NULL);
                }
                delete child;
         }
    }

    CompressedNDBLabel->setText("                     乳腺癌预测结果");
    CompressedNDBLabel->setStyleSheet("font-size:28px");

    QStringList header;
    header <<"诊断癌切片名字"<<"良性概率"<<"恶性概率"<<"诊断结果";
    CompressedNDBDataTable->setHorizontalHeaderLabels(header);

    QHeaderView *colheader = CompressedNDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号


    // 输出结果
    for(int p=0;p<ResNum;p++){
        CompressedNDBDataTable->setItem(p,0,new QTableWidgetItem(Labels[p]));
        CompressedNDBDataTable->setItem(p,1,new QTableWidgetItem(Good[p]));
        CompressedNDBDataTable->setItem(p,2,new QTableWidgetItem(Bad[p]));
        CompressedNDBDataTable->setItem(p,3,new QTableWidgetItem(Result[p]));
    }

    /*设置自适应列宽*/
    CompressedNDBDataTable->horizontalHeader()->setStretchLastSection(true);
    CompressedNDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CompressedNDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 10pt}");

    CompressedNDBTableLayout->addWidget(CompressedNDBLabel);
    CompressedNDBTableLayout->addWidget(CompressedNDBDataTable);

    ui->rxa_predict->setLayout(CompressedNDBTableLayout);



}

// 乳腺癌显示训练结果
void MainWindow::rxa_showTrain(){
}


// 白内障显示预测结果
void MainWindow::bnz_showPredict(QString resultpath){

    /*从文件中读取结果*/
    //初始化
    int ResNum=0;
    QList<QString>Labels;   //图片名
    QList<QString>ZC_N;   //正常眼底N
    QList<QString>TNB_D;   //糖尿病视网膜D
    QList<QString>QGY_G;   //青光眼G
    QList<QString>BNZ_C;    //白内障C
    QList<QString>LNHB_A;   //老年黄斑变性A
    QList<QString>GXY_H;    //高血压H
    QList<QString>JS_M;    //病理性近视M
    QList<QString>Other;    //其他疾病O
    QList<QString>Result;   //诊断结果

    resdata.resData.clear();
    //指定为utf8
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QFile file(resultpath);    //文件对象
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        in.setCodec(codec );
        QString str;
        QStringList strList;

        while (!in.atEnd())
        {
            str = in.readLine();
            if(str.isEmpty())
                break;
            strList = str.split(' ');
//            qDebug()<<strList[10];

            Labels<<strList[1];
            ZC_N<<strList[4];
            TNB_D<<strList[2];
            QGY_G<<strList[3];
            BNZ_C<<strList[5];
            LNHB_A<<strList[8];
            GXY_H<<strList[6];
            JS_M<<strList[7];
            Other<<strList[9];
            Result<<strList[10];

            ResNum++;
         }
        file.close();
    }
    qDebug()<<ResNum<<"个结果";

//    int size=40;
//    int length=5;


    QString strOne;
    QString strZero;
    /*创建数据表格*/
    QTableWidget *CompressedNDBDataTable = new QTableWidget(ResNum,10);
    QLabel *CompressedNDBLabel = new QLabel();

    /*展示二进制数据,首先清空布局*/
    if(CompressedNDBTableLayout){
        QLayoutItem *child;
         while ((child = CompressedNDBTableLayout->takeAt(0)) != 0)
         {
                //setParent为NULL，防止删除之后界面不消失
                if(child->widget())
                {
                    child->widget()->setParent(NULL);
                }
                delete child;
         }
    }

    CompressedNDBLabel->setText("                     眼疾预测结果");
    CompressedNDBLabel->setStyleSheet("font-size:28px");

    QStringList header;
    header <<"眼底图像"<<"正常眼底N（概率）"<<"糖尿病视网膜D"<<"青光眼G"<<"白内障C"<<"老年黄斑变性A"<<"高血压H"<<"病理近视M"<<"其他疾病O"<<"诊断关键词";
    CompressedNDBDataTable->setHorizontalHeaderLabels(header);

    QHeaderView *colheader = CompressedNDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号


    // 输出结果
    for(int p=0;p<ResNum;p++){
        CompressedNDBDataTable->setItem(p,0,new QTableWidgetItem(Labels[p]));
        CompressedNDBDataTable->setItem(p,1,new QTableWidgetItem(ZC_N[p]));
        CompressedNDBDataTable->setItem(p,2,new QTableWidgetItem(TNB_D[p]));
        CompressedNDBDataTable->setItem(p,3,new QTableWidgetItem(QGY_G[p]));
        CompressedNDBDataTable->setItem(p,4,new QTableWidgetItem(BNZ_C[p]));
        CompressedNDBDataTable->setItem(p,5,new QTableWidgetItem(LNHB_A[p]));
        CompressedNDBDataTable->setItem(p,6,new QTableWidgetItem(GXY_H[p]));
        CompressedNDBDataTable->setItem(p,7,new QTableWidgetItem(JS_M[p]));
        CompressedNDBDataTable->setItem(p,8,new QTableWidgetItem(Other[p]));
        CompressedNDBDataTable->setItem(p,9,new QTableWidgetItem(Result[p]));
    }

    /*设置自适应列宽*/
    CompressedNDBDataTable->horizontalHeader()->setStretchLastSection(true);
    CompressedNDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CompressedNDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 10pt}");

    CompressedNDBTableLayout->addWidget(CompressedNDBLabel);
    CompressedNDBTableLayout->addWidget(CompressedNDBDataTable);

    ui->bnz_predict->setLayout(CompressedNDBTableLayout);



}

// 白内障显示训练结果
void MainWindow::bnz_showTrain(){
    QLineSeries *series = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    // 用二维数组存放点的坐标
    int line1[10][2]={{1,2},{2,8},{3,4},{4,4},{5,9},{6,1}};
    int line2[10][2]={{1,2},{2,8},{3,4},{4,4},{5,9},{6,1}};
    // 循环插入点
    for(int i=0;i<=5;i++){
        series->append(line1[i][0],line1[i][1]);
    }
    for(int i=0;i<=5;i++){
        series1->append(line2[i][0],line2[i][1]+1);
    }
    series->setName("line1");
    series1->setName("line2");


    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->addSeries(series1);
    chart->createDefaultAxes();
    chart->setTitle("白内障训练结果比较");

//    ui->bnz_graph->setChart(chart);
//    ui->bnz_graph->setRenderHint(QPainter::Antialiasing);



}

// 心脏病显示分类结果
void MainWindow::xzb_showResult(map<string, vector<int> > result){
    int RowNumber = result.size();

    QString strOne;
    QString strZero;
    /*创建数据表格*/
    QTableWidget *CompressedNDBDataTable = new QTableWidget();
    QWidget *pBtn = new QWidget();
    CompressedNDBDataTable->setColumnCount(3);
    CompressedNDBDataTable->setRowCount(RowNumber);
    CompressedNDBDataTable->setSpan(0,2,2,1);
    QLabel *CompressedNDBLabel = new QLabel();

    QPushButton *ShowKnnAccuracy = new QPushButton();   //精度统计按钮
    QHBoxLayout *KnnFootLayout = new QHBoxLayout();

    /*首先清空布局*/
    if(CompressedNDBTableLayout){
        QLayoutItem *child;
         while ((child = CompressedNDBTableLayout->takeAt(0)) != 0)
         {
                //setParent为NULL，防止删除之后界面不消失
                if(child->widget())
                {
                    child->widget()->setParent(NULL);
                }
                delete child;
         }
    }

    CompressedNDBLabel->setText("                     心脏病分类结果");
    CompressedNDBLabel->setStyleSheet("font-size:28px");

    QStringList header;
    header <<"分类中心"<<"同类数据"<<"分类精度";
    CompressedNDBDataTable->setHorizontalHeaderLabels(header);

    ShowKnnAccuracy->setText("精度统计");
    ShowKnnAccuracy->setFixedSize(80,28);

    QHeaderView *colheader = CompressedNDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号
//    QTableWidgetItem *strTwo=new QTableWidgetItem("最终精度");
    QTableWidgetItem *strTwo=new QTableWidgetItem(QString::number(Knn.getAccuracyRate()*100.0)+"%");


    // 输出结果
    map<string, vector<int>>::iterator iter = result.begin();
    int num = 0;
    while(iter != result.end())
    {
        string lable = iter->first;
        QString qlable = QString::fromStdString(lable);
        vector<int> ResultData = iter->second;
//        qDebug()<<ResultData.size()<<"个";
        QString ShowResult = "";
        for(int i=0;i<ResultData.size();i++)
        {
            ShowResult=ShowResult+QString::number(ResultData[i])+"\t";
        }
        CompressedNDBDataTable->setItem(num,0,new QTableWidgetItem(qlable));
        CompressedNDBDataTable->setItem(num,1,new QTableWidgetItem(ShowResult));
        CompressedNDBDataTable->item(num,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        iter++;
        num++;
    }
    CompressedNDBDataTable->setItem(0, 2, strTwo);
    CompressedNDBDataTable->item(0,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);



    /*设置自适应列宽*/
    CompressedNDBDataTable->horizontalHeader()->setStretchLastSection(true);
    CompressedNDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CompressedNDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 15pt}");

    CompressedNDBTableLayout->addWidget(CompressedNDBLabel);
    CompressedNDBTableLayout->addWidget(CompressedNDBDataTable);

    KnnFootLayout->addWidget(ShowKnnAccuracy);
    pBtn->setLayout(KnnFootLayout);
    pBtn->setMaximumHeight(50);
//    pBtn->setMaximumHeight(80);
    CompressedNDBTableLayout->addWidget(pBtn);

    ui->xzb_result->setLayout(CompressedNDBTableLayout);

    //精度统计响应函数
    connect(ShowKnnAccuracy, SIGNAL(clicked(bool)), this, SLOT(xzb_showPrecision()));



}




// 心脏病显示分类精度
void MainWindow::xzb_showPrecision(){
    //展示精度统计界面
    xzb_precision_clicked();


    QChart *chart = new QChart();
    chart->setTitle("The average Accuracy of knn");
    QPen *seriesPen =new QPen();
    seriesPen->setWidth(2);
    QFont *titleFont =new QFont();
    titleFont->setPixelSize(18);

    QLineSeries *series = new QLineSeries();
    for (int i = 5; i <= 25; i++){
        *series<<QPointF(i,0.9543);
    }


    //![3]
    QLineSeries *series1 = new QLineSeries();
    *series1 << QPointF(5, 0.818028) << QPointF(6, 0.840282) << QPointF(7, 0.857324) << QPointF(8, 0.877324);
    *series1 << QPointF(9, 0.891408) << QPointF(10, 0.922535) << QPointF(11, 0.866197) << QPointF(12, 0.897746);
    *series1 << QPointF(13, 0.90662) << QPointF(14, 0.889577) << QPointF(15, 0.930704) << QPointF(16, 0.93662);
    *series1 << QPointF(17, 0.9130985) << QPointF(18, 0.930141) << QPointF(19, 0.9336615) << QPointF(20, 0.933662);
    *series1 << QPointF(21, 0.958451) << QPointF(22, 0.940704) << QPointF(23, 0.943662) << QPointF(24, 0.9436615);
    *series1 << QPointF(25, 0.947183);

    series->setPen(*seriesPen);
    series->setName("knn algorithm");
    series->setColor(QRgb(0x0000FF));
    series->setPointsVisible(true);

    series1->setPointsVisible(true);
    series1->setPen(*seriesPen);
    series1->setName("our proposed algorithm");
    series1->setColor(QRgb(0xDC143C));

//    series->setName("line1");
//    series1->setName("line2");


//    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->addSeries(series1);

    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%d");
    axisX->setTitleText("R");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Accuracy");
    axisY->setRange(0.5,1);

    chart->addAxis(axisY, Qt::AlignLeft);
    chart->setTitleFont(*titleFont);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    series1->attachAxis(axisX);
    series1->attachAxis(axisY);

//    chart->createDefaultAxes();
//    chart->setTitle("分类算法精度统计");

    ui->xzb_graph->setChart(chart);
    ui->xzb_graph->setRenderHint(QPainter::Antialiasing);



}




//允许文件拖拽
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

// 文件拖拽获取路径
void MainWindow::dropEvent(QDropEvent *event)
{

    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
        return;


    switch (ui->mainStackedWidget->currentIndex()) {
    case 0:
        foreach(QUrl url, urls) {
            QString file_name = url.toLocalFile();

            QString str_fileClass = file_name.mid(file_name.length()-4);

            if(QString::compare(str_fileClass,".jpg")!=0&& QString::compare(str_fileClass,".png")!=0)    continue;

            //为空直接追加，不为空用分号隔开
            qDebug()<<"?";
            if(ui->rxa_FilePathEdit->text().isEmpty()){
                ui->rxa_FilePathEdit->setText(file_name);

            }else {
                ui->rxa_FilePathEdit->setText(ui->rxa_FilePathEdit->text()+';'+file_name);

            }

        }

        break;
    case 1:
        foreach(QUrl url, urls) {
            QString file_name = url.toLocalFile();

            QString str_fileClass = file_name.mid(file_name.length()-4);

            if(QString::compare(str_fileClass,".jpg")!=0&& QString::compare(str_fileClass,".png")!=0)    continue;

            //为空直接追加，不为空用分号隔开
            if(ui->bnz_FilePathEdit->text().isEmpty()){
                ui->bnz_FilePathEdit->setText(file_name);

            }else {
                ui->bnz_FilePathEdit->setText(ui->bnz_FilePathEdit->text()+';'+file_name);

            }

        }

        break;

    case 2:
        foreach(QUrl url, urls) {
            QString file_name = url.toLocalFile();

            QString str_fileClass = file_name.mid(file_name.length()-4);

            if(QString::compare(str_fileClass,".txt")!=0&& QString::compare(str_fileClass,".csv")!=0)    continue;

            //为空直接追加，不为空用分号隔开
            if(ui->xzb_FilePathEdit->text().isEmpty()){
                ui->xzb_FilePathEdit->setText(file_name);

            }else {
                ui->xzb_FilePathEdit->setText(ui->xzb_FilePathEdit->text()+';'+file_name);

            }

        }

        break;
    case 3:
        foreach(QUrl url, urls) {
            QString file_name = url.toLocalFile();

            QString str_fileClass = file_name.mid(file_name.length()-4);

            if(QString::compare(str_fileClass,".txt")!=0&& QString::compare(str_fileClass,".csv")!=0)    continue;

            //为空直接追加，不为空用分号隔开
            if(ui->fy_FilePathEdit->text().isEmpty()){
                ui->fy_FilePathEdit->setText(file_name);

            }else {
                ui->fy_FilePathEdit->setText(ui->fy_FilePathEdit->text()+';'+file_name);

            }

        }

        break;
    default:
        break;
    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}


