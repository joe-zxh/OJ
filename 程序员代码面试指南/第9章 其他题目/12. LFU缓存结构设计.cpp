#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
 
using namespace std;
 
int K, curSize=0, minf=0; //minf 记录最小的frequency
 
unordered_map<int, pair<int, int> > m; // key: key   value:(value, freq)
unordered_map<int, list<int> >fres; // key: freq value: freqList 从头开始加入更新，从尾删除。
unordered_map<int, list<int>::iterator >iters; // key: key  value: freqList里的具体位置
 
long get(long key) {
    if (m.find(key) == m.end()) { // 不存在key
        return -1;
    }
 
    fres[m[key].second].erase(iters[key]);
    m[key].second++;
    fres[m[key].second].push_front(key);
    iters[key] = fres[m[key].second].begin();
 
    while (fres[minf].size() == 0)
        minf++;
 
    return m[key].first;
}
 
void set(long key, long value) {
 
    if (get(key)!=-1) { // 存在key
        // get函数里面已经更新了fres和iter了，只需更新m即可
        m[key].first = value;
        return;
    }
 
    // 不存在key
 
    if (m.size() >= K) { // 缓存大小边界
        list<int>::iterator it = fres[minf].end();
        it--;
        m.erase(*it);
        iters.erase(*it);
        fres[minf].pop_back();
    }
 
    minf = 1;
    m[key] = {value, 1};
    fres[minf].push_front(key);
    iters[key] = fres[minf].begin();
}
 
int main() {
    int N, opt, key, value;
    cin >> N >> K;
 
    for (int i = 0; i < N; i++) {
        cin >> opt;
        if (opt == 1) {
            cin >> key >> value;
            set(key, value);
        }
        else {
            cin >> key;
            cout << get(key) << endl;
        }
    }
 
    return 0;
}