#include <QProgressDialog>
#include <QEventLoop>
#include <QTimer>
#include "progress.h"

Progress::Progress()
{
//    p_dlg=new QProgressDialog();
//    int num=1000;

//    p_dlg->setLabelText("诊断中...");
//    p_dlg->setRange(0,100); //设置进度对话框的步进范围
//    p_dlg->setCancelButtonText("停止诊断");

//    p_dlg->setModal(true);
//    p_dlg->setStyleSheet("background-color:#444444;color:#ffffff");
//    p_dlg->setMinimumDuration(5);
//    p_dlg->setWindowTitle("诊断提示");
//    p_dlg->setAutoClose(false);
//    p_dlg->setAutoReset(false);


//    p_dlg->show();
//    p_dlg->resize(QSize(500,100));
//    p_dlg->setValue(0);
//    t = new QTimer(this);
//    t->setSingleShot(false);
//    connect(t, SIGNAL(timeout()), this,SLOT(updateValue()));
//    t->start(1000*2);

////    tmp=new QTimer(this);
////    connect(tmp, SIGNAL(timeout()), this,SLOT(end()));
////    tmp->start(1000*5);

}

void Progress::progress()
{
    p_dlg=new QProgressDialog();
    int num=1000;

    p_dlg->setLabelText("诊断中...");
    p_dlg->setRange(0,100); //设置进度对话框的步进范围
    p_dlg->setCancelButtonText("停止诊断");

    p_dlg->setModal(true);
    p_dlg->setStyleSheet("background-color:#444444;color:#ffffff");
    p_dlg->setMinimumDuration(5);
    p_dlg->setWindowTitle("诊断提示");
    p_dlg->setAutoClose(false);
    p_dlg->setAutoReset(false);


    p_dlg->show();
    p_dlg->resize(QSize(500,100));
//    p_dlg->setValue(0);
    t = new QTimer(this);
    t->setSingleShot(false);
    connect(t, SIGNAL(timeout()), this,SLOT(updateValue()));
    t->start(1000*2);

    tmp=new QTimer(this);
    connect(tmp, SIGNAL(timeout()), this,SLOT(end()));
    tmp->start(1000*5);
}

void  Progress::updateValue(){
    steps++;
    p_dlg->setValue(steps);
    if(steps > p_dlg->maximum()-2 || p_dlg->wasCanceled())
    {
        t->stop();
        steps = 0;
        p_dlg->hide();

    }

}

void  Progress::end(){
    t->stop();
    tmp->stop();
    p_dlg->setValue(100);
    p_dlg->setLabelText("诊断结束");
    p_dlg->setCancelButtonText("完成诊断");


}


