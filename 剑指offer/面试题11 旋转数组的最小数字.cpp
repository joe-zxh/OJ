class Solution {
public:
    int f(vector<int> rotateArray, int start, int end) {
        if(start+1==end){
            return rotateArray[start]<rotateArray[end]?rotateArray[start]:
                rotateArray[end];
        }
        if(start==end){
            return rotateArray[start];
        }

        int mid = start+((end-start)>>1);
        if(rotateArray[start]>rotateArray[mid]){
            return f(rotateArray, start, mid);
        }else if(rotateArray[mid]>rotateArray[end]){
            return f(rotateArray, mid, end);
        }else{ // start=mid=end
            int ind = start+1;
            while(ind<mid){
                if(rotateArray[ind]<rotateArray[start]){
                    return rotateArray[ind];
                }else if(rotateArray[ind]>rotateArray[start]){
                    return f(rotateArray, ind, mid);
                }else{
                    ind++;
                }
            }
            return f(rotateArray, mid, end);
        }
    }

    int minNumberInRotateArray(vector<int> rotateArray) {
        return f(rotateArray, 0, rotateArray.size()-1);
    }
};