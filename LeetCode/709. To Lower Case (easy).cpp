// 709. To Lower Case (easy)

class Solution {
public:
    // iterate string for uppercase characters and convert them to lowercase characters.
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;    
            }
        }
        return str;
    }
};