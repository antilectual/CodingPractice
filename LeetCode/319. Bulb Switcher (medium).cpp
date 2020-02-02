// Leetcode Problem 319. Bulb Switcher (medium)

// Algorithm: Brute force solution that follows the problem description. Create an array for all bulbs with them starting as "on". Skip first round as that is what turns them on. Iterate through all bulbs toggling on/off every xth bulb n-1 times where x is the iteration number.
class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulbs(n, true);
        int x = 2;
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = x-1; j<n; j+=x)
            {
                bulbs[j] = bulbs[j] ^ 1;
            }
            x++;
        }
        for(int i = 0; i < n; i++)
        {
            if(bulbs[i] == true)
            {
                count++;
            }
        }
        return count;
    }
};