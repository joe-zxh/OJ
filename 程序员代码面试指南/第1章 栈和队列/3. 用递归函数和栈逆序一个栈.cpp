#include <iostream>
#include <stack>

using namespace std;

long getBottom(stack<long> &st) {
	long t1 = st.top();
	st.pop();
	if (st.empty()) {
		return t1;
	}
	else {
		long result = getBottom(st);
		st.push(t1);
		return result;
	}
}

void reverse(stack<long> &st) {
	if (st.empty()) {
		return;
	}
	else {
		long t1 = getBottom(st);
		reverse(st);
		st.push(t1);
	}
}

int main() {
	long n, temp;
	cin >> n;
	stack<long> st;
	while (n--) {
		cin >> temp;
		st.push(temp);
	}

	while (!st.empty()) {
		temp = st.top();
		st.pop();
		printf("%d ", temp);
	}

	/*reverse(st);

	while (!st.empty()) {
		temp = st.top();
		st.pop();
		printf("%d ", temp);
	}*/
	printf("\n");
	return 0;
}