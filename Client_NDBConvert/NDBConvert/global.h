#ifndef GLOBAL_H
#define GLOBAL_H
#define OK 1 //返回OK
#define NO 0 // 返回错误
#include<QList>
/*双精度原数据*/
typedef struct OriginData{
    QList<QList<double>>dData;   //数据
    QList<QString>labels;     //标签
}OriginData;

/*二进制串数据*/
typedef struct BStrData
{
    QList<QString> bData;   //数据
//    QList<QList<QString>>bData;
    QList<int> collen;    //属性长度
    int collen_max;      //属性最大长度
}BStrData;

typedef struct Ent{
//    QList<QList<int>>pos;    //位置
//    QList<QList<QString>>PosChar;    //字符
//    int pos[20];
//    char PosChar[20];
    int *pos;
    char *PosChar;
}Ent;

/*单条串生成的负数据库*/
typedef  QList<QList<int>> NDBPosData;


typedef struct NDB{
    NDBPosData nData;
    int *nOne;
    int *nZero;
}NDB;

//typedef struct NDBData{
////    QList<int>vpos;
////    QList<char>vposchar;
//    int *vpos;
//    char *vposchar;
//}NDBData;


#endif // GLOBAL_H
