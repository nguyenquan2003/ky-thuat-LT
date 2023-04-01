#include <iostream>
#include <fstream>
using namespace std;
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
void writeFile(int arr[], int n)
{
	//mở file
	ofstream fileOut;
	fileOut.open("array.txt", ios_base::out);

	//xử lí file
	fileOut << n << "\n";
	for (int i = 0; i < n; i++)
	{
		fileOut << arr[i] << " ";
	}

	//đóng file
	fileOut.close();
}

//đọc file với form trong file text
/*
		6
		1 2 3 4 5 6
*/
void readFile(int arr[], int& n)
{
	//Mo file
	ifstream fileIn;
	fileIn.open("array.txt", ios_base::in);

	//xu li file
	fileIn >> n;
	for (int i = 0; i < n; i++)
	{
		fileIn >> arr[i];
	}

	//dong file
	fileIn.close();
}


//đọc file với form
/*
	  1 2 3 4 5 6
*/
void rFile(int arr[], int& n)
{
	//Mo file
	ifstream fileIn;
	fileIn.open("array.txt", ios_base::in);

	//xu li file
	int index = 0;
	while (!fileIn.eof())
	{
		fileIn >> arr[index];
		index++;
		n++;
	}

	//dong file
	fileIn.close();
}
void Nhap(int arr[], int& n)
{
	cout << "nhap n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> arr[i];
	}
}

int main()
{
	int arr[100];
	int n ;
	Nhap(arr, n);
	writeFile(arr, n);
	//rFile(arr, n);
	printArray(arr, n);
	system("pause");
}