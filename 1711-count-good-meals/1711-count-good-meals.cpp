class Solution {
public:
    int countPairs(vector<int>& d) {
         vector<int>v;
         for(int i=0;i<=21;i++){
             v.push_back(pow(2,i));
         }
         unordered_map<int,int>m;
         int ans=0;
         for(int i=0;i<d.size();i++){
             for(int j=0;j<=21;j++){
                if(m.count(v[j]-d[i]))
                 ans=(ans+(m[v[j]-d[i]]))%1000000007;  
             }
             m[d[i]]++;
         }
        return ans;
    } 
};