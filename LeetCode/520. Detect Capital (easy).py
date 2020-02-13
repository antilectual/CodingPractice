# LeetCode problem 520. Detect Capital (easy)
# Algorithm: Using python built-in methods to test all upper, or lower except first char (upper or lower case on first char is okay)
#            For not using built-ins could iterate the characters in the word to test all within the bounds of upper case, 
#            or all except first are within the bounds of lower case ASCII.
#            All empty and 1 character strings are valid.
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.isupper() or word[1:].islower() or len(word) < 2