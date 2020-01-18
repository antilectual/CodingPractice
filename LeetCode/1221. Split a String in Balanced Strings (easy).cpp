// 1221. Split a String in Balanced Strings (easy)

// Algorithm - Iterate the string count L's and R's and whenever they are equal, increment the balance count.
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0, countL = 0, countR = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'L')
            {
                countL++;
            }
            if(s[i] == 'R')
            {
                countR++;
            }
            if(countL == countR)
            {
                count++;
            }
        }
        return count;
    }
};