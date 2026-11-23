class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // init a new array called nums which is of length 2 * nums
        //for each value in nums, set ans[i] = nums[i]

        vector<int> ans(nums.size() * 2, 0);

        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
};