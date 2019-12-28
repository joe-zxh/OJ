#include<iostream>
#include<map>
using namespace std;

class TrieTreeNode {
public:
	char val;
	int pass;// 有多少word经过了这个节点。
	int ends;// 有多少word以这个节点作为结尾。
	map<char, TrieTreeNode*> nexts;
};

void Insert(TrieTreeNode* root, string str) {
	int sz = str.size();
	TrieTreeNode* cur = root;
	cur->pass++;
	cur->ends = sz == 0 ? cur->ends + 1 : cur->ends;
	for (int i = 0; i < sz; i++) {
		if (cur->nexts.find(str[i]) != cur->nexts.end()) {
			cur = cur->nexts[str[i]];
			cur->pass++;
		}
		else {
			TrieTreeNode *ttn = new TrieTreeNode;
			ttn->val = str[i];
			ttn->pass = 1;
			ttn->ends = 0;
			cur->nexts[str[i]] = ttn;
			cur = ttn;
		}
	}
	cur->ends++;
}

void Delete(TrieTreeNode* root, string str) {
	int sz = str.size();
	TrieTreeNode* cur = root, *pre;
	cur->pass--;
	cur->ends = sz == 0 ? cur->ends - 1 : cur->ends;
	for (int i = 0; i < sz; i++) {
		if (cur->nexts.find(str[i]) != cur->nexts.end()) {
			pre = cur;
			cur = cur->nexts[str[i]];
			cur->pass--;
			if (cur->pass == 0) {
				pre->nexts.erase(pre->nexts.find(str[i])); // 这样删不太安全
				return;
			}
		}
		else {
			printf("error: delete a word that do not exists!\n");
			return;
		}
	}
	cur->ends--;
}

void Search(TrieTreeNode* root, string str) {
	int sz = str.size();
	TrieTreeNode* cur = root;

	for (int i = 0; i < sz; i++) {
		if (cur->nexts.find(str[i]) != cur->nexts.end()) {
			cur = cur->nexts[str[i]];
		}
		else {
			printf("NO\n");
			return;
		}
	}
	if (cur->ends > 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}	
}

void PrefixNum(TrieTreeNode* root, string str) {
	int sz = str.size();
	TrieTreeNode* cur = root;
	for (int i = 0; i < sz; i++) {
		if (cur->nexts.find(str[i]) != cur->nexts.end()) {
			cur = cur->nexts[str[i]];
		}
		else {
			printf("0\n"); // 不存在这样的前缀
			return;
		}
	}
	printf("%d\n", cur->pass);
}

int main() {
	int m, op;
	string word;
	TrieTreeNode* root = new TrieTreeNode();
	root->pass = 0;
	root->ends = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> op >> word;
		if (op == 1) {
			Insert(root, word);
		}
		else if (op == 2) {
			Delete(root, word);
		}
		else if (op == 3) {
			Search(root, word);
		}
		else if (op == 4) {
			PrefixNum(root, word);
		}
	}
	return 0;
}