#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int *bingo(vector <int> &boardNumbers)
{
    int boardSum = 0;
    int win = 0;
    for (int i = 0; i < boardNumbers.size() / 25; i++)
    {
        int boardStart = i * 25;
        for (int j = 0; j < 25; j += 5)
        {
            int markedNumber = 0;
            for (int k = 0; k < 5; k++)
            {
                if (boardNumbers[j + k + (25 * i)] == -1)
                    markedNumber++;
                if (markedNumber == 5)
                {
                    win = 1;
                    for (int l = boardStart; l < (boardStart + 25); l++)
                    {
                        if (boardNumbers[l] != -1)
                        {
                            boardSum += boardNumbers[l];
                        }
                        boardNumbers[l] = -2;  
                    }
                }
            }
        }
        for (int j = 0; j < 5; j++)
        {
            int markedNumber = 0;
            for (int k = 0; k < 5; k++)
            {
                if (boardNumbers[(25 * i) + j + (k * 5)] == -1)
                    markedNumber++;
                if (markedNumber == 5)
                {
                    win = 1;
                    for (int l = boardStart; l < boardStart + 25; l++)
                    {
                        if (boardNumbers[l] != -1)
                        {
                            boardSum += boardNumbers[l];
                        }
                        boardNumbers[l] = -2;     
                    }
                }
            }
        }
    }
    static int result[2];
    result[0] = win;
    result[1] = boardSum;
    return result;
}

void printBoards(vector <int> boardNumbers)
{
    for (int i = 0; i < boardNumbers.size() / 25; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cout << boardNumbers[(i * 25) + (j * 5) + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ifstream in("04.in");
    cin.rdbuf(in.rdbuf()); // redirect cin to file

    string line;
    getline(cin, line);
    int numberOfBoards = 0;
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
        numberOfBoards++;
    } while (getline(cin, line));

    numberOfBoards /= 6;

    int lastNumber;
    int numberIndex = 0;
    int numberOfWins = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        replace(boardNumbers.begin(), boardNumbers.end(), numbers[i], -1);

        int *ptr;
        ptr = bingo(boardNumbers);

        if (*ptr)
        {
            cout << numbers[i] * *(ptr+1) << endl;
        }
    }
}