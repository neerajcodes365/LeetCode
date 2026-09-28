class Solution:
    def h(self,s):
        h=int(s[:2])*60*60
        m=int(s[3:5])*60
        s=int(s[6:])
        return h+m+s

    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        return self.h(endTime)-self.h(startTime)