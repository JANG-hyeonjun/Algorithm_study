# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


import sys

input = sys.stdin.readline
#만약 문자열을 저장하고 싶을 경우 .rstrip()을 추가해라
seq_size = int(input())
sequence = list(map(int,input().split()))

dp = [1] * seq_size

for i in range(seq_size):
    for j in range(i):
        if sequence[i] > sequence[j]:
            dp[i] = max(dp[i],dp[j] + 1)

print(max(dp))
#이렇게 간단했다니 허허...