// Leetcode 804. Unique Morse Code Words (easy)

// Algorithm - Iterates through the words building the morse code version and adds it to the map (where the index is the morse code word)
//             The map will have a size() that is equal to the number of unique morse code words added which is returned.
// 2019/1/20 - Update: No longer parsing the string to create the vector
// 2019/1/20 - Update: Removed debug code.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        
        vector<string> morseLetters =         {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string, string> transformations;
        string stringBuild;
        
        // Algorithm
        for(int i = 0; i < words.size(); i++)
        {
            stringBuild = "";
            for(int j = 0; j < words[i].size(); j++)
            {
                int mLIndex = words[i][j] - 'a';
                stringBuild = stringBuild + morseLetters[mLIndex];
            }
            if(stringBuild != "")
            {
                transformations[stringBuild] = words[i];  
            }
        }
        return transformations.size();
    }
};