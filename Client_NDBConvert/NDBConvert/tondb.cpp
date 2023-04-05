#include"tondb.h"
#include<QDebug>
#include<QFile>
#include<ctime>
#include"global.h"
#include<ctime>
#include<QFileInfo>
#include"ndbvalues.h"
using namespace std;

ToNDB::ToNDB()
{

}

/*产生随机数*/
double ToNDB::rand_1()
{
//     srand((unsigned)time(NULL));    //随机数种子
//     double a=(rand()%100)*0.01;
     double a = (double)rand() / (RAND_MAX + 1.0);
     return a;    //产生0~1之间的随机数
}

int ToNDB::Attr_rnd(int n)
{
    double b=0 + (int)n * rand() / (RAND_MAX + 1);
    return b;
}

int ToNDB::AttrLength(int count)
{
    int length=0;
//    for(int i=0;i<count;i++){
//        length+=collen[i];
//    }
    length=(count)*8;
    return length;
}

/*文本类型*/
int ToNDB::AttrLength_text(int count)
{
    int length=0;
    for(int i=0;i<count;i++){
        length+=collen[i];
    }
    return length;
}

//参数初始化
int ToNDB::SetNDB(int Kx, QList<double> Px,QList<double> qx, int Rx,BStrData *bStrData,QString path)
{
    K=Kx;
    R=Rx;
    filepath=path;
    double temp=0.0;
    double temp_q=0.0;

    //获取二进制数据最大长度
    BSData.collen_max=bStrData->collen_max;

    for(int i=0;i<=K;i++)
    {   //获取概率P并计算反转概率Qi
        P<<Px[i];
        temp+=Px[i];
        Q<<temp;
    }

    for(int i=0;i<BSData.collen_max;i++){   //此处需要改，，因为q是根据最大长度来的，改q
        q<<qx[i];
        temp_q += qx[i];
        Q_q<<temp_q;
        Same<<1-temp_q;   //计算相同位的概率
    }
    return OK;
}

/*判断记录属于什么类型*/
int ToNDB::FindType(double rnd)
{
    for(int i=1;i<=K;i++){   //从1开始
        if(Q[i]>rnd){
            return i;   //返回类型i
        }
    }
    return K;
}

/*寻找确定位位置**/
int ToNDB::FindPos(int j)
{
    int Size=attrNum[j].size();
    int num=rand()%Size;   //随机选择一个属性号数
    int Pos;  int count=0;
    for(int i=0;i<attrNum[j][num];i++)   //0~num个属性
    {
        count=count+BSData.collen.at(i);
    }
    Pos=count+j;
    sameattr=count;
    return Pos;
}

/*通过概率q计算反转位并返回j*/
int ToNDB::rnd_q(double rnd1)
{
    for(int j=0;j<BSData.collen_max;j++){   //从1开始
        if(Q_q[j]>rnd1){
            return j;   //返回类型i
        }
    }
    return BSData.collen_max;
}

/*相同的位*/
int ToNDB::Same_q(double rnd1)
{
    for(int j=0;j<BSData.collen_max;j++){   //从1开始
        if(Same[j]>rnd1){
            return j;   //返回类型i
        }
    }
    return BSData.collen_max;
}

/*计算0和1的个数*/
void ToNDB::addToNDB(Ent x,int number)
{

        for (int i = 0; i < K; i++)
        {
            if(x.PosChar[i] == '0'){
               nDB.nZero[x.pos[i]]++;

            }
            else{
               nDB.nOne[x.pos[i]]++;
            }

        }

        if(cn == 0){
            nDB.nData<<SurePos;
        }

        cn++;
//        qDebug()<<"加入"<<cn<<"个";

        //计算NDBData中0和1的个数
}


