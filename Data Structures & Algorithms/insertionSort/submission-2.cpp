class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> result;

        if (pairs.empty()) {
            return result;
        }

        result.push_back(pairs);

        for (int i = 1; i < pairs.size(); i++) {
            int j = i;

            while (j > 0 && pairs[j].key < pairs[j - 1].key) {
                Pair temp = pairs[j];
                pairs[j] = pairs[j - 1];
                pairs[j - 1] = temp;

                j--;
            }

            result.push_back(pairs);
        }

        return result;
    }
};