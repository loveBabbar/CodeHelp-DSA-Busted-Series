


def linearsearch(arr,k):

    for i in range(len(arr)):
        print(arr[i])
        if (arr[i]==k):
           return arr[i]

print(linearsearch([9,4,2,5,8,3],2))