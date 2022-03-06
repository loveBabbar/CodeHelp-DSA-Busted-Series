def subsequence(s,o):
    if len(s)==0:
        print(o)
        return 
    subsequence(s[1:],o)
    subsequence(s[1:],o+s[0])
str=input("enter the string:")
subsequence(str,"")