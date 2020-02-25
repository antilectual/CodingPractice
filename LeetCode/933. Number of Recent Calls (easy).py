# LeetCode problem 933. Number of Recent Calls (easy)
# Algorithm - Add pings to queue as they come in.  If the current ping is over 3000 seconds after the previous ping, pop it from the queue.  The length of the queue is the number of pings within 3000.

class RecentCounter:

    count = 0
    pings = []
    def __init__(self):
        self.count = 0
        self.pings = []

    def ping(self, t: int) -> int:
        self.pings.append(t)
        while(t - 3000 > self.pings[0]):
            self.pings.pop(0)
        return len(self.pings)
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)