#include <iostream>
using namespace std;
void interchangeSort_int_tang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void interchangeSort_int_giam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}
void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}
void xuat(int a[])
{
	cout << "xuat mang : ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << "\t";
	}
}
void interchangeSort_float_tang(float b[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (b[i] > b[j])
				swap(b[i], b[j]);
}
void xuat(float b[])
{
	cout << "xuat mang : ";
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << "\t ";
	}
}
void interchangeSort_float_giam(float b[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (b[i] < b[j])
				swap(b[i], b[j]);
}
void main()
{
	int d, a[5] = { 4, 6, 9, 2, 3 };
	float b[5] = { 4.5, 6.2, 9.7, 2.8, 3.8 };
	cout << "------------MENU------------" << endl;
	cout << "1. sap xep tang dan theo so nguyen " << endl;
	cout << "2. sap xep tang dan theo so thuc " << endl;
	cout << "3. sap xep giam dan theo so thuc " << endl;
	cout << "4. sap xep giam dan theo so nguyen " << endl;
	cout << "moi ban chon bai : " ;
	cin >> d;
	switch (d)
	{
	case 1:  interchangeSort_int_tang(a, 5);
		xuat(a);
		break;
	case 2:  interchangeSort_float_tang(b, 5);
		xuat(b);
		break;
	case 3: interchangeSort_float_giam(b, 5);
		xuat(b);
		break;
	case 4:  interchangeSort_int_giam(a, 5);
		xuat(a);
		break;
	default: cout << "ban nhap sai cu phap moi ban nhap lai ";
		break;
	}
}