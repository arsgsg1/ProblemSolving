import sys
from collections import defaultdict, deque
ans_dict = defaultdict(list)
graph = [[] for _ in range(N + 1)]
input = sys.stdin.readline
#define end
N, M = map(int, input().split())
for _ in range(M):
    e, s = map(int, input().split())
    graph[s].append(e)
#input end
def bfs(start: int) -> int: #노드 개수를 반환
    global N
    cnt = 0
    visit = [False for _ in range(N + 1)]
    q = deque([start])
    visit[start] = True
    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            if not visit[nxt]:
                cnt += 1
                visit[nxt] = True
                q.append(nxt)
    return cnt
#function end
for i in range(1, N + 1):
    ans_dict[bfs(i)].append(i)
l = sorted(ans_dict.keys(), reverse=True)
print(*ans_dict[l[0]])
#main end