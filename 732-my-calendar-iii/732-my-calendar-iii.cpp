

class MyCalendarThree {
public:
    int ans;
    
class Node
{
public:
   int start, end;
   Node *left = nullptr, *right = nullptr;
   int lazy = 0; // 0 no lazy; 1 lazy under tracked; 2 lazy under no tracked
   int state;
   Node(int b, int ed, int st) : start(b), end(ed), state(st) {}
   Node() : start(0), end(0), state(0) {}
};
  
int max_size = static_cast<int>(pow(10.0, 9)) + 1;

void lazyupdate(Node *node)
{  
     
         node->left->lazy += node->lazy;
         node->right->lazy += node->lazy;
 
         node->lazy = 0; 
   
}

int update(Node *node, int left, int right, bool state) // update [left,right) with state
{
   // lazy propagation 
 
   // if node have no intersection with [left, right)
   if ((node->end) <= left || (node->start) >= right)
      return node->state + node->lazy;
   // [left, right) contains node
   if (left <= (node->start) && (node->end) <= right)
   {    
      node->lazy++;
      // node -> lazy +=state if cumulative sum is needed
      // lazy operation
   
      return node->state + node->lazy;
   } 
   // part of [left, right) in node
   // if there is no children 
    
   if (node->left == nullptr)
   {  
      int mid = ((node->start) + (node->end)) / 2;
      node->left = new Node(node->start, mid, node->state);
      node->right = new Node(mid, node->end, node->state);
   }  
    
    lazyupdate(node);
    
   int result_left = update(node->left, left, right, state), result_right = update(node->right, left, right, state);
   node->state = max(result_left , result_right);
 
   return node->state; 
} 

bool query(Node *node, int left, int right)
{
   lazyupdate(node);
   // cout<<"tranverse["<<node->start<<","<<node->end<<")"<<node->state<<endl;
   //  when target have no intersection with node
   if (left >= (node->end) || right <= (node->start))
      return true;
   // target in the intersection if the node is active
   // reach the leaf, if node is active then the part of [left, right) is active
   if ((left <= (node->start) && (node->end) <= right) || !(node->left))
      return node->state;
   // part of of [left, right) in node
   return query(node->left, left, right) && query(node->right, left, right);
}
    
    Node* root;
    
    MyCalendarThree() {
        root=new Node(0,1000000001,0);
    }
    
    int book(int start, int end) {
      
        return update(root,start,end,1); 
         
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */