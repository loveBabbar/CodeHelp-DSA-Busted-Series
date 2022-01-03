n=int(input())
i=2
while i<n:
  if n%i==0:
    print(f"Not prime for {i}",end=" ")
  else:
    print(f"Prime for {i}",end=" ")
  i+=1
