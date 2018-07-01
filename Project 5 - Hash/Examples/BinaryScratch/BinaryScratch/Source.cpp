#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string name = "3 Tamra";
	int wtf = stoi(name, nullptr, 10);

	//cout << name << endl;
	cout << name << endl << wtf << endl;


	system("PAUSE");
	return 0;
}