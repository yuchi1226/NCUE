class Node:
    def __init__(self, level, benefit, weight, include):
        self.level = level
        self.benefit = benefit
        self.weight = weight
        self.include = include

def bound(node, n, M, p, w):
    if node.weight >= M:
        return 0
    else:
        result = node.benefit
        j = node.level + 1
        totalWeight = node.weight
        while j < n and totalWeight + w[j] <= M:
            totalWeight += w[j]
            result += p[j]
            j += 1
        if j < n:
            result += (M - totalWeight) * p[j] / w[j]
        return result

def branchAndBound(M, n, p, w):
    queue = []
    root = Node(-1, 0, 0, [])
    queue.append(root)
    maxProfit = 0
    while queue:
        currentNode = queue.pop(0)
        if currentNode.level == -1:
            nextLevel = 0
        else:
            nextLevel = currentNode.level + 1
        if nextLevel == n:
            continue
        include = list(currentNode.include)
        include.append(1)
        left = Node(nextLevel, currentNode.benefit + p[nextLevel], currentNode.weight + w[nextLevel], include)
        left.bound = bound(left, n, M, p, w)
        if left.weight <= M and left.benefit > maxProfit:
            maxProfit = left.benefit
            bestNode = left
        if left.bound > maxProfit:
            queue.append(left)
        include.pop()
        include.append(0)
        right = Node(nextLevel, currentNode.benefit, currentNode.weight, include)
        right.bound = bound(right, n, M, p, w)
        if right.weight <= M and right.benefit > maxProfit:
            maxProfit = right.benefit
            bestNode = right
        if right.bound > maxProfit:
            queue.append(right)
    return bestNode

# 讀取輸入檔案
with open('input.txt', 'r') as file:
    data = file.readlines()

M, n = map(int, data[0].split())
p = list(map(int, data[1].split()))
w = list(map(int, data[2].split()))

resultNode = branchAndBound(M, n, p, w)

# 輸出展開節點資訊
for i in range(len(resultNode.include)):
    print(resultNode.include[i], end='')
print(f" LB={resultNode.benefit} UB={resultNode.bound}")

# 輸出最後選擇結果
print(f"最後選擇結果 總獲利 {resultNode.benefit}")
