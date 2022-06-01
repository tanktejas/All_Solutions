class Solution {
public:
    
    //forula used :- abs(a-b) = { a-b, -(a-b) };
    // and expand full expression and observe.
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
        int mx1=INT_MIN,mi1=INT_MAX,mx2=INT_MIN,mi2=INT_MAX,mx3=INT_MIN,mi3=INT_MAX,mx4=INT_MIN,mi4=INT_MAX;
        
        int n=a1.size();
        for(int i=0;i<n;i++){
            mx1=max(mx1,a1[i]+a2[i]+i);
            mi1=min(mi1,a1[i]+a2[i]+i);
            
            mx2=max(mx2,i-a1[i]-a2[i]);
            mi2=min(mi2,i-a2[i]-a1[i]);
            
            mx3=max(mx3,i+a1[i]-a2[i]);
            mi3=min(mi3,i+a1[i]-a2[i]);
            
            mx4=max(mx4,i-a1[i]+a2[i]);
            mi4=min(mi4,i-a1[i]+a2[i]);
        }
        
        return max(max(mx1-mi1,mx2-mi2),max(mx3-mi3,mx4-mi4));
    }
};       