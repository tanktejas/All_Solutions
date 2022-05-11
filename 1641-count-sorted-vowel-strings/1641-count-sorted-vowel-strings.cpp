class Solution {
public:
    int ans=0; 
    void dorecur(int n,int s){
        if(s>=5){
            return ;
        }
        if(n==0){
            ans++;
            return ;
        }
         
          dorecur(n-1,s);
          dorecur(n,s+1); 
    }
    int countVowelStrings(int n) {
        dorecur(n,0);
        return ans;
    }
};