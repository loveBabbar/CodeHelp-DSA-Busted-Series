n = int(input())
row = 1

while row <= n:
    # space print karlo
    space = n - row
    while space:
        print(" ", end="")
        space = space - 1

    #stars print karlo
    col = 1;
    while col <= row:
        print("*", end="")
        col = col + 1

    print()
    row = row + 1
    
