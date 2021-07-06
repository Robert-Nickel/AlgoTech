def partition(numbers):
    A = [] # leeres Array a anlegen
    B = [] # leeres Array b anlegen
    sum_A = 0 # Summe A auf 0 setzen
    sum_B = 0 # Summe B auf 0 setzen
    for n in sorted(numbers, reverse=True): # sort descending
        if sum_A < sum_B: # left side smaller right side
           A.append(n) #  -> add something to the left
           sum_A = sum_A + n # increase the sum of added element
        else: # right side smaller than left side
           B.append(n) # -> add something on the right
           sum_B = sum_B + n # increase the sum of the right side
    return (A, B) # return the tupel 

print(partition([4,4,8]))