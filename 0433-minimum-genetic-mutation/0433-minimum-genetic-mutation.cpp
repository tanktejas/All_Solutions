class Solution {
public:
    
    unordered_map<string,int>mp;
    
    int f;
    
    int find(string s,string e,int mu)
    { 
         
        if(s==e){
            cout<<1;
            f=min(f,mu);
            return 1;
        }
        
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<26;j++)
            {   
                string made=s;
                made[i]=('A'+j);
                if(made!=s and mp[made])
                { 
                    mp[made]=0;
                    if(find(made,e,mu+1)) return 1;
                }
            }  
        }
        
      return 0;     
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
         
         int n=bank.size();
         f=INT_MAX;
         for(int i=0;i<n;i++)
         {
             mp[bank[i]]++;
         }
        
         queue<string>q;
         int cnt=0;
         q.push(start);
        
         while(!q.empty())
         {
             
             int siz=q.size(); 
             
             while(siz--)
             {
                 string curr=q.front();
                 q.pop(); 
                 if(curr==end){ 
                     return cnt;  
                 }
                 
                 for(int i=0;i<8;i++)
                 {
                     
                     for(int j=0;j<26;j++)
                     {
                         string h=curr;
                         h[i]='A'+j;
                         if(mp[h] and h!=start){
                             mp[h]=0;
                             q.push(h);
                         }
                     }
                 }
                 
             }
             
            cnt++;
         }  
         
        return -1;
    }
};