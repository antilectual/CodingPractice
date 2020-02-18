# LeetCode problem 1217. Play with Chips (easy)
# Algorithm explanation: Since moving 2 places is free, all odds and all evens can be stacked together for free. We just have to determine if it's cheaper to move all odds or all evens by figuring out which there are fewer of.
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odds = evens = 0
        for i in chips:
            if (i % 2 == 1):
                odds += 1
            else:
                evens += 1
        return min(odds, evens)