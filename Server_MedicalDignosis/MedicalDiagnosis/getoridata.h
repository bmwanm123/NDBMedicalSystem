#ifndef GETORIDATA_H
#define GETORIDATA_H
#include<QString>
#include<QVector>
#include<QList>
#include"global.h"
//using namespace std;
class GetOriData
{
public:
    void setFileName(QString s);   //原数据文件读取路径

    int ReadData();  //读取文件，并将其转化为浮点数
    OriginData* getOriData();   //返回转化后的原始数据首地址

private:
    QString filename;
    OriginData OriData;
};


#endif // GETORIDATA_H
