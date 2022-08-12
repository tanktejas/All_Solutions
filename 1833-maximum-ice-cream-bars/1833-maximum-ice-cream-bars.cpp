class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        sort(c.begin(),c.end());
        int b=0;
        int buy=0;
        while(b<c.size() and (coins-c[b])>=0){
            coins-=(c[b]);
            buy++;
            b++;
        }
        
        return buy;
    }
};