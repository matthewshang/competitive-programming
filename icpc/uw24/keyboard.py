from collections import defaultdict

s = input()

table = [
    [' ', 'A', 'B', ' ', ' '], 
    [' ', 'C', 'D', 'E', ' '],
    ['F', 'G', 'H', 'I', 'J'],
    ['K', 'L', 'M', 'N', 'O'],
    ['P', 'Q', 'R', 'S', 'T'],
    [' ', 'U', 'V', 'W', ' '],
    [' ', 'X', 'Y', ' ', ' '],
    [' ', ' ', 'Z', ' ', ' ']]

n, m = len(table), len(table[0])

g = defaultdict(list)
for i in range(n):
    for j in range(m):
        if table[i][j] == ' ':
            continue
        
        c = table[i][j]
        if i == 0 or table[i - 1][j] == ' ':
            end = n - 1
            while table[end][j] == ' ':
                end -= 1
            g[c].append(table[end][j])
        else:
            g[c].append(table[i - 1][j])
        
        if i == n - 1 or table[i + 1][j] == ' ':
            end = 0
            while table[end][j] == ' ':
                end += 1
            g[c].append(table[end][j])
        else:
            g[c].append(table[i + 1][j])
        
        if j == 0 or table[i][j - 1] == ' ':
            end = m - 1
            while table[i][end] == ' ':
                end -= 1
            g[c].append(table[i][end])
        else:
            g[c].append(table[i][j - 1])
        
        if j == m - 1 or table[i][j + 1] == ' ':
            end = 0
            while table[i][end] == ' ':
                end += 1
            g[c].append(table[i][end])
        else:
            g[c].append(table[i][j + 1])

def idx(c):
    return ord(c) - ord('A')

INF = 1000000
dist = [[INF] * 26 for _ in range(26)]
for i in range(26):
    c = chr(i + ord('A'))
    dist[i][i] = 0
    for next in g[c]:
        if next == c:
            continue
        dist[idx(c)][idx(next)] = 1
        dist[idx(next)][idx(c)] = 1

for k in range(26):
    for i in range(26):
        for j in range(26):
            if dist[i][j] > dist[i][k] + dist[k][j] and dist[i][k] != INF and dist[k][j] != INF:
                dist[i][j] = dist[i][k] + dist[k][j]

def solve():
    ans = dist[idx('A')][idx(s[0])]
    for i in range(len(s) - 1):
        ans += dist[idx(s[i])][idx(s[i + 1])]
    ans += len(s)
    print(ans)
solve()