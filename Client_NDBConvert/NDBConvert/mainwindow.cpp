
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
#include<QHeaderView>
#include<process.h>

using namespace std;

QVBoxLayout *NDBTableLayout = new QVBoxLayout();
QVBoxLayout *CompressedNDBTableLayout = new QVBoxLayout();



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
    connect(ui->btn_dataDisplay,&QToolButton::clicked,this,&MainWindow::btn_dataDisplay_clicked);
    connect(ui->btn_dataInput,&QToolButton::clicked,this,&MainWindow::btn_dataInput_clicked);
    connect(ui->btn_dataNdb,&QToolButton::clicked,this,&MainWindow::btn_dataNdb_clicked);

    //主要菜单切换
    connect(ui->btnMenu_change,&QToolButton::clicked,this,&MainWindow::btnMenu_change_clicked);
    connect(ui->btnMenu_setting,&QToolButton::clicked,this,&MainWindow::btnMenu_setting_clicked);

    //根据当前主菜单界面改变按钮颜色
    int mainMenu_flag=ui->mainStackedWidget->currentIndex();
    if(mainMenu_flag){
        ui->btnMenu_setting->setStyleSheet("background-color:rgba(	220,220,220,70)");
    }
    else{
        ui->btnMenu_change->setStyleSheet("background-color:rgba(	220,220,220,70)");
    }

    //根据当前数据转换界面改变按钮颜色
    btn_dataInput_clicked();
//    int leftMenu_flag=ui->changeStackedWidget->currentIndex();
//    if(leftMenu_flag){
//        ui->btn_dataDisplay->setStyleSheet("background-color:rgba(176,196,222,70),");
//    }
//    else{
//        ui->btn_dataInput->setStyleSheet("background-color:rgba(176,196,222,70)");
//    }


    //开始转化
    connect(ui->ToNDBButton,&QPushButton::clicked,this,&MainWindow::ToNDBButton_clicked);

    //选择原数据
    connect(ui->SelectPathButton,&QPushButton::clicked,this,&MainWindow::SelectFile_clicked);

    //保存设置
    connect(ui->btn_saveSetting,&QPushButton::clicked,this,&MainWindow::btn_saveSetting_clicked);

    //展示
//    showNdb();
//    showDis();

    tcpSocket = new QTcpSocket(this);
     Pro = new Progress();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//开始转化相应函数
