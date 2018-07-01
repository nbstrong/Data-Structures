#include <iostream>
#include <string>

using namespace std;

int main() {

	int int1;
	int *pointer1;

	pointer1 = &int1;
	*pointer1 = 42;

	cout << "Demo 1:" << endl;
	cout << "int1 = " << int1 << endl;
	cout << "&int1 = " << &int1 << endl;
	cout << "*&int1 = " << *&int1 << endl;
	cout << "pointer1 = " << pointer1 << endl;
	cout << "*pointer1 = " << *pointer1 << endl;

	system("PAUSE");
	return 0;
}