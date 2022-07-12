class Solution {
public:
    int tar;
    bool is(vector<int> &m,int s1,int s2,int s3,int s4,int idx){
        
        if(idx==m.size()){   
            return s1==s2 and s2==s3 and s3==s4;
        }
         
        
        if(s1+m[idx] <= tar)
           if(is(m,s1+m[idx],s2,s3,s4,idx+1)) return 1;
        if(s2+m[idx] <= tar)
           if(is(m,s1,s2+m[idx],s3,s4,idx+1)) return 1;
        if(s3+m[idx] <= tar)
           if(is(m,s1,s2,s3+m[idx],s4,idx+1)) return 1;
        if(s4+m[idx] <= tar)
           if(is(m,s1,s2,s3,s4+m[idx],idx+1)) return 1;
        
        
        return 0;
        
    }
    
    bool makesquare(vector<int>& m) {
        int sum=0;
        
        for(int i=0;i<m.size();i++) sum+=m[i];
        
        if((sum%4)!=0) return 0;
        
        sort(m.begin(),m.end(),greater<int>());
        
        tar=sum/4;
        return is(m,0,0,0,0,0);
    }
};