struct cmp{
   bool operator()(pair<int,int> a,pair<int,int> b){
       if(a.first == b.first) return a.second > b.second;
       
       return a.first > b.first;
   }  
};

struct cmp1{
   bool operator()(pair<int,int> a,pair<int,int> b){
       if(a.first == b.first) return a.second > b.second;
       
       return a.first > b.first;
   }  
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& se, vector<int>& ta) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>avai;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>unavai;
        int m=se.size();
        int n=ta.size();
        vector<int>ans(n);
        
        for(int i=0;i<m;i++){
           avai.push(make_pair(se[i],i));     
          
        }   
         int time=0;
        for(int i=0;i<n;i++){
            
            if(time<i) time=i;
            
            while(!unavai.empty() and unavai.top().first <= (time)){
                auto y=unavai.top();
                unavai.pop(); 
                avai.push({se[y.second],y.second});
                
            }    
            
            if(avai.empty()){
               
               auto tp=unavai.top();
               unavai.pop();
               time=tp.first;
                
               avai.push({se[tp.second],tp.second});
                
                while(!unavai.empty() and unavai.top().first == tp.first){
                     auto tpp=unavai.top();
                     unavai.pop(); 
                     avai.push({se[tpp.second],tpp.second}); 
                }   
                     
            }   
                 auto tt=avai.top();
                 avai.pop();
                 ans[i]=tt.second;  
                 unavai.push({time+ta[i],tt.second}); 
      } 
        return ans;
    }
};