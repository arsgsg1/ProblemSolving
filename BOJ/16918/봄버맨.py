from collections import deque
R, C, N = map(int, input().split())
arr = [[] for _ in range(R)]
for r in range(R):
    for x in input():
        arr[r].append((x, 3) if x == 'O' else (x, -1))
#input end
dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]
def set_bomb(R: int, C: int, time: int):
    for r in range(R):
        for c in range(C):
            if arr[r][c][0] == '.':
                arr[r][c] = ('O', time + 3)

def in_range(r: int, c: int) -> bool:
    return r >= 0 and c >= 0 and r < R and c < C

def explode(q: deque):
    while q:
        r, c = q.popleft()
        arr[r][c] = ('.', -1)
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]
            if not in_range(nr, nc): continue
            arr[nr][nc] = ('.', -1)

def find_limit_bomb(R: int, C: int, time: int):
    q = deque([])
    for r in range(R):
        for c in range(C):
            if arr[r][c][0] == 'O' and arr[r][c][1] == time:
                q.append((r, c))
    explode(q)

#function end
time = 1
while time < N:
    time += 1
    set_bomb(R, C, time)
    if time >= N: break
    time += 1
    find_limit_bomb(R, C, time)

for r in range(R):
    for c in range(C):
        print(f"{arr[r][c][0]}", end='')
    print()