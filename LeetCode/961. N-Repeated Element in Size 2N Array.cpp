// LeetCode problem 961. N-Repeated Element in Size 2N Array (easy)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> searchSet;
        for (int i = 0; i < A.size(); i++)
        {
            if(searchSet.count(A[i]))
            {
                return A[i];
            }
            else
            {
                searchSet.emplace(A[i]);
            }
        }
        return -1;
    }
};