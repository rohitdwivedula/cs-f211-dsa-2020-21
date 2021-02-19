# Editorials

## A: Challenge Accepted!
You are given a string (`S`) of length `N (<= 500)` and asked to find if it contains the substring "baab" (`M=4`) anywhere in it. Since the constraints for M and N are very small, you can use a naive brute force search to find the string (if the constraint of recursion wasn't there). Psuedocode for this solution assuming strings are one indexed:

```
for i in range [1 ... N-M+1]:
	if S[i, i+4] == "baab":
		return True, i
return False
```
The time complexity of this solution is O(M * N). 

Take a look at the PDF `1A.pdf` in this directory for a more detailed description of a possible approach modelling this problem as a finite state machine. Another approach would be to use the [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm) for a linear time algorithm. 