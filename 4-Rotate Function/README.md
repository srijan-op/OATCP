# 4-Rotate Function

## Algorithm:

To solve this problem, we need to make a couple observations. Since calculating F(0)...F(n-1) individually will take a lot of time, we can instead try calculating F(0) and then try to derive the F(1)...F(n-1) in constant time each. If we try to see the relationship between F(0) and F(1), we can notice that the difference between the two is that all the numbers have their factors increased by except the last number whose factor is reset to 0. Thus we can write formally:

```
F(1) = F(0) + (sum_of_all_nums - arr[n-1]) - ((n-1) * arr[n-1])
     = F(0) + sum_of_all_nums - (n * arr[n-1])
```

Hence, the generalized form becomes:

```
F(i) = F(i-1) + sum_of_all_nums - (n * arr[n-i])
```

Thus, we can calculate F(0) and then proceed to calculated all F(1)...F(n-1) and choose the maximum among them.

### Time Complexity: O(N) where N = length of the array

### Space Complexity: O(1) 