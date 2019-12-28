#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int sz = str.size();
	int count = 0;
	for (int i = 0; i < sz; i++) {
		if (str[i] == '*') {
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		printf("*");
	}

	for (int i = 0; i < sz; i++) {
		if (str[i] != '*') {
			printf("%c", str[i]);
		}
	}
	return 0;
}