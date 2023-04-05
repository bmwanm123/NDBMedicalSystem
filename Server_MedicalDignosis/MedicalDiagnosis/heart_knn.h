#ifndef HEART_KNN_H
#define HEART_KNN_H
#include<global.h>
#include<QMap>
using namespace std;
typedef pair<int, double>  PAIR;  //pair将一対值组合成一个值

class HEART_KNN{
public:
    int ReadNDBData(QString filepath);  //读取负数据库期望值文件
    void ReadLabel();    //读取标签
    void SetKnn_k(int k);     //设置分类参数k
    QList<double> getNDBValue(QStringList qStrList);  //获取value数据
    int startKNN(double testdataRate);      //KNN分类
    int dataSetSplit(double testdataRate);   //分割数据
    void datatest();      //对分割后的数据进行测试
    string getMaxFreqLabel(int valueIndex);   //判断测试数据属于哪类标签

    //比较辅助类，相当于java中的compara函数
    struct CmpByValue
    {
        bool operator() (const PAIR& lhs, const PAIR& rhs)
        {
            return lhs.second < rhs.second;
        }
    };

    double EuclidDis_NDB(int ndbindex,int testindex);  //计算训练数据和测试数据的距离
    map<string, vector<int>> getResult();      //获取分类结果
    double getAccuracyRate();       //计算分类精度
    void resetVariable();  //重置

private:
    //knn算法参数k
    int Knn_k;

    //存储lable
    QList<string> labels;

    QList<Label> labels1;

    //测试数据
    QList<int> testData;

    //训练数据
    QList<int> trainData;

    //存放期望值
    QList<QList<double>> Dvalues;

    //测试结果
    map<string, vector<int>> testResult;

    //存储训练数据和测试数据之间的欧式距离
    map<int, double> mapIndexDis;

    //准确率
    double accuracy;

};

#endif // HEART_KNN_H
