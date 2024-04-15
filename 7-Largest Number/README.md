# 7-Largest Number

## Algorithm:

This problem can be solved by sorting the numbers using a custom comparator which works on the basis of a simple greedy algorithm. Assume all the numbers as strings, let us say we have 2 number strings s1 and s2. We can see that we should always order the strings according to the following comparator:

```
s1 < s2 if s1 + s2 > s2 + s1
s2 > s1 otherwise
```

Let us assume that a number string contains XXX__XXX and we have to fill s1 and s2 in between. We can go with 2 options either XXX(s1)(s2)XXX or XXX(s2)(s1)XXX. If s1 + s2 > s2 + s1 then it means that s1 contains larger digits which should be coming at significant place in the final number as compared to the digits in s2, since XXX(s1)(s2)XXX >= XXX(s2)(s1)XXX will always hold true. Hence, we can sort the array according to the above comparator and then join all of them to create a string in that order to get our final answer.

### Time Complexity: O(N\*M\*log(N\*M)) where N = number of number strings in the array and M = length of each number string 

### Space Complexity: O(N*M) where N = number of number strings in the array and M = length of each number string