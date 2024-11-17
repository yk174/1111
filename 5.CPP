#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Vector
{

private:
    double x;
    double y;

public:
    Vector(double x, double y) : x(x), y(y) {}

    Vector add(const Vector &other) const
    {
        return Vector(this->x + other.x, this->y + other.y);
    }

    void print() const
    {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }

    void dir() const
    {
        double mo = sqrt(x * x + y * y);
        cout << "向量之和x=" << x << "，y=" << y << endl
             << "模长为" << mo << endl;
    }
};

int main()
{
    int input[4] = {0};         // 初始化数组
    for (int i = 0; i < 4; ++i) // 输入
    {
        cin >> input[i];
    }
    Vector v1(input[0], input[1]);
    Vector v2(input[2], input[3]);

    Vector v3 = v1.add(v2);
    v3.dir();
    return 0;
}