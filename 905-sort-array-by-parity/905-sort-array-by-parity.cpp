class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
         vector<int>temp=nums;
        while(i<j){
            if(temp[j]%2 == 0){
                swap(temp[j],temp[i]);
                i++;
            }else if(temp[i]%2){ 
                swap(temp[i],temp[j]);
                j--;
            }else{
                i++;
                j--;
            }
        }
        return temp;
    }
};