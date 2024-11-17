#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define maxn 10005
#define mod 7654321

void shuzi(string a)
{
    int pos = a.length() - 1;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] != '0')
        {
            pos = i;
            break;
        }
    }

    for (int i = pos; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
}
void dian(string a, int b) // 605//09.34//0.00//900.890
{
    int k = -1;
    int num = -1;
    for (int i = b - 1; i >= 0; i--)
    {
        if (a[b - 1] != '0')
        {
            num = 0;
            cout << a[i];
        }
        else if (a[i] != '0')
        {
            k = i;
            num = 1;
            break;
        }
    }
    if (k != -1 && num == 1)
    {
        for (int i = k; i >= 0; i--)
        {
            cout << a[i];
        }
    }
    if (num == -1)
        cout << 0;

    cout << "."; //.9860
    k = -1;
    int j = a.length() - 1;
    num = -1;
    int pos = a.length() - 1;
    for (int i = a.length() - 1; i > b; i--)
    {
        if (a[i] != '0')
        {
            pos = i;
            break; // 600.00980
        }
    }
    // cout<<pos<<endl;
    for (int i = b + 1; i <= pos; i++)
    {
        if (a[b + 1] != '0')
        {
            num = 0;
            cout << a[j--];
        }
        else if (a[i] != '0')
        {
            k = i;
            num = 1;
            break;
        }
    }
    if (k != -1 && num == 1)
    {
        for (int i = pos; i >= k; i--)
        {
            cout << a[i];
        }
    }
    if (num == -1)
        cout << 0;
}
void chufa(string a, int b) // 700/27
{
    int k = -1;
    int num = -1;
    for (int i = b - 1; i >= 0; i--)
    {
        if (a[b - 1] != '0')
        {
            num = 0;
            cout << a[i];
        }
        else if (a[i] != '0')
        {
            k = i;
            num = 1;
            break;
        }
    }
    if (k != -1 && num == 1)
    {
        for (int i = k; i >= 0; i--)
        {
            cout << a[i];
        }
    }
    if (num == -1)
        cout << 0;
    cout << "/";
    k = -1;
    int j = a.length() - 1;
    num = -1;
    int pos = a.length() - 1;
    for (int i = a.length() - 1; i > b; i--)
    {
        if (a[i] != '0')
        {
            pos = i;
            break;
        }
    }
    for (int i = b + 1; i < a.length(); i++) // 600.084
    {
        if (a[b + 1] != '0')
        {
            num = 0; // cout<<a[j--];
        }
        else if (a[i] != '0')
        {
            k = i;
            num = 1;
            break;
        }
    }
    if (num == 0)
    {
        for (int i = pos; i > b; i--)
            cout << a[i];
    }
    // cout<<pos<<endl;
    if (k != -1 && num == 1)
    {
        for (int i = pos; i >= k; i--)
        {
            cout << a[i];
        }
    }
    if (num == -1)
        cout << 0;
}
void quyu(string a, int b) // 8670%
{
    int k = -1;
    int num = -1;
    for (int i = b - 1; i >= 0; i--)
    {
        if (a[b - 1] != '0')
        {
            num = 0;
            cout << a[i];
        }
        else if (a[i] != '0')
        {
            k = i;
            num = 1;
            break;
        }
    }
    if (k != -1 && num == 1)
    {
        for (int i = k; i >= 0; i--)
        {
            cout << a[i];
        }
    }
    if (num == -1)
    {
        cout << 0;
    }

    cout << "%";
}

int main()
{
    string a;
    int fuhao[4] = {0}; //. / %
    int b, c, d;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '.')
            fuhao[1] = 1, b = i;
        if (a[i] == '/')
            fuhao[2] = 1, c = i;
        if (a[i] == '%')
            fuhao[3] = 1, d = i;
    }

    if (fuhao[1] == 0 && fuhao[2] == 0 && fuhao[3] == 0)
        shuzi(a);
    if (fuhao[1])
        dian(a, b);
    if (fuhao[2])
        chufa(a, c);
    if (fuhao[3])
        quyu(a, d);

    return 0;
}
