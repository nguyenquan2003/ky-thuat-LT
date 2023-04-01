#include <iostream>
#include <cmath>
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
int Tinh_Tong(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int i = 0; i < dong; i++)
	{
		tong= tong + a[i][0] + a[i][cot - 1];
	}
	for (int j = 1; j < cot - 1; j++)
	{
		tong = tong + a[0][j] + a[dong - 1][j];
	}
	cout << " tong cac gia tri tren bien la : "<<tong;
	return tong;
}
void Timx(int a[][50], int dong, int cot, int x)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] == x)
				cout << "\n a " << "[" << i << "]" << "[" << j << "] =" << a[i][j];
		}
	}
}
int DemSoLanXuatHienCuaX(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			dem++;
		}
	}
	return dem;
}
int KiemTraHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			tong += i;
		}
	}
	if (tong == n)
	{
		return 1;
	}
	return 0;
}
void xuat_So_HT(int a[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraHoanThien(a[i][j]) == 1)
			{
				cout << a[i][j] << " ";
			}
		}
	}
}
int TimChuSoDauLe(int n)
{
	int dv;
	while (n >= 10)
	{
		dv = n % 10;
		n = n / 10;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	return 1;
}
int Liet_Ke_Vi_Tri_Chu_So_Dau_Le(int a[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (TimChuSoDauLe(a[i][j]) == 1)
			{
				return a[i][j];
			}
		}
		return 0;
	}
}
int Tinh_Tong_So_Le(int a[][50], int dong, int cot)
{
	int tong = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (TimChuSoDauLe(a[i][j]) == 1)
			{
				tong += a[i][j];
			}
		}
	}
	cout << "tong cac phan tu co chu so dau la : " << tong << endl;
	return tong;
}
int Tim_So_Chan(int a[][50], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 == 0)
			{
				dem++;
			}
		}

	}
	cout << "cac so chan la : " << dem<<endl;
	return dem;
}
void Tim_So_Am(int a[][50], int dong, int cot)
{
	cout << "cac so am la : ";
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] < 0)
			{
				cout << a[i][j] << "  ";
			}
		}

	}
}
void Tim_So_Duong(int a[][50], int dong, int cot)
{
	cout << "cac so duong la : ";
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] < 0)
			{
				cout << a[i][j] << "  ";
			}
		}

	}
}
int Tim_So_Le(int a[][50], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				dem++;
			}
		}

	}
	cout << "cac so le la : " << dem<<endl;
	return dem;
}
int KiemTraNguyenTo(int n)
{
	if (n < 2)
	{
		return 0;
	}
	else if (n > 2)
	{
		if (n % 2 == 0)
		{
			return 0;
		}
		for (int i = 3; i <= sqrt((float)n); i += 2)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
int Tim_So_Nguyen_To(int a[][50], int dong, int cot)
{
	int dem = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraNguyenTo(a[i][j]) == 1)
			{
				dem++;
			}
		}
	}
	cout << "cac so nguyen to la : " << dem;
	return dem;
}
int tongCacPhanTuLonHonTriTuyetDoiPhiaSauNo(int a[][50], int dong, int cot)
{
	int sum = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (j < cot - 1)
			{
				if (a[i][j] > abs(a[i][j + 1]))
				{

					sum += a[i][j];
				}
			}
			else //j == cot - 1
			{
				if (a[i][j] > abs(a[i + 1][0]))
				{
					cout << "i= " << i << ", j= " << j << endl;

				}
			}
		}
	}
	return sum;
}
int Tong_Dongk(int a[][50], int dong, int cot, int& k)
{
	int tong = 0;
	for (int j = 0; j < cot; j++)
	{
		tong += a[k][j];
	}
	cout << " tong gia tri k la: " << tong;
	return tong;
}
void main()
{
	int a[50][50], dong, cot, chon,k;
	cout << "====================MENU==================== " << endl;
	cout << "1, tinh tong cac phan tu co chu so dau la chu so le " << endl;
	cout << "2. liet ke cac so hoan thien " << endl;
	cout << "3. tinh tonng cac ptu nho hon tri tuyet doi cua ptu sau no " << endl;
	cout << "4. tinh tong gia tri tren dong k " << endl;
	cout << "5. tinh tong cac gia tri nam tren bien " << endl;
	cout << "6. dem so lan xuat hien cua 1 gia tri x  " << endl;
	cout << "7. dem so luong cac so chan, so le, so am, so duong, so nguyen to " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	nhap(a, dong, cot);
	switch (chon)
	{
	case 1: Liet_Ke_Vi_Tri_Chu_So_Dau_Le(a, dong, cot);
		Tinh_Tong_So_Le(a, dong, cot);
		break;
	case 2:
		cout << "So hoan thien: ";
		xuat_So_HT(a, dong, cot);
		break;
	case 3: cout << "\nNoi dung cua mang la: \n";
		xuat(a, dong, cot);
		cout << "Tong cac ptu lon hon tri tuyet doi phia sau la : " << tongCacPhanTuLonHonTriTuyetDoiPhiaSauNo(a, dong, cot);
		break;
	case 4: cout << "nhap k = ";
		cin >> k;
		cout << "\nNoi dung cua mang la: \n";
		xuat(a, dong, cot);
		Tong_Dongk(a, dong, cot, k);
		break;
	case 5:
		cout << "\nNoi dung cua mang la: \n";
		xuat(a, dong, cot);
		Tinh_Tong(a, dong, cot);
		break;
	case 6: int x;
		cout << "\nNhap gia tri can tim: ";
		cin >> x;
		Timx(a, dong, cot, x);
		break;
	case 7: Tim_So_Chan(a, dong, cot);
		Tim_So_Le(a, dong, cot);
		Tim_So_Am(a, dong, cot);
		Tim_So_Duong(a, dong, cot);
		Tim_So_Nguyen_To(a, dong, cot);
		break;
	default:
		break;
	}
}