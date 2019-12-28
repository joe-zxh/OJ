#include <iostream>
#include <string>
using namespace std;

void flip(string &line, int left, int right) {
	char tmp;
	for (int i = 0; i < (right - left) / 2; i++) {
		tmp = line[left+i];
		line[left+i] = line[right - i - 1];
		line[right - i - 1] = tmp;
	}
}

int main()
{
	string line;
	getline(cin, line);

	int sz = line.size();
	int left = 0;
	int right = 0;

	while (right < sz) {
		if (line[right] == ' ') {
			flip(line, left, right);
			left = right + 1;
		}
		right++;
	}
	flip(line, left, right);
	cout << line << endl;
	return 0;
}