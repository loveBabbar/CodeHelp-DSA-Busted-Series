"""
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. 
Each time you can either climb one step or two steps. 
You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

I/P : N=3
O/P : 3
Explanation:
{(0,1),(1,2),(2,3)}
{(0,1),(1,3)}
{(0,2),(1,3)}
"""

def print_count_ways(n):
    if(n<0):
        return 0
    if(n==0):
        return 1
    
    return print_count_ways(n-1)+print_count_ways(n-2)
    
if __name__=="__main__":
    n=int(input())
    print(print_count_ways(n))