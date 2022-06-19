class Solution {
public:
    class trienode{
        public:
           trienode* v[26];
           vector<int>idx;
          
    };
    
    
    class trie{
        trienode* node1;
        public:
          trie(){
            node1=new trienode();
            for(int i=0;i<26;i++){
                node1->v[i]=NULL;
            }
          }
         
        void insert(string s,int ind){
            trienode* node=node1;
            for(int i=0;i<s.length();i++){
                
                if(node->v[s[i]-'a']==NULL){
                    node->v[s[i]-'a']=new trienode();
                    node=node->v[s[i]-'a'];
                }else{
                    node=node->v[s[i]-'a'];   
                }
              
                node->idx.push_back(ind);
            }
        }
        
        vector<int> search(string pre){
             trienode* node=node1;
            for(int i=0;i<pre.length();i++)
            {
                if(node->v[pre[i]-'a']==NULL){
                    return {};
                }else{
                    node=node->v[pre[i]-'a'];
                }
            }
            
             return node->idx;
        }
        
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sw) {
       sort(pro.begin(),pro.end());
        vector<vector<string>>ans;
        
        trie t;
        
        for(int i=0;i<pro.size();i++){
              t.insert(pro[i],i);
        }
        string tt="";
        
        for(int i=0;i<sw.length();i++){
             tt+=sw[i];
            
            vector<int> bb=t.search(tt);
            if(bb.size()>3){
                vector<string>h(3);
                h[0]=pro[bb[0]];  
                h[1]=pro[bb[1]];
                h[2]=pro[bb[2]];
                ans.push_back(h);
            }else{  
                vector<string>h;
                for(int i=0;i<bb.size();i++){
                    h.push_back(pro[bb[i]]);
                }
                ans.push_back(h);
            }
        }
        
        return ans;
    }
};