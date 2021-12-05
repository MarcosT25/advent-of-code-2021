#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int bingo(vector <int> boardNumbers)
{
    for (int i = 0; i < boardNumbers.size(); i += 5)
    {
        int markedNumber = 0;
        for (int j = 0; j < 5; j++)
        {
            if (boardNumbers[i + j] == -1)
                markedNumber++;
            if (markedNumber == 5)
                return i + j;
        }
    }
    int markedNumber = 0;
    int count = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < boardNumbers.size(); i += 5)
        {
            if (count == 5)
            {
                count = 0;
                markedNumber = 0;
            }
            if (boardNumbers[i + j] == -1)
                markedNumber++;
            count ++;
            if (markedNumber == 5)
                return i + j;
        }
    }
    return -1;
}

int main()
{
    ifstream in("04.in");
    cin.rdbuf(in.rdbuf()); // redirect cin to file

    string line;
    getline(cin, line);
    int end = 0;
    vector <int> numbers;
    vector <int> boardNumbers;
    size_t pos = 0;
    string number;
    while ((pos = line.find(",")) != string::npos) {
        number = line.substr(0, pos);
        numbers.push_back(stoi(number)); //each number
        line.erase(0, pos + 1);
    }
    numbers.push_back(stoi(line));
    getline(cin, line); // ignore the last number
    do
    {
        if (line.length() > 0) // not null line
        {
            for (int i = 0; i < line.length(); i+= 3)
            {
                boardNumbers.push_back(stoi(line.substr(i, 2))); // substr(star, step)
            }
        }
    } while (getline(cin, line));

    int lastNumber;
    int numberIndex = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        replace(boardNumbers.begin(), boardNumbers.end(), numbers[i], -1);
        if (bingo(boardNumbers) != -1)
        {
            numberIndex = bingo(boardNumbers);
            lastNumber = numbers[i];
            break;
        }
    }

    int boardStart = (numberIndex / 25) * 25;
    int boardSum = 0;

    for (int i = boardStart; i < boardStart + 25; i++)
        if (boardNumbers[i] != -1)
            boardSum += boardNumbers[i];

    cout << boardSum * lastNumber << endl;
}