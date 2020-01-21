// Leetcode 1021. Remove Outermost Parentheses (easy)

// Algorithm - Finds outer opening parenthesis. Matches following opening parenthesis to closing parenthesis until it finds  a closing without a matched opening which will be the closing to an outer opening parenthesis.
// VERY naively assumes string input is valid.
class Solution {
public:
    string removeOuterParentheses(string S) {
        //vector<char> outerParenStack;
        //vector<char> innerParenStack;
        bool foundOuter = false;
        vector<char> parenStack;
        string resultStr;
        for(int i = 0; i < S.size(); i++)
        {
            // case where we find the opening of an outer parenthesis i.e expecting '(' with no '(' previously stored.
            if(parenStack.empty() && !foundOuter)
            {
                if(S[i] == '(') // if statement shouldn't be necessary. If all are matched, next should always be '('
                {
                    foundOuter = true;
                }
            }
            // case where we only have an outer parenthesis.  If we find a closing, we have a matching outer and we reset.
            // otherwise we add a new opening parenthesis to the stack and the stack is no longer empty.
            else if(parenStack.empty())
            {
                // found closing outer
                if(S[i] == ')')
                {
                    foundOuter = false;    
                }
                // push new opening to stack and adding to the string
                else
                {
                    parenStack.push_back(S[i]);
                    resultStr = resultStr + S[i];
                }
            }
            // case where the stack isn't empty: i.e. we are not looking for a closing outer parenthesis.
            // must be part of the string. push/pop based on if we are matching. 
            // Naively assumes valid string where ')' matches  to appropraite'('
            else
            {
                // push opening parenthesis
                if(S[i] == '(')
                {
                    parenStack.push_back(S[i]);
                }
                // pop on closing parenthesis
                else
                {
                    parenStack.pop_back();
                }
                resultStr = resultStr + S[i];
            }
        }
        return resultStr;
    }
};