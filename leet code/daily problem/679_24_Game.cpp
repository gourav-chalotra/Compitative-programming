#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const double eps = 1e-6;
    bool check24(vector<double> cards)
    {
        if (cards.size() == 1)
        {
            return (fabs(cards[0] - (double)24)) < eps;
        }
        for (int i = 0; i < cards.size(); i++)
        {
            for (int j = 0; j < cards.size(); j++)
            {
                if (j == i)
                    continue;

                double a = cards[i], b = cards[j];

                // addition
                vector<double> cards_temp;
                for (int m = 0; m < cards.size(); m++)
                {
                    if (m == i || m == j)
                        continue;
                    cards_temp.push_back(cards[m]);
                }

                vector<double> opt = {(a - b), (a + b), (b - a), (b * a)};
                if (fabs(b) > eps)
                    opt.push_back(a / b);
                if (fabs(a) > eps)
                    opt.push_back(b / a);
                for (int k = 0; k < opt.size(); k++)
                {
                    cards_temp.push_back(opt[k]);
                    if (check24(cards_temp))
                        return true;
                    cards_temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> crd;
        for (auto i : cards)
            crd.push_back((double)i);

        return check24(crd);
    }
};

int main()
{
    
}