#include<iostream>
#include<map>

using namespace std;

map<int, int>hm; // key: head  value: len
map<int, int>tm; // key: tail  value: len

int main() {
	int n, t;
	cin >> n;

	int res = 1;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (hm.find(t) == hm.end()) {
			hm[t] = 1;
			tm[t] = 1;

			if (hm.find(t + 1) != hm.end()) { // merge
				hm[t] += hm[t + 1];
				tm[t + hm[t] - 1] = hm[t];
				
				res = res < hm[t] ? hm[t] : res;
				//hm.erase(hm.find(t + 1));
				//tm.erase(tm.find(t));
			}

			if (tm.find(t - 1) != tm.end()) { // merge
				tmp = tm[t + hm[t] - 1] = tm[t + hm[t] - 1] + tm[t-1];
				hm[t - 1 - tm[t - 1] + 1] = tmp;
				res = res < tmp ? tmp : res;
				//tm.erase(tm.find(t-1));
				//hm.erase(hm.find(t));
			}
		}
	}
	cout << res << endl;	
	return 0;
}
