class TreeAncestor {
public:
    
    vector<vector<int>>v;
      int lo=22;
    TreeAncestor(int n, vector<int>& pa){  
       
          v.resize(n,vector<int>(lo+1,-1));
          
        // v[0][0]=0;
         // pa[0]=0;
        
       for(int i = 0; i < n; i++)
            v[i][0] = pa[i];
         
        for(int i = 1; i < lo; i++)
            for(int node = 0; node < n; node++) {
              
                int farthest_ancestor = v[node][i - 1];
                if(farthest_ancestor != -1)
                    v[node][i] = v[farthest_ancestor][i-1];
            }
           
    } 
      
    int getKthAncestor(int node, int k) {
        
        // 2^1(2nd) ancestor of 4 i.e 2. And 2 is also the kth(3rd) ancestor of node 5
        for(int pos = 0; pos<lo; pos++) {
            // If bit is set, jump to pos-th ancestor of current node
            if(k & (1 << pos)) { 
                node = v[node][pos]; 
                if(node == -1)
                    return -1;
            }
        }
        return node;
         
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */