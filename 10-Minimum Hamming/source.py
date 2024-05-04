nums = [int(i) for i in input().split()]

all_bits = []

for num in nums:
    num_bits = format(num, '032b')
    all_bits.append(num_bits)

ans = 0

for bit in range(0, 32):
    on_bits = 0
    for num in all_bits:
        on_bits += int(num[bit])
    ans += on_bits * (len(nums) - on_bits)

print(ans)    