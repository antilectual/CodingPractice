// LeetCode problem 852. Peak Index in a Mountain Array (easy)
// Algorithm: Simple solution: Problem states A is a "mountain", thus we only need to find when values stop increasing. Iterates from start of array.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0;
        while(A[i] <= A[i+1])
        {
            i++;
        }
        return i;
    }
};