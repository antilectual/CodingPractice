# LeetCode problem 942. DI String Match (easy)
# Algorithm: Count the amount of decreases, chooses x = to that count. 
#            When an increase occurs, use the next higher unused value above x. 
#            When an decrease occurs, use the next loweer unused value above x. 
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        result = []
        countI = 0
        countD = 0
        minVal = 0
        maxMax = 0
        n = len(S)
        for i in S:
            if(i == "I"):
                countI += 1
        countD = n - countI
        minVal = maxVal = countD
        result.append(countD)
        for x in S:
            if(x == "I"):
                maxVal += 1
                result.append(maxVal)
            else:
                minVal -= 1
                result.append(minVal)
        return result
