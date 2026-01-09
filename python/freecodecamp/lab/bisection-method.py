def square_root_bisection(number, epsilon=0.1, max_iterations=50):
    if (number < 0):
        raise ValueError("Square root of negative number is not defined in real numbers")

    if (number == 0 or number == 1):
        print(f"The square root of {number} is {number}")
        return number
    else:
        root = None
        hi = max(1, number)
        lo = 0
        for i in range(0, max_iterations):
            mid = (hi + lo)/2
            if (hi - lo < epsilon):
                root = mid
                break
            elif mid**2 > number:
                hi = mid
            else:
                lo = mid
        
        if root == None:
            print(f"Failed to converge within {max_iterations} iterations")
            return None
        else:
            print(f"The square root of {number} is approximately {root}")
            return root

