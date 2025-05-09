def lcs(a, b):
    len_a = len(a)
    len_b = len(b)
    dp = [[0]*(len_b+1) for _ in range (len_a+1)]
    
    for i in range(1,len_a+1):
        for j in range(1,len_b+1):
            if a[i-1]==b[j-1]: # 같은 경우
                dp[i][j] = dp[i-1][j-1] + 1
            else : # 다른 경우
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[len_a][len_b]               

str1 = input()
str2 = input()

print(lcs(str1, str2))