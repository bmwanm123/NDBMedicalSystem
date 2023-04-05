#ifndef TONDB_H
#define TONDB_H
#include"global.h"
#include<QList>

class ToNDB
{
public:
    ToNDB();
    int SetNDB(int Kx,QList<double>Px,QList<double>qx, int Rx);    //参数为K ,P,Q,R
    int ToNDBData(BStrData* bStrData,QList<QString>labels);       //将二进制数据转化成负数据库
    int FindType(double rnd);    //判断该条记录属于何种类型，即有几个确定位
    void Generate_Random_Item(int type,int i);      //生成type个与原字符串不同的位，K-type个相同的位
    double rand_1();      //生成0~1的随机数
    int rnd_q(double num);      //计算反转位 j
    int Same_q(double num);     //计算相同的确定位 j
    int FindPos(int j);     //寻找确定位位置
    void addToNDB(Ent x);     //tianjia
    void test();
private:
    int K;    //确定位的位数
    QList<double>P;    //串中有i个确定位的概率
    QList<double>Q;    //反转概率
    QList<double>q;    //参数q
    QList<double>Q_q;   //确定位概率求和
    QList<double>Same;    //相同位
    int R;   //控制负数据库生成的长度
    int m;  //二进制串位数
    int N;   //没条串生成的负数据库长度
    QList<int> collen;//二进制的长度
//    QList<NDB> nDBs;//N串的负数据库
//    QList<int> v;//暂时生成的负数据库
    int *a;//用于做随机数的数组
    QList<QString>labels;//标签值

    QList<QList<int> >attrNum;   //属性位大于或者等于i的个数
    QList<int>diff;       //不同的位
    QList<int>same_q;     //相同的位
    int sameattr;       //相同个数的属性

    int cn=0;


    QList<bool>flag;  //访问标志
private:
    BStrData  BSData;
    Ent v;
    QList<Ent>NDB;
};

#endif // TONDB_H
