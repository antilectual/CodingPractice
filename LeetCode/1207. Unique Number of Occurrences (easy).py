# LeetCode problem 1207. Unique Number of Occurrences (easy)

# Algorithm: Creates a map of values and the number of times they appear. Creates a list of unique counts.  If a count is found to already exist in the list as it is being added, the counts are not unique.
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        countDict = {}
        uniques = {}
        #initialize counts to 0
        for x in arr:
            countDict[x] = 0
        #count values
        for x in arr:
            countDict[x] += 1
        for val in countDict:
            if countDict[val] in uniques.keys():
                return False
            else:
                uniques[countDict[val]] = 1
        return True
        
            