/*随机生成type个确定位于原串不同，k-type相同**/
void ToNDB::Generate_Random_Item(int type,int singal_num,int cn)   //第i条记录
{

    double rnd1=0.0;
    int AttrPos=0;


    //初始化指针
    diff=new double[K+1];
    memset(diff,0.0,sizeof(double)*(K+1));
    same=new double[K+1];
    memset(same,0.0,sizeof(double)*(K+1));

    v.pos=new int[K+1];
    memset(v.pos,0,sizeof(int)*(K+1));
    v.PosChar=(char*)malloc(sizeof(char)*(K+1));
//    v.PosChar=new char[K+1];
//    memset(v.PosChar,'0',sizeof(char)*(K+1));
    /**
    属性type 一个for循环来存于指针中，
    **/


    for(int i=0;i<K;i++)    //K个确定位
    {
//        AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
        AttrPos=Attr_rnd(1536);    //每选择一个bit位随机选择某个属性
        if(i<type)
        {
            rnd1=rand_1();     //产生随机数  用于选择不同于原串的位
            diff[i]=rnd_q(rnd1);   //返回不同位  j
            v.pos[i]=diff[i]+AttrLength(AttrPos);      //不同位位置

//            while(v.pos[i]>AttrLength(collen.size())){
//            while(v.pos[i]>AttrLength(1536)){
////                AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
//                diff[i]=rnd_q(rand_1());
//                v.pos[i]=diff[i]+AttrLength(AttrPos);      //不同位位置
////                v.pos[i]=AttrLength(collen.size());
//            }

//            qDebug()<<"diff"<<diff[i];
            if(i>=1){
                for(int count=0;count<i;count++){
                    if(v.pos[i] == v.pos[count] ){
                        diff[i]=rnd_q(rand_1());   //若相同重新生成随机数
                        v.pos[i]=diff[i]+AttrLength(AttrPos);

//                        while(v.pos[i]>AttrLength(collen.size())){
//                        while(v.pos[i]>AttrLength(1536)){
////                            AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
//                            diff[i]=rnd_q(rand_1());
//                            v.pos[i]=diff[i]+AttrLength(AttrPos);      //不同位位置
////                            v.pos[i]=AttrLength(collen.size());
//                        }
                    }
                }
            }

            if(bstrdata->bData[singal_num].at(v.pos[i]) == '1' ){
                v.PosChar[i]='0';
                SurePos<<-v.pos[i];  //取反
            }
            else {
                v.PosChar[i]='1';
                SurePos<<v.pos[i];
            }
        }
        //K-type位于原串相同
        else{
            same[i]=Attr_rnd(BSData.collen_max);
//            same[i]=Same_q(rand_1());
            v.pos[i]=same[i]+AttrLength(AttrPos);

//            while(v.pos[i]>AttrLength(collen.size())){
//            while(v.pos[i]>AttrLength(1536)){
////                AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
//                same[i]=Attr_rnd(BSData.collen_max);
//                v.pos[i]=same[i]+AttrLength(AttrPos);      //不同位位置
////                v.pos[i]=AttrLength(collen.size());
//            }
            if(i>=1){
//                same[i]=Attr_rnd(BSData.collen_max);
                for(int count=0;count<i;count++){
                    if(v.pos[i] == v.pos[count]){
                       same[i]=Attr_rnd(BSData.collen_max);
//                        same[i]=Same_q(rand_1());
                       v.pos[i]=same[i]+AttrLength(AttrPos);

//                       while(v.pos[i]>AttrLength(collen.size())){
//                        while(v.pos[i]>AttrLength(1536)){
////                           AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
//                           same[i]=Attr_rnd(BSData.collen_max);
//                           v.pos[i]=same[i]+AttrLength(AttrPos);      //不同位位置
////                           v.pos[i]=AttrLength(collen.size());
//                       }
                    }
                }
            }
            if(bstrdata->bData[singal_num].at(v.pos[i]) == '1' ){
                v.PosChar[i]='1';
                SurePos<<v.pos[i];
            }
            else {
                v.PosChar[i]='0';
                SurePos<<-v.pos[i];
            }
        }

        /*将K个确定位位置记录下来*/

    }

    addToNDB(v,singal_num);
    delete [] v.pos;
    delete [] v.PosChar;
    delete [] diff;
    delete [] same;
}

