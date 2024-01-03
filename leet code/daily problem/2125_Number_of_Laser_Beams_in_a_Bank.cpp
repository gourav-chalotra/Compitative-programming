#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> arrange(vector<string> bank, int index)
    {
        vector<string> newBank;
        for (int i = 0; i < bank.size(); i++)
        {
            if (i == index)
                continue;
            newBank.push_back(bank[i]);
        }
        return newBank;
    }
    int numberOfBeams(vector<string> &bank)
    {
        int lenes = 0;
        for (int i = 0; i < bank.size() - 1;)
        {
            int onesi = count(bank[i].begin(), bank[i].end(), '1');
            if (onesi)
            {
                int onesj = count(bank[i + 1].begin(), bank[i + 1].end(), '1');
                if (onesj)
                {
                    lenes += (onesj * onesi);
                    i++;
                }
                else
                    bank = arrange(bank, i + 1);
            }
            else
                bank = arrange(bank, i);
        }
        return lenes;
    }
};

int main()
{
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    Solution s;
    cout << s.numberOfBeams(bank);
}