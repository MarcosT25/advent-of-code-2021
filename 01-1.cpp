#include <iostream>
#include <string>
using namespace std;

int getFlizeSize()
{
    char line[8];
    int fileSize = 0;
    FILE *fp;
    fp = fopen("01.in", "r");
    while (fgets(line, 6, fp) != NULL)
    {
        fileSize++;
    }
    fclose(fp);
    return fileSize;
}

int main()
{
    int fileSize = getFlizeSize();
    int inputArray[fileSize];
    int increased = 0;
    char line[8];
    FILE *fp;
    fp = fopen("01.in", "r");
    for (int i = 0; i < fileSize; i++)
    {
        fgets(line, 6, fp);
        inputArray[i] = stoi(line);
        if (i > 0) // ignore the first line
        {
            if (inputArray[i] > inputArray[i - 1])
            {
                increased++;
            }
        }
    }
    fclose(fp);
    cout << increased << endl;
    return 0;
}