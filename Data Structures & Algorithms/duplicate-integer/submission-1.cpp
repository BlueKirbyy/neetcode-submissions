class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); i++){
            if(vals.find(nums[i]) != vals.end()){
                return true;
            }
            else{
                vals[nums[i]]++;
            }
        }
        return false;
    }
};