# LeetCode problem 859. Buddy Strings (easy)
# Algorithm: Test if 2 characters can be swapped in string A to result in string B by:
#            1) Making sure the strings are equal length (swap won't change length so it can never be equal)
#            2) Counting the number of characters that are different. (a string with swappable characters can only have 0 or 2 differences)
#            3) If 0 difference, check for a duplicate character that can be swapped (if all characters are unique, no swap can be made)
#            4) Testing if a string with 2 differences can swap the different characters and be the desired string

class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):                # Test if string has same length
            return False
        count = 0
        index1 = index2 = -1
        alphabet = [0 for i in range(26)]
        for i, ch in enumerate(A):          # Test if string has 2 characters that are different between A and B
            if A[i] != B[i]:
                count += 1
                if count > 2:
                    return False
                elif index1 == -1:
                    index1 = i
                else:
                    index2 = i
            alphabet[string.ascii_lowercase.index(A[i])] += 1
        if count == 0:                      # Test if string is the same but has a duplicate that it can swap
            if len(A) > 26:                     # only 26 letters in alphabet so one must be duplicate
                return True
            for x in alphabet:
                if x > 1:
                    return True
        if count != 2:
            return False
        tempCh = A[index1]
        C = ""
        for i, ch in enumerate(A):          # Test if swapping the 2 characters creates the desired string
            if i == index1:
                C += A[index2]
            elif i == index2:
                C += A[index1]
            else:
                C += A[i]
        if C == B:
            return True
        return False