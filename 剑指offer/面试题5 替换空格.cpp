class Solution {
public:
	void replaceSpace(char *str,int length) {
	int spacecount = 0, i, j;
	int originLen = 0;

	while(str[originLen]!='\0') {
		if(str[originLen++]==' ') {
			spacecount++;
		}
	}
	originLen++;
	i = originLen-2;
	j = originLen+2*spacecount-2;

	str[j+1]='\0';
	
	if(j>=length) {
		cout<<"error"<<endl;
		return; // 无法进行拓展
	}
	while(i>=0) {
		if(str[i]==' '){
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
			i--;
		}else{
			str[j--]=str[i--];
		}
	}
}
};