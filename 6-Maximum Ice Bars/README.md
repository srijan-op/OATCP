# 6-Maximum Ice Bars

## Algorithm:

This problem can be solved using a simple greedy approach. We can sort the prices of the ice-creams in non decreasing order and then greedily pick the ice-creams starting from the cheapest to ensure the maximum number of ice-creams. We can prove the greedy approach always works by contradiction.

Let us assume that the ice-creams are sorted in non decreasing order and you have k coins remaining. If a case ever arises that we will choose to pick arr[1] over arr[0], it means that we must be left with more money in order to buy more ice-creams with the leftover money. However, since our array is sorted in non-decreasing order we can say that arr[0] <- arr[1] which is contradictory to our situation, since picking arr[0] over arr[1] will always ensure you are left with more or the same amount of money. Hence, it will always be optimal to pick the cheaper ice-creams first. Hence proved. 

### Time Complexity: O(N*log(N)) where N = number of ice-creams

### Space Complexity: O(1) (Assuming we use quick sort or any in place sorting algorithm)