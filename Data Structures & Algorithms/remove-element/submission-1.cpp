class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //keep track of index values not = val
        int k = 0;

        //loop through each index
        //if index value != val, k++ and let nums[k] = nums[i] (place the number at the front of the array)
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};