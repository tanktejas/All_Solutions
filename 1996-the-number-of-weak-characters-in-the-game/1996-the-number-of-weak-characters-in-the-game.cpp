class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(),pro.end(),greater<vector<int>>());
        int n=pro.size();
        priority_queue<int>p;
        vector<int>hj;
        int cnt=0;
         
        for(int i=0;i<n;)
        {
             int ele=pro[i][0];
             hj.clear();
             int tp=p.size() ? p.top() : -1e9;  
              
        
             while(i<n and ele == pro[i][0])
             {   
                 int  hh=pro[i][1];
                 if(tp > hh)  
                 {
                     cnt++;
                 }  
                 
                 hj.push_back(pro[i][1]);
                 i++;  
             }
            
            int yy=hj.size();
            for(int l=0;l<yy;l++)
            {
                p.push(hj[l]);
            }
            
        }
        return cnt;
    }
};