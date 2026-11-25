class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<int, int> string1;
        std::unordered_map<int, int> string2;

        for(int i = 0; i < s.size(); i++){
            string1[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            string2[t[i]]++;
        }
        return string1 == string2;
    }
};
