/*RESULTS
Time: ~ 30 min
DificultyR: easy
Dificulty: Really easy
TimeBeats: 31.6%
MemoryBeats: 61.6
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> solution = {i, j};
                    return solution;
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> test = {2, 7, 11, 15};

    vector<int> res = solution.twoSum(test, 9);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}

/* Take aways; - making searches in an unordered map is a lot faster, so try to do them there.
               - Remove functions from the loop code .size() */