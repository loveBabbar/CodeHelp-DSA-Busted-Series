
def isPossible(arr, n, m, mid):
    studentCount = 1
    pageSum = 0
    # print "checking for mid "

    for i in range(n):
        if(pageSum + arr[i] <= mid):
            pageSum += arr[i]

        else:

            studentCount += 1
            if(studentCount > m or arr[i] > mid):
                return False

            pageSum = arr[i]

        if(studentCount > m):
            return False

        # print " for i " + i + " Student " + studentCount + " pageSum " + pageSum + endl

    return True


def allocateBooks(arr, n, m):
    s = 0
    sum = 0

    for i in range(n):
        sum += arr[i]

    e = sum
    ans = -1
    mid = s + (e-s)/2

    while(s <= e):

        if(isPossible(arr, n, m, mid)):
            # print " Mid returned TRUE" + endl
            ans = mid
            e = mid - 1

        else:
    
            s = mid + 1

        mid = s + (e-s)/2

    return ans
