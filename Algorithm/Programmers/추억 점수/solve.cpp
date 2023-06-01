#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void print(const vector<int>& answer);
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo);
int main()
{
    vector<string> name{"may", "kein", "kain", "radi"};
    vector<int> yearning{5, 10, 1, 3};
    vector<vector<string>> photo{{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}};
    vector<int> answer = solution(name,yearning,photo);
    
    print(answer);
}

void print(const vector<int>& answer)
{   
    int nSize = answer.size();
    int i=0;
    cout << "[";
    for (; i < nSize-1; i++)
    {
        cout << answer[i] << ",";
    }
    cout << answer[i] << "]" << endl;
}


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer{};
    map<string,int> nameScore{};

    int nameLength = name.size();
    int photoYLength = photo.size();

    for (size_t i = 0; i < nameLength; i++)
    {
        nameScore.emplace(name[i],yearning[i]);
    }

    for (size_t i = 0; i < photoYLength; i++)
    {
        int photoXLength = photo[i].size();
        int TotalScore = 0;
        for (size_t j = 0; j < photoXLength; j++)
        {
            auto iter = nameScore.find(photo[i][j]);
            if(iter!= nameScore.end())
                TotalScore+=iter->second;

        }
        answer.emplace_back(TotalScore);
    }
    return vector<int>(answer);
}