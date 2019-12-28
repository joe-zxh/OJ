#include<iostream>
using namespace std;
void foldPapper(int i, int N, bool isDown) {
	if (i > N) {
		return;
	}	
	foldPapper(i + 1, N, true);
	isDown ? printf("down\n") : printf("up\n");
	foldPapper(i + 1, N, false);
}

int main() {
	int n;
	cin >> n;
	foldPapper(1, n, true);
	return 0;
}