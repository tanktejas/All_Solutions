class Solution {
public:      
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   
        vector<int>ui(m+n);
        for(int i=0;i<m;i++)
        {
            ui[i]=nums1[i];
        }
        
        for(int i=0;i<n;i++){
            ui[i+m]=nums2[i];
        }        
        
        sort(ui.begin(),ui.end());
        
        nums1=ui;
    }
};

