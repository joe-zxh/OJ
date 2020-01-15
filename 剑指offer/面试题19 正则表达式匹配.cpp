class Solution {
public:
bool match(char* str, char* pattern) {
    if(*pattern=='\0'){
        return *str=='\0';
    }

    if(*(pattern+1)=='*'){

        if((*str != '\0' && *pattern == '.') || *pattern==*str){
            return match(str, pattern+2) || match(str+1, pattern);
        }else{
            return match(str, pattern+2);   
        }       
        
    }else if((*str != '\0' && *pattern == '.') || *pattern==*str){
        return match(str+1, pattern+1);
    }else{
        return false;
    }
}
};