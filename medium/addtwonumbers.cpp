/*RESULTS
Time: ~ 5 hours
DificultyR: normal
Dificulty: Very Hard
TimeBeats: 34.79%
MemoryBeats: 73.07%
*/

#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *resul = new ListNode();
        ListNode *res = resul;
        int calc;
        bool listOne = true;
        bool listTwo = true;
        while (listOne)
        {
            if (listTwo)
            {
                calc = (l1->val + l2->val) + carry;
                if (calc >= 10)
                {
                    resul->val = calc % 10;
                    carry = 1;
                }
                else
                {
                    resul->val = calc;
                    carry = 0;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else
            {
                calc = l1->val + carry;
                if (calc >= 10)
                {
                    resul->val = calc % 10;
                    carry = 1;
                }
                else
                {
                    resul->val = calc;
                    carry = 0;
                }
                l1 = l1->next;
            }

            // end of loop

            if (l1 == nullptr)
            {
                listOne = false;
            }
            else
            {
                ListNode *newnode = new ListNode();
                resul->next = newnode;
                resul = newnode;
            }
            if (l2 == nullptr)
            {
                listTwo = false;
            }
            else
            {
                if (l1 == nullptr)
                {
                    ListNode *newnode = new ListNode();
                    resul->next = newnode;
                    resul = newnode;
                }
            }
        }
        while (listTwo)
        {
            calc = l2->val + carry;
            if (calc >= 10)
            {
                resul->val = calc % 10;
                carry = 1;
            }
            else
            {
                resul->val = calc;
                carry = 0;
            }
            l2 = l2->next;

            if (l2 == nullptr)
            {
                listTwo = false;
            }
            else
            {
                ListNode *newnode = new ListNode();
                resul->next = newnode;
                resul = newnode;
            }
        }

        if (carry)
        {
            ListNode *newnode = new ListNode();
            resul->next = newnode;
            resul = newnode;
            newnode->val = 1;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> test = {2, 7, 11, 15};

    // vector<int> res = solution for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << endl;
    // }

    return 0;
}

/* Take aways;  */