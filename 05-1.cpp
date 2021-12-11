#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ifstream in("05.in");
    cin.rdbuf(in.rdbuf());

    string line;
    int x1, x2, y1, y2;
    int board[1000][1000] = {0};

    while(getline(cin, line))
    {
        x1 = stoi(line.substr(0, line.find(",")));
        y1 = stoi(line.substr(line.find(",") + 1, line.find("-") - line.find(",") - 2));
        x2 = stoi(line.substr(line.find(">") + 2, line.rfind(",") - line.find(">") - 2));
        y2 = stoi(line.substr(line.rfind(",") + 1));
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                for (int i = 0; i < (y1 - y2 + 1); i++)
                {
                    board[x1][y2 + i]++;
                }
            }
            if (y2 > y1)
            {
                for (int i = 0; i < (y2 - y1 + 1); i++)
                {
                    board[x1][y1 + i]++;
                }
            }
        }
        if (y1 == y2)
        {
            if (x1 > x2)
            {
                for (int i = 0; i < (x1 - x2 + 1); i++)
                {
                    board[x2 + i][y1]++;
                }
            }
            if (x2 > x1)
            {
                for (int i = 0; i < (x2 - x1 + 1); i++)
                {
                    board[x1 + i][y1]++;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (board[j][i] >= 2)
                count++;
        }
    }
    cout << count << endl;
}