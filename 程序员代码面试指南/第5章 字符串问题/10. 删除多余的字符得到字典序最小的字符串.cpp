#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getStr(string str) {	
	
	int sz = str.size();
	int map[26] = {};
	int letter;

	for (int i = 0; i < sz; i++) { // 记录词频
		letter = str[i]-'a';
		map[letter]++;
	}

	string res="";

	int L = 0, R = 0;
	int midLetter, minInd;

	while (R<sz) {
		letter = str[R] - 'a';
		
		if (map[letter] != -1) {
			map[letter]--;
		}
		
		if (map[letter] == 0) {
			minInd = L;
			for (int i = L+1; i <= R; i++) {
				if (str[i] <= str[minInd]) {
					minInd = i;
				}
			}
			res += str[minInd];
			map[str[minInd]-'a'] = -1;

			for (int i = minInd + 1; i <= R; i++) { // 恢复词频
				if (map[str[i]-'a'] != -1) {
					map[str[i] - 'a']++;
				}
			}
			L = minInd + 1;
		}
		else {
			R++;
		}
	}
	cout << res;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (map[i] != -1&&map[i]!=0) {
			ch = 'a' + i;
			cout << ch;
		}
	}	
}

int main()
{
	string a;
	cin >> a;
	getStr(a);
	return 0;
}