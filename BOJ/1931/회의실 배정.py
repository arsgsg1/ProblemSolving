'''
시작 시간이 빠른 순으로 정렬 -> 반례 존재
걸리는 시간이 빠른 순으로 정렬 -> 반례 존재
끝나는 시간이 빠른 순으로 정렬
'''
import sys
import heapq as hq
input = sys.stdin.readline
N = int(input())
q, cur, answer = [], 0, 0
for _ in range(N):
    st, en = map(int, input().split())
    hq.heappush(q, (en, st))
while q:
    en, st = hq.heappop(q)
    if cur <= st:
        #print(st, en)
        cur = en
        answer += 1
print(answer)