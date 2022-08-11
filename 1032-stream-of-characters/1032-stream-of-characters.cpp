  
class StreamChecker {
public:
    
    class trienode
{
public:
   trienode *arr[26];
   int end=0; 
};
  
class trie
{
   trienode *root;
 
public:
   trie()
   {
      root = new trienode();
      for (int i = 0; i < 26; i++)
      {
         root->arr[i] = NULL;
      }
   }

   void insert(string &s)
   {
      trienode *temp = root;
       
      for (int i = s.length()-1; i >= 0; i--)
      {
         if (temp->arr[s[i] - 'a'] == NULL)
         {
            temp->arr[s[i] - 'a'] = new trienode();
         }
         temp = temp->arr[s[i] - 'a'];
      } 
       temp->end=1;
   }
    
    bool check(string &s){
        
        trienode* temp=root;
        int i=s.length()-1;  
        while(i>=0 and temp->arr[s[i]-'a']){
            temp=temp->arr[s[i]-'a'];  
            if(temp->end) return 1;
            i--;
        }
        return 0;
    }
};
    
    trie tt;
    string stream="";     
    StreamChecker(vector<string>& words) {
        int i;
        for(i=0;i<words.size();i++){ 
            tt.insert(words[i]);  
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);    
       return tt.check(stream);  
         
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */