class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int bestCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                current++;
            }
            else{
                current = 0;
            }
            if(current > bestCount){
                bestCount = current;
            }
        }
        return bestCount;
    }
};