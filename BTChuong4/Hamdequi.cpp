#include <iostream>
#include <cmath>
using namespace std;
long bai_1(int n)
{
    if (n == 0)
        return 0;
    return bai_1(n - 1) + n;
}
float bai_2(int n)
{
    if (n == 1)
        return sqrt(2.0);
    return sqrt(2 + bai_2(n - 1));
}
float bai_3(int n) 
{
    if (n == 1)
        return 0.5;
    return bai_3(n - 1) + (float)n / (n + 1);
}
long bai_4(int n)
{
    if (n == 0)
        return 1;
    return bai_4(n - 1) + 1 / ((2 * n) + 1);
}
long bai_5(int n)
{
    if (n == 1)
        return 1;
    return bai_5(n - 1) + n * (n + 1);
}
long bai_6(int n)
{
    if (n == 1)
        return 1;
    return bai_6(n - 1) + 1 / ((n) * (n + 1) * (n + 2));
}
//long bai_9(int n)
//{
//    if (n == 1)
//        return 1;
//    bai_9(n-1)+
//}
long bai_11(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return bai_11(n - 1) + bai_11(n - 2);
}
int main()
{
    int n,chon;
    cout << "nhap n =";
    cin >> n;
    cout << "moi ban chon bai : ";
    cin >> chon;
    switch (chon)
    {
    case 1: cout<<"S= "<<bai_1(n);
        break;
    case 2: cout << "S= " << bai_2(n);
        break;
    case 3: cout << "S= " << bai_3(n);
        break;
    case 4: cout << "S= " << bai_4(n);
        break;
    case 5: cout << "S= " << bai_5(n);
        break;
    case 6: cout << "S= " << bai_6(n);
        break;
    case 11: cout << "F= "<<bai_11(n);
        break;
    default:
        break;
    }
}