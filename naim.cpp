#include <iostream>
#include <string.h>

using namespace std;
void print(string);
void print(int);
void print(int, int);


int main() {
	print("hi");
	print(7, 8);
	print(7);
}

void print(string str) {
	cout << str << endl;
}

void print(int n) {
	print(to_string(n));
}

void print(int m, int n) {
	print(to_string(n));
	print(to_string(m));
}