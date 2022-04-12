class Solution {
public:
    vector<int>size;
    vector<int>parent;
    
    int findpar(int ele){
        if(parent[ele]==ele){
            return ele;
        }
        return parent[ele]=findpar(parent[ele]);
    }
       
    void makepar(int fir,int sec)
    {
        int par1=findpar(fir),par2=findpar(sec);
        if(size[par1]<size[par2]){
            parent[par1]=par2;
            // size[par2]+=size[par1];
            // size[par1]=0;
        }else if(size[par1]>=size[par2]){
            parent[par2]=par1;
            // size[par1]+=size[par2];
            // size[par2]=0;
        } 
    }
    bool equationsPossible(vector<string>& eq) {
         size.resize(27,0);
         parent.resize(27,0);
     
        for(int i=0;i<27;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<eq.size();i++){
            string equat=eq[i];
            int n1=equat[0]-'a';
            int n2=equat[3]-'a';
            char operand=equat[1];
            if(operand=='='){      
                makepar(n1,n2);
            } 
            
        }  
        
        for(int i=0;i<eq.size();i++){
            string equat=eq[i];
            int n1=equat[0]-'a';
            int n2=equat[3]-'a'; 
            char operand=equat[1];
            if(operand=='!'){   
               int parn1=findpar(n1);
               int parn2=findpar(n2);
                
                    if(parn1==parn2){
                         return 0;
                    } 
                
            } 
            
        }
        return 1;
    }
};