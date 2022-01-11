def factorial(n):
    # base case
    if n == 0:
        return 1
    smallerProblem = factorial(n-1)
    biggerProblem = n * smallerProblem

    return biggerProblem

if __name__ == "__main__":
    n=int(input())
    ans = factorial(n)
    print(ans)
