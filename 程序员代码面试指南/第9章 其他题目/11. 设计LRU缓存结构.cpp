#include <iostream>
#include <list>
#include <map>

using namespace std;

class kvpair {
public:
	long key, value;
	kvpair() {}
	kvpair(long k, long v):key(k), value(v) {}
};

long K;
list <kvpair> valuelist; // 规定最新更新放到头部，删除从尾部开始删除
map <long, list <kvpair>::iterator> keyNode;// key: key, value: Node address

void set(long key, long value) {
	if (keyNode.find(key) != keyNode.end()) { // key已经存在
		valuelist.erase(keyNode.find(key)->second);
	}
	else { // key不存在
		if (valuelist.size() == K) { // 检查是否要删除元素
			keyNode.erase(keyNode.find(valuelist.back().key));
			valuelist.pop_back();
		}
	}
	valuelist.push_front(kvpair(key, value));
	keyNode[key] = valuelist.begin();
}

long get(long key) {
	if (keyNode.find(key) == keyNode.end()) {
		return -1;
	}
	long res = (keyNode.find(key)->second)->value;

	valuelist.erase(keyNode.find(key)->second);
	valuelist.push_front(kvpair(key, res));
	keyNode[key] = valuelist.begin();
	return res;
}

int main() {
	long N, opt, key, value;
	cin >> N >> K;

	for (long i = 0; i < N; i++) {
		cin >> opt;
		if (opt == 1) {
			cin >> key >> value;
			set(key, value);
		}
		else {
			cin >> key;
			cout << get(key) << endl;
		}
	}

	return 0;
}