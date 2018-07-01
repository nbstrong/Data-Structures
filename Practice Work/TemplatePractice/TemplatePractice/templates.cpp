#include <iostream>
using namespace std;

template <class T>

void swap_these(T & a, T & b) {
	T a_old = a;
	a = b;
	b = a_old;
}

int main() {

	int array[5] = {1, 2, 3, 5, 4};

	swap_these(array[3], array[4]);

	for (int i = 0; i < 5; i++) {
		cout << array[i] << endl;
	}

	return 0;
}