void MainWindow::ToNDBButton_clicked()
{
     qDebug()<<"转化函数";

     //调用进度条
//     Progress *p1 = new Progress();

//     Pro->progress();

//     //获取文件路径
//     orifilepath=ui->FilePathEdit->text();
//     qDebug()<<orifilepath;

     /*参数 k p r这里先定义为常量，等界面有了输入框，在改**/
//     int k=4;
     int R = 10;
//     int R = ui->lineEdit_setting_params->text().toInt();     //获取参数R
     int k = ui->lineEdit_setting_num->text().toInt();    //获取参数K
     QList<double>P;
     QList<double>q;
     P<<0.0;
//     P<<0.9;  P<<0.02; P<<0.03;  P<<0.05;
     if(k==4){
         P<<ui->lineEdit_p1->text().toDouble();
         P<<ui->lineEdit_p2->text().toDouble();
         P<<ui->lineEdit_p3->text().toDouble();
         P<<ui->lineEdit_p4->text().toDouble();
     }
     //参数q
     if(FileType == "txt" || FileType == "csv")
     {
         q<<0.05; q<<0.1; q<<0.1; q<<0.1; q<<0.1; q<<0.1; q<<0.1;q<<0.1;q<<0.1;q<<0.15;
     }
     else{
         q<<ui->lineEdit_q0->text().toDouble();
         q<<ui->lineEdit_q1->text().toDouble();
         q<<ui->lineEdit_q2->text().toDouble();
         q<<ui->lineEdit_q3->text().toDouble();
         q<<ui->lineEdit_q4->text().toDouble();
         q<<ui->lineEdit_q5->text().toDouble();
         q<<ui->lineEdit_q6->text().toDouble();
         q<<ui->lineEdit_q7->text().toDouble();
     }

//     q<<0.05;   q<<0.1;   q<<0.1;  q<<0.1; q<<0.1; q<<0.1; q<<0.1;q<<0.35;

     //将数据转化成二进制以及负数据库
     for(int PictureCount=0;PictureCount<str_pic_list.size();PictureCount++)
     {
//         Pro->progress();
         orifilepath = str_pic_list.at(PictureCount);
         if(orifilepath==""){
             return;
         }
         qDebug()<<"文件路径"<<orifilepath;
         getoridata.setFileName(orifilepath,FileType);  //传递文件路径
         int readStatus = getoridata.ReadData();    //返回数据读取状态，1：成功 0：失败
         //如果读取成功，则过去转化成浮点数的原数据进行二进制转化
         if (readStatus==1){
            OriginData* OriData = getoridata.getOriData();    //获取原数据（double)

            /*转化成二进制数据*/
           int toBStatus= BString.toBinaryString(OriData,FileType);    //判断是否转化成二进制串
           BStrData* bStrData = BString.getBStrData();     //获取二进制串数据

           /*转化成负数据库*/
            if(toBStatus==1){
                toNDB.SetNDB(k,P,q,R,bStrData,orifilepath);   //参数初始化
                int toNDBStatus=toNDB.ToNDBData(bStrData,OriData->labels,FileType);
                int length=bStrData->bData.at(0).size();

                if(toNDBStatus==OK){
                    qDebug()<<"负数据生成成功";
                    qDebug()<<length<<"ya ";

                     /*展示负数据库*/
                    if(PictureCount == 0)
                    {
                        QList<NDB>nDBs=toNDB.getNDB();
                        showNdb(nDBs,length,k);
                        //进入负数据库界面
                        btn_dataNdb_clicked();
                        showDis(nDBs,length);
                    }

                    toNDB.ToWriteFile(orifilepath);   //写入文件
                }

            }
         }
//         Pro->end();
     }

//     Pro->end();

}

/*连接服务器*/
void MainWindow::connect_slot()
{
    tcpSocket->connectToHost(QHostAddress::LocalHost,800);
}

/*发送数据*/
void MainWindow::send_slot()
{
    QString str = "请调用python";
    tcpSocket->write(qPrintable(str));
}

/*接收数据*/
void MainWindow::recv_slot()
{
    QByteArray byte;
    byte = tcpSocket->readAll();
    qDebug()<<QString(byte);
    if(QString(byte) == "Successfully")
    {
        qDebug()<<"初始化成功！";
    }
}

