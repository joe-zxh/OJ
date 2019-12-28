#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int n, curneed=1, t;
	cin >> n;
	unordered_map<int, bool> m; // key: 元素 value: 是否出现过

	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == curneed) {		
			printf("%d %d\n", curneed++, t);
			while (m.find(curneed) != m.end()) {
				m.erase(m.find(curneed));
				printf("%d %d\n", curneed++, t);				
			}
		}
		else {
			m[t] = true;
		}
	}
	return 0;
}