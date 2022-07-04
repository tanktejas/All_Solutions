class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        
        if(n==1) return 1;
        
        vector<int>v(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
             q.push({r[i],i});
        }
         
        while(!q.empty()){
            auto ele=q.top();
            q.pop();
            if(ele.second==0){
                if(r[ele.second+1] < ele.first){
                    v[ele.second]=v[ele.second+1]+1;
                }else{
                    v[ele.second]=1;
                } 
            }else if(ele.second==n-1){
                if(r[ele.second-1] < ele.first){
                    v[ele.second]=v[ele.second-1]+1;
                }else{
                    v[ele.second]=1;
                }
            }else{
                int mm=0;
                if(r[ele.second-1] < ele.first)
                  mm=max(mm,v[ele.second-1]);
                if(r[ele.second+1] < ele.first)
                 mm=max(mm,v[ele.second+1]);
                  
                 v[ele.second]=1+mm; 
            
            }
        }   
        
        int s=0;
        for(int i=0;i<n;i++){
            s+=v[i]; 
        }
        cout<<endl;
        return s;
    }
};