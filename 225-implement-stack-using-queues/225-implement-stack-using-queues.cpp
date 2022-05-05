class MyStack {
public:
    queue<int>q1; 
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);                    //o(1)
       
    }  
        
    int pop() {
      int ee=0;
      int size=q1.size();
      while(size>1){                  //o(n)
          q1.push(q1.front());
          q1.pop(); 
          size--;
      }
      ee=q1.front();
      q1.pop();
      return ee;
    }
    
    int top() {
        int ee=0;
        int size=q1.size();         //o(n)
      while(size>1){
          q1.push(q1.front());
          q1.pop();
          size--;
      }
      ee=q1.front();
      q1.pop();
      q1.push(ee);
      return ee;
    }
    
    bool empty() {
        return q1.empty();           //o(1)
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */