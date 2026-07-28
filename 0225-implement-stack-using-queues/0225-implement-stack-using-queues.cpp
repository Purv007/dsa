#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> a;
    int n;

    MyStack() {
        n = 0;
    }

    void push(int x) {
        a.push(x);
        n++;
    }

    int pop() {
        for (int i = 0; i < n - 1; i++) {
            a.push(a.front());
            a.pop();
        }
        int t = a.front();
        a.pop();
        n--;
        return t;
    }

    int top() {
        int t;
        for (int i = 0; i < n; i++) {
            t = a.front();
            a.push(t);
            a.pop();
        }
        return t;
    }

    bool empty() {
        return n == 0;
    }
};
