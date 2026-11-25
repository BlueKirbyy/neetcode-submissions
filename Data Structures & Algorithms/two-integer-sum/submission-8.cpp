class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> vals;
        for(int i = 0; i < nums.size(); i++){
            vals[nums[i]] = i;       
        }
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(vals.find(comp) != vals.end() && vals[comp] != i){
                return {i, vals[comp]};
            }
        }
        return {};
    }
};
