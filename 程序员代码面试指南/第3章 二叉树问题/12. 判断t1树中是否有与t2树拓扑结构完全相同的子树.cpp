#include <iostream>
#include <vector>
#include <string>

using namespace std;
int* nexts;

void getNext(vector<string>& stri) {
	int sz = stri.size();
	nexts = new int[sz];

	nexts[0] = -1;

	if (sz == 1) {
		return;
	}
	nexts[1] = 0;

	if (sz == 2) {
		return;
	}

	int cn;
	for (int i = 2; i < sz; i++) {
		cn = nexts[i - 1];
		while (true) {
			if (stri[cn] == stri[i - 1]) {
				nexts[i] = cn + 1;
				break;
			}
			else if (cn > 0) {
				cn = nexts[cn];
			}
			else {
				nexts[i] = 0;
				break;
			}
		}
	}
}

// KMP: 从s1left开始找 第一个匹配的索引位置
int getFirstInd(vector<string>& str1, vector<string>& str2, int s1left) {
	getNext(str2);

	int sz1 = str1.size();
	int sz2 = str2.size();

	int i1 = s1left;
	int i2 = 0;

	while (i1 < sz1 && i2 < sz2) {
		if (str1[i1] == str2[i2]) {
			i1++;
			i2++;
		}
		else if (nexts[i2] == -1) { // 0位置扩不动
			i1++;
		}
		else {
			i2 = nexts[i2];
		}
	}

	delete[]nexts;
	return i2 == sz2 ? i1 - sz2 : -1;
}

void genStr(int head, int* lc, int* rc, vector<string>* stri) { // 序列化
	int cur = head;

	if (cur != 0) {
		stri->push_back(to_string(cur));
		stri->push_back("!");

		genStr(lc[head], lc, rc, stri);
		genStr(rc[head], lc, rc, stri);
	}
	else {
		stri->push_back("#");
		stri->push_back("!");
	}
}

void isContain(int* tree1l, int* tree1r, int* tree2l, int* tree2r,
	int head1, int head2) {
	vector<string> str1, str2;

	genStr(head1, tree1l, tree1r, &str1);
	genStr(head2, tree2l, tree2r, &str2);

	if (getFirstInd(str1, str2, 0) != -1) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
}

int main()
{
	int n1, root1, t;
	cin >> n1 >> root1;
	int* tree1l = new int[n1 + 1];
	int* tree1r = new int[n1 + 1];

	for (int i = 0; i < n1; i++) {
		cin >> t;
		cin >> tree1l[t] >> tree1r[t];
	}

	int n2, root2;
	cin >> n2 >> root2;
	int* tree2l = new int[n1 + 1];
	int* tree2r = new int[n1 + 1];

	for (int i = 0; i < n2; i++) {
		cin >> t;
		cin >> tree2l[t] >> tree2r[t];
	}

	if (n2 > n1) {
		printf("false\n");
	}
	else {
		isContain(tree1l, tree1r, tree2l, tree2r, root1, root2);
	}
	delete[]tree1l, tree1r, tree2l, tree2r;
	return 0;
}
