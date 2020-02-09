# LeetCode problem  151. Reverse Words in a String (medium)
# Algorithm: Reverse words in a string. Easily done python!
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        newString = ""
        for i, word in enumerate(words):
            if(i != 0):
                word = word + " "
            newString = word + newString
        return newString