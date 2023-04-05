#include"ndbvalues.h"
#include<QDebug>
#include<QFile>
#include<QtMath>
#include<QFileInfo>
#include"tobstring.h"
using namespace std;


/**变量初始化*/
void NDBValues::initVariable()
{
    p0=new double[bSdata.collen_max+1];
    p1=new double[bSdata.collen_max+1];
//    collenSum=new int[collen.size()+1];  //计算该率Q所要用到的collen累加和
    collenSum=new int[1536+1];  //计算该率Q所要用到的collen累加和
    collenSum[0]=0;
//    for(int i=1;i<collen.size();i++)
    for(int i=1;i<1536;i++)
    {
//        collenSum[i]=collenSum[i-1]+collen[i-1];
        collenSum[i]=collenSum[i-1]+8;
    }
}

/*文本类型*/
void NDBValues::initVariable_text()
{
    p0=new double[bSdata.collen_max+1];
    p1=new double[bSdata.collen_max+1];
    collenSum=new int[collen.size()+1];  //计算该率Q所要用到的collen累加和
    collenSum[0]=0;
    for(int i=1;i<collen.size();i++)
    {
        collenSum[i]=collenSum[i-1]+collen[i-1];
    }
}

/*相同和不同概率计算*/
void NDBValues::calVariableP()
{
    pDiff=new double[bSdata.collen_max+1];
    pSame=new double[bSdata.collen_max+1];

    for(int i=0;i<bSdata.collen_max;i++)
    {
      double Ndiff=0,Nsame=0;
      for(int j=1;j<=K;j++)
      {
        Ndiff+=j*p[j]*q[i];
        Nsame+=((K-j)*p[j])/bSdata.collen_max;
      }
        pDiff[i]=Ndiff/(Ndiff+Nsame);
        pSame[i]=1-pDiff[i];
    }
}

/*清除指针*/
void NDBValues::deleteVariable()
{
    delete p0;
    delete p1;
    delete pDiff;
    delete pSame;
    delete collenSum;
}

/*计算负数据对应的期望值*/
void NDBValues::ENDBvalues(int count,int Kx, NDB nDB, BStrData *bStrData,QList<double>px,QList<double>qx,QString path,QString filetype,QList<QString>labels1)
{
    /**
    负数据库第count条记录，nDB是一条NDB记录，bStrData是原二进制串数据
    */

    Singal_nDB=nDB;

    if(count==0)     //只需执行一次
    {
        p=px;
        q=qx;
        K=Kx;
        bSdata.collen_max=bStrData->collen_max;
        collen = bStrData->collen;
        filepath=path;
        FileType=filetype;
        labels=labels1;
        if(filetype == "txt" || filetype == "csv")
        {
           initVariable_text();
        }
        else{
            initVariable();
        }
        calVariableP();

//        qDebug()<<bSdata.collen_max<<collen.size();

//        for(int i=0;i<bSdata.collen_max;i++)
//        {
//            qDebug()<<pDiff[i]<<"butong"<<pSame[i];
//        }

//        for(int i=0;i<bStrData->bData[0].length();i++){
//            qDebug()<<Singal_nDB.nZero[i]<<"ge0"<<Singal_nDB.nOne[i]<<"Ge1";
//        }
    }

    int n;
    double tempDvalue;
    double paraQ;
    QList<double>tempValues;  //存储一个属性的期望值

    //第i个属性需要和2^i位进行计算求和
//    for(int attrIndex=0;attrIndex<collen.size();attrIndex++)
    if(FileType == "txt" || FileType == "csv")
    {
        for(int attrIndex=0;attrIndex<collen.size();attrIndex++)   //一条记录的所有属性
        {

            CountPrQ(attrIndex);
            n=pow(2.0,collen[attrIndex]);   //一个属性相比的总数
            tempDvalue=0;
            for(int j=0;j<n;j++)
            {
                int bitCount=j;
                paraQ=1.0;
                for(int b=collen[attrIndex]-1;b>=0;b--){   //二进制串从右往左
                    if(bitCount>=pow(2.0,b)){   //bitCount位与b位，只能为0和1，如果两位相同或bitCount为1
                        paraQ=paraQ*p1[collen[attrIndex]-b-1];  //此时是从左到右
                        bitCount=bitCount-pow(2.0,b);
                    }
                    else{
                        paraQ=paraQ*p0[collen[attrIndex]-b-1];
                    }
                }

                tempDvalue+=j*paraQ;   //一位
            }
            tempValues<<tempDvalue;  //存储一条记录所有属性

        }
    }
    else{
        for(int attrIndex=0;attrIndex<1536;attrIndex++)  //1536个数
        {

            CountPrQ(attrIndex);
            n=pow(2.0,collen[attrIndex]);   //一个属性相比的总数
            tempDvalue=0;
            for(int j=0;j<n;j++)
            {
                int bitCount=j;
                paraQ=1.0;
                for(int b=collen[attrIndex]-1;b>=0;b--){   //二进制串从右往左
                    if(bitCount>=pow(2.0,b)){   //bitCount位与b位，只能为0和1，如果两位相同或bitCount为1
                        paraQ=paraQ*p1[collen[attrIndex]-b-1];  //此时是从左到右
                        bitCount=bitCount-pow(2.0,b);
                    }
                    else{
                        paraQ=paraQ*p0[collen[attrIndex]-b-1];
                    }
                }

                tempDvalue+=j*paraQ;   //一位
            }
            tempValues<<tempDvalue;  //存储一条记录所有属性

        }
    }

    Dvalues<<tempValues;    //所有记录
//    qDebug()<<count<<"第";

    if(count==bStrData->bData.size()-1)   //所有记录执行完，写入文件
    {
        qDebug()<<count<<"tiao";
        DValueWriteFile(filepath);
    }


    if(FileType == "jpg" || FileType == "png")
    {
        if((count+1) % 24 == 0){   //192*192/1536=24
            Dvalues.clear();
        }
    }

}

