#include <iostream>
#include <unordered_set>
using namespace std;
 
int main()
{
    int n, glen=1, curmax, curmin;
    scanf("%d", &n);
    int* arr = new int[n];
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    unordered_set<int> s;    
    for (int i = 0; i + glen < n; i++) {
        curmax = curmin = arr[i];
        s.insert(arr[i]);
        for (int j = i+1; j < n; j++) {
            if (s.find(arr[j]) != s.end()) { // 出现重复元素
                break;
            }
            else {
                s.insert(arr[j]);
                curmax = curmax < arr[j] ? arr[j] : curmax;
                curmin = curmin > arr[j] ? arr[j] : curmin;
                if (curmax - curmin == j - i) {
                    glen = glen < j - i + 1 ? j - i + 1 : glen;
                }
            }          
        }
        s.clear();
    }
    printf("%d\n", glen);
     
    delete[]arr;   
    return 0;
}