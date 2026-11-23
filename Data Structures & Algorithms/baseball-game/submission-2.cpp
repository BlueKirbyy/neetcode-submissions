#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> scores;

        for(int i = 0; i < operations.size(); i++){

            if(operations[i] == "+"){
                int last = scores.top();
                scores.pop();
                int secondLast = scores.top();
                scores.push(last);
                int newScore = last + secondLast;
                scores.push(newScore);
            }
            else if(operations[i] == "D"){
                int newScore = scores.top() * 2;
                scores.push(newScore);
            }
            else if(operations[i] == "C"){
                scores.pop();
            }
            else{
                scores.push(std::stoi(operations[i]));
            }
        }

        int total = 0;

        while(!scores.empty()){
            total += scores.top();
            scores.pop();
        }

        return total;
    }
};