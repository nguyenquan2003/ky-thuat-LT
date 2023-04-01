#include <iostream>
#include <fstream>
using namespace std;
struct sv
{
	char mssv[15], hoten[50];
	float diemtb;
};
void Nhap(sv a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap sv thu : " << i << endl;
		cout << "nhap ma so sv : " << endl;
		fflush(stdin);
		cin >> a[i].mssv;
		cout << "nhap ho ten : " << endl;
		fflush(stdin);
		cin >> a[i].hoten;
		cout << "nhap diem trung binh : " << endl;
		fflush(stdin);
		cin >> a[i].diemtb;
	}
}
void Xuat(sv dssv[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "xuat sv : " << i << endl;
		cout << "xuat ma so sv : " << dssv[i].mssv << endl;
		cout << "xuat ho ten : " << dssv[i].hoten << endl;
		cout << "diem trung binh : " << dssv[i].diemtb << endl;
	}
}
void ghi_file_dssv(FILE*& f, sv dssv[], int& n, char* filename)
{
	f = fopen("dssv.bin", "wb");
	fwrite(&n, sizeof(int), 1, f);
	for (int i = 0; i < n; i++)
		fwrite(&dssv[i], sizeof(dssv[i]), 1, f);
	fclose(f);
}
void doc_file_dssv(FILE*& f, sv dssv[], int& n, char* filename)
{
	try
	{
		f = fopen("dssv.bin", "rb");
		if (!f)
			throw "\nFile khong ton tai!";
		fread(&n, sizeof(int), 1, f);
		for (int i = 0; i < n; i++)
			fread(&dssv[i], sizeof(dssv[i]), 1, f);
		fclose(f);
	}
	catch (const char* err)
	{
		puts(err);
	}
}
void doc_1_sv(FILE*& f, sv& sv)
{
	fgets(sv.hoten, 30, f);
	fscanf(f, "%f", &sv.diemtb);
	fgets(sv.mssv, 30, f);
}
void doc_file_dssv_text(FILE*& f, sv dssv[], int& n, char* filename)
{
	f = fopen("dssv.bin", "rb");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
		doc_1_sv(f, dssv[i]);
	fclose(f);
}
void main()
{
	int a[30];
	sv dssv[30];
	int n;
	FILE* f;
	char filename[] = "dssv.bin", writefile[] = "bai2phan3";
	doc_file_dssv_text(f, dssv, n, filename);
	doc_file_dssv(f, dssv, n, writefile);
	ghi_file_dssv(f, dssv, n, writefile);
	Xuat(dssv, n);
}