//选择原数据文件
void MainWindow::SelectFile_clicked()
{
    //选择多张图片文件
    QString ChoseFilePath;
//    QString FileType;
    QStringList str_path_list = QFileDialog::getOpenFileNames(this,"打开文件",QDir::currentPath(),tr("File(*.png *.jpg *.txt *.csv)"));
    for (int i = 0; i < str_path_list.size(); i++){
        QString str_path = str_path_list[i];
        if(str_path.contains("-NDB")){
            str_path="";
            QMessageBox::information(this,tr("提示"),tr("请选择正确的文件！"),QMessageBox::Abort);
        }
        //路径
        qDebug() << "path=" << str_path;
//        if(i==0){
//              ChoseFilePath=str_path.left(str_path.lastIndexOf("/"));    //获取所选择文件所在的文件夹路径
//              /*判断选择文件类型，是图片还是文本*/
//              QStringList strs=str_path.split(".");
//              FileType=strs[1];
//        }

        if(i==0){
              /*判断选择文件类型，是图片还是文本*/
            QFileInfo typeinfo(str_path);
            FileType = typeinfo.suffix();
            qDebug()<<FileType<<"文件类型";
        }

//        /*如果是.txt  .csv文本文件 直接对原路径进行转化*/
//        if(FileType == "txt" || FileType == "csv") //获取文件后缀
//        {
//            str_pic_list<<str_path_list[i];
//            qDebug()<<str_path_list[i];
//        }
//        /*对图片转化成数组*/
//        else {
//            //获取存储路径
//            QString  oripicturename=str_path.right(str_path.length()-str_path.lastIndexOf("/"));
//            QString NDBPicturename=oripicturename.left(oripicturename.lastIndexOf("."))+".txt";
//            if(str_path.contains("乳腺癌数据")){
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/乳腺癌数据/array"+NDBPicturename;
//            }
//            else if(str_path.contains("新冠肺炎数据"))
//                {
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/新冠肺炎数据/array"+NDBPicturename;
//            }
//            else{
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/白内障数据/array"+NDBPicturename;
//            }
//            qDebug()<<oripicturename<<"原来"<<NDBPicturename<<"负数据"<<str_pic_list[i]<<"路径";
//        }

        /*如果是.txt  .csv文本文件 直接对原路径进行转化*/
        if(FileType == "txt" || FileType == "csv") //获取文件后缀
        {
            str_pic_list<<str_path_list[i];
            qDebug()<<str_path_list[i];
        }
        /*对图片转化成数组*/
        else {
            //获取存储路径
//            QString  oripicturename=str_path.right(str_path.length()-str_path.lastIndexOf("/"));
//            QString NDBPicturename=oripicturename.left(oripicturename.lastIndexOf("."))+".txt";
            QFileInfo info(str_path);
            QString NDBPicturename = info.completeBaseName()+".txt";
            if(str_path.contains("乳腺癌数据")){
                QStringList strs=str_path.split("乳腺癌数据/");
                QString xiangdui_path = strs[0] + "乳腺癌数据/array/"+NDBPicturename;
                str_pic_list<<xiangdui_path;
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/乳腺癌数据/array/"+NDBPicturename;
            }
            else if(str_path.contains("新冠肺炎数据"))
                {
                QStringList strs=str_path.split("新冠肺炎数据/");
                QString xiangdui_path = strs[0] + "新冠肺炎数据/array/"+NDBPicturename;
                str_pic_list<<xiangdui_path;
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/新冠肺炎数据/array/"+NDBPicturename;
            }
            else{
                QStringList strs=str_path.split("眼部疾病数据/");
                QString xiangdui_path = strs[0] + "眼部疾病数据/array/"+NDBPicturename;
                str_pic_list<<xiangdui_path;
//                str_pic_list<<"F:/2020竞赛/基于信息负表示的隐私保护在线医疗诊断系统/ExecutableFiles/白内障数据/array/"+NDBPicturename;
            }
            qDebug()<<NDBPicturename<<"负数据"<<str_pic_list[i]<<"路径";
        }

        //为空直接追加，不为空用分号隔开
        if(ui->FilePathEdit->text().isEmpty()){
            ui->FilePathEdit->setText(str_path);

        }else {
            ui->FilePathEdit->setText(ui->FilePathEdit->text()+';'+str_path);
        }


    }

}

//主菜单切换
void MainWindow::btnMenu_change_clicked(){

    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->btnMenu_change->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->mainStackedWidget->setCurrentIndex(0);
}
void MainWindow::btnMenu_setting_clicked(){
    ui->btnMenu_setting->setStyleSheet("background-color:rgba(220,220,220,70)");
    ui->btnMenu_change->setStyleSheet("background-color:rgba(220,220,220,0)");
    ui->mainStackedWidget->setCurrentIndex(1);
}



