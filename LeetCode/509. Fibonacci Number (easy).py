# LeetCode problem 509. Fibonacci Number (easy)

# Algorithm: Pre-calculate first 30 fibonacci numbers and store them.  Retrieve and return the appropriate Nth value from memory.
class Solution:
    fibNumbers = []
    isPreCalculated = False
    def fib(self, N: int) -> int:
        if(N < 0):
            return -1
        if(N == 0):
            return 0
        elif(N == 1):
            return 1
        if not self.isPreCalculated:
            current = 1
            last = 0
            self.fibNumbers.append(current)
            for i in range(2,31):
                temp = last
                last = current
                current = temp + current
                self.fibNumbers.append(current)
            self.isPreCalculated = True
        return self.fibNumbers[N-1]
    