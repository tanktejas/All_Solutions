class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        set<char>s;
        int n=words.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int>m; 
            for(int k=0;k<words[i].size();k++){
                m[words[i][k]]=1;
            }
        
            for(int j=i+1;j<n;j++){
              bool bo=1;
                for(int l=0;l<words[j].size();l++){
                    if(m[words[j][l]]==1){
                        bo=0;
                    }
                }
              if(bo){
                  if((words[i].length()*words[j].length())>ans)
                       ans=words[i].length()*words[j].length();
              }
            }
        }
        return ans;
    }
};