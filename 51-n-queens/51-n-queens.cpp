class Solution {
public:
    vector<vector<string>>ans;
    vector<string>currans;
    
    bool issafe(int row,int col,int n){
        
        int f=row,s=col;
        
        while(f>=0 and s>=0){
            if(currans[f][s]=='Q') return 0;
            f--;
            s--;
        }
        
        f=row,s=col;
        
        while(f>=0){
            if(currans[f][s]=='Q') return 0;
            f--;
        }
        
        f=row,s=col;
        
        while(f>=0 and s<=n){
          if(currans[f][s]=='Q') return 0; 
            f--;
            s++;
        }
        
        return 1;
        
    }
    
    void find(int row,int n){
        
        if(row==n){
            ans.push_back(currans);
            return ;
        }
        
        for(int col=0;col<n;col++){
            
            if(issafe(row,col,n)){
                currans[row][col]='Q';
                
                find(row+1,n);
                
                currans[row][col]='.';  
                
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
      
      string temp="";
      for(int i=0;i<n;i++){
          temp+='.';
      }
      for(int i=0;i<n;i++){
          currans.push_back(temp);
      }  
        
      find(0,n);   
    
      return ans;
    }
};