#include"heart_knn.h"
#include<QDebug>
#include<QFile>
#include<algorithm>
#include<math.h>
#include<QString>
#include<QStringList>
using namespace std;


/*获取一行的期望值*/
QList<double> HEART_KNN::getNDBValue(QStringList qStrList)
{
    QList<double>tmpList;
    for(int i=0;i<qStrList.size();i++)
    {
//        tmpList.push_back(qStrList);
        tmpList<<qStrList.at(i).toDouble();
    }
    return tmpList;
}

/*读取负数据库期望值文件*/
int HEART_KNN::ReadNDBData(QString filepath)
{
    resetVariable();
    QFile file(filepath);
    qDebug()<<filepath<<"路径";
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"错误";
        return NO;
    }
    QTextStream in(&file);
    QString LN=in.readLine();
    QString LP=in.readLine();

    QStringList LNs=LN.split(",");
    QStringList LPs=LP.split(",");
    qDebug()<<LNs.size();

    for(int i=0;i<LNs.size();i++)
    {
        Label label;
        label.labelName=LNs.at(i);
        label.labelPos=LPs.at(i).toInt();
        labels1<<label;
    }

    //获取标签
    ReadLabel();

    //读取负数据期望值
    QString str;
    QStringList strlist;
    int count=0;
    while(!in.atEnd())
    {
        str = in.readLine();
        if(str.isEmpty())
            break;
        strlist = str.split(',');  //获取一行中的每一个数据

        Dvalues<<(getNDBValue(strlist));
        count++;
    }
//    file.close();
    qDebug()<<count<<"个";
    return OK;
}

/*读取标签函数*/
void HEART_KNN::ReadLabel()
{
//    int j=0;
    for(int i=0;i<labels1.size();i++)
    {
        for(int j=0;j<=labels1[i].labelPos;j++)
        {
            string temp = labels1[i].labelName.toStdString();
            labels.append(temp);
        }
    }
}

/*获取分类参数k*/
void HEART_KNN::SetKnn_k(int k)
{
    Knn_k=k;
}

/*进行KNN分类  testdatarate为测试数据占比*/
int HEART_KNN::startKNN(double testdataRate)
{

    //根据testdataRate分割数据
    if(dataSetSplit(testdataRate) == NO)
    {
        return NO;
    }

    //对分割后的数据进行测试
    datatest();

    return OK;
}

/*分割数据*/
int HEART_KNN::dataSetSplit(double testdataRate)
{
    if(testdataRate > 0.25)
    {
        return NO;
    }
    QList<int>temp;
    for(int i=0;i<Dvalues.size();i++)
    {
        temp<<i;    //顺序存储下标
    }

    //将下标随机打乱
    random_shuffle(temp.begin(),temp.end());

    int testDataSize = Dvalues.size()*testdataRate;  //测试数据长度
    for(int i=0;i<testDataSize;i++)
    {
        testData<<(temp[i]);   //存储测试数据在Dvalues中的下标
    }
    for(int i=testDataSize;i<Dvalues.size();i++)
    {
        trainData<<(temp[i]);    //存储训练数据的下标
    }

    return OK;
}

/*对分割后的数据进行测试*/
void HEART_KNN::datatest()
{
    //对于每一个testData,传入getMaxFreqLabel函数，获取对应的label,然后作为结果返回
    for (int i = 0; i < testData.size(); i++)
    {
        //存储某类标签下对应的负数据集下标
       testResult[getMaxFreqLabel(testData[i])].push_back(testData[i]);
    }
}

/*判断dvalue的测试结果属于哪类标签*/
string HEART_KNN::getMaxFreqLabel(int valueIndex)
{
    //计算测试数据与每个训练数据之间的距离
    for(int i=0;i<trainData.size();i++)
    {
        mapIndexDis[trainData[i]] = EuclidDis_NDB(trainData[i],valueIndex);
    }

    //将map类型转化为pair以便排序
    vector<PAIR> vecIndexDis(mapIndexDis.begin(),mapIndexDis.end());

    //排序
    sort(vecIndexDis.begin(), vecIndexDis.end(), CmpByValue());

    //对距离最近的k个元素进行类别统计
    map<string, int> labelCount;
    for (int i = 0; i < Knn_k; i++) {
        labelCount[labels[vecIndexDis[i].first]]++;
    }

    //求得数量最大的类别
    map<string, int>::const_iterator mapIt = labelCount.begin();
    string finalLabel;
    int maxFreq = 0;

    while (mapIt != labelCount.end())
    {
        if (mapIt->second > maxFreq)
        {
            maxFreq = mapIt->second;
            finalLabel = mapIt->first;
        }
        mapIt++;
    }

    return finalLabel;
}

/*欧式距离计算*/
double HEART_KNN::EuclidDis_NDB(int ndbindex, int testindex)
{
    double Eudistance = 0.0;
    QList<double>TestData = Dvalues[testindex];
    QList<double>ndbdata = Dvalues[ndbindex];

    for(int i=0;i<TestData.size();i++)
    {
        Eudistance += pow((TestData[i] - ndbdata[i]) , 2.0);
    }
    Eudistance = sqrt(Eudistance);
    return Eudistance;
}

/*获取分类结果*/
map<string,vector<int>> HEART_KNN::getResult()
{
    return testResult;
}

/*计算分类精度*/
double HEART_KNN::getAccuracyRate()
{
    double totalData = testData.size();
    double rightData = 0.0;

    map<string, vector<int>>::iterator iter = testResult.begin();

    while (iter != testResult.end()) {
        string label = iter->first;
        vector<int> testData = iter->second;

        for (int i = 0; i < testData.size(); i++) {
            if (labels[testData[i]] == label) {
                rightData += 1;
            }
        }

        iter++;
    }

    accuracy = rightData / totalData;

    return accuracy;
}

void HEART_KNN::resetVariable()
{
    labels1.clear();
    labels.clear();
    testData.clear();
    trainData.clear();
    Dvalues.clear();
    testResult.clear();
//    accuracy = 0;
}
