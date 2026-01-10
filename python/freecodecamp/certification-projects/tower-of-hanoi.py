def hanoi_solver(disk_number):
    disk1 = [i for i in range(1, disk_number+1)]
    disk1 = disk1[::-1]
    disk2 = []
    disk3 = []
    game = [disk1, disk2, disk3]
    string = str(disk1) + ' ' + str(disk2) + ' ' + str(disk3)
    string = solve(game, disk_number, 1, 3, string)
    return string

def solve(array, amount, start, end, string):
    if (amount == 0):
        return string
    other = 6 - start - end
    string = solve(array, amount-1, start, other, string)
    array[end-1].append(amount)
    array[start-1].remove(amount)
    string += '\n' + str(array[0]) + ' ' + str(array[1]) + ' ' + str(array[2]) 
    string = solve(array, amount-1, other, end, string)

    return string 
    
