def verify_card_number(digits):
    sum = 0
    double = False
    for digit in digits[::-1]:
        if digit == '-' or digit == ' ':
            pass
        else:
            if not double:
                sum += int(digit)
                double = True
            else:
                digit_sum = int(digit) * 2
                digit = str(digit_sum)
                digit_sum =  int(digit[0]) + int(digit[1]) if len(digit) == 2 else int(digit[0])
                sum += digit_sum
                double = False

    if sum % 10 == 0:
        return "VALID!"
    else:
        return "INVALID!"



