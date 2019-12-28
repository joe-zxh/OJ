#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class Res {
public:
	int value;
	int pos; // 返回下一个开始检查的位置
	Res(int v, int p):value(v), pos(p) {}
};

void addNum(list<string> &st, int num) {		
	if (!st.empty()) {
		
		string top = st.back();
		if (top == "*") {
			st.pop_back();
			num = atoi((st.back()).c_str())*num;
			st.pop_back();
		}else if(top == "/") {
			st.pop_back();
			num = atoi((st.back()).c_str())/num;
			st.pop_back();
		}
	}
	st.push_back(to_string(num));
}

int cal(list<string>st) {
	int val = atoi((st.front()).c_str());
	st.pop_front();
	bool add = false;

	while (!st.empty()) {

		if (st.front() == "+") {
			add = true;
		}
		else if (st.front() == "-") {
			add = false;
		}
		else {
			val += add?atoi((st.front()).c_str()):-atoi((st.front()).c_str());
		}
		st.pop_front();
	}

	return val;
}

void printList(list<string>st) {
	list<string>::iterator it = st.begin();

	while (it != st.end()) {
		cout << (*it) << endl;
		it++;
	}
}

Res value(string str, int startPos) {
	list<string> li;
	int strLen = str.length();
	int ind = startPos;
	int pre = 0;

	while (ind < strLen&&str[ind] != ')') { // 到最后了，或者遇到 右括号，那么停止
		if (str[ind] >= '0'&&str[ind] <= '9') {
			pre = pre * 10 + (str[ind++] - '0');
		}
		else if (str[ind] == '(') {
			Res res = value(str, ind + 1);
			pre = res.value; // 下一个位置肯定是 遇到+-*/  所以会把pre的内容收集起来
			ind = res.pos + 1;
		}
		else { // 遇到+-*/
			addNum(li, pre);
			string s(1, str[ind++]);
			li.push_back(s);
			pre = 0;
		}	
	}
	addNum(li, pre);
	
	int val = cal(li);

	Res resValue(val, ind);
	return resValue;
}

int main()
{
	string str;
	cin >> str;

	cout << value(str, 0).value << endl;
	return 0;
}