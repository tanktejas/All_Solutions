class Solution {
public:
    int minMoves(int tar, int maxd) {
        int op=0;
        while(tar!=1){
            if(tar&1){
                
                tar-=1;
                op++;
            }else{
                if(maxd)
                {  
                    tar/=2;
                    maxd--;
                }else{ 
                    op+=(tar-1);
                    break;
                    tar-=1;
                }
                op++;
            }
        }
        return op;
    }
};