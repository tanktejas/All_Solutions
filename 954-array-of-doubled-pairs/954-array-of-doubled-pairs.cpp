bool cmp(int a,int b){
    
     if(a==b){
         return 0; 
     }
    
     if(a==0 and b==0){
         return 0;
     }
      
     if(a==0 or b==0) return a < b;
     
     if(a>0 and b>0){
         return a<b;
     }
    
    if(a<0 and b<0){
        return abs(a) < abs(b);
    }
    
    if((a<0 and b>0) or (a>0 and b<0)){
         return a<b;
    }
    
    return 0;
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
      
        bool bo=1;
        int n=arr.size();
 
        //hashing logic 
        
          map<int,int>m;
        
          for(int i=0;i<arr.size();i++){
              m[arr[i]]++;
          }
          
          for(int i=0;i<arr.size();i++){
              
              if(m[arr[i]]){
              
              if(m[arr[i]*2]) m[arr[i]*2]--; 
              else bo=0;
              
              m[arr[i]]--;
                  
              }
          }
        
        return bo;
    }
};
