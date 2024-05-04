# 10-Minimum Hamming

## Algorithm:

This problem can be solved naively by calculating the Hamming Distance of all possible pairs, however there is faster approach available which can bring the complexity down to O(N). We can observe that whenever we calculate the Hamming distance between two numbers, all the bit pairs contribute individually to the final answer. We can thus, calculate the answer contributed by all such pairs for each ith bit in a number. Assuming all numbers can be expressed in 32 bits, we can iterate over all the number's ith bit and check whether it is on or off, and maintain the final on_bits and off_count count. Since, only the pairs which have their ith bits different contribute to the answer, we can thus calculate the answer contributed by all ith bits of the numbers by calculating the number of pairs where the ith bits are different. In this way, we can calculate the answer for a single bit in O(N) and, the final answer can be calculated by summing the answers for all bits, whose count will not exceed 32.   

### Time Complexity: O(N * 32) = O(N) (Ammortized)

### Space Complexity: O(1)