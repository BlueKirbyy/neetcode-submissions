#include <string>
#include <vector>
#include <stack>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> scores;
        int total = 0;

        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int first = scores.top();
                scores.pop();
                int second = scores.top();
                int newScore = first + second;
                scores.push(first);
                scores.push(newScore);
            }
            else if(operations[i] == "D"){
                int prevScore = scores.top();
                int newScore = prevScore * 2;
                scores.push(newScore);
            }
            else if(operations[i] == "C"){
                scores.pop();
            }
            else{
                scores.push(std::stoi(operations[i]));
            }
        }

        while(!scores.empty()){
            total += scores.top();
            scores.pop();
        }
        return total;
    }
};