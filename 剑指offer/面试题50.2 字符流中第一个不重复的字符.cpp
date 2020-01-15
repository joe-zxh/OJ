class Solution
{
public:
    int count[256]={0};
    int onceInd = -1;// 当前第一个 只出现一次的字符的位置。
    int curInd = -1;// count当前扩充到的位置。
    map<int, int> char2Ind; // key: 字符 value: 字符在count中的位置
    map<int, int> ind2Char; // key: 字符在count中的位置 value: 字符

  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(char2Ind.find(ch)==char2Ind.end()){
            curInd++;
            count[curInd] = 1;
            char2Ind[ch] = curInd;
            ind2Char[curInd] = ch;
            if(onceInd==-1){
                onceInd = 0;
            }
        }else{
            if((count[char2Ind[ch]]++)==1&&char2Ind[ch]==onceInd){
                while(count[onceInd]>1){
                    onceInd++;
                }
            }            
        }         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(onceInd>=0 && onceInd <256 && count[onceInd]==1){
            return ind2Char[onceInd];
        }else{
            return '#';
        }    
    }
};