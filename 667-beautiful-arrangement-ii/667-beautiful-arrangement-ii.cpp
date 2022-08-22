class Solution {
public:
 
    vector<int> constructArray(int n, int k) {
        int i=1;
        
        int j=n;
        vector<int>ans;
        int diff=n-k-1;
        
        while(diff--)
        {
            ans.push_back(i);
            i++;
        }
        
        while(i<j)
        {
            ans.push_back(i);
            ans.push_back(j);
            i++,j--;
        }
        if(i==j) ans.push_back(i);
        
        return ans;
    }
};