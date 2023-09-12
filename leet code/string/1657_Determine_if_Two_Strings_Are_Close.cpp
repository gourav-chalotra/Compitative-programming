#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        map<char, int> w1, w2;
        for (int i = 0; i < word1.size(); i++)
        {
            w1[word1[i]]++;
        }

        for (int i = 0; i < word2.size(); i++)
        {
            w2[word2[i]]++;
        }

        string s1, s2;

        for (auto i = w1.begin(); i != w1.end(); i++)
        {
            cout << "first : " << i->first << " second: " << i->second << endl;
            s1 += i->first;
        }
        cout << "\n \n";
        for (auto i = w2.begin(); i != w2.end(); i++)
        {
            cout << "first : " << i->first << " second: " << i->second << endl;
            s2 += i->first;
        }
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;

        for (auto i = w1.begin(); i != w1.end(); i++)
        {
            int found = 0;
            for (auto j = w2.begin(); j != w2.end(); j++)
            {
                if(j->second == i->second)
                {
                    j->second = 0;
                    i->second = 0;
                    found = 1;
                    break;
                }
            }
            if(!found)
                return false;
        }
        if(s1 == s2)
            return true;
        return false;
    }
};

int main()
{
    string word1 = "uau", word2 = "ssx";
    cout << "word1 " << word1 << "\nword2 " << word2 << endl;
    Solution s;
    cout << s.closeStrings(word1, word2);
    return 0;
}