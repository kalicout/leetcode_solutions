/*RESULTS
Time: ~ 3 hours
DificultyR: normal
Dificulty: not that hard
TimeBeats: 100%
MemoryBeats: 85.29%
*/

#include <iostream>
#include <string>
#include <unordered_map>

// takeaway
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.size();
        if (size == 0)
        {
            return 0;
        }
        if (size == 1)
        {
            return 1;
        }
        int maxcount = 0;
        int actcount = 0;
        int pos_elimin = 0;
        vector<int> db(256, -1);
        for (auto i = s.begin(); i != s.end(); i++)
        {
            actcount += 1;
            if (db[*i] != -1)
            {
                int seen_before_rep = actcount - pos_elimin;
                if (db[*i] > pos_elimin)
                {
                    pos_elimin = db[*i]; // last position where seen
                }
                db[*i] = actcount;
                if (seen_before_rep > maxcount)
                {
                    maxcount = seen_before_rep - 1;
                }
            }
            else
            {
                db[*i] = actcount;
            }
        }
        if (pos_elimin == 0)
        {
            return actcount;
        }
        if (actcount - pos_elimin > maxcount)
        {
            return actcount - pos_elimin;
        }
        return maxcount;
    }
};

void test_take_away(string &s)
{
    vector<int> hash(256, -1);
    int n = s.size();
    for (auto i = 0; i < n; i++)
    {

        // If only alphanums are used you can use this for a  SC - O(256)
        hash[s[i]] = i;
        cout << s[i] << endl;
        cout << hash[s[i]] << endl;
    }
}

int main()
{
    Solution solution;
    string a = "abba";

    int res = solution.lengthOfLongestSubstring(a);

    test_take_away(a);

    cout << res << endl;

    return 0;
}

/*Take away:  vector <int> hash(256,-1) used for ASCII since in hash[string[i]] string[i] is converted to a "int"*/