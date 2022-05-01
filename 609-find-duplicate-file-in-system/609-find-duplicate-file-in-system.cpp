class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& pa) {
        int n=pa.size();
        vector<vector<string>>ans;
        map<string,vector<string>>m;
        for(int i=0;i<n;i++){
            string p=pa[i];
            string val="";
            int j=0;
            while(p[j]!=' '){
                val+=p[j];
                j++;
            }      
            j++;   
           while(j<p.length()){
             string temp=""; 
              string name="";
              while(p[j]!='('){
                 name+=p[j];   
                 j++;
              }
               j++;
              while(p[j]!=')'){
                  temp+=p[j];
                  j++;
              }
              m[temp].push_back(val+"/"+name);
              j++;
              j++;
           }
        }

        for(auto ele:m){
            if(ele.second.size()>1)
              ans.push_back(ele.second);
        }
        
        return ans;
    }
};