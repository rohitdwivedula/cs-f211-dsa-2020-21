# Editorials

## A: Big Sum
Summing two very large `N` digit numbers can be solved in O(N) time. Start with two pointers on the least significant bit and add digitwise, while maintaining how muvh to `carry` over to the next digit. An implementation of this problem which uses O(N) space is given in `A.c`. Note that this problem can be solved with O(1) space as well, by adding in place.