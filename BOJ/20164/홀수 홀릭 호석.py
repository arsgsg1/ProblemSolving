'''
while 한자리 수가 될때까지
    1. 홀수의 개수를 누적
    2. 한자리수이면 최댓값, 최솟값 저장하고 break
    3. 두자리 수이면 2개로 나눠 합을 구함
        - 0 < n < len(a) - 1
        - a[:n], a[n:]
    4. 세자리 수이면 임의의 위치에서 3개의 수로 분할하고 3개를 더함
        - 0 < first < end < len(a) - 1
        - a[:first], a[first:end], a[end:]
output 1의 최솟값과 최댓값
'''
max_cnt, min_cnt = 0, 1e10
N = input()
def is_odd(nums: str) -> bool:
    return int(nums) % 2 == 1
def recur(nums: str, acc_sum: int):
    global max_cnt, min_cnt
    cnt = 0
    for num in nums:
        if is_odd(num):
            cnt += 1
    if len(nums) <= 1:
        max_cnt = max(acc_sum + cnt, max_cnt)
        min_cnt = min(acc_sum + cnt, min_cnt)
        return
    elif len(nums) == 2:
        for i in range(1, len(nums)):
            a, b = int(nums[:i]), int(nums[i:])
            recur(str(a + b), acc_sum + cnt)
    elif len(nums) >= 3:
        for i in range(1, len(nums)):
            for j in range(i + 1, len(nums)):
                a, b, c = int(nums[:i]), int(nums[i:j]), int(nums[j:])
                recur(str(a + b + c), acc_sum + cnt)
    return
recur(N, 0)
print(min_cnt, max_cnt)