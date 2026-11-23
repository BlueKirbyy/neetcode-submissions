class Solution {
public:
    bool isValid(string s) {
        //create an array to store the left most symbols
        //loop through s, add each of the starting chars to the end of the arry. (, {, [)
        //if not those symbols, perform a series of checks
        //check for ( . if symbols array is empty or if the last element of the symbols array does not match the ( char, return false. else, we have a valid match, remove the starting char from the symbols array.
        // check for }. perform the same steps as above.
        //check for ]. perform the same steps as above
        //if we make it through the end of the loop, return true because that means we were able to successfully remove each of the elements in the symbols array because we found a match.

        vector<char> symbols;
        char parentheses = '(';
        char squig = '{';
        char bracket = '[';

        for(int i = 0; i < s.size(); i++){
            if(s[i] == parentheses || s[i] == squig || s[i] == bracket){
                symbols.push_back(s[i]);
            }
            else if(s[i] == ')'){
                if(symbols.empty() || symbols[symbols.size() - 1] != parentheses){
                    return false;
                }
                symbols.pop_back();
            }
            else if(s[i] == '}'){
                if(symbols.empty() || symbols[symbols.size() - 1] != squig){
                    return false;
                }
                symbols.pop_back();
            }
            else if(s[i] == ']'){
                if(symbols.empty() || symbols[symbols.size() - 1] != bracket){
                    return false;
                }
                symbols.pop_back();
            }
        }
        return symbols.empty();

    }
};
