#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ifstream in("03.in");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to file

    int gamma = 0;
    int epsilon = 0;
    string line;
    getline(cin, line);
    char bGamma[line.length()];
    char bEpsilon[line.length()];
    int fileSize = 0;
    int occurrencesOfOne[line.length()] = {0};
    do // filling the array with the nember of times that 1 appeared
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '1')
            {
                occurrencesOfOne[i]++;
            }
        }
        fileSize++;
    } while (getline(cin, line));
    
    for (int i = 0; i < line.length(); i++) // checking if the most commom digit was 1
    {
        if (occurrencesOfOne[i] > fileSize / 2)
        {
            bGamma[i] = '1';
            bEpsilon[i] = '0';
        }
        else
        {
            bGamma[i] = '0';
            bEpsilon[i] = '1';
        }
    }
    for (int i = line.length() - 1; i >= 0; i--) // converting to decimal
    {
        gamma += (int) (bGamma[i] - '0')* pow(2, line.length() - 1 - i);
        epsilon += (int) (bEpsilon[i] - '0') * pow(2, line.length() - 1 - i);
    }

    cout << gamma * epsilon << endl;
}