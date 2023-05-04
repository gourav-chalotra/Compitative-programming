#include <iostream>
#include <list>
#include <string>
#include<queue>
#include <malloc.h>
using namespace std;
struct Node
{
    char data;
    Node *next;
};
Node *newNode(char val = 'E')
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = val;
    ptr->next = nullptr;
    return ptr;
}

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> qR, qD;
        for (int i = 0; i < senate.size(); i++)
            (senate[i] == 'R') ? qR.push(i) : qD.push(i);

        while (!qR.empty() && !qD.empty())
        {
            int indexR = qR.front(), indexD = qD.front();
            qR.pop(), qD.pop();
            (indexR < indexD) ? qR.push(indexR + senate.size()) : qD.push(indexD + senate.size());
        }
        return (!qR.empty()) ? "Radiant" : "Dire";
    }
};
int main()
{
    Solution s;
    string str = "RD";
    cout << s.predictPartyVictory(str);
}