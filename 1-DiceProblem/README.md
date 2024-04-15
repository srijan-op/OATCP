# 1-DiceProblem

## Algorithm:

In order to solve this problem we can make use of dyanmic programming. Let dp[n] be the number of possible ways to create n using dice rolls. We can see that the following equation holds:

```
dp[n] = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-4] + dp[n-5] + dp[n-6]
```

Since for every dp[n-i] for i in [1, 6], we can further roll a die and that will contribute as a combination. Thus, we can sum these up to calculate dp[n]. Base case is dp[0] = 1.  We can iterate over all n in [1, sum] and calculate the required number of combinations. Modular addiion has also been used to prevent integer overflow and meet the problem constraints.

### Time Complexity: O(N) where N = sum which has to be constructed

### Space Complexity: O(N) where N = sum which has to be constructed