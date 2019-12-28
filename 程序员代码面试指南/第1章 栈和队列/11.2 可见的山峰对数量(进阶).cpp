#include<iostream>
#include<stack>

using namespace std;

class Record {
public:
	long val, num;
	Record() {}
	Record(long v, long n) :val(v), num(n) {}
};

long nextInd(long curInd, long n) {
	return (curInd + 1) % n;
}

long Ck2(long k) {
	return k == 1 ? 0 : k * (k - 1) / 2;
}

long viewMount(long *arr, long n) {
	if (n < 2) {
		return 0;
	}

	stack<Record> st;	
	long res = 0;
	long maxInd = 0;

	for (long i = 1; i < n; i++) {
		maxInd = arr[i] > arr[maxInd] ? i : maxInd;
	}

	long curInd = maxInd;

	Record t1, t2;
	do {
		if (st.empty()) {
			Record a(arr[curInd], 1);
			st.push(a);
		}
		else {
			t1 = st.top();
			while (arr[curInd]>t1.val) { // 弹出，并结算
				res += (Ck2(t1.num) + 2 * t1.num);
				st.pop();
				if (!st.empty()) {
					t1 = st.top();
				}
				else {
					break;
				}
			}

			if (arr[curInd] == t1.val) {
				t1.num++;
				st.pop();
				st.push(t1);
			}
			else {
				Record a(arr[curInd], 1);
				st.push(a);
			}			
		}
		curInd = nextInd(curInd, n);
	} while ( curInd != maxInd);

	while (!st.empty()) {
		if (st.size() >= 3) {
			t1 = st.top();
			res += (Ck2(t1.num) + 2 * t1.num);
			st.pop();
		}
		else if (st.size() == 2) {
			t1 = st.top(); st.pop();
			t2 = st.top();
			res += (Ck2(t1.num) + t1.num * (t2.num > 1 ? 2 : 1));
		}
		else {
			t1 = st.top(); st.pop();
			res += Ck2(t1.num);
		}
	}

	return res;
}

int main() {
	long n;
	cin >> n;
	long* arr = new long[n];

	for (long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << viewMount(arr, n);

	return 0;
}

