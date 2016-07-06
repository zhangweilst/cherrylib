#include <iostream>
using namespace std;

int main()
{
	int a[3] = { 1, 2, 3 };
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	int *p = &a[2];
	cout << p[0] << " " << p[-1] << " " << p[-2] << endl;
}
