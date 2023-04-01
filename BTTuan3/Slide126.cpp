#include <iostream>
using namespace std;
void Nhap(int a[], int n)
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
	cout << endl;
}
void Tinh_Tong(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong = tong + a[i];
	}
	cout << "tong cua cac phan tu la : " << tong;
}
int Kt_So_Nt(int n) 
{
	if (n < 2)
		return 0;
	else
	{
		for (int i = 2; i <= n / 2; i++)
			if (n % i == 0)
				return 0;
		return 1;
	}
}
void Xuat_So_Nt(int a[], int n)
{
	cout << "\nCac so nguyen to co trong mang : " ;
	for (int i = 0; i < n; i++)
	{
		if (Kt_So_Nt(a[i]))
		cout << a[i]<<"\t";
	}
	cout << endl;
}
void Xuat_So_Chan(int a[], int n)
{
	cout << "cac so chan la : ";
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i]<<"\t";
		}
	}
	cout << endl;
}
void Xuat_So_Le(int a[], int n)
{
	cout << "cac so le la : ";
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			cout << a[i] << "\t";
		}
	}
	cout << endl;
}
int Dem_Phan_Tu(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
			dem++;
	}
	cout << "so lan phan tu x co trong mang : "<<dem<<endl;
	return dem;
}
bool KiemTraSHT(int x)
{
	int i, tong = 0;
	for (i = 1; i < x; i++)
		if (x % i == 0)
			tong = tong + i;
	if (tong == x)
		return true;
	return false;
}
int TongPTSHT(int a[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (KiemTraSHT(a[i]) == true)
			tong = tong + a[i];
	}
	cout << "so hoan thien la : "<<tong;
	return tong;
	return -1;
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
	cout << "dia chi cua Max la : " << &max << endl;
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
	int a[30], n,d;
	cout << "------------MENU------------" << endl;
	cout << "1. tinh tong cac phan tu  " << endl;
	cout << "2. xuat cac so nguyen to " << endl;
	cout << "3. xuat cac phan tu o vi tri chan/le " << endl;
	cout << "4. dem so phan tu lon hon x " << endl;
	cout << "5. xuat cac so hoan thien " << endl;
	cout << "6. xuat gia tri max/min kem theo vi tri trong mang " << endl;
	cout << "nhap n = ";
	cin >> n;
	cout << "moi ban chon bai : ";
	cin >> d;
	switch (d)
	{
	case 1: Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		Tinh_Tong(a, n);
		break;
	case 2: Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		Xuat_So_Nt(a, n);
		break;
	case 3: Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		Xuat_So_Chan(a, n);
		Xuat_So_Le(a, n);
		break;
	case 4: int x;
		Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		cout << "nhap x = ";
		cin >> x;
		Dem_Phan_Tu(a, n, x);
		break;
	case 5: Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		TongPTSHT(a, n);
		break;
	case 6 : Nhap(a, n);
		cout << "xuat mang vua nhap : ";
		Xuat(a, n);
		timMax(a, n);
		timMin(a, n);
		break;
	default: cout << "ban nhap sai moi ban chon lai ";
		break;
	}
}