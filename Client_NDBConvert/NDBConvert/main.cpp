#include "mainwindow.h"
#include <QApplication>
#include<QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":stylesheet.qss");

    if( qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }
    else
    {
        qDebug("Open failed");
    }
    MainWindow w;
    w.show();

//    Py_Initialize();//初始化py模块
//        if ( !Py_IsInitialized() )
//        {
//        return -1;
//        }
//        PyRun_SimpleString("import sys");//设置py脚本的路径
//        PyRun_SimpleString("sys.path.append('./')");//当前路径
//        PyObject* pModule = PyImport_ImportModule("hellotest12");  // 这里的test_py就是创建的python文件
//        if (!pModule) {
//                qDebug()<< "Cant open python file!\n";
//                return -1;
//            }
//        PyObject* pFunhello= PyObject_GetAttrString(pModule,"hello");  // 这里的hello就是python文件定义的函数
//        if(!pFunhello){
//             qDebug()<<"Get function hello failed";
//             return -1;
//         }
//        PyObject_CallFunction(pFunhello,nullptr);//调用hello函数
//         Py_Finalize();//释放py模块

    return a.exec();
}
