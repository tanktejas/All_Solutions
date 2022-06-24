class Solution {
public:
    bool isPossible(vector<int>& tar) {
      sort(tar.begin(),tar.end());
      reverse(tar.begin(),tar.end());
      int n=tar.size();
        long long sum=0;
     
      priority_queue<int>q;
        
      for(int i=0;i<n;i++){
           q.push(tar[i]);      
         sum+=tar[i];
      }
    
      while(!q.empty())
      {
          auto ele=q.top();
          q.pop();
          
          if(ele==1) continue;
              
          
          if(sum==ele or (ele<=(sum-ele))) return 0;
          
           int add=sum-ele;
           int mod=ele%add;  
          // int add=ele%sum;
          
          if((add)==1) mod=1; 
          sum-=ele;
          
          q.push(mod);
          sum+=(mod);
      }
        return 1;
    }
};