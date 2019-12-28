#include <iostream>

using namespace std;

long* nexts;

void getNext(string str) {
	long sz = str.size();
	nexts = new long[sz];

	if (sz == 0) {
		printf("Fuck\n");
		return;
	}

	nexts[0] = -1;

	if (sz == 1) {
		return;
	}
	nexts[1] = 0;

	if (sz == 2) {
		return;
	}

	long cn;
	for (long i = 2; i < sz; i++) {
		cn = nexts[i - 1];
		while (true) {
			if (str[cn] == str[i - 1]) {
				nexts[i] = cn + 1;
				break;
			}
			else if (cn > 0){
				cn = nexts[cn];
			}
			else {
				nexts[i] = 0;
				break;
			}
		}
	}
}

// 从s1left开始找 第一个匹配的索引位置
long getFirstInd(string str1, string str2, long s1left) {
	
	long sz1 = str1.size();
	long sz2 = str2.size();

	long i1 = s1left;
	long i2 = 0;

	while (i1<sz1&&i2<sz2) {
		if (str1[i1] == str2[i2]) {
			i1++;
			i2++;
		}
		else if(nexts[i2]==-1){ // 0位置扩不动
			i1++;
		}
		else {
			i2 = nexts[i2];
		}
	}

	return i2 == sz2 ? i1 - sz2 : -1;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	getNext(str2);
	
	long ind=-1;
	bool firstPrint = true;
	do {
		ind = getFirstInd(str1, str2, ind+1);
		if (ind != -1 || firstPrint) {
			printf("%d ", ind);
			firstPrint = false;
		}		
	} while (ind!=-1);

	delete []nexts;
	return 0;
}