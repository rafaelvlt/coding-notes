def quick_sort(array):
    if (len(array) == 0):
        return []
    if (len(array) == 1):
        return array

    high = len(array) - 1
    pivot = array[high]
    
    less = [i for i in array if i < pivot]
    equal = [i for i in array if i == pivot]
    greater = [i for i in array if i > pivot]

    final = quick_sort(less)
    final.extend(equal)
    final.extend(quick_sort(greater))

    return final

