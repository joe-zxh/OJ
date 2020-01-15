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

string LeftRotateString(string str, int n) {
    int sz = str.size();
    if(sz==0||sz<n){
        return "";
    }
    rotateStr(str, 0, n-1);
    rotateStr(str, n, sz-1);
    rotateStr(str, 0, sz-1);
    return str;
}
};