/*文本类型负数据库确定位确定*/
void ToNDB::Generate_Random_Item_text(int type, int singal_num)
{
    double rnd1=0.0;
    int AttrPos=0;
    //初始化指针
    diff=new double[K+1];
    memset(diff,0.0,sizeof(double)*(K+1));
    same=new double[K+1];
    memset(same,0.0,sizeof(double)*(K+1));
    v.pos=new int[K+1];
    memset(v.pos,0,sizeof(int)*(K+1));
    v.PosChar=(char*)malloc(sizeof(char)*(K+1));

    for(int i=0;i<K;i++)    //K个确定位
    {
        AttrPos=Attr_rnd(collen.size());    //每选择一个bit位随机选择某个属性
        if(i<type)
        {
            rnd1=rand_1();     //产生随机数  用于选择不同于原串的位
            diff[i]=rnd_q(rnd1);   //返回不同位  j
            v.pos[i]=diff[i]+AttrLength_text(AttrPos);      //不同位位置
            while(v.pos[i]>=AttrLength_text(collen.size())){
                diff[i]=rnd_q(rand_1());
                v.pos[i]=diff[i]+AttrLength_text(AttrPos);      //不同位位置
            }
            if(i>=1){
                for(int count=0;count<i;count++){
                    if(v.pos[i] == v.pos[count] ){
                        diff[i]=rnd_q(rand_1());   //若相同重新生成随机数
                        v.pos[i]=diff[i]+AttrLength_text(AttrPos);

                        while(v.pos[i]>=AttrLength_text(collen.size())){
                            diff[i]=rnd_q(rand_1());
                            v.pos[i]=diff[i]+AttrLength_text(AttrPos);      //不同位位置
                        }
                    }
                }
            }

            if(bstrdata->bData[singal_num].at(v.pos[i]) == '1' ){
                v.PosChar[i]='0';
                SurePos<<-v.pos[i];  //取反
            }
            else {
                v.PosChar[i]='1';
                SurePos<<v.pos[i];
            }
        }
        //K-type位于原串相同
        else{
            if(AttrPos == collen.size()-1){
                same[i]=Attr_rnd(collen.at(collen.size()-1));
            }
            else{
               same[i]=Attr_rnd(BSData.collen_max);
            }
            v.pos[i]=same[i]+AttrLength_text(AttrPos);

            if(i>=1){
                for(int count=0;count<i;count++){
                    if(v.pos[i] == v.pos[count]){
                        if(AttrPos == collen.size()-1){
                            same[i]=Attr_rnd(collen.at(collen.size()-1));
                        }
                        else{
                           same[i]=Attr_rnd(BSData.collen_max);
                        }
                       v.pos[i]=same[i]+AttrLength_text(AttrPos);
                    }
                }
            }
            if(bstrdata->bData[singal_num].at(v.pos[i]) == '1' ){
                v.PosChar[i]='1';
                SurePos<<v.pos[i];
            }
            else {
                v.PosChar[i]='0';
                SurePos<<-v.pos[i];
            }
        }

        /*将K个确定位位置记录下来*/

    }

    addToNDB(v,singal_num);
    delete [] v.pos;
    delete [] v.PosChar;
    delete [] diff;
    delete [] same;
}

