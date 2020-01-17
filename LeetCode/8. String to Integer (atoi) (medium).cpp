// 8. String to Integer (atoi) (medium)
// convert a string to an integer
// 

class Solution {
public:
    int myAtoi(string str) {
        bool isNegative = 0;
        int count = 0, start = 0, digitPlace = 0, numDigits = 0;
        long currentInt = 0;
        
        // skips white space (and negative sign if it exists) and finds if the number is positive or negative
        for(int i = 0; i <str.size(); i++)
        {
            if(str[i] != ' ')
            {
                start = i;
                if(str[i] == '-')
                {
                    isNegative=true;
                    start++;
                    i++;
                }
                if(str[i] == '+')
                {
					// bugfix - catch doubles
                    if(str[i-1] == '-')
                    {
                        return 0;
                    }
                    start++;
                    i++;
                }
                // bugfix - skip leading 0's
                for(int j = i; j<str.size(); j++)
                {
                    if(str[j] == '0')
                    {
                        start++;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
        }
        
        // counts how many digits for the purpose of placing values in the correct location in the integer
        for(int i = start; i < str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                numDigits++;
            }
            else
            {
                break;
            }
        }
        // Constructs the integer. Starts with the integer start location in the string
        for(int i = start; i < str.size(); i++)
        {
            digitPlace = i - start + 1;
            if(str[i] >= '0' && str[i] <= '9')
            {
                int currentDigit = str[i] - '0';
                if(numDigits > 10)
                {
                    currentInt = INT_MAX;
                    currentInt += 2;
                }
                else
                {
                    currentInt += currentDigit * pow(10, numDigits - digitPlace);    
                }
                // Testing for overflow during number construction to prevent testing absurdly long numbers
                if(currentInt >= INT_MAX && !isNegative)
                {
                    return INT_MAX;
                }
                if(currentInt * -1 <= INT_MIN && isNegative)
                {
                    return INT_MIN;
                }
            }
            else
            {
                break;
            }
        }
        if(isNegative)
        {
            currentInt *= -1;
        }
        return (int) currentInt;
    }
};