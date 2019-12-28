#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<int, pair<int,int>> m; // key: key  value: <value, timestamp>
	int n, opt, time=0, setto, lastSet=-1, key, value, ts;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> opt;

		if (opt == 1) {
			cin >> key >> value;
			m[key] = pair<int, int>(value, time);
			time++;
		}
		else if (opt == 2) {
			cin >> key;
			if (m.find(key) != m.end()) {
				ts = m[key].second;
				if (ts < lastSet) {
					printf("%d\n", setto);
				}
				else {
					printf("%d\n", m[key].first);
				}
			}
			else {
				printf("-1\n");
			}
		}
		else { // opt==3
			cin >> value;
			lastSet = time;
			setto = value;
			time++;
		}
	}

	return 0;
}