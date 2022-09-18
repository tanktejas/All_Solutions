class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>s;
        int n=height.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        { 
            while(!s.empty() and height[s.top()] < height[i])
            {
                int y=height[s.top()];
                s.pop();
                
                if(s.empty()) break;
                
                ans+=((min(height[i],height[s.top()])-y)*(i-s.top()-1)); 
            } 
            s.push(i);   
        }
        
        return ans;
    }
};