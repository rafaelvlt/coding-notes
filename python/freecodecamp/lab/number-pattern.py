def number_pattern(n):
    if not isinstance(n, int):
        return "Argument must be an integer value."
    if n < 1:
        return "Argument must be an integer greater than 0."
    final_string = ""
    for i in range(1, n+1):
        if (i != n):
            final_string += str(i) + ' '
        else:
            final_string += str(i)

    return final_string

