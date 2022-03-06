# IF-else for print value is true or false
a = 10
if(a=10):
  print(True)
else:
  print(False)
  
# Check a is < value then true or false or print anything
a = int(input())
if(a<10):
  print("A is less then to 10")
else:
  print("A is Greter then to 10")
 
# one more example total marks 100 we have 2 subject
hindi = 20
english = 40
total = hindi + english
if(total>=60):
  print("A Grade")
elif(total>=50 && total<60):
  print("B Grade")
elif(total>=40 && total<50):
  print("C Grade")
else:
  print("Fail")
