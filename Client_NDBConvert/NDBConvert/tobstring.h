#ifndef TOBSTRING_H
#define TOBSTRING_H
#include"global.h"

class ToBString
{
public:
    ToBString();
    int toBinaryString(OriginData* OriData,QString filetype);    //转化成二进制数据
    BStrData* getBStrData();     //获取二进制数据的首地址
    int getBStrLength();         //获取属性长度
    void WriteFile();

private:
    BStrData  bStrData;
    QString filename;
    QString FileType;
};

#endif // TOBSTRING_H