/*计算为原二进制串为0和1的概率*/
void NDBValues::CountPrQ(int collenIndex)
{
    //第ndnIndex条负数据库记录的第collenIndex个属性
    int *oneCount=Singal_nDB.nOne;
    int *zeroCount=Singal_nDB.nZero;
    int CountID;
    for(int j=0;j<collen[collenIndex];j++)   //一个属性所有位 8位
//    for(int j=0;j<8;j++)   //一个属性所有位 8位
    {
        CountID=collenSum[collenIndex]+j;    //确定位置
        p0[j]=(pow(pSame[j],zeroCount[CountID])*pow(pDiff[j],oneCount[CountID])) / (pow(pSame[j],zeroCount[CountID])*pow(pDiff[j],oneCount[CountID]) + pow(pSame[j],oneCount[CountID])*pow(pDiff[j],zeroCount[CountID]));
        p1[j]=(pow(pDiff[j],zeroCount[CountID])*pow(pSame[j],oneCount[CountID])) / (pow(pSame[j],zeroCount[CountID])*pow(pDiff[j],oneCount[CountID]) + pow(pSame[j],oneCount[CountID])*pow(pDiff[j],zeroCount[CountID]));
//        qDebug()<<p0[j]<<"0概率"<<p1[j]<<"1概率";
    }
}

/*将期望值写入文件*/
int NDBValues::DValueWriteFile(QString s)
{
    QString filename;
    if(FileType == "txt" || FileType == "csv")
    {
        QList<int> kind;
        QList<QString>label;
        QString tmpLabel=labels.at(0);
        label<<tmpLabel;
        for(int i=0;i<labels.size();i++)
         {
             if(labels.at(i).compare(tmpLabel)!=0)
             {
                 tmpLabel=labels.at(i);
                 label<<tmpLabel;
                 kind<<i-1;
             }
         }

           kind<<labels.size()-1;

        QStringList strs=s.split(".");
        filename=strs[0];

//        QFileInfo info(s);
//        filename = info.completeBaseName();

        filename+="-NDBValue.csv";
        QFile file(filename);
        if (file.open(QIODevice::Text|QFile::WriteOnly |QIODevice::Truncate)){
        QTextStream out(&file);
        int i=0;
        /**写入负数据库期望值相关参数
         * 第一行
         * labelName:标签的名字
         * 第二行
         * labelPos: 顺序排列下的同一标签的最后一个位置（从0开始）
         * */
        //第一行，
        for(int i=0;i<label.size()-1;i++)
        {
            out<<label.at(i)<<",";
        }
        out<<label.at(label.size()-1)<<"\n";
        //第二行
        for(i=0;i<kind.size()-1;i++){
            out<<kind.at(i)<<",";
        }
        out<<kind.at(kind.size()-1)<<"\n";

        //写入文件的具体的负数据期望值
        i=0;
        qDebug()<<Dvalues.size()<<"个期望"<<Dvalues[0].length()<<"长为";
        while(i<Dvalues.size())
        {
            for(int j=0;j<Dvalues[0].length()-1;j++){
                out<<Dvalues[i].at(j)<<",";
            }
            out<<Dvalues[i].at(Dvalues[i].length()-1)<<"\n";
            i++;
        }
      }
        file.close();
    }
    else {
        QStringList strs=s.split("array/");
//        QString name=strs[1];
//        QStringList strs1=name.split(".");
//        QString name1=strs1[0];   //获取图片名字

        QFileInfo info(s);
        QString name1 = info.completeBaseName();

        filename=strs[0]+"TestNDBValues/"+name1+"-NDBValue.txt";
    //    qDebug()<<filename;

        QFile file(filename);
        if (file.open(QIODevice::Text|QFile::WriteOnly |QIODevice::Truncate)){
        QTextStream out(&file);
        int i=0;

        qDebug()<<Dvalues.size()<<"个期望"<<Dvalues[0].length()<<"长为";
    //    i=0;
        while(i<Dvalues.size())
        {
    //        qDebug()<<nDBs.size()<<m<<"输入";
//            for(int j=0;j<Dvalues[0].length()-1;j++){
            for(int j=0;j<Dvalues[0].length();j++){
                //qDebug()<<nDBs[i].nZero[j];
                if(i==23 && j==Dvalues[0].length()-1){
                    out<<Dvalues[i].at(j);
                }
                else{
                    out<<Dvalues[i].at(j)<<",";
                }
                if(Dvalues[i].at(j)>256){
                    qDebug()<<Dvalues[i].at(j)<<"超过";
                }
            }
    //        out<<Dvalues[i].at(Dvalues[0].length()-1)<<"\n";
            i++;
        }
      }
        file.close();
    }
    qDebug()<<filename;
    return OK;
}



