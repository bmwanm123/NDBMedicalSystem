#include"tobstring.h"
#include<QDebug>
#include"global.h"
#include<QtMath>


ToBString::ToBString()
{

}

/*求出每一列的最大的位数。*/
int findMaxBinaryLength(int v,QString filetype) {
    int i=0;
    while (v>0)
    {
        v/= 2;    //计算这个数有多少二进制位
        i++;
    }
    if(filetype == "txt" || filetype == "csv")
    {
        return i;
    }
    else{  //是图片
        return 8;
    }
}

//将浮点数转成二进制数
int ToBString::toBinaryString(OriginData *OriData,QString filetype)
{
    bStrData.collen.clear();    //每一个属性长度
    bStrData.bData.clear();    //浮点数数据
    bStrData.collen_max=0;
    FileType=filetype;

    //获取原浮点数行和列
    int nRow = OriData->dData.size();
    int nCol = OriData->dData[0].size();
    int n=0;
    int number=0;
    double MAX=0.0 , temp=0.0;
    int MAX1=0, inttemp=0;

    /*求每一列即每一个属性转化成二进制所能形成最大的长度*/
    for(int j=0;j<nCol;j++){
        MAX=0.0;
        for(int i=0;i<nRow;i++){
            temp=fabs(OriData->dData[i][j]);    //取绝对值
            //求最大
            if(temp>MAX){
                MAX=temp;
            }
        }
        MAX1=int(MAX);  //某列的最大值
        bStrData.collen<<findMaxBinaryLength(MAX1,FileType);    //将最大值计算成二进制的最大位数

//        qDebug()<<findMaxBinaryLength(MAX1)<<"zhi"<<bStrData.collen_max;
        //寻找属性的最大长度
        if(findMaxBinaryLength(MAX1,FileType) >= bStrData.collen_max){
            bStrData.collen_max=findMaxBinaryLength(MAX1,FileType);
        }
    }

//    qDebug()<<bStrData.collen_max<<"bit";

    /*根据最大列将原图片数据转化成二进制串*/
    if(filetype == "jpg" || filetype == "png")
    {
        for(int i=0;i<nRow;i++){
            QString bstr;   //存储一条记录
            int DataNumber=0;
            for(int j=0;j<nCol;j++){
                n=bStrData.collen[j];   //列长
    //            qDebug()<<n<<"长度";
                inttemp=(int)OriData->dData[i][j];
                //将一行中的某个数转化成二进制
                for(int k=n-1;k>=0;k--){
                    bstr += QString::number((inttemp>>k) & 1);    //通过循环右移与1相且来计算每一位是0 是1
                }

                //1536个数据一个批次   192*192
                if((j+1) % 1536 == 0){
    //                qDebug()<<bstr;
                    bStrData.bData<<bstr;
                    DataNumber++;
                    bstr="";
                }

            }   //一行结束
    //         qDebug()<<bstr;
    //        bStrData.bData<<bstr;    //存储
            qDebug()<<DataNumber<<"个批次";
            number++;
        }

        WriteFile();
        return OK;
    }
    else{   //根据最大列将原文本数据转化成二进制串
        for(int i=0;i<nRow;i++){
            QString bstr;   //存储一条记录
            int DataNumber=0;
            for(int j=0;j<nCol;j++){
                n=bStrData.collen[j];   //列长
                inttemp=(int)OriData->dData[i][j];
                //将一行中的某个数转化成二进制
                for(int k=n-1;k>=0;k--){
                    bstr += QString::number((inttemp>>k) & 1);    //通过循环右移与1相且来计算每一位是0 是1
                }

            }   //一行结束
            bStrData.bData<<bstr;    //存储
            number++;
        }
        qDebug()<<number<<"个文本数据";
        WriteFile();
        return OK;
    }
}

/*获取二进制数据的首地址*/
BStrData* ToBString::getBStrData()
{
    return &bStrData;
}

/*获取一条记录的二进制串长度*/
int ToBString::getBStrLength()
{
    return bStrData.bData[0].size();
}

void ToBString::WriteFile()
{
//    QStringList strs=s.split(".");
//    QString filename=strs[0];
    filename+="D:bsdata.txt";
    QFile file(filename);
    if (file.open(QIODevice::Text|QFile::WriteOnly |QIODevice::Truncate)){
    QTextStream out(&file);
    int i=0;
    while(i<bStrData.bData.size())
    {
        qDebug()<<bStrData.bData[i].length()<<"输入";
//        for(int j=0;j<bStrData.bData[0].length()-1;j++){
        for(int j=0;j<bStrData.bData[i].length()-1;j++){
            //qDebug()<<nDBs[i].nZero[j];
            out<<bStrData.bData[i].at(j);
        }
//        out<<bStrData.bData[0].at(bStrData.bData[0].length()-1)<<"\n";
        out<<bStrData.bData[i].at(bStrData.bData[i].length()-1)<<"\n";
        i++;
    }
    qDebug()<<i<<"条二进制串";
  }
    file.close();
//    qDebug()<<filename;
}
