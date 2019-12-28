#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ind;
	cin >> ind;
	string str;
	cin >> str;
	int sz = str.size();
	
	char tmp;
	for (int i = 0; i < ind / 2; i++) {
		tmp = str[i];
		str[i] = str[ind - 1 - i];
		str[ind - 1 - i] = tmp;
	}

	for (int i = 0; i < (sz-ind)/2; i++) {
		tmp = str[i+ind];
		str[i + ind] = str[sz -1 - i];
		str[sz - 1 - i] = tmp;
	}
	
	for (int i = 0; i < sz / 2; i++) {
		tmp = str[i];
		str[i] = str[sz - 1 - i];
		str[sz - 1 - i] = tmp;
	}
	cout << str << endl;
	return 0;
}