# LeetCode problem 680. Valid Palindrome II
# Algorithm: Spaghetti Code.  Checks palindrome property from outsides in using 2 pointers.  Only 1 delete allowed (skipCount keeps track)

class Solution:
    def validPalindrome(self, s: str) -> bool:
        maxSkip = 1
        skipCount = 0
        leftPtr = 0
        rightPtr = len(s)-1
        while rightPtr >= leftPtr:
            if s[leftPtr] == s[rightPtr]:                               # Case: Palindrome property still holds true
                leftPtr += 1
                rightPtr -= 1
            elif s[leftPtr+1] == s[rightPtr] and skipCount < maxSkip:   # Case: Delete left corrects palindrome sequence
                if leftPtr + 2 > rightPtr - 1:                          # End of Palindrome
                    return True
                elif s[leftPtr+2] == s[rightPtr-1]:                     # Continue
                    skipCount += 1
                    leftPtr += 2
                    rightPtr -= 1
                elif s[leftPtr] == s[rightPtr -1]:                      # Case: Left fails on next but Delete right corrects palindrome sequence
                    if leftPtr > rightPtr -2:
                        return True
                    elif s[leftPtr+1] == s[rightPtr-2]:
                        skipCount += 1                                                          
                        leftPtr += 1
                        rightPtr -= 2
                    else:
                        return False                                    # Delete left fails on next, delete right fails on next = full fail
                else:
                    return False                                        # Delete left fails on next, delete right fails = full fail
            elif s[leftPtr] == s[rightPtr -1] and skipCount < maxSkip:  # Case: Delete right corrects palindrome sequence
                if leftPtr > rightPtr -2:
                    return True
                elif s[leftPtr+1] == s[rightPtr-2]:
                    skipCount += 1                                                          
                    leftPtr += 1
                    rightPtr -= 2
                else:
                    return False                                        # Left fails and delete right cannot correct palindrome
            else:                                                       # Delete left or right cannot correct palindrome
                return False
                
            if skipCount > maxSkip:                                     # Too many deletes required
                return False
        
        return True
                
        