#include <iostream>
#include <string>

using namespace std;

void valid(string str) {	
	long count = 0;
	long sz = str.size();

	for (long i = 0; i < sz; i++) {
		if (str[i] == '(') {
			count++;
		}
		else if (str[i] == ')'){
			if (count == 0) {
				cout << "NO" << endl;
				return;
			}
			else {
				count--;
			}
		}
		else {
			cout << "NO" << endl;
			return;
		}
	}

	if (count == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	string str;
	cin >> str;
	valid(str);
	return 0;
}