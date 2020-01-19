// Leetcode 657. Robot Return to Origin (easy)

// Naively assumes valid input string
// Algorithm - Increments and decrements position based on a given move.  After all moves completed, tests pos against 0,0
class Solution {
public:
    bool judgeCircle(string moves) {
        int vertPos = 0, horizPos = 0;
        
        for(int i = 0; i<moves.size(); i++)
        {
            switch(moves[i])
            {
                case 'L':
                        horizPos--;
                        break;    
                case 'R':
                        horizPos++;
                        break;    
                case 'U':
                        vertPos++;
                        break;    
                case 'D':
                        vertPos--;
                        break;    
                default:
                        break;
            };
        }
        
        if(vertPos == 0 && horizPos == 0)
        {
            return true;
        }
        return false;
    }
};