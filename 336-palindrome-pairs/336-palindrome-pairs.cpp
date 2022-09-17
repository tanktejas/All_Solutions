
 class trie{
    public:
     trie* arr[26];
     vector<int>pi;
     int end;
     trie(){ 
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        } 
         end=-1;
    }
      
};

class Solution {
public:
     trie* node;
     
     bool ispal(int i,int j,string &s)
     {
         while(i<=j and s[i]==s[j]){
             i++; 
             j--;
         } 
         return i>=j;  
     }
    
      void insertin(string &w,int &idx){
           trie* temp=node; 
           int uu=w.length();
           for(int i=uu-1;i>=0;i--){ 
                 int req=w[i]-'a'; 
                if(ispal(0,i,w)){ 
                    temp->pi.push_back(idx);
                }   
                if(temp->arr[req]!=NULL){
                    temp=temp->arr[req];  
                }else{
                    temp->arr[req]=new trie();
                    temp=temp->arr[req];  
                }           
           }
          
          temp->pi.push_back(idx);  
          temp->end=idx;
          
      }
    
      vector<int> search(string &s,int yy)
      {
          
          trie* temp=node;    
          int n=s.length(); 
          vector<int>kk;       
        
          for(int i=0;i<n and temp;i++)
          { 
              if(temp->end!=-1 and temp->end!=yy and ispal(i,n-1,s))
              { 
                  kk.push_back(temp->end);    
              }
               
              temp=temp->arr[s[i]-'a'];
          }
          
          if(temp==NULL)
          { 
              return kk;
          }else{
           
              int uuer=temp->pi.size();
              for(int i=0;i<uuer;i++)
              {
                  if(temp->pi[i]!=yy)
                     kk.push_back(temp->pi[i]);  
              }
              
          }
          
         return kk;
          
      }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        node=new trie();
        vector<vector<int>>ans;
        int n=words.size();
        int idx=-1;
        
        for(int i=0;i<n;i++)
        {
           string ss=words[i]; 
            insertin(ss,i);  
        } 
      
        for(int i=0;i<n;i++)
        {  
            vector<int>asa=search(words[i],i);
            int siz=asa.size();
            for(int j=0;j<siz;j++)
            {  
                ans.push_back({i,asa[j]});
            }
        }
        
        return ans;
    }
};