// Leetcode problem 1266. Minimum Time Visiting All Points (easy)

// Explaination:
//              Absolute value is magnitude of distance between x points or y points.
//              Since diagonals are equivalent to horizontal/vertical, optimal is to take diagonals whenever possible.
//              If x and y values are equal, a diagonal can be used.  
//              Anything excess beyond min(x, y) are vertical or horizontal traversal that needs to be added after diagonal traversal.
//
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        long distance = 0;
        for(int i = 0; i < points.size() - 1; i++)
        {
            int x = 0, y = 0;
            x = abs(points[i][0] - points[i+1][0]);
            y = abs(points[i][1] - points[i+1][1]);
            distance += abs(x-y) + min(x,y);
        }
        return distance;
    }
};