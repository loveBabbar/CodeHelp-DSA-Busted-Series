n = int(input())
i = 1
count = 1
while i <= n:
  j = 1
  while j <= n:
    print(count, end = ' ')
    count = count + 1
    j = j + 1
  print()
  i = i + 1
