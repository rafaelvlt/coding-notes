def adjacency_list_to_matrix(adjlist):
    n = len(adjlist)
    adjmatrix = [[0] * n for _ in range(n)]
    
    for node in range(n):
        for index in adjlist[node]:
            adjmatrix[node][index] = 1

    for node in range(n):
        print(adjmatrix[node])

    return adjmatrix
