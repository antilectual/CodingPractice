# LeetCode problem 389. Find the Difference (easy)
# Algorithm: Add the letters in s, subtract the letters in t.  The value that doesn't balance to 0 is the extra character.

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        counts = dict.fromkeys(string.ascii_lowercase, 0)
        result = ""
        for i,ch in enumerate(s):       # count the letters in s and t
            counts[s[i]] += 1
            counts[t[i]] -= 1
        counts[t[-1]] -= 1              # count the extra letter in t
        for ch in counts:
            if counts[ch] != 0:
                result = ch
                break
        return result