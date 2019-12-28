#include <iostream>
using namespace std;

int main()
{
	char ch;
	while ((ch=cin.get()) != '\n') {
		if (ch != ' ') {
			printf("%c", ch);
		}
		else {
			printf("%%20");
		}
	}
	return 0;
}