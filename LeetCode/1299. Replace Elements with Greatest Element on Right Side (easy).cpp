// 1299. Replace Elements with Greatest Element on Right Side

// Algorithm: iterate the array from right to left finding the largest value and replacing the current value in the same index in a copy of the array
// Note: does not modify the array arr.  Would require copying elements from the copy back to arr.
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> replacedElements;
        int currentMax = -1;
        for(int i = arr.size() -1; i >= 0; i--)
        {
            replacedElements.emplace(replacedElements.begin(), currentMax);
            if(arr[i] > currentMax)
            {
                currentMax = arr[i];
            }
        }
        return replacedElements;
    }
};