#include <iostream>
using namespace std;
struct date
{
	int ngay, thang, nam;
};
struct sv
{
	date ngaysinh;
	char gt[5], hoten[20];
};
void nhap(sv& x);
void nhapN(sv dssv[], int& n);
void xuat(sv x);
void xuatN(sv dssv[], int n);
void tim(sv x);
int main()
{
	sv dssv[40];
	int n;
	nhapN(dssv, n);
	xuatN(dssv, n);
}
void nhap(sv& x)
{
	cout << "nhap ho ten : ";
	rewind(stdin);
	gets_s(x.hoten, 20);
	cout << "nhap ngay sinh : ";
	rewind(stdin);
	cin >> x.ngaysinh.ngay;
	cin >> x.ngaysinh.thang;
	cin >> x.ngaysinh.nam;
	cout << "nhap gioi tinh : ";
	rewind(stdin);
	cin >> x.gt;
}
void nhapN(sv dssv[], int& n)
{
	cout << "nhap n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		nhap(dssv[i]);
}
void xuat(sv x)
{
	cout << "ho va ten : " << x.hoten << endl;
	cout << "ngay sinh : " << x.ngaysinh.ngay << "/" << x.ngaysinh.thang << "/" << x.ngaysinh.nam << endl;
	cout << "gioi tinh : " << x.gt << endl;
}
void xuatN(sv dssv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		xuat(dssv[i]);
		tim(dssv[i]);
	}

}
void tim(sv x)
{
	if (strcmp(x.gt, "nam") == 0)
		cout << "nam nghi huu : " << x.ngaysinh.nam + 62 << endl;
	else
		cout << "nam nghi huu : " << x.ngaysinh.nam + 60 << endl;
}