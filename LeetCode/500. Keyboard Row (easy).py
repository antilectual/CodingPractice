# LeetCode problem 500. Keyboard Row (easy)
# Algorithm: For each word in the list, test the first letter to see which keyboard row it is in.  Then test every other letter in the word to ensure it is in the same row.  If they are, add it to the results list.

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        firstRow = ["q","w","e","r","t","y","u","i","o","p"]
        secondRow = ["a","s","d","f","g","h","j","k","l"]
        thirdRow = ["z","x","c","v","b","n","m"]
        results = []
        if words == [] or words == None:
            return words
        for word in words:
            testWord = word.lower()
            testRow = []
            if testWord[0] in firstRow:
                testRow = firstRow
            elif testWord[0] in secondRow:
                testRow = secondRow
            elif testWord[0] in thirdRow:
                testRow = thirdRow
            test = True
            for l in testWord:
                if l not in testRow:
                    test = False
                    break
            if test == True:
                results.append(word)
        return results