#ifndef NDBVALUES_H
#define NDBVALUES_H
#include"global.h"
#include"tobstring.h"

class NDBValues
{
public:
    NDBValues() {}
    void ENDBvalues(int count,int Kx,NDB nDB,BStrData *bStrData,QList<double>px,QList<double>qx,QString path,QString filetype,QList<QString>labels);       //计算负数据库一条记录的期望值
    void CountPrQ(int collenIndex);
    //初始化计算所需要的变量
      void initVariable();
      void initVariable_text();
      void calVariableP();
      //释放计算用到的变量
      void deleteVariable();
      int DValueWriteFile(QString s);

private:
    QList<int>collen;
    int K;   //参数K
    QList<double>p;
    QList<double>q;
    QList<QList<double>>Dvalues;    //存储期望值
    double *pDiff;
    double *pSame;
    double *p0;
    double *p1;
    int *collenSum;
    BStrData bSdata;
    NDB Singal_nDB; //单条负数据记录
    QString filepath;
    QString FileType;
    QList<QString>labels;
};

#endif // NDBVALUES_H
