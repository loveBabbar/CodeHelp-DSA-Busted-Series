n = int(input())
row = 1

while row <= n:
    #Print karo space (1st triangle)
    space = n - row 
    while space:
        print(" ", end="")
        space = space - 1

    #print 2nd triangle 
    j = 1
    while j <= row:
        print(j, end="")
        j = j + 1

    #print 3rd triangle
    start = row - 1
    while start:
        print(start, end="")
        start = start - 1

    print()
    row = row + 1
