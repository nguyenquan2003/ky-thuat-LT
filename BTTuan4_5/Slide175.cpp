#include <iostream>
using namespace std;
struct PS
{
	int TS, MS;
};
void nhapPS(PS& x)
{
	cout << "nhap tu so : ";
	cin >> x.TS;
	do
	{
		cout << "nhap mau so : ";
		cin >> x.MS;
		if (x.MS == 0)
			cout << " yeu cau ban nhap lai ";
	} 
	while (x.MS == 0);
}
void xuatPS(PS x)
{
	cout << x.TS<<"/" << x.MS;
}
float TongPS(PS x1, PS x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.MS + x1.MS * x2.TS;
	Mau = x1.MS * x2.MS;
	return (float)Tu / Mau;
}
float HieuPS(PS x1, PS x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.MS - x1.MS * x2.TS;
	Mau = x1.MS * x2.MS;
	return (float)Tu / Mau;
}
float TichPS(PS x1, PS x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.TS;
	Mau = x1.MS * x2.MS;
	return (float)Tu / Mau;
}
float ThuongPS(PS x1, PS x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.MS;
	Mau = x1.MS * x2.TS;
	return (float)Tu / Mau;
}
int main()
{

	PS x, ps1, ps2;
	int d;
	cout << "=============MENU============= " << endl;
	cout << "1. nhap va xuat phan so " << endl;
	cout << "3. kiem tra mau so khac 0 " << endl;
	cout << "4. toi gian phan so " << endl;
	cout << "5. tinh tong, thuong, hieu va tich cua 2 phan so " << endl;
	cout << "moi ban chon bai : ";
	cin >> d;
	switch (d)
	{
	case 1: nhapPS(x);
		 xuatPS(x);
		break;
	case 3: cout << "nhap tu so : ";
		cin >> x.TS;
		while (1)
		{
			cout << "nhap mau so khac 0 : ";
			cin >> x.MS;
			if (x.MS != 0)
				break;
		}
		xuatPS(x);
		break;
	case 4: nhapPS(x);
		if (x.MS == 0)
			cout << "phan so khong ton tai ";
		for (int i = (int)(x.TS / 2); i > 1; i--)
		{
			if (x.TS % i == 0 && x.MS % i == 0)
			{
				cout << "phan so toi gian la " << x.TS / i << "/" << x.MS / i;
			}
		}
		break;
	case 5: cout << "Nhap phan so 1: "<<endl;
		nhapPS(ps1);
		cout << "Nhap phan so 2: "<<endl;
		nhapPS(ps2);
		cout << "Phan so 1 la: "; xuatPS(ps1);
		cout << "\nPhan so 2 la: "; xuatPS(ps2);

		cout << "\nTong 2 phan so la: " << TongPS(ps1, ps2);
		cout << "\nHieu 2 phan so la: " << HieuPS(ps1, ps2);
		cout << "\nTich 2 phan so la: " << TichPS(ps1, ps2);
		cout << "\nThuong 2 phan so la: " << ThuongPS(ps1, ps2);
		break;
	default:
		break;
	}
}
