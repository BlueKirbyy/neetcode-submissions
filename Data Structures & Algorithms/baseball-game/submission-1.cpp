#include <string>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        //loop through each element in the ops array
        //keep track of total score with var int total
        //if + then total += ops[i] + ops[i - 1]
        //if c then total -= ops[i]
        //if d then total = ops[i] * 2

        int total = 0;
        vector<int> scores;

        for(int i = 0; i < operations.size(); i++){
            if (operations[i] == "+") {
            // handle +
                scores.push_back(scores[scores.size() - 2] + scores[scores.size() - 1]);
            }
            else if (operations[i] == "C") {
                // handle C
                scores.pop_back();
            }
            else if (operations[i] == "D") {
                // handle D
                scores.push_back(scores.back() * 2);
            }
            else {
                scores.push_back(stoi(operations[i]));
            }
        }
        for(int i = 0; i < scores.size(); i++){
            total += scores[i];
        }
        return total;
    }
};