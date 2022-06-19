class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sw) {
       sort(pro.begin(),pro.end());
        vector<vector<string>>ans;
        
        for(int i=1;i<=sw.size();i++){
            vector<string>temp;
            int cnt=1;
            string cc=sw.substr(0,i);
            for(int j=0;j<pro.size() and cnt<=3;j++){
                 string ff=pro[j].substr(0,i);
                 if(cc==ff)
                 {
                     temp.push_back(pro[j]);
                     cnt++;
                 }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};