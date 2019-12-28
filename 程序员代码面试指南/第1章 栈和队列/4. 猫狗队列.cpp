#include<iostream>
#include <queue>
#include <string>
 
using namespace std;
 
class Pet {
public:
    int num;
    int timestamp;
};
 
queue<Pet> dog, cat;
 
int n, temp, gtime = 0;
string opt;
 
void add() {
    cin >> opt >> temp;
    Pet a;
    a.num = temp;
    a.timestamp = gtime++;
    if (opt == "cat") {
        cat.push(a);
    }
    else {
        dog.push(a);
    }
}
 
void isDogEmpty() {
    dog.empty() ? printf("yes\n") : printf("no\n");
}
 
void isCatEmpty() {
    cat.empty() ? printf("yes\n") : printf("no\n");
}
 
void isEmpty() {
    (dog.empty() && cat.empty()) ? printf("yes\n") : printf("no\n");
}
 
void pollDog() {
    while (!dog.empty()) {
        printf("dog %d\n", dog.front().num);
        dog.pop();
    }
}
 
void pollCat() {
    while (!cat.empty()) {
        printf("cat %d\n", cat.front().num);
        cat.pop();
    }
}
 
void pollAll() {
    while (!dog.empty() && !cat.empty()) {
        int dt = dog.front().timestamp;
        int ct = cat.front().timestamp;
 
        if (dt < ct) {
            printf("dog %d\n", dog.front().num);
            dog.pop();
        }
        else {
            printf("cat %d\n", cat.front().num);
            cat.pop();
        }
    }
    pollDog();
    pollCat();
}
 
int main() {   
    cin >> n;
 
    while (n--) {
        cin >> opt;
        if (opt=="add") {
            add();
        }
        else if (opt=="isEmpty") {
            isEmpty();
        }
        else if (opt == "isDogEmpty") {
            isDogEmpty();
        }
        else if (opt == "isCatEmpty") {
            isCatEmpty();
        }
        else if (opt == "pollAll") {
            pollAll();
        }
        else if (opt == "pollDog") {
            pollDog();
        }
        else if (opt == "pollCat") {
            pollCat();
        }
    }
    return 0;
}
