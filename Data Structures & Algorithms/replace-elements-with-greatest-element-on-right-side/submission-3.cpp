class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            int currentBest = -1;
            for(int j = i + 1; j < arr.size(); j++){
                if(arr[j] > currentBest){
                    currentBest = arr[j];
                }
            }
            arr[i] = currentBest;
        }
        return arr;
    }
};