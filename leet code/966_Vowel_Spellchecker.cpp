#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        vector<string> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            cout << queries[i] << endl;
            string q = queries[i];
            string correctWord = "";
            for (int j = 0; j < wordlist.size(); j++)
            {
                string w = wordlist[i];

                if (q.size() != w.size())
                {
                    continue;
                }
                else
                {
                    // query exactly matches a word in the wordlist (case-sensitive)
                    for (int k = 0; k < wordlist.size(); k++)
                    {
                        if (wordlist[k] == q)
                        {
                            correctWord = q;
                            break;
                        }
                    }
                    if (correctWord != "")
                        break;
                    // find the freq of the characters
                    unordered_map<char, int> mp;
                    for (auto i : q)
                    {
                        mp[i]++;
                    }
                    for (auto i : w)
                    {
                        mp[i]++;
                    }
                    // we check the not matching words case here.
                    for (auto i : mp)
                    {
                        if (i.second % 2 == 1)
                            break;
                    }
                    // here we will check the position base case where I see each chracter and compair with each other.
                    vector<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'U', 'u'};
                    for (int k = 0; k < q.size() && k < w.size(); k++)
                    {
                        if (q[k] != w[k])
                        {
                            if (q[k] >= 'a' && q[k] <= 'z')
                            {
                                int positQ = q[k] - 'a';
                                int positW = 0;
                                if (w[k] >= 'a' && w[k] <= 'z')
                                {
                                    positW = w[k] - 'a'; // for a - z
                                }
                                else
                                {
                                    positW = w[k] - 'A'; // for A - Z
                                }
                                // if the position not matching then check the character is vowel or not.
                                bool checkVowelsW = false;
                                bool checkVowelsQ = false;
                                if (positQ != positW)
                                {

                                    for (int l = 0; l < vowels.size(); l++)
                                    {
                                        if (w[k] == vowels[l])
                                        {
                                            checkVowelsW = true;
                                            break;
                                        }
                                    }
                                    for (int l = 0; l < vowels.size(); l++)
                                    {
                                        if (q[k] == vowels[l])
                                        {
                                            checkVowelsQ = true;
                                            break;
                                        }
                                    }
                                }
                                if (checkVowelsQ && checkVowelsW)
                                {
                                    
                                }
                            }
                            else
                            {
                                int positQ = q[k] - 'A';
                                int positW = 0;
                                if (w[k] >= 'a' && w[k] <= 'z')
                                {
                                    positW = w[k] - 'a'; // for a - z
                                }
                                else
                                {
                                    positW = w[k] - 'A'; // for A - Z
                                }
                            }
                        }
                    }
                }
            }
            ans.push_back(correctWord);
        }
    }
};

int main()
{
    Solution s;
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"}, queue = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};

    s.spellchecker(wordlist, queue);
}