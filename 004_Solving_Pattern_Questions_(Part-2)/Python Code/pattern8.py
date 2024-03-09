n = int(input())
row = 1

while row <= n:
    col = 1
    start = ord('A') + n - row
    while col <= row:
        print(chr(start), end="")
        start = start + 1
        col = col + 1

    print()
    row = row + 1
