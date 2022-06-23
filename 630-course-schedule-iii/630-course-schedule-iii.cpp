class Solution {
public:
    int scheduleCourse(vector<vector<int>>& co) {
        if(co.size()==0) return 0;
        
        sort(co.begin(),co.end(),[&](auto a,auto b){
            return a[1] < b[1];
        });
         
        priority_queue<int>q; 
        int n=co.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++){
            
            sum+=co[i][0];
            
            
            if(sum > co[i][1]){
                q.push(co[i][0]);
                int tt=q.top();
                q.pop();
                sum-=tt;
            }else{
                q.push(co[i][0]);
            }
          
        }
        
        return q.size();
    }
};