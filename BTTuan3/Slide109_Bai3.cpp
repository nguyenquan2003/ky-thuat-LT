#include <iostream>
using namespace std;
void main()
{
	char st[] = "Hello", * p1;
	p1 = st;
	cout<<" st[0] la : "<< *st<<endl;
	cout <<" st[1] la : " << *(st + 1)<<endl;
	cout <<" st[2] la : " << *(st + 2)<<endl;
	cout <<" st[3] la : " << *(st + 3)<<endl;
	cout <<" st[4] la : " << *(st + 4) << endl;
}