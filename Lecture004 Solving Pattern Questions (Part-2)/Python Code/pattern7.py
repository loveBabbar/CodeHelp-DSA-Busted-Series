n = int(input())

row = 1

while row <= n:
    col = 1
    while col <= row:
        ch = (ord('A') + row + col - 2)
        print(chr(ch), end="")
        col = col + 1

    print()
    row = row + 1