//左侧栏切换菜单
void MainWindow::btn_dataInput_clicked(){
    ui->btn_dataInput->setProperty("state","clicked");
    style()->polish(ui->btn_dataInput);
    ui->widget_dataInputBorder->setProperty("state","on");
    style()->polish(ui->widget_dataInputBorder);

    ui->btn_dataDisplay->setProperty("state","unclicked");
    style()->polish(ui->btn_dataDisplay);
    ui->widget_dataDisplayBorder->setProperty("state","off");
    style()->polish(ui->widget_dataDisplayBorder);

    ui->btn_dataNdb->setProperty("state","unclicked");
    style()->polish(ui->btn_dataNdb);
    ui->widget_dataNdbBorder->setProperty("state","off");
    style()->polish(ui->widget_dataNdbBorder);


    setStyle(QApplication::style());

    ui->changeStackedWidget->setCurrentIndex(0);

}
void MainWindow::btn_dataDisplay_clicked(){
    ui->btn_dataInput->setProperty("state","unclicked");
    style()->polish(ui->btn_dataInput);
    ui->widget_dataInputBorder->setProperty("state","off");
    style()->polish(ui->widget_dataInputBorder);

    ui->btn_dataDisplay->setProperty("state","clicked");
    style()->polish(ui->btn_dataDisplay);
    ui->widget_dataDisplayBorder->setProperty("state","on");
    style()->polish(ui->widget_dataDisplayBorder);

    ui->btn_dataNdb->setProperty("state","unclicked");
    style()->polish(ui->btn_dataNdb);
    ui->widget_dataNdbBorder->setProperty("state","off");
    style()->polish(ui->widget_dataNdbBorder);


    ui->changeStackedWidget->setCurrentIndex(1);
}
void MainWindow::btn_dataNdb_clicked(){

    ui->btn_dataInput->setProperty("state","unclicked");
    style()->polish(ui->btn_dataInput);
    ui->widget_dataInputBorder->setProperty("state","of");
    style()->polish(ui->widget_dataInputBorder);

    ui->btn_dataDisplay->setProperty("state","unclicked");
    style()->polish(ui->btn_dataDisplay);
    ui->widget_dataDisplayBorder->setProperty("state","off");
    style()->polish(ui->widget_dataDisplayBorder);

    ui->btn_dataNdb->setProperty("state","clicked");
    style()->polish(ui->btn_dataNdb);
    ui->widget_dataNdbBorder->setProperty("state","on");
    style()->polish(ui->widget_dataNdbBorder);

    ui->changeStackedWidget->setCurrentIndex(2);
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

void MainWindow::showNdb(QList<NDB>nDBs,int length,int K){
    /*创建表格数据  length为完整二进制串的长度*/
    QTableWidget *NDBDataTable = new QTableWidget(nDBs.size(),2);
    QLabel *NDBHeaderLabel = new QLabel();
    QString ShowNDBData;
    int IntData[10];
    qDebug()<<nDBs.size()<<length;
    for(int j=0;j<nDBs.size();j++){
        // 第一列数据
        ShowNDBData="";
        for(int i=0;i<K;i++){
            IntData[i]=nDBs[j].nData.at(0).at(i);
            qDebug()<<IntData[i];
            if(i==K-1)
                ShowNDBData=ShowNDBData+QString::number(IntData[i]);
            else
                ShowNDBData=ShowNDBData+QString::number(IntData[i])+"\t";

        }
        NDBDataTable->setItem(j,0,new QTableWidgetItem(ShowNDBData));

        // 第二列数据
        if(FileType == "txt" || FileType == "csv")
        {
            QString ShowData="";
            int tmp=0;
            for(int k=1;k<=length;k++){
                for(int n=0;n<K;n++){
                    if(k==abs(IntData[n])){
                        tmp=1;
                        if(IntData[n]>0)
                            ShowData=ShowData+"1  ";
                        else
                            ShowData=ShowData+"0  ";
                        break;
                    }else
                        tmp=0;
                }
                if(tmp==0)
                    ShowData=ShowData+"*  ";
            }
            NDBDataTable->setItem(j,1,new QTableWidgetItem(ShowData));
        }
        else{
            QString ShowData="";
            int tmp=0;
    //        for(int k=0;k<length;k++){
            for(int k=0;k<116;k++){
                for(int n=0;n<K;n++){
    //                if(k==abs(IntData[n])){
                    if(k==abs((int)IntData[n]/100)){
                        tmp=1;
                        if(IntData[n]>0)
                            ShowData=ShowData+"1  ";
                        else
                            ShowData=ShowData+"0  ";
                        break;
                    }else
                        tmp=0;
                }
                if(tmp==0)
                    ShowData=ShowData+"*  ";
            }
            NDBDataTable->setItem(j,1,new QTableWidgetItem(ShowData));
        }
    }


    QStringList header;
    header<<"确定位数据"<<"所有二进制串";

    NDBDataTable->setHorizontalHeaderLabels(header);

    NDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 10pt;}");


    QHeaderView *colheader = NDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号

    /*设置自适应列宽*/
    NDBDataTable->horizontalHeader()->setStretchLastSection(true);
    NDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    NDBHeaderLabel->setText("                负数据库转化结果");
    NDBHeaderLabel->setStyleSheet("font-size:28px");
    NDBTableLayout->addWidget(NDBHeaderLabel);
    NDBTableLayout->addWidget(NDBDataTable);
    ui->dataNdb->setLayout(NDBTableLayout);


}

