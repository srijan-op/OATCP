# 3-Maximum Product Subarray

## Algorithm:

We can try to solve this problem by calculating the maximum product subarray ending at ith index of the array for all i = [0, n-1] and then choose the maximum among them as our final answer. To calculate the maximum product subarray ending at each index we have three choices:

1. Multiply the number with the maxiumum product subarray ending at the index just before it.
2. Multiply the number with the minimum product subarray ending at the index just before it.
3. Do not multiply the number and assume the number alone to be the maximum product subarray ending at the index. 

Thus, dp recurrence will be as follows:

```
max_subarray[i] = max(max_subarray[i-1] * arr[i], min_subarray[i-1] * arr[i], arr[i])
min_subarray[i] = min(min_subarray[i-1] * arr[i], min_subarray[i-1] * arr[i], arr[i])   
```

With base case being:

```
max_subarray[i] = arr[0]
min_subarray[i] = arr[0]
```

And the final answer:

```
ans = max(max_subarray[i]) for i in [0, n-1]
```

We can further optimize this by using individual dp variables instead of a dp array which has been done in the source code.

Modular multiplication to prevent integer overflow and meet the problem constraints.


### Time Complexity: O(N) where N = length of the array

### Space Complexity: O(1) 