#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int Dem_Khoang_Trang(char chuoi[20])
{
	int dem = 0;
	for (int i = 0; i < strlen(chuoi); i++)
	{
		if (chuoi[i] == ' ')
		{
			dem++;
		}
	}
	cout << "khoang trang trong chuoi la : " << dem;
	return 0;
}
void xoa(char chuoi[], int vt)
{
	for (int i = vt + 1; i < strlen(chuoi); i++)
	{
		chuoi[i - 1] = chuoi[i];
	}
	chuoi[strlen(chuoi) - 1] = '\0';
}
void Xoa_Khoang_Trang(char chuoi[])
{
	for (int i = 0; i < strlen(chuoi); i++)
	{
		if (chuoi[i] == ' ')
		{
			xoa(chuoi, i);
			i--;
		}
	}
	cout << "ki tu sau khi xoa la : " << chuoi;
}
void In_Hoa_Chu_Dau(char chuoi[])
{
	if (chuoi[0] != ' ')
	{
		chuoi[0] = chuoi[0] - 32;
	}
	for (int i = 1; i < strlen(chuoi); i++)
	{
		if (chuoi[i] == ' ' && chuoi[i + 1] != ' ' && chuoi[i + 1] >= 'a' && chuoi[i + 1] <= 'z')
		{
			chuoi[i + 1] = chuoi[i + 1] - 32;
		}
		else
		{
			for (int i = 0; i < strlen(chuoi); i++)
			{
				if (chuoi[i] == ' ' && chuoi[i + 1] != ' ' && chuoi[i + 1] >= 'a' && chuoi[i + 1] <= 'z')
				{
					chuoi[i + 1] = chuoi[i + 1] - 32;
				}
			}
		}
	}
	cout << chuoi;
}
void Cat_Ho_Ten(char* chuoi)
{
	int n = strlen(chuoi);
	char* t;
	for (int i = n - 1; i >= 0; i--)
		if (chuoi[i] == 32)
		{
			t = chuoi + i + 1;
			cout << "ten : " << t << "\n";
			chuoi[i] = '\0';
			break;
		}

}
int main()
{
	int chon;
	char chuoi[20];
	cout << "==============MENU============== " << endl;
	cout << "2.dem khoang tranng trong chuoi " << endl;
	cout << "3. xoa khoang trang thua trong chuoi " << endl;
	cout << "4. doi ki tu dau tien thanh chu in hoa " << endl;
	cout << "6. cat chuoi ho ten thanh chuoi ho lot va ten " << endl;
	cout << "moi ban chon bai : ";
	cin >> chon;
	cin.ignore();
	cout << "nhap ki tu : ";
	gets_s(chuoi);
	switch (chon)
	{
	case 2: Dem_Khoang_Trang(chuoi);
		break;
	case 3: Xoa_Khoang_Trang(chuoi);
		break;
	case 4: In_Hoa_Chu_Dau(chuoi);
		break;
	case 6:  Cat_Ho_Ten(chuoi);
		cout << "Ho : " << chuoi;
		break;
	default:
		break;
	}
	
	
}