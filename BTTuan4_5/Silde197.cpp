#include <iostream>
using namespace std;
void nhap(int a[][50], int& dong, int& cot)
{
	do
	{
		cout << "cho biet so dong cua mang : ";
		cin >> dong;
	} while (dong <= 0);
	do
	{
		cout << "cho biet so cot cua mang : ";
		cin >> cot;
	} while (cot <= 0);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "Gia tri phan tu a " << "[" << i << "]" << "[" << j << "] =";
			cin >> a[i][j];

		}
	}
}
void xuat(int a[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
			cout << "\t" << a[i][j];
		cout << endl;
	}
}
void Tinh_Duong_Cheo_Chinh(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int i = 0; i < cot; i++)
	{
		tong += a[i][i];
	}
	cout << "tong duong cheo chinh la " << tong;
}
void Tinh_Duong_Cheo_Phu(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int j = 0; j < dong; j++)
	{
		tong += a[j][dong - 1 - j];
	}
	cout << "tong duong cheo chinh la " << tong;
}
int Tong_Ptu_Dgcheo_Chinh(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (i < j)
				tong += a[i][j];

		}
	}
	cout << "tong cac phan tu tren duong cheo chinh la : " << tong;
	return tong;
}
int Tong_Ptu_Dgcheo_Phu(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (i > j)
				tong += a[i][j];
		}
	}
	cout << "tong cac phan tu tren duong cheo phu la : " << tong;
	return tong;
}
int main()
{
	int dong, cot, a[50][50], chon;
	cout << "==============MENU=============="<<endl;
	cout << "1. tinh tong cac phan tu nam tren duong cheo chinh  " << endl;
	cout << "2. tinh tong cac phan tu nam tren duong cheo phu  " << endl;
	cout << "3. tinh tong cac phan tu nam phia tren duong cheo chinh " << endl;
	cout << "4. tinh tong cac phan tu nam phia tren duong cheo phu " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	nhap(a, dong, cot);
	switch (chon)
	{
	case 1: xuat(a, dong, cot);
		Tinh_Duong_Cheo_Chinh(a, dong, cot);
		break;
	case 2: xuat(a, dong, cot);
		Tinh_Duong_Cheo_Phu(a, dong, cot);
		break;
	case 3: xuat(a, dong, cot);
		Tong_Ptu_Dgcheo_Chinh(a, dong, cot);
		break;
	case 4 : xuat(a, dong, cot);
		Tong_Ptu_Dgcheo_Phu(a, dong, cot);
		break;
	default: cout << "ban nhap sai cu phap moi ban nhap lai ";
		break;
	}
}