// LeetCode problem 344. Reverse String (easy)
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tempChar1;
        for(int i = 0; i < s.size() / 2; i++)
        {
            tempChar1 = s[i];
            s[i] = s[s.size() - (i + 1)];
            s[s.size() - (i + 1)] = tempChar1;
        }
    }
};