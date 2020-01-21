// Leetcode 1021. Remove Outermost Parentheses (easy)

// Algorithm - Finds outer opening parenthesis. Matches following opening parenthesis to closing parenthesis until it finds  a closing without a matched opening which will be the closing to an outer opening parenthesis.
// Optimizations: Matching changed from utilizing a stack, to a simple count comparison of open vs closed parenthesis.
// Optimization: String concatenations done only when finding closing outer parenthesis. Concatenates a substring instead of char by char.
class Solution {
public:
    string removeOuterParentheses(string S) {
        bool foundOuter = false;
        int openParenCount = 0;
        int subStringSize = 0;
        int subStringStart = 1;
        string resultStr;
        for(int i = 0; i < S.size(); i++)
        {
            // case where we find the opening of an outer parenthesis i.e expecting '(' with no '(' previously stored.
            if(!openParenCount && !foundOuter)
            {
                foundOuter = true;
                subStringStart = i + 1;
                subStringSize = 0;
            }
            // case where we only have an outer parenthesis.  If we find a closing, we have a matching outer and we reset.
            // otherwise we increment the count of open parenthesis found.
            else if(!openParenCount)
            {
                // found closing outer
                if(S[i] == ')')
                {
                    foundOuter = false;
                    resultStr = resultStr + S.substr(subStringStart, subStringSize);
                }
                // opening parenthesis part of result.
                else
                {
                    openParenCount++;
                    subStringSize++;
                }
            }
            // case where the count isn't 0: i.e. we are not looking for a closing outer parenthesis.
            // must be part of the string. increment/decrement count based on if we are matching. 
            // Increments substring size as this substring must be part of the final string.
            else
            {
                // increment opening parenthesis
                if(S[i] == '(')
                {
                    openParenCount++;
                }
                // decrement on closing parenthesis
                else
                {
                    openParenCount--;
                }
                subStringSize++;
            }
        }
        return resultStr;
    }
};