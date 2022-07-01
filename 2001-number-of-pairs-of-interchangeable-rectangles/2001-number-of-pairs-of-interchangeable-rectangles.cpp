class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& re) {
        map<double,long long>m;
        for(int i=0;i<re.size();i++){
            double irr=re[i][0],irt=re[i][1];
            double ii=(irr/irt); 
            m[(ii)]++; 
        }
        
        long long ans=0;
        for(auto ele:m){
            if(ele.second > 1) ans+=(ele.second*(ele.second-1))/2;   
            
        }
        
        return ans;
    }
};

