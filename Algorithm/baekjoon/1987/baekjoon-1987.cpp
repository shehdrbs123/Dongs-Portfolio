#include <iostream>
#include <set>

int MAX_COL{};
int MAX_ROW{};
int AR_DROW[4]{ -1,1,0,0 };
int AR_DCOL[4]{ 0,0,-1,1 };
char AR_DATA[20][21]{};
bool AR_ALPHA[26];
int ANSWER{};

void findRoute(int currentRow, int currentCol, int currentLength);
int main()
{
    std::cin >> MAX_ROW >> MAX_COL;

    for (int i = 0; i < MAX_ROW; i++)
    {
        std::cin >> AR_DATA[i];
    }

    findRoute(0, 0, 0);
    
    std::cout << ANSWER;
}

void findRoute(int currentRow, int currentCol, int currentLength)
{
    if (currentRow < 0 || currentRow >= MAX_ROW || currentCol < 0 || currentCol >= MAX_COL)
        return;

    if (AR_ALPHA[AR_DATA[currentRow][currentCol]-'A'] == false)
    {
        AR_ALPHA[AR_DATA[currentRow][currentCol] - 'A'] = true;
        currentLength++;
        if (ANSWER < currentLength) ANSWER = currentLength;
        for (int i = 0; i < 4; i++)
        {
            findRoute(currentRow + AR_DROW[i], currentCol + AR_DCOL[i], currentLength);
        }
    }
    else {
        return;
    }
    AR_ALPHA[AR_DATA[currentRow][currentCol] - 'A'] = false;
}