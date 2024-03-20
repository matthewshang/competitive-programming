from collections import Counter

T = int(input())
for tc in range(1, T + 1):
    N, K = map(int, input().split())
    S = map(int, input().split())
    count = Counter(S)
    res = "NO" if K * 2 < N or count.most_common(1)[0][1] > 2 else "YES"
    print(f"Case #{tc}: {res}")
