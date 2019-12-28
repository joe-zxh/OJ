#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
using namespace std;

struct p //运算符重载<
{
	string str;
	int count;
	p(string s, int c) { str = s; count = c; }
	bool operator<(const p& a) const
	{
		return count > a.count || (count==a.count&&str<a.str); //小根堆，并且字典序是反过来的
	}
};

int main() {
	map<string, int> m;
	string str;
	int N, k;
	cin >> N >> k;
	for (long i = 0; i < N; i++) {
		cin >> str;
		if (m.find(str) == m.end()) {
			m[str] = 1;
		}
		else {
			m[str]++;
		}
	}
	priority_queue <p> q;

	map<string, int>::iterator iter;
	iter = m.begin();
	while (iter != m.end()) {
		if (q.size() < k) {
			q.push(p(iter->first, iter->second));
		}
		else {
			if (q.top().count<iter->second || q.top().count == iter->second&&q.top().str>iter->first) {
				q.pop();
				q.push(p(iter->first, iter->second));
			}
		}
		iter++;
	}
	
	stack<p> st;
	
	while (!q.empty()) {
		st.push(q.top());
		q.pop();
	}

	while (!st.empty()) {
		cout << st.top().str << " " << st.top().count << endl;
		st.pop();
	}
	return 0;
}