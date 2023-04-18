#include <iostream>
using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int largestSize = (word1.size() >= word2.size()) ? word1.size() : word2.size();
        string mergedString;
        int i = 0;
        while (i < largestSize)
        {
            if (i < word1.size())
                mergedString.push_back(word1.at(i));
            if (i < word2.size())
                mergedString.push_back(word2.at(i));
            i++;
        }
        return mergedString;
    }
};
int main()
{
}