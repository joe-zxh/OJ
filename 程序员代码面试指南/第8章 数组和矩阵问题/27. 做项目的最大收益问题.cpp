#include<iostream>
#include<queue>
 
using namespace std;
 
struct Proj {
    long cost;
    long profit;
};
 
struct cmpMinCost {
    bool operator() (const Proj &a, const Proj &b) {
        return a.cost > b.cost;
    }
};
 
struct cmpMaxProfit {
    bool operator() (const Proj &a, const Proj &b) {
        return a.profit < b.profit;
    }
};
 
int main() {
    priority_queue<Proj, vector<Proj>, cmpMinCost> minHeapCost;
    priority_queue<Proj, vector<Proj>, cmpMaxProfit> maxHeapProfit;
     
    long N, W, K, temp;
 
    cin >> N >> W >> K;
 
    Proj *projects = new Proj[N];
 
    for (long i = 0; i < N; i++) {
        cin >> temp;
        projects[i].cost = temp;
    }
    for (long i = 0; i < N; i++) {
        cin >> temp;
        projects[i].profit = temp;
    }
 
    for (long i = 0; i < N; i++) {
        if (projects[i].cost<=W) {
            maxHeapProfit.push(projects[i]);
        }
        else {
            minHeapCost.push(projects[i]);
        }
    }
 
    while (K > 0 && !maxHeapProfit.empty()) {
        W += maxHeapProfit.top().profit;
        maxHeapProfit.pop();
         
        while (!minHeapCost.empty()&&minHeapCost.top().cost<= W) {
            maxHeapProfit.push(minHeapCost.top());
            minHeapCost.pop();
        }
        K--;
    }
 
    cout << W << endl;
    return 0;
}