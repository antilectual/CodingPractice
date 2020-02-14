# LeetCode problem 557. Reverse Words in a String III (easy)
# Algorithm: Split the string into words and reverse words one by one then concatenate the reversed words.

class Solution:
    def reverseWords(self, s: str) -> str:
        if s == "":
            return s
        wordList = s.split()
        result = ""
        result += wordList[0][::-1]
        for word in wordList[1:]:
            result = result + " " + word[::-1]
        return result