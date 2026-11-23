class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //first element should be -1
        //loop backwards through the array
        //take the value in greatest and store it in current index
        //keep track of the greatest value to the right of the array
        //if current > greatest, greatest = current

        int greatest = -1;

        for(int i = arr.size() - 1; i >= 0; i--){
            int current = arr[i];
            arr[i] = greatest;

            if(current > greatest){
                greatest = current;
            }
        }
        return arr;
    }
};