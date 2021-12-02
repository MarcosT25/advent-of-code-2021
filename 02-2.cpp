#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("02.in");
    streambuf *cinbuf = cin.rdbuf(); //save old buf
    cin.rdbuf(in.rdbuf()); //redirect cin to file

    int xAxis = 0;
    int yAxis = 0;
    int aim = 0;

    string line;
    while(getline(cin, line))  //input from the file in.txt
    {
        int num = stoi(line.substr(line.find(" ") + 1));
        if (line.substr(0, line.find(" ")) == "forward")
        {
            xAxis += num;
            yAxis += aim * num;
        }
        else if (line.substr(0, line.find(" ")) == "up")
        {
            aim -= num;
        }
        else if (line.substr(0, line.find(" ")) == "down")
        {
            aim += num;
        }
    }
    cout << xAxis * yAxis << endl;
}