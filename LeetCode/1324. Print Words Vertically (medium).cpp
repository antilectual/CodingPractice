// LeetCode Problem 1324. Print Words Vertically (medium)
// https://leetcode.com/problems/print-words-vertically/

// Takes a list of words and prints new words fromed by the ith letter of each word in the list.
class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream original(s);
        string tempString;
        vector<string> wordList, vertWordList;
        int maxWordLength = 0;
        while(original >> tempString)
        {
            wordList.push_back(tempString);
            if(tempString.size() > maxWordLength)
            {
                maxWordLength = tempString.size();
            }

        }
        
        for(int i = 0; i < maxWordLength; i++)
        {
            tempString = "";
            int trailingSpaces = 0;
            for(int j = 0; j < wordList.size(); j++)
            {
                // Make sure there are enough letters in the word, otherwise it's a space.
                if(i < wordList[j].size())
                {
                    // only add spaces if we found a letter after them (No trailing spaces allowed)
                    for(int k = 0; k < trailingSpaces; k++) 
                    {
                        tempString += " ";
                    }
                    tempString += wordList[j][i];
                    trailingSpaces = 0;
                }
                else
                {
                    trailingSpaces++;
                }
            }
            vertWordList.push_back(tempString);
        }
        return vertWordList;
    }
};