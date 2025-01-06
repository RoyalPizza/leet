// clang++ twosum.cpp -o bin/twosumcpp

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Note: Made nums const because it should be and so I could use {}
    vector<int> twoSum(const vector<int> &nums, const int target)
    {
        for (int x = 0; x < nums.size(); x++)
        {
            for (int y = x + 1; y < nums.size(); y++)
            {
                if (nums[x] + nums[y] == target)
                {
                    cout << x << "," << y << " equals " << target << endl;
                    return {x, y};
                }
            }
        }

        return {};
    }

    // Note: Made nums const because it should be and so I could use {}
    vector<int> twoSumHash(const vector<int> &nums, const int target)
    {
        unordered_map<int, int> map;
        map[nums[0]] = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (map.count(temp) > 0)
            {
                cout << i << "," << map[temp] << " equals " << target << endl;
                return {i, map[temp]};
            }
            map[nums[i]] = i;
        }

        cout << "no sum found for " << target << endl;
        return {};
    }
};

int main()
{
    Solution solution;
    solution.twoSumHash({2, 7, 11, 15}, 9);
    solution.twoSumHash({3, 2, 4}, 6);
    solution.twoSumHash({3, 3}, 6);

    return 0;
}