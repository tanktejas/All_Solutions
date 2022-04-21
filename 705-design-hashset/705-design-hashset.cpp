class node{
    node* next;
    int val;
    public:
     node(){}
     node(int data){
         next=NULL;
         val=data;
     }    
    node* add(node* root,int val){
        if(!root){
            return root=new node(val);
        }
        node* temp=root;
      
          while(temp->next){
            temp=temp->next;
          } 
           
          temp->next=new node(val);
       
        return root;
    }
   node* remove(node* root,int val){
       
        
       while(root and root->val==val) root=root->next;
       
       node* temp=root;
       
       
       while(temp and temp->next){
           if(temp->next->val==val){
               node* curr=temp;
               temp=temp->next;
               while(temp and temp->val==val){
                   temp=temp->next;
               } 
               curr->next=temp; 
           }else{
               temp=temp->next;
           }
       }
       
    return root;
   }
  bool contain(node* root,int val){
      node* temp=root;
      while(temp){
          if(temp->val==val) return 1;
        temp=temp->next;
      }
      return 0;
  }
};
class MyHashSet {
public:
    node* root;
    node obj;
    MyHashSet() { 
        root=NULL;
    }
    
    void add(int key) {
       root=obj.add(root,key);
    }     
    
    void remove(int key) {
        root=obj.remove(root,key);
    }
    
    bool contains(int key) {
        return obj.contain(root,key);
    }
}; 


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */