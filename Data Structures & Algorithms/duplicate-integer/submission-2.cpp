class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); i++){
            vals[nums[i]]++;
            if(vals[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};