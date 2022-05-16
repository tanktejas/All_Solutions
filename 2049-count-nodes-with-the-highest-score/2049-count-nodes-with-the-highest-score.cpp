class Solution {
public:
    
    int find(int node,long long &maxi,int n,vector<pair<int,int>> &tree,int &cnt){
        
        if(node==-1) return 0;
        
        if(tree[node].first==-1 and tree[node].second==-1){
             if((n-1)==maxi){
                cnt++;   
             }else if((n-1)>maxi){
                cnt=1;
                 maxi=n-1;
             }
            
            return 1;
        }
        
        long long left=find(tree[node].first,maxi,n,tree,cnt);
        long long right=find(tree[node].second,maxi,n,tree,cnt);
        
        long long temp=1;
        if(left!=0) temp*=left;
        if(right!=0) temp*=right;
        
        if((n-(left+right+1))!=0) temp*=(n-(left+right+1));
        
        
        if(temp==maxi){
            cnt++;   
        }else if(temp>maxi){
            maxi=temp;
            cnt=1;
        }
         
         
        return left+right+1;
    }
    
    int countHighestScoreNodes(vector<int>& pa) {
        int n=pa.size();
        vector<pair<int,int>>tree(n,make_pair(-1,-1));
        
        for(int i=1;i<n;i++){
            int child=i;
            int par=pa[i];
            
            if(tree[par].first==-1) tree[par].first=child;
            else tree[par].second=child;
            
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<tree[i].first<<" "<<tree[i].second<<endl;
        // }
        int cnt=0;
        long long  maxi=0;
        
        find(0,maxi,n,tree,cnt);
        
        return cnt;
    }
};