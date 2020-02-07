# LeetCode problem 468. Validate IP Address (medium)

class Solution:
    def validIPAddress(self, IP: str) -> str:
        if(self.testValidIPV4Address(IP)):
            return "IPv4"
        if(self.testValidIPV6Address(IP)):
            return "IPv6"
        return "Neither"
        
    def testValidIPV4Address(self, IP: str):
        valueList = IP.split('.')
        if (len(valueList) != 4):                   # case of not having 4 pieces
            return False
        for x in valueList:
            if (x == ""):                           # case of empty
                return False
            try:                                    # case of not a number
                int(x)
                int(x[0])                           # case of negative -_-
            except:
                return False
            if (int(x) < 0 or int(x) > 255):        # case of invalid number
                return False
            if( len(x) != 1 and x[0] == '0'):       # case of leading 0
                return False
        return True
    
    def testValidIPV6Address(self, IP: str):
        valueList = IP.split(':')
        if (len(valueList) != 8):
            return False
        for x in valueList:
            if (x == ""):                           # case of empty
                return False
            try:                                    # case of not a number
                int(x,16)
                int(x[0], 16)                       # case of negative -_-
            except:
                return False
            a = hex(int(x, 16))[2:]
            if(int(x, 16) != 0 and a.upper() != x.lstrip('0').upper()):             # case of validating legal hex value
                return False
            if(len(x) > 4):                         # case of too many digits or leading 0's
                return False
            #if(int(x, 16) == 0 and (len(x) == 2 or len(x) == 3)):   # case of leading zeros on 0
            #    return False
        return True