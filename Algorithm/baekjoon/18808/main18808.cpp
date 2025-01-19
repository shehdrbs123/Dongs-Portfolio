#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1}

bool sticker[101][11][11] = {false,};
pair<int,int> stickerSize[101];
bool notebook[41][41] = {false};

bool canPlaceSticker(int stickerIdx)
{

    return false; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

   
    int noteY,noteX,count;
    cin >> noteY >> noteX >> count;

    for(int i=0;i<count;++i)
    {
        int stickerY,stickerX;
        cin >> stickerY >> stickerX;
        stickerSize[i].first = stickerX;
        stickerSize[i].second = stickerY;

        for(int j=0;j<stickerY;++j)
        {  
            for(int k=0;k<stickerX;++k)
            {
                cin >> sticker[i][j][k];
            }
        }
    }

    for(int i=0;i<count;++i)
    {
        for(int j=0;j<noteY;++j)
        {
            bool isPlace =false;
            for(int k=0;k<noteX-;++k)
            {
                if(canPlaceSticker(notebook,sticker))
                {
                    isPlace = true;
                    break;
                }
            }
        }
    }

    return 0;
}