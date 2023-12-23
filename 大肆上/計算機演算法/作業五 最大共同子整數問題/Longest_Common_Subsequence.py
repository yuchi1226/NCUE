def largest_common_sub_integer(n1, n2):
    str_n1 = str(n1)
    str_n2 = str(n2)

    len_n1 = len(str_n1)
    len_n2 = len(str_n2)

    dp = [[0] * (len_n2 + 1) for _ in range(len_n1 + 1)]

    for i in range(1, len_n1 + 1):
        for j in range(1, len_n2 + 1):
            if str_n1[i - 1] == str_n2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[len_n1][len_n2]

# 讀取檔案
with open('input.txt', 'r') as file:
    lines = file.readlines()

# 處理每一行輸入
for line in lines:
    inputs = line.strip().split()
    n1 = int(inputs[0])
    n2 = int(inputs[1])

    result = largest_common_sub_integer(n1, n2)
    print(result)
