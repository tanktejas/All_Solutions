class MyCircularQueue {
public:
    int msiz;
    int idx;
    vector<int>q;
    MyCircularQueue(int k) {
        msiz=k;
        q.resize(msiz,-1);
        idx=0;
    }
    
    bool enQueue(int value) {
        if(idx==msiz) return 0;
        q[idx++]=value;
        return 1;  
    }
      
    bool deQueue() {
         if(idx == 0){
             return 0;
         }
         
         for(int i=0;i<idx-1;i++)
         {
             q[i]=q[i+1];
         }
         
         idx--;
        return 1;
    }
    
    int Front() {
        if(idx==0) return -1;
        return q[0];
    }
    
    int Rear() {
        if(idx==0) return -1;
        return q[idx-1];        
    }
    
    bool isEmpty() {
        return idx==0;
    }
    
    bool isFull() {
        return idx==msiz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */