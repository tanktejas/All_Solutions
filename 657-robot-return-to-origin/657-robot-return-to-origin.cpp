class Solution {
public:
    bool judgeCircle(string moves) {
        int udd=0,lrd=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U') udd++;
            if(moves[i]=='D') udd--;
            if(moves[i]=='L') lrd++;
            if(moves[i]=='R') lrd--;
        }
        
        return udd==0 and lrd==0;
    }
};