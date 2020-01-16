// 1282. Group the People Given the Group Size They Belong To (medium)
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
/*
Algorithm:
Iterates through each item in groupSizes finding an ID not assigned to a group.  When an ID is found, iterates the rest of  groupSizes finding more people from that group and marking them as assigned until it is full;
Assumes the following constraints:
    - n is an ID
    - groupSizes.length == n
    - 1 <= groupSizes[i] <= n
    - A solution exists where all groups are full and all n can be assigned.
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groupings;
        vector<bool> isUsed(groupSizes.size());
        // populate isUsed with false
        for(int i = 0; i < isUsed.size(); i++)
        {
            isUsed[i] = 0;
        }
        for(int i = 0; i<groupSizes.size(); i++)
        {
            if(isUsed[i] == false)
            {   
                int countFromCurrentGroup = 0;
                vector<int> tempGroup;
                // iterate goupSizes and fill vector with more values that fit group until full
                for(int j = i; j<groupSizes.size(); j++)
                {
                    // if we have filled our group, start next group
                    if(countFromCurrentGroup >= groupSizes[i])
                    {
                        break;
                    }
                    // if we haven't used it and it's the same as what we're looking for
                    else if(isUsed[j] == false && groupSizes[j] == groupSizes[i])
                    {
                        tempGroup.push_back(j);
                        isUsed[j] = true;
                        countFromCurrentGroup++;
                    }
                }
                groupings.push_back(tempGroup);
            }
        } 
        return groupings;
    }
};