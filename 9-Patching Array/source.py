nums = [int(i) for i in input().split()]
n = int(input())

mx_till_now = 0
ptr = 0
ans = 0
while mx_till_now < n and ptr < len(nums):
    if nums[ptr]-1 > mx_till_now:
       while mx_till_now < nums[ptr]-1:
           mx_till_now = 2 *mx_till_now + 1
           ans += 1
    mx_till_now += nums[ptr]
    ptr+=1

if mx_till_now < n:
    mx_till_now += (n-mx_till_now)
    ans +=1

print(ans)