class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> word1;
        std::unordered_map<char, int> word2;

        for(int i = 0; i < s.size(); i++){
            word1[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            word2[t[i]]++;
        }
        return word1 == word2;
    }
};
