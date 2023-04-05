#include"getoridata.h"
#include<QFile>
#include<QDebug>
#include"global.h"



/*每一行的数据转化成浮点数*/
QList<double> getTmpList(QStringList qStrList,QString filetype){
    QList<double> tmpList;
    if(filetype == "txt" || filetype == "csv")
    {
        for(int i=0;i<qStrList.size()-1;i++){    //减1是去除最后一个标签
            /*需要分大小精度进行*/
            if(qStrList.at(i).toDouble()<10)
                tmpList<<qStrList.at(i).toDouble()*100;
//                tmpList<<qStrList.at(i).toDouble();
            else
                tmpList<<qStrList.at(i).toDouble();
        }
//        qDebug()<<filetype;
    }
   else{
        for(int i=0;i<qStrList.size();i++){
            /*需要分大小精度进行*/
            if(qStrList.at(i).toDouble()<10)
                tmpList<<qStrList.at(i).toDouble()*100;
    //        else if(qStrList.at(i).toDouble()>1000)
    //             tmpList<<qStrList.at(i).toDouble()/100;
            else
                tmpList<<qStrList.at(i).toDouble();
        }

        qDebug()<<filetype;
    }
    return tmpList ;
}

//设定读取文件的路径
void GetOriData::setFileName(QString filepath,QString filetype)
{
    filename=filepath;
    FileType=filetype;
}

//读取文件
int GetOriData::ReadData()
{
    //初始化
    OriData.dData.clear();
    OriData.labels.clear();
    QFile file(filename);    //文件对象
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
            strList = str.split(',');
            OriData.labels<<(strList.last());
            OriData.dData<<(getTmpList(strList,FileType));
         }
        file.close();
    }
    return OK;
}

OriginData* GetOriData::getOriData()
{
    return &OriData;
}
