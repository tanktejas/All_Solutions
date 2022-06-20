bool cmp(string &s1,string &s2){
  return s1.length() > s2.length();    
}

class Solution {
public:
    class trienode{
          public:
            trienode* arr[27]; 
    };
    
    class trie{
        trienode* root;
        public:
        
        trie(){
            root=new trienode();
            for(int i=0;i<26;i++) {
                root->arr[i]=NULL;
            }
        }
        
        bool insert(string s){
            trienode* temp=root;
            int n=s.length();
            bool isnewcreated=0;
            for(int i=0;i<n;i++){
                if(temp->arr[s[i]-'a']==NULL){
                   temp->arr[s[i]-'a']=new trienode();
                    isnewcreated=1;
                } 
                temp=temp->arr[s[i]-'a'];
            }
            return isnewcreated;
        }
        
    };
    
    
    int minimumLengthEncoding(vector<string>& words) {
        
       
        trie tt;
   
        sort(words.begin(),words.end(),cmp);
     
        int len=0;
        
        for(int i=0;i<words.size();i++){
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            if(tt.insert(rev)){
                len+=words[i].length()+1;
            }
        } 
        
        return len;
    }
};


