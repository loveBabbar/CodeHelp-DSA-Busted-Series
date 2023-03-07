/*
@ Maximum Height by Stacking Cuboids

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed).
Choose a subset of cuboids and place them on each other.
You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
Return the maximum height of the stacked cuboids


Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

Example 3:
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &currCuboid, vector<int> &prevCuboid)
    {
        // considering >= in this question instead of >
        return (
                   (currCuboid[0] >= prevCuboid[0]) &&
                   (currCuboid[1] >= prevCuboid[1]) &&
                   (currCuboid[2] >= prevCuboid[2]))
                   ? true
                   : false;
    }
    int getMaxHeight(vector<vector<int>> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // include
                int include = 0;
                if (prev == -1 || isValid(nums[curr], nums[prev]))
                {
                    include = nums[curr][2] + nextRow[curr + 1]; // adding height instead of 1.
                }
                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // step-1: sort all the dimension for every cuboid
        for (auto &cuboid : cuboids)
            sort(cuboid.begin(), cuboid.end());

        // step-2: sort all the cuboids basis on remaining width or length
        sort(cuboids.begin(), cuboids.end());

        // step-3: Use LIS login
        return getMaxHeight(cuboids);
    }
};