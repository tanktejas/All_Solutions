class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int>ans;
        
        unordered_map<int,int>vis;
        
        for(int i=1;i<=9;i++)
        {
            
            queue<int>q;
            q.push(i);
            int kk=n-1;
            
            while(!q.empty() and kk--)
            {
                int siz=q.size();
                
                while(siz--)
                {
               
                int tt=q.front();
                q.pop();
                  
                int last=tt%10;
                if((last-k) >= 0)
                {
                    q.push(tt*10 + (last - k));
                }
                if((last+k) <= 9)
                {
                    q.push(tt*10 + (last + k));
                }
                    
              }   
            }
            
            while(!q.empty())
            {
                int tt=q.front();
                q.pop(); 
                if(!vis[tt]){
                    vis[tt]=1;
                    ans.push_back(tt);
                }
            }
            
        }
        
        return ans;
    }
};