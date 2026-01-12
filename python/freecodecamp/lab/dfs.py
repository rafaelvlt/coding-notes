def dfs(adjmatrix, start_node):
    n = len(adjmatrix)
    visited = [False] * n
    stack = []
    stack.append(start_node)
    visited[start_node] = True
    reachable = [start_node]
    while(stack):
        current_node = stack.pop()
        for i in range(n):
            if (adjmatrix[current_node][i] and not visited[i]):
                stack.append(i)
                visited[i] = True
                reachable.append(i)

    return reachable


