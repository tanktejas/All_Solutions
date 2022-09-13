class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        vector<string>v;
        int n=data.size();
        
        for(int i=0;i<n;i++)
        {
            int ele=data[i];
            string gg="";
            
            for(int j=0;j<8;j++)
            {
                gg+=('0' + (ele%2));
                ele/=2;
            }
            reverse(gg.begin(),gg.end());
            v.push_back(gg);  
        } 
        int i=0;
        while(i<n)
        {
            int howmany=0;
            
            for(int j=0;j<8;j++)
            {
                if(v[i][j]=='0') break;
                else howmany++;
            } 
            
            if(howmany>4 or howmany==1) return 0; 
            if(howmany!=0)
               howmany--;
             
            i++;   
            while(howmany>0 and i<n)
            {
                if(v[i][0]!='1' or v[i][1]!='0') break; 
                howmany--;
                i++;
            } 
            
            if(howmany) return 0; 
            
        }
             
        return 1;
    }
};