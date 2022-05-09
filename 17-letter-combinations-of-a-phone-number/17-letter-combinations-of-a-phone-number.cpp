class Solution {
public:
    vector<string>ans;
    vector<string>word={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fun(string num,string temp,int idx){
        
        if(temp.length()== num.length()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0;i<word[num[idx]-'0'].length();i++){
            fun(num,temp+word[num[idx]-'0'][i],idx+1);
        }
        
    }  
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {}; 
        int idxx=0;
        fun(digits,"",idxx);
        return ans;
    }
}; 