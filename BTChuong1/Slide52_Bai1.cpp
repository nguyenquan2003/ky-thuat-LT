#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "nhap 3 so nguyen a,b,c : " << endl;
	cin >> a >> b >> c;
	try
	{
		if (a == b) throw 1;
		cout << "ket qua : " << (float)c / (a - b);
	}
	catch (int n)
	{
		cout << "chia cho 0 ";
	}
	return 0;
}