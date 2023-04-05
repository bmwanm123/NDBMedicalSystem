#ifndef GLOBAL_H
#define GLOBAL_H
#define OK 1 //返回OK
#define NO 0 // 返回错误
#include<QList>
/*双精度原数据*/
typedef struct OriginData{
    QList<QList<double> >dData;   //数据
    QList<QString>labels;     //标签
}OriginData;

/*二进制串数据*/
typedef struct BStrData
{
    QList<QString> bData;   //数据
    QList<int> collen;    //属性长度
    int collen_max;      //属性最大长度
}BStrData;

/*标签结构体*/
typedef struct Label{
    QString labelName;//标签的结构体
    int labelPos;//标签的所在的最后一个位置
}Label ;

/*单条串生成的负数据库*/
typedef QList<QList<int> > NDBData;

/*负数据库*/
//typedef struct NDB{
//    NDBData nData;
//    int *nOne;     //二进制位为1的个数
//    int *nZero;    //二进制位为0的个数
//}NDB;

typedef struct Ent{
    QList<int>pos;    //位置
    QList<QString>PosChar;    //字符
}Ent;

/*诊断数据*/
typedef struct ResultData
{
    QList<QList<QString>> resData;   //数据
}ResultData;

//QList<Ent>NDB;

#endif // GLOBAL_H
