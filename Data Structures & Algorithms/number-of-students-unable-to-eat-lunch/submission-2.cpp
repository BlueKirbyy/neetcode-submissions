class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> studentQueue;

        for(int i = 0; i < students.size(); i++){
            studentQueue.push(students[i]);
        }
        int sandwichIdx = 0;
        int rejected = 0;

        while(!studentQueue.empty() && rejected != studentQueue.size()){
            if(studentQueue.front() == sandwiches[sandwichIdx]){
                rejected = 0;
                sandwichIdx++;
                studentQueue.pop();
            }
            else{
                rejected++;
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
            }
        }
        return studentQueue.size();
    }
};