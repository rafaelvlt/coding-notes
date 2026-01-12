def fibonacci(n):
    sequence = [0, 1]
    sequence = sequence + [0] * (n -1)
    
    for i in range(2, n+1):
        sequence[i] = sequence[i-1] + sequence[i-2]
    
    return sequence[n]
