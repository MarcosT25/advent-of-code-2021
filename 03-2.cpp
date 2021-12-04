#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream in("03.in");
    cin.rdbuf(in.rdbuf()); // redirect cin to file

    vector <string> bOxygenVector;
    vector <string> bCarbonicVector;
    string line;
    while (getline(cin, line))
    {
        bOxygenVector.push_back(line); // filling oxygen vector
        bCarbonicVector.push_back(line); // filling co2 vector
    }
    int numberOfOnes[bOxygenVector[0].length()] = {0};
    for (int i = 0; i < bOxygenVector[0].length(); i++)
    {
        for (int j = 0; j < bOxygenVector.size(); j++)
        {
            if (bOxygenVector[j][i] == '1')
            {
                numberOfOnes[i]++;
            }
        }
        char filter;
        if (numberOfOnes[i] >= bOxygenVector.size() - numberOfOnes[i]) // if more 1 than 0
        {
            filter = '1';
        }
        else
        {
            filter = '0';
        }
        for (int j = 0; j < bOxygenVector.size(); j++)
        {
            if (bOxygenVector[j][i] != filter) // if char different filter
            {
                bOxygenVector.erase(bOxygenVector.begin() + j);
                j = -1; // reseta o loop puta merda
            }
        }
        numberOfOnes[i] = 0; // reset the array
    }
    int oxygen = stoi(bOxygenVector[0], nullptr, 2);

    for (int i = 0; i < bCarbonicVector[0].length(); i++)
    {
        for (int j = 0; j < bCarbonicVector.size(); j++)
        {
            if (bCarbonicVector[j][i] == '1')
            {
                numberOfOnes[i]++;
            }
        }
        char filter;
        if (numberOfOnes[i] >= bCarbonicVector.size() - numberOfOnes[i]) // if more 1 than 0
        {
            filter = '1';
        }
        else
        {
            filter = '0';
        }
        for (int j = 0; j < bCarbonicVector.size(); j++)
        {  
            if (bCarbonicVector[j][i] == filter) // if char in filter
            {
                bCarbonicVector.erase(bCarbonicVector.begin() + j);
                j = -1;
            }
        }
    }
    int carbonic = stoi(bCarbonicVector[0], nullptr, 2);
    cout << oxygen * carbonic << endl;
}