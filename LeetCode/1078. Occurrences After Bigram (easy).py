# LeetCode problem 1078. Occurrences After Bigram (easy)
# Algorithm: Iterate the words in the string looking for sequences of 3 where i = first, i+1 = second, and i+2 = third. Appends third to result list.
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        wordList = text.split()
        length = len(wordList)
        result = []
        for i,word in enumerate(wordList):
            if word == first:
                if i < length - 2:
                    if wordList[i+1] == second:
                        result.append(wordList[i+2])
        return result
                        