class Solution {
public:
void rotateStr(string &str, int start, int end) {
    int midI = (end-start+1)>>1;
    char ch;
    
    for(int i = 0;i<midI;i++){
        ch = str[start+i];
        str[start+i] = str[end-i];
        str[end-i] = ch;
    }    
}

string ReverseSentence(string str) {
    int sz = str.size();

    int last = 0, cur=0;

    while(cur<=sz){
        if(cur==sz || str[cur]==' '){
            rotateStr(str, last, cur-1);
            last = cur+1;
        }
        cur++;
    }
    rotateStr(str, 0, sz-1);
    return str;
}
};