class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];

        int currentMax = 0;
        int currentMin = 0;
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currentMax = max(currentMax, 0);
            currentMax += nums[i];
            maxSum = max(maxSum, currentMax);

            currentMin = min(currentMin, 0);
            currentMin += nums[i];
            minSum = min(minSum, currentMin);

            totalSum += nums[i];
        }

        if(maxSum < 0){
            return maxSum;
        }

        int circularMax = totalSum - minSum;

        return max(maxSum, circularMax);
    }
};