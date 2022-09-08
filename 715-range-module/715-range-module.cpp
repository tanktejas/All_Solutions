

class RangeModule {
public:
    
    class Node
{
public:
   int start, end;
   Node *left = nullptr, *right = nullptr;
   int lazy = 0; // 0 no lazy; 1 lazy under tracked; 2 lazy under no tracked
   bool state;
   Node(int b, int ed, bool st) : start(b), end(ed), state(st) {}
   Node() : start(0), end(0), state(false) {}
};
// class Tree
// {
// public:

int max_size = static_cast<int>(pow(10.0, 9)) + 1;

void lazyupdate(Node *node)
{
   if ((node->lazy) != 0)
   {
      node->state = ((node->lazy) == 1);
      if (node->left)
      {
         node->left->lazy = node->lazy;
         node->right->lazy = node->lazy;
      }
      node->lazy = 0;
   }
}

bool update(Node *node, int left, int right, bool state) // update [left,right) with state
{
   // lazy propagation
   lazyupdate(node);
   // if node have no intersection with [left, right)
   if ((node->end) <= left || (node->start) >= right)
      return node->state;
   // [left, right) contains node
   if (left <= (node->start) && (node->end) <= right)
   {
      node->state = state;
      // lazy operation
      if (node->left)
      {
         if (state)
         {
            node->left->lazy = 1;
            node->right->lazy = 1;
         }
         else
         {
            node->left->lazy = 2;
            node->right->lazy = 2;
         }
      }
      return node->state;
   }
   // part of [left, right) in node
   // if there is no children
   if (node->left == nullptr)
   {
      int mid = (node->start) + ((node->end) - (node->start)) / 2;
      node->left = new Node(node->start, mid, node->state);
      node->right = new Node(mid, node->end, node->state);
   }
   bool result_left = update(node->left, left, right, state), result_right = update(node->right, left, right, state);
   node->state = result_left && result_right;
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
// };
    Node *root;
     
    RangeModule() {
        root = new Node(0, max_size, false);
    }
    
    void addRange(int left, int right) {
        update(root,left,right,1);
    }
    
    bool queryRange(int left, int right) {
        return  query(root,left,right);
    }
    
    void removeRange(int left, int right) {
         update(root,left,right,0);
    }
};  

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */