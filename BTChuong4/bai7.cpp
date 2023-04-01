#include <iostream>
using namespace std;
int bai_7(int n)
{
    if (n == 1)
        return 1;
    return bai_7(n - 1) + n * n;
}
int main()
{
    int n;
    cout << "nhap n = ";
    cin >>n;
    cout << "S= "<<bai_7(n);
}
