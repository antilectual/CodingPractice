#LeetCode problem 905. Sort Array By Parity (easy)

#Algorithm - add even and odds to their own lists. Return the concatenation of evens + odds.
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        evens = []
        odds = []
        for val in A:
            if val % 2 == 0:
                evens.append(val)
            else:
                odds.append(val)
        return evens + odds
    