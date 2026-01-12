def dfs_n_queens(n):
    if (n < 1):
        return []
    
    solutions = []
    ans = [-1 for _ in range(n)]
    dfs(0, ans, n, solutions)
    return solutions
def dfs(row, ans, n, solutions):
    if ans[n-1] != -1:
        solutions.append(ans[:])
        return
    for col in range(n):   
        if not is_valid(row, col, ans):
            continue
        ans[row] = col
        dfs(row+1, ans, n, solutions)
        ans[row] = -1


def is_valid(row, col, ans):
    if ans[row] != -1:
        return False
    if col in ans:
        return False
    
    for i in range(row):
        if (abs(i - row) == abs(ans[i] - col)):
            return False

    return True
    
