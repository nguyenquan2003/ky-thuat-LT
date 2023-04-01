#include <iostream>
using namespace std;
void Nhap(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> a[i];
	}
}
void Xuat(int a[], int n)
{
	cout << "xuat mang ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
void timMax(int a[], int n)
{
	int* max = &a[0];
	for (int i = 0; i < n; i++)
	{
		if (*max < a[i])
			*max = a[i];
	}
	cout << " Max =  " << *max << endl;
	cout<<"dia chi cua Max la : "<< &max << endl;
}
void timMin(int a[], int n)
{
	int* min = &a[0];
	for (int i = 0; i < n; i++)
	{
		if (*min > a[i])
			*min = a[i];
	}
	cout << " Min =  " << *min << endl;
	cout << "dia chi cua Min la : " << &min << endl;
}
int main()
{
	int a[30], n;
	cout << "nhap n = ";
	cin >> n;
	Nhap(a, n);
	Xuat(a, n);
	timMax(a, n);
	timMin(a, n);
}