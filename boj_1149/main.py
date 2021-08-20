# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


import sys

input = sys.stdin.readline

house_number = int(input())
dp = []

for i in range(house_number):
    dp.append(list(map(int,input().split())))

for i in range(1,len(dp)):
    dp[i][0] = min(dp[i - 1][1] , dp[i - 1][2]) + dp[i][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + dp[i][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][2]

print(min(dp[house_number-1][0],dp[house_number-1][1],dp[house_number-1][2]))