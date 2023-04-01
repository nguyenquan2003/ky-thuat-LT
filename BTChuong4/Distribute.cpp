#include <iostream>
using namespace std;
int distribute(int m, int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (m == 0)
		return 1;
	if (m < n)
		return distribute(m, m);
	return distribute(m, n - 1) + distribute(m - n, n);
}
int main()
{
	int m, n;
	cout << "nhap n = ";
	cin >> n;
	cout << "nhap m = ";
	cin >> m;
	cout<<distribute(m, n);
}