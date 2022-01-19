n = int(input())

row = 1

while row<=n:
    col = 1
    value = row
    while col <= row:
        print(value, end="")
        value = value + 1
        col = col + 1
    print()
    row = row + 1;
    
