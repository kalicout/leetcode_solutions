/*RESULTS
Time: ~ 10 hours
DificultyR: hard
Dificulty: really hard
TimeBeats: 5.79%
MemoryBeats: 80.03%
*/

#include <iostream>

// takeaway
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int l = (s1 + s2) / 2;
        bool f = (s1 + s2) % 2;
        cout << "TIPE: " << f << endl;
        int i_ = 0;
        int j_ = 0;

        int nums[2] = {1000001, 1000001};
        bool l_reached = false;

        //  // Check empties
        if (s1 == 0)
        {
            if (f)
            {
                return nums2[l];
            }
            else
            {
                return (nums2[l - 1] + nums2[l]) / (double)2;
            }
        }

        if (s2 == 0)
        {
            if (f)
            {
                return nums1[l];
            }
            else
            {
                return (nums1[l - 1] + nums1[l]) / (double)2;
            }
        }
        if (s1 + s2 == 2)
        {
            return (nums1[0] + nums2[0]) / (double)2.0;
        }

        for (; i_ < s1;)
        {
            if (nums1[i_] <= nums2[j_])
            {
                nums[0] = nums[1];
                nums[1] = nums1[i_];
                cout << "appended numI:" << nums1[i_] << endl;
                i_++;
                if (i_ + j_ == l + 1)
                {
                    cout << "i" << endl;
                    l_reached = true;
                    i_--;
                    break;
                }
            }
            else
            {

                nums[0] = nums[1];
                nums[1] = nums2[j_];
                cout << "appended numJ:" << nums2[j_] << endl;
                j_++;
                if (i_ + j_ == l + 1)
                {
                    cout << "j" << endl;
                    l_reached = true;
                    j_--;
                    break;
                }
            }
            if (j_ == s2)
            {
                for (; !l_reached;)
                {
                    nums[0] = nums[1];
                    nums[1] = nums1[i_];
                    cout << "appended numJJ:" << nums1[i_] << endl;
                    i_++;
                    if (i_ + j_ == l + 1)
                    {
                        cout << "II" << endl;
                        if (f)
                        {
                            // if (nums[1] == 0) {return 0.0;}
                            return nums[1] / (double)1.0;
                        }
                        // if (nums[1] == 0 && nums[0]) {return 0.0;}
                        return (nums[0] + nums[1]) / (double)2.0;
                    }
                }
            }
        }

        for (; !l_reached;)
        {
            nums[0] = nums[1];
            nums[1] = nums2[j_];
            cout << "appended numJJ:" << nums2[j_] << endl;
            j_++;
            if (i_ + j_ == l + 1)
            {
                cout << "J" << endl;
                break;
            }
        }

        cout << "nums0: " << nums[0] << endl;
        cout << "nums1: " << nums[1] << endl;

        if (f)
        {
            // if (nums[1] == 0) {return 0.0;}
            return nums[1] / (double)1.0;
        }
        // if (nums[1] == 0 && nums[0]) {return 0.0;}
        return (nums[0] + nums[1]) / (double)2.0;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {1, 3};
    vector<int> b = {2};

    double res = solution.findMedianSortedArrays(a, b);

    cout << res << endl;

    return 0;
};

/*Take away: You can rerun a function with an if statement:
func(nums1, nums2) if nums1 > nums2 --> func (nums2, num1)

CAN BE COUNTER PROD: it needs to be used with some head
*/
