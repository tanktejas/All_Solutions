class Solution {
public:      
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0; 
        if(n==0) return ;
        
        while(i<m){       
            if(nums1[i]>nums2[0]){  
                swap(nums1[i],nums2[0]);
                int j=0;
                while(j<(n-1)  and nums2[j]>nums2[j+1]){
                    swap(nums2[j],nums2[j+1]);
                    j++;
                }
            }
            i++;
        }
       
        for(int k=m;k<(m+n);k++){
            nums1[k]=nums2[k-m];
        }
        
    }
};