void MainWindow::showDis(QList<NDB>nDBs,int length){

//    int size=40;
//    int length=5;


    QString strOne;
    QString strZero;
    /*创建数据表格*/
    QTableWidget *CompressedNDBDataTable = new QTableWidget(nDBs.size(),2);
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

    CompressedNDBLabel->setText("                   数据压缩结果");
    CompressedNDBLabel->setStyleSheet("font-size:28px");

    QStringList header;
    header <<"确定位为 0 的数据位压缩"<<"确定位为 1 的数据位压缩";
    CompressedNDBDataTable->setHorizontalHeaderLabels(header);

    QHeaderView *colheader = CompressedNDBDataTable->verticalHeader();
    colheader->setHidden(true);// 隐藏行号

    qDebug()<<nDBs.size()<<"tiao"<<length<<"长度";
    for(int p=0;p<nDBs.size();p++){
        strOne="";
        strZero="";
        /*负数据库长度*/
//        for(int j=0;j<length;j++)
        for(int j=0;j<22;j++)
        {
            strZero=strZero+QString::number(nDBs[p].nZero[j])+"\t";
            strOne=strOne+QString::number(nDBs[p].nOne[j])+"\t";
//            strZero=strZero+QString::number(0)+"\t";
//            strOne=strOne+QString::number(1)+"\t";
        }
        /*同一行，左边表示0的数据压缩，右边表示1的数据*/
        CompressedNDBDataTable->setItem(p,0,new QTableWidgetItem(strZero));
        CompressedNDBDataTable->setItem(p,1,new QTableWidgetItem(strOne));
    }

    /*设置自适应列宽*/
    CompressedNDBDataTable->horizontalHeader()->setStretchLastSection(true);
    CompressedNDBDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    CompressedNDBDataTable->horizontalHeader()->setStyleSheet("QHeaderView::section{font: 10pt}");

    CompressedNDBTableLayout->addWidget(CompressedNDBLabel);
    CompressedNDBTableLayout->addWidget(CompressedNDBDataTable);

    ui->dataDisplay->setLayout(CompressedNDBTableLayout);



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

    //往文本框中追加多个文件名

    foreach(QUrl url, urls) {
        QString file_name = url.toLocalFile();

        QString str_fileClass = file_name.mid(file_name.length()-4);

        if(QString::compare(str_fileClass,".jpg")!=0&& QString::compare(str_fileClass,".png")!=0
                && QString::compare(str_fileClass,".txt")!=0 && QString::compare(str_fileClass,".csv")!=0
                )    continue;

        //为空直接追加，不为空用分号隔开
        if(ui->FilePathEdit->text().isEmpty()){
            ui->FilePathEdit->setText(file_name);

        }else {
            ui->FilePathEdit->setText(ui->FilePathEdit->text()+';'+file_name);

        }

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


