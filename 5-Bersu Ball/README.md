# 5-Bersu Ball

## Algorithm:

We can solve this problem using dyanamic programming. We can divide the problem into smaller subproblems and work our way up from there. Let dp[i][j] be the maximum number of pairs which can be formed from boys[i...n-1] and girls[j..n-1]. We can see that we have 2 options to pick from in this case:

1. We are able to match the i-th boy with the j-th girl and thus dp[i][j] becomes 1 + dp[i+1][j+1]
2. We are not able to match the i-th boy with the j-th girl in which case we can pick the maximum among dp[i+1][j] and dp[i][j+1]

Hence our dp recurrence will now become:

```
dp[i][j] = max {
                1 + dp[i+1][j+1] if abs(boys[i] - girls[j]) <= 1 else 0
                dp[i+1][j]
                dp[i][j+1]
            }
```

Since we cannot make any pairs once we have exhausted either of boys or girls the base case becomes:

```
dp[i][j] = 0 if i >= len(boys) or j >= len(girls)
```

Then, our final answer becomes:

```
dp[0][0]
```

### Time Complexity: O(N*M) where N = number of boys and M = number of girls

### Space Complexity: O(N*M) where N = number of boys and M = number of girls