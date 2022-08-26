class Solution {
public:
     vector<int>v;
     int no;
    
    bool op(int i)
    {
        if(i==no)
        {
            int num=0;
            for(int i=0;i<no;i++)
            { 
                if(i==0 and v[i]==0){
                    return 0;
                }
                num=(num*10)+(v[i]); 
            }   
            return (num&(num-1))==0; 
        }
        bool h=0;
        
        for(int j=i;j<no;j++)
        {        
            swap(v[i],v[j]);
            h|=op(i+1);
            swap(v[i],v[j]);
        }
        
        return h;
    }
    
    bool reorderedPowerOf2(int n) {
        while(n)
        {
            v.push_back(n%10);
            n/=10;
        }
       
        reverse(v.begin(),v.end());
        no=v.size(); 
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        
       return op(0);
    }
};