/*二进制串转化成负数据库*/
int ToNDB::ToNDBData(BStrData *bStrData, QList<QString>labels_ori,QString filetype)
{
    FileType=filetype;
    nDBs.clear();
    bstrdata=bStrData;  //获取二进制数据
    labels.clear();
    labels=labels_ori;
    m=bStrData->bData[0].length();     //二进制串的长度
    collen=bStrData->collen;   //传入二进制串各个属性的长度
    N=m*R;
    int type=0;

    qDebug()<<bStrData->bData.size()<<"条";
    qDebug()<<N<<"长"<<BSData.collen_max<<"bit"<<collen.size();
    qsrand(time(NULL));

    //文本类型对每条二进制串生成对应的负数据库
    if(filetype == "txt" || filetype == "csv")
    {
        for(int i=0;i<bStrData->bData.size();i++)   //所有二进制串
        {
            cn=0;
            nDB.nOne=new int[N+1];
            memset(nDB.nOne,0,sizeof(int)*(N+1));
            nDB.nZero=new int[N+1];
            memset(nDB.nZero,0,sizeof(int)*(N+1));
            nDB.nData.clear();    //此处要有，否则循环是一样结果
            //每条二进制串生成 N条负数据记录
            for(int j=0;j<N;j++)
            {
                double rnd=rand_1();    //产生0~1之间的随机数
                type=FindType(rnd);              //判断属于何种类型记录
                SurePos.clear();
                Generate_Random_Item_text(type, i);     //找出确定为的位置
            }
            nDBs<<nDB;
            /*计算每一条记录的期望值*/
            CNDBvalue.ENDBvalues(i,K,nDB,bStrData,P,q,filepath,filetype,labels);
        }
    }
    else{   //图片类型对每条二进制串生成对应的负数据库
        for(int i=0;i<bStrData->bData.size();i++)   //所有二进制串
        {
            cn=0;
            nDB.nOne=new int[N+1];
            memset(nDB.nOne,0,sizeof(int)*(N+1));
            nDB.nZero=new int[N+1];
            memset(nDB.nZero,0,sizeof(int)*(N+1));
            nDB.nData.clear();    //此处要有，否则循环是一样结果

            //每条二进制串生成 N条负数据记录
            for(int j=0;j<N;j++)
            {
    //            double rnd=(qrand()%100)*0.01;    //产生0~1之间的随机数
                double rnd=rand_1();    //产生0~1之间的随机数
                type=FindType(rnd);              //判断属于何种类型记录
                SurePos.clear();
                Generate_Random_Item(type, i,j);     //找出确定为的位置
    //            nDB.nData<<SurePos;

    //            if(j==1000){
    //                break;
    //            }
            }


            nDBs<<nDB;

            /*计算每一条记录的期望值*/
            CNDBvalue.ENDBvalues(i,K,nDB,bStrData,P,q,filepath,FileType,labels);

    //        delete [] nDB.nOne;
    //        delete [] nDB.nZero;

        }
    }
    return OK;

}

/*返回负数据*/
QList<NDB> ToNDB::getNDB()
{
    return nDBs;
}

int ToNDB::ToWriteFile(QString s)
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
        filename+="-NDB.csv";
        qDebug()<<filename;
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
        while(i<nDBs.size())
        {
            qDebug()<<nDBs.size()<<"条"<<m<<"二进制位";
            for(int j=0;j<bstrdata->bData[i].length()-1;j++){
                out<<nDBs[i].nZero[j]<<",";
            }
            out<<nDBs[i].nZero[bstrdata->bData[i].length()-1]<<"\n";
            for(int j=0;j<bstrdata->bData[i].length()-1;j++){
                out<<nDBs[i].nOne[j]<<",";
            }
            out<<nDBs[i].nOne[bstrdata->bData[i].length()-1]<<"\n";
            i++;
        }
      }
        file.close();
    }  //文本类型数据写入完成
    else{
        QStringList strs=s.split("array/");
//        QString name=strs[1];
//        QStringList strs1=name.split(".");
//        QString name1=strs1[0];   //获取图片名字

        QFileInfo info(s);
        QString name1 = info.completeBaseName();

        filename=strs[0]+"TestNDBData/"+name1+"-NDB.csv";
        qDebug()<<filename;
        QFile file(filename);
        if (file.open(QIODevice::Text|QFile::WriteOnly |QIODevice::Truncate)){
        QTextStream out(&file);
        int i=0;
        while(i<nDBs.size())
        {
            qDebug()<<nDBs.size()<<"条"<<m<<"二进制位";
            for(int j=0;j<bstrdata->bData[i].length()-1;j++){
                out<<nDBs[i].nZero[j]<<",";
            }
            out<<nDBs[i].nZero[bstrdata->bData[i].length()-1]<<"\n";
            for(int j=0;j<bstrdata->bData[i].length()-1;j++){
                out<<nDBs[i].nOne[j]<<",";
            }
            out<<nDBs[i].nOne[bstrdata->bData[i].length()-1]<<"\n";
            i++;
        }
      }
        file.close();
    }  //图片数据写入完成

    return OK;
}

