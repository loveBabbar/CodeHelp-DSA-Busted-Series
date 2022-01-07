def merge(list1, list2):

    size1 = len(list1)
    size2 = len(list2)
    list3=[]
    i,j = 0,0


    while i<size1 and j<size2:
        if list1[i] < list2[j]:
            list3.append(list1[i])
            i+=1
        else:
            list3.append(list2[j])
            j+=1


    while i<size1:
        list3.append(list1[i])
        i+=1
    
    while j<size2:
        list3.append(list2[j])
        j+=1
    
    return list3

if __name__ == "__main__":
    list1 = [1, 3, 5, 7, 9]
    list2 = [2, 4, 6]
    list3 = merge(list1,list2)
    print(list3)