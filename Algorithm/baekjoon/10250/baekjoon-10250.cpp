#include <iostream>
using namespace std;

int main()
{
    int nInputCount{};
    int nHeight{};
    int nWidth{};
    int nPeople{};
    int nFloor{};
    int nRoomNum{};

    cin >> nInputCount;

    for (size_t i = 0; i < nInputCount; i++)
    {
        cin >> nHeight >> nWidth >> nPeople;
        nPeople -= 1;
        nFloor = nPeople % nHeight + 1;
        nRoomNum = nPeople / nHeight + 1;

        printf("%d%02d\n", nFloor, nRoomNum);
    }
}