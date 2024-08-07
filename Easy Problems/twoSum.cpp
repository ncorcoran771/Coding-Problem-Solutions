#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

// Two Sum Problem - Easy

// This problem requires you to take in a list of numbers and a target value, and return the 2 indices of the values
// in that list that add up to the target number.

// At first, you may try a brute force approach. You use a double-nested for-loop and iterate through the entire
// list checking whether each combination of numbers gives you your target. This gives a time complexity of O(n^2),
// and takes around 49ms to run.

// Brute force:
// vector<int> twoSum(vector<int>& nums, int target) 
// {
//     for(int i=0;i<nums.size();i++)
//     {
//         for(int j=i+1;j<nums.size();j++)
//         {
//             if(nums[i]+nums[j]==target)
//             return {i,j};
//         }
//     }
//     return {};  
// }

// This is a good starting point, but we can go faster...

// What if we didn't check all possible combinations of numbers in the list, but instead we picked a number to start with,
// and seached for other numbers in the list that would "compliment" our first number and add to our target number.

// That's almost what we were doing in the brute force approach, but with an array, looking up those "compliments" requires
// us to iterate over the array multiple times. By using a HASH MAP, this process becomes faster.
// In each slot of the hash table, we store a number and its index. We can look up the number in the hast table to find its index

// As we go over the list of numbers, we can take our current number, and see if there any "compliments" in the map.
// If there are, we return the indices, which are convenietly stored in the hashmap. If not, we store the number and index
// in the table for future reference.

// Below is a solution that has a time complexity of O(n), and takes 3ms to run. This is ~16.3 times faster than our first
// brute force approach. Pretty cool, right?

// Below is my code that was used to solve this problem.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();    //find size of list to iterate over
        unordered_map<int, int> map;    //make a map to store values for easier access
        for (int i = 0; i < n; i++)     //iterate through the list, but only once
        {
            if (map.find(target - nums[i]) != map.end())    //if the "compliment" to our current number exists in the map...
                return {map[target - nums[i]], i};  // we return its index as while as the index of our current number
            map[nums[i]] = i; //if not, we add our current number and its index to the map for future use
        }
        return {}; //if, at the end of this we don't have a pair, we return an empty list
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {2,7,6,23,5}; //edit this to try your own test cases
    const vector<int> test = s1.twoSum(nums,9);
    if(test.empty())
        cout<<"Empty List. No pairs returned"<<endl;
    else
    {
        for(int t:test)
            cout<<t<<" ";
        cout<<endl;
    }
}

//You can compile and run this program with:
// g++ -o twoSum twoSum.cpp
// ./twoSum

