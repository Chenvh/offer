#include<iostream>
#include<stack>
using namespace std;
/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
*/

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int temp; //保存栈顶用
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        // if(s1.empty()) return -1;
        
        if( !(s2.empty()) ) {
            temp = s2.top(); //
            s2.pop();
            return temp;
        }
        if( s1.empty() ) return -1;
        while( !(s1.empty()) ) {
            s2.push(s1.top());
            s1.pop();
        }
        temp = s2.top();
        s2.pop();    
        return temp;
    }
};

int main() {
    stack<int> t1;
    t1.push(1);
    cout << t1.empty() << endl;
    return 0;
}
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */