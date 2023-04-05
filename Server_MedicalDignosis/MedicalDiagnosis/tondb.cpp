#include"tondb.h"
#include<QDebug>
#include<QFile>
#include<ctime>
#include"global.h"
using namespace std;

ToNDB::ToNDB()
{

}

double ToNDB::rand_1()
{
     srand((unsigned)time(NULL));    //随机数种子
     return (rand()%100)*0.01;    //产生0~1之间的随机数
}

//参数初始化
int ToNDB::SetNDB(int Kx, QList<double> Px,QList<double> qx, int Rx)
{
    K=Kx;
    R=Rx;
    double temp=0.0;
    double temp_q=0.0;
    for(int i=0;i<=K;i++)
    {   //获取概率P并计算反转概率Qi
        P<<Px[i];
        temp+=Px[i];
        Q<<temp;
    }

    for(int i=0;i<=BSData.collen_max;i++){
        q<<qx[i];
        temp_q += qx[i];
        Q_q<<temp_q;
        Same<<1-temp_q;
    }

    flag={false};

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

/*计算反转位并返回j*/
int ToNDB::rnd_q(double rnd1)
{
    for(int j=1;j<=BSData.collen_max;j++){   //从1开始
        if(Q_q[j]>rnd1){
            return j;   //返回类型i
        }
    }
    return BSData.collen_max;
}

/*相同的位*/
int ToNDB::Same_q(double rnd1)
{
    for(int j=1;j<=BSData.collen_max;j++){   //从1开始
        if(Same[j]>rnd1){
            return j;   //返回类型i
        }
    }
    return BSData.collen_max;
}

/*随机生成type个确定位于原串不同，k-type相同**/
void ToNDB::Generate_Random_Item(int type,int i)   //第i条记录
{
    int singal_num=i;
    int count=0;
    int Postemp;
    while(count<K)
    {
        if(count<type)
        {  //生成I个与原字符串不同的位
            if(count==0)
            {
                diff<<rnd_q(rand_1());
                Postemp=FindPos(diff.at(count));
                if(!flag.at(Postemp))
                {
                    flag[Postemp]=true;
                    v.pos[count]=Postemp;
//                    v.PosChar[count]='0'+'1'-BSData.bData.at(singal_num).at(Postemp);
                    count++;
                }
            }

            else{
                int DIFF=0;
                DIFF=rnd_q(rand_1());
                if(DIFF == diff.at(count-1))
                {
                      DIFF=rnd_q(rand_1());
                }
                diff<<DIFF;
                Postemp=FindPos(diff.at(count));
                if(!flag.at(Postemp))
                {
                    flag[Postemp]=true;
                    v.pos[count]=Postemp;
//                    v.PosChar[count]='0'+'1'-BSData.bData.at(singal_num).at(Postemp);
                    count++;
                }
            }
        }
        else{   //随机选择K-i个相同
            int same=0+(int)BSData.collen_max*rand()/(RAND_MAX+1);  //产生随机数
            for(int i=0;i<diff.size();i++){
                if(same==diff.at(i)){
                    same=0+(int)BSData.collen_max*rand()/(RAND_MAX+1);
                }
            }
            Postemp=same+sameattr;
            if(!flag.at(Postemp)){
                flag[Postemp]=true;
                v.pos[count]=Postemp;
                v.PosChar[count]=BSData.bData.at(singal_num).at(Postemp);
                count++;
        }
    }
  }
}

void ToNDB::addToNDB(Ent x)
{

        for (int i = 0; i < K; i++)
        {
            NDB[cn].pos[i]=x.pos.at(i);
            NDB[cn].PosChar[i]=x.PosChar.at(i);
        }
        cn++;
        qDebug()<<cn;
}

/*二进制串转化成负数据库*/
int ToNDB::ToNDBData(BStrData *bStrData, QList<QString> labels_ori)
{
    labels.clear();
    labels=labels_ori;
//    nDBs.clear();
    m=bStrData->bData[0].length();     //二进制串的长度
    collen=bStrData->collen;   //传入二进制串各个属性的长度
    N=m*R;
    int type=0;
    BSData.collen_max=bStrData->collen_max;

    qDebug()<<N<<"长"<<BSData.collen_max<<"bit"<<collen.size();

    //计算属性位大于或者等于I的个数
    for(int i=0;i<BSData.collen_max;i++){
        for(int j=0;j<collen.size();j++)
        {

            if(collen.at(j)>=i+1){
                attrNum[i]<<j;
//                qDebug()<<i<<"ge";
            }
        }
        qDebug()<<i<<"ge";
    }

    srand((unsigned)time(NULL));    //随机数种子
    //对每条二进制串生成对应的负数据库
    for(int i=0;i<bStrData->bData.size();i++)   //所有二进制串
    {
//        NDB nDB;
//        nDB.nOne=new int(m+1);
//        memset(nDB.nOne,0,sizeof(int)*(m+1));
//        nDB.nZero=new int(m+1);
//        memset(nDB.nZero,0,sizeof(int)*(m+1));

        //每条二进制串生成 N条负数据记录
        for(int j=0;j<N;j++)
        {
            double rnd=(rand()%100)*0.01;    //产生0~1之间的随机数
            type=FindType(rnd);
            qDebug()<<type<<"类";
            Generate_Random_Item(type, i);
            addToNDB(v);
        }
    }
    return OK;

}


void ToNDB::test()
{
    for (int i = 0; i < cn; i++)
        {
            for (int j = 0; j < K; j++)
            {
                if (NDB.at(i).PosChar.at(j) == '1')
                    qDebug()<<"-";
                qDebug()<<NDB.at(i).pos.at(j)+1;

            }
            qDebug()<<"\n";
        }
}
