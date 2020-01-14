// 1252. Cells with Odd Values in a Matrix

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int count = 0;
        int tempArray[n][m];
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                tempArray[i][j] = 0;
            }
        }
        for(int x = 0; x<indices.size(); x++)
        {
            int j = indices[x][0];
            int k = indices[x][1];
            for(int i = 0; i< m; i++)
            {
                tempArray[j][i]++;
            }
            for(int i = 0; i< n; i++)
            {
                tempArray[i][k]++;
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                bool test = tempArray[i][j] % 2 == 1;
                if(test)
                {
                    count++;
                }
            }
        }
        return count;
    }
};