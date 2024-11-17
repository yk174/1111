#include <iostream>
#include <cmath>
#define N 10
using namespace std;
class Mat
{
public:
    int m = 1, n = 1;       // 行数和列数
    double mat[N][N] = {0}; // 矩阵开始的元素

    Mat() {}
    Mat(int mm, int nn)
    {
        m = mm;
        n = nn;
    }
    void create(); // 创建矩阵
    void Print();  // 打印矩阵
    void eye();    // 令矩阵行列下标相同时值为 1，不同时为 0

    bool inv(Mat a); // 求矩阵的逆
};

void Mat::create()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
}
void Mat::Print()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
void Mat::eye()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}
bool Mat::inv(Mat a)
{
    if (a.n != a.m)
    {
        cout << "矩阵不可逆" << endl;
        return false;
    }
    m = a.m;
    n = a.n;
    eye(); // 创建单位矩阵

    // 下来进行自上而下的初等行变换，使得矩阵 a.mat 变成单位上三角矩阵
    for (int i = 1; i <= m; i++) // 注意这里要 i<=m，和之前的上三角矩阵有不同
    {                            // 因为要判断最后一行化为上三角矩阵的最后一行最后一列元素是否为 0
        // 寻找第 i 列不为零的元素
        int k;
        for (k = i; k <= m; k++)
        {
            if (fabs(a.mat[k][i]) > 1e-10) // 满足这个条件时，认为这个元素不为0
                break;
        }
        if (k <= m) // 说明第 i 列有不为0的元素
        {
            if (k != i) // 说明第 i 行 第 i 列元素为零，需要和其他行交换
            {
                // 交换第 i 行和第 k 行所有元素
                for (int j = 1; j <= n; j++) // 需从第一个元素交换，注意与之前化上三角矩阵不同
                {                            // 使用mat[0][j]作为中间变量交换元素,两个矩阵都要交换
                    a.mat[0][j] = a.mat[i][j];
                    a.mat[i][j] = a.mat[k][j];
                    a.mat[k][j] = a.mat[0][j];
                    mat[0][j] = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = mat[0][j];
                }
            }
            double b = a.mat[i][i]; // 倍数
            // 将矩阵 a.mat 的主对角线元素化为 1
            for (int j = 1; j <= n; j++) // 从第一个元素开始
            {
                a.mat[i][j] /= b;
                mat[i][j] /= b;
            }
            for (int j = i + 1; j <= m; j++)
            {
                // 注意本来为 -a.mat[j][i]/a.mat[i][i],因为a.mat[i][i]等于 1，则不需要除它
                b = -a.mat[j][i];
                for (k = 1; k <= n; k++)
                {
                    a.mat[j][k] += b * a.mat[i][k]; // 第 i 行 b 倍加到第 j 行
                    mat[j][k] += b * mat[i][k];
                }
            }
        }
        else
        {
            cout << "矩阵不可逆" << endl;
            return false;
        }
    }

    // 下面进行自下而上的行变换，将 a.mat 矩阵化为单位矩阵
    for (int i = m; i > 1; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            double b = -a.mat[j][i];
            a.mat[j][i] = 0; // 实际上是通过初等行变换将这个元素化为 0,
            for (int k = 1; k <= n; k++)
            { // 通过相同的初等行变换来变换右边矩阵
                mat[j][k] += b * mat[i][k];
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "请输入n的值" << endl;
    cin >> n;
    Mat a(n, n);
    cout << "请输入 " << a.m << "*" << a.n << " 的矩阵：" << endl;
    a.create();

    Mat b;
    if (b.inv(a))
        b.Print();
    return 0;
}