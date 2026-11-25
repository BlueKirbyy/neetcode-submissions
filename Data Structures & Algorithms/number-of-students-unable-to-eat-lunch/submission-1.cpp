class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> studentQueue;

        for(int i = 0; i < students.size(); i++){
            studentQueue.push(students[i]);
        }
        int sandwichIndex = 0;
        int rejected = 0;
        while(!studentQueue.empty() && rejected != studentQueue.size()){
            if(studentQueue.front() == sandwiches[sandwichIndex]){
                rejected = 0;
                studentQueue.pop();
                sandwichIndex++;
            }else{
                rejected++;

                studentQueue.push(studentQueue.front());
                studentQueue.pop();
            }
        }
        return studentQueue.size();
    }
};