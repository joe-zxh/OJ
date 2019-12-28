#include <iostream>
#include <stack>
#include <list>
using namespace std;

void monoStack(long *arr, long n) {
	stack <pair<long, list<long>>> mst; // 压的是 (值, 位置)
	pair<long, long> *lr = new pair<long, long> [n];
	pair<long, list<long>> t1, t2;
	long p1, p2;

	for (long i = 0; i < n; i++) {
		if (mst.empty()) {
			list<long> li;
			li.push_back(i);
			mst.push(pair<long, list<long>>(arr[i], li));
		}
		else {
			t1 = mst.top();
			
			while (t1.first > arr[i]) {
				mst.pop();

				// 获得左边的值
				if (!mst.empty()) {
					t2 = mst.top();
					list<long>::iterator iter = t2.second.end(); // 最后一个元素才是
					iter--;
					p1 = *iter;
				}
				else {
					p1 = -1;
				}

				// 设置 左右2边的值
				while (!t1.second.empty()) {
					lr[t1.second.front()].second = i;
					lr[t1.second.front()].first = p1;
					t1.second.pop_front();
				}		
							   
				if (!mst.empty()) {
					t1 = t2;
				}
				else {
					break;
				}
			}
			
			if (mst.empty() || mst.top().first!=arr[i]) {
				list<long> li;
				li.push_back(i);
				mst.push(pair<long, list<long>>(arr[i], li));
			}
			else { // mst.top().first()==arr[i]
				mst.top().second.push_back(i);
			}
		}
	}

	while (!mst.empty()) {
		t1 = mst.top();
		mst.pop();
		
		if (mst.empty()) {
			p1 = -1;
		}
		else {
			list<long>::iterator iter = mst.top().second.end(); // 最后一个元素才是
			iter--;
			p1 = *iter;
		}

		while (!t1.second.empty()) {
			lr[t1.second.front()].second = -1;
			lr[t1.second.front()].first = p1;
			t1.second.pop_front();
		}
	}

	for (long i = 0; i < n; i++) {
		printf("%d %d\n", lr[i].first, lr[i].second);
	}
	delete[]lr;
}

int main() {
	long n;
	cin >> n;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	monoStack(arr, n);
	
	delete[]arr;
	return 0;
}