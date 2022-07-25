class Solution {
public:
    vector<string>tmp;
    vector<string>ans;
    
    void find(int idx,string s)
    {
        if(tmp.size()==4 and idx==s.length()){
            int f=stoi(tmp[0]);
            int s=stoi(tmp[1]);
            int t=stoi(tmp[2]);
            int fo=stoi(tmp[3]);
            
            string ans1="";
            ans1=tmp[0]+"."+tmp[1]+"."+tmp[2]+"."+tmp[3];
            
            if(f<=255 and s<=255 and t<=255 and fo<=255){
                 ans.push_back(ans1);
            }
            
            return ;
        }
        
        
        for(int i=idx;i<s.length();i++)
        {   
            if((i-idx)<=3 and (s[idx]!='0' or i==idx)){
                string sub=s.substr(idx,i-idx+1);
                tmp.push_back(sub);
                find(i+1,s);
                tmp.pop_back();
            }
        }
        
    }
     
    
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12) return {};
        
        find(0,s);
        
        return ans;
    }
};