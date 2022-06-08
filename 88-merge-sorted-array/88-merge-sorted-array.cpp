class Solution {
public:      
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
        if(n==0) return ;
    
        for(int k=m;k<(m+n);k++){
            nums1[k]=nums2[k-m];
        }
        
        int gap=(m+n);
        while(gap > 0){
            int i=0;
            for(int i=0;(gap+i)<(n+m);i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i],nums1[i+gap]);
                }
            }
            if(gap<=1) gap=0;
            else 
             gap=(gap/2)+(gap%2);
        }
        
    }
};