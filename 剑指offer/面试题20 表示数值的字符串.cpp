class Solution {
public:
bool scanUnsignedInt(char** string){
    char*p = *string;
    while(**string!='\0'&& **string>='0'&& **string<='9'){
        (*string)++;
    }
    return *string>p; // 是否存在过数字
}

bool scanInteger(char** string){
    if(**string=='+'||**string=='-'){
        (*string)++;
        return scanUnsignedInt(string);
    }else{
        return scanUnsignedInt(string);
    }
}

bool isNumeric(char* string) {
    if(string==NULL){
        return false;
    }

    bool numeric = false;
    numeric = scanInteger(&string);

    if(*string=='.'){
        string++;
        numeric = scanUnsignedInt(&string) || numeric; // 要把scanUnsigendInt放在前面 不然 可能不会执行。      
    }

    if(*string=='e'||*string=='E'){
        string++;
        numeric = scanInteger(&string) && numeric;
    }
    
    return numeric && *string=='\0';    
}
};