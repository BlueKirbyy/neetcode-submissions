class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); i++){
            vals[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(vals.find(complement) != vals.end() && vals[complement] != i){
                return {i, vals[complement]};
            }
        }
        return {};
    }
};
