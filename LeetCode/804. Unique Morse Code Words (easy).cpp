// Leetcode 804. Unique Morse Code Words (easy)

// Algorithm - Iterates through the words building the morse code version and adds it to the map (where the index is the morse code word)
//             The map will have a size() that is equal to the number of unique morse code words added which is returned.
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        string commaDelimitedMorseLetters =
            ".-,-...,-.-.,-..,.,..-.,--.,....,..,.---,-.-,.-..,--,-.,---,.--.,--.-,.-.,...,-,..-,...-,.--,-..-,-.--,--..,";
        vector<string> morseLetters;
        int lastStart = 0;
        // Build a vector of the morse code alphabet. Find a comma delimter and add all characters between it and the previous comma.
        for(int i = 0; i < commaDelimitedMorseLetters.size(); i++)
        {
            if(commaDelimitedMorseLetters[i] == ',')
            {
                morseLetters.push_back(commaDelimitedMorseLetters.substr(lastStart, i-lastStart));
                lastStart = i + 1;
            }
        }
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
                if(i <= 0)
                {
                    cout << "zen = " + morseLetters[25] + " " + morseLetters['e' - 'a'] + " " + morseLetters['n' - 'a'] << endl;
                    cout << "gin = " + morseLetters['g' - 'a'] + " " + morseLetters['i' - 'a'] + " " + morseLetters['n' - 'a'] << endl;   
                }
            }
        }
        return transformations.size();
    }
};