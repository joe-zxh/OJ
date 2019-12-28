#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int sz = str.size();
	int ind = 0;
	int count = 1;
	bool first = true;
	while (ind<sz) {
		if (ind==sz-1 || str[ind] != str[ind + 1]) {
			if (first) {
				printf("%c_%d", str[ind], count);
				first = false;
			}
			else {
				printf("_%c_%d", str[ind], count);
			}
			count = 0;
		}
		count++;
		ind++;
	}	
	return 0;
}