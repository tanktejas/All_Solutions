class Solution {
public:
    int minRefuelStops(int target, int sf, vector<vector<int>>& s) {
        
        sort(s.begin(),s.end());
        
        int need=0;
        int n=s.size();
        
        priority_queue<int>pq;
        int cp=sf;
        int taking=0;
        
        for(int i=0;i<n;i++)
        {   
            if(cp < s[i][0])
            { 
                 while(!pq.empty() and cp < s[i][0])
                 { 
                      cp+=pq.top();
                      pq.pop();
                      taking++;
                 }  
                 
                 if(cp < s[i][0]){
                     return -1;
                 }
                
            } 
        
            pq.push(s[i][1]); 
        }
        
                 while(!pq.empty() and cp < target)
                 { 
                      cp+=pq.top();
                      pq.pop();
                      taking++;
                 }  
        
        if(cp < target){
            return -1;
        }
        
        return taking;
    }
};