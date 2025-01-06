#include <bits/stdc++.h>
using namespace std;
#include <sstream>

class Solution
{
public:
    string compressedString(string word)
    {
        int count = 1;
        std::stringstream res;

        for (int i = 0; i < word.size(); i++)
        {
            if (i < word.size() - 1 && word[i] == word[i + 1])
            {
                count++;
                if (count > 9)
                {
                    res << "9" << word[i];
                    count = 1;
                }
            }
            else
            {
                res << count << word[i];
                count = 1;
            }
        }
        return res.str();
    }
};


int main()
{
    string str = "ksjhdkajsd";
    Solution s;
    cout << s.compressedString(str);
}

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     for(int i = 0; i < 10 ; i++)
//     {
//         cout << (char)(i+48) << endl;
//     }
//     string str = "";
//     str.push_back('a');
//     str.push_back('b');
//     str.push_back('b');
//     str.push_back('b');
//     str.push_back('b');
//     str.push_back('b');
//     str.push_back('b');
//     cout << str<<endl;
// }