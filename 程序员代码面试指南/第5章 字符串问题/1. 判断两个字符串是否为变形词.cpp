#include <iostream>
#include <string>

using namespace std;

int main() {
	int len1, len2;
	cin >> len1 >> len2;
	string str1, str2;
	cin >> str1 >> str2;
	if (len1 != len2) {
		printf("false\n");
		return 0;
	}

	int count[256] = {};

	for (int i = 0; i < len1; i++) {
		count[str1[i]]++;
	}

	for (int i = 0; i < len2; i++) {
		count[str2[i]]--;
	}

	for (int i = 0; i < len2; i++) {
		if (count[str2[i]] != 0) {
			printf("false\n");
			return 0;
		}
	}

	printf("true\n");
	return 0;
}