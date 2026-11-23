class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //init the greatest value with - 1
        //loop backwards through arr, setting current index value to current var
        //set current index value to best
        //if current > best, best becomes current
        //return arr

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