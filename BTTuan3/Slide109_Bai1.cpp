#include <iostream>
using namespace std;
int main()
{
	float* pa, * pb, a = 90, b = 76;
	pa = &a;//pa tro toi a
	pb = &b;//pa tro toi b
	cout << "gia tri pa tro toi la : " << *pa << endl;
	cout << "gia tri pb tro toi la : " << *pb << endl;
	cout << "gia tri pa : " << pa << endl;
	cout << "gia tri pb : " << pb << endl;
	return 0;
}