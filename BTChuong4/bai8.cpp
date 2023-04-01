#include <iostream>
using namespace std;
int bai_8(int n)
{
    if(n == 1)
        return 1;
    int tich = 1;
    for(int i = 1; i <= n; i++)
    {
        tich *= i;
    }
    return bai_8(n - 1) + tich;
}
int main()
{
    int n;
    cout << "nhap n = ";
    cin >> n;
    cout << "S = " << bai_8(n);
}
