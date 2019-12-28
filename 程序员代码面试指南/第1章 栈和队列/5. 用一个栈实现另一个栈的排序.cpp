#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<long> st) {
	stack<long> help;
	long t1, t2;
	while (!st.empty()) {
		t1 = st.top();
		st.pop();
		while (!help.empty() && t1 < help.top()) {
			t2 = help.top();
			help.pop();
			st.push(t2);
		}
		help.push(t1);
	}

	while (!help.empty()) {
		t1 = help.top();
		help.pop();
		printf("%d ", t1);
	}
	printf("\n");
}


int main() {
	long n, temp;
	cin >> n;
	stack<long> st;
	while (n--) {
		cin >> temp;
		st.push(temp);
	}
	sortStack(st);

	return 0;
}