# 剑指Offer

## Day1
### 剑指 Offer 09. 用两个栈实现队列

#### 题目描述

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

#### 思路

- 栈 A 放队尾元素，实现 *appendTail*
- 栈 B 把栈A倒叙，提取队首，实现 *deleteHead* 

#### 复杂度分析

##### 时间复杂度

- 函数 *appendTail* 为：O(1)
- 函数  *deleteHead* 为：O(N)

##### 空间复杂度 O(N)

最差情况下，栈 `A` 和 `B` 共保存 N 个元素

#### 代码

```C++
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
```



### 剑指 Offer 30. 包含min函数的栈

#### 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

#### 难点

min时间复杂度是O(1)

#### 思路

- 需要辅助栈实现，使用两个栈：栈A、栈B

- 栈A正常存储、栈B存储栈A中 **非严格降序** 元素，即栈B栈顶元素始终对应栈A最小的元素

#### 函数设计

- `push(int x)`：保持栈B结构，即栈B栈顶元素始终是栈A中最小的元素
- 保持栈A和栈B一致性，如果A栈顶等于B栈顶，则A、B同时pop、否则A pop

#### 代码

```C++
class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    int temp; //保存栈顶
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if(s2.top() == s1.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};
```

