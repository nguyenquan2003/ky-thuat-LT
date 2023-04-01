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
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
void Xoa(int a[], int& n, int vtxoa)
{
	for (int i = vtxoa; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void Them(int a[], int& n, int x, int k)
{
	n++;
	for (int i = n - 1; i > k; i--)
		a[i] = a[i - 1];

	a[k] = x;
}
int main()
{
	int d, a[100], vtxoa, x, k, n;
	cout << "------------MENU------------" << endl;
	cout << "1. xoa phan tu tai vi tri k " << endl;
	cout << "2. them phan tu x tai vi tri k " << endl;
	cout << "nhap so phan tu : ";
	cin >> n;
	cout << "moi ban chon bai : ";
	cin >> d;
	switch (d)
	{
	case 1: Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		cout << "nhap vi tri can xoa : ";
		cin >> vtxoa;
		Xoa(a, n, vtxoa);
		cout << "mang sau khi da xoa la : ";
		Xuat(a, n);
		break;
	case 2:  Nhap(a, n);
		cout << "\nNhap phan tu can chen: ";
		cin >> x;
		cout << "Nhap vi tri can chen: ";
		cin >> k;
		Them(a, n, x, k);
		cout << "Mang sau khi chen: " << endl;
		Xuat(a, n);
		return 0;
		break;
	default: cout << "ban nhap sai moi ban chon lai ";
		break;
	}
}