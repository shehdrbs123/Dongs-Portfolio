#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "Trie.h"

using namespace std;
int main()
{
    Trie* root;
    vector<string> vStrVector;
    root = new Trie{};
    root->Init();

    std::ifstream inputFile{"words_alpha.txt"};

    if(!inputFile.is_open())
    {
        cout << "나니가 몬다이 아르\n";
        return 1;
    }

    string line;
    while(std::getline(inputFile,line))
    {
        root->insert(line);
        vStrVector.push_back(line);
    }
    inputFile.close();

    while(true)
    {
        {
            string word;
            cout << "find word : ";
            getline(cin,word);
            auto start = std::chrono::high_resolution_clock::now();
            if(root->find(word))
            {
                auto end = std::chrono::high_resolution_clock::now();
                auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds> (end - start);
                cout << "Trie time : " << duration1.count() << "ns\n";

                bool find = false;
                start = std::chrono::high_resolution_clock::now();
                cout << "Find vector (size : " << vStrVector.size() << ")\n";
                for(int i=0;i<vStrVector.size();++i)
                {
                    if(vStrVector[i] == word)
                    {
                        find = true;
                        end = std::chrono::high_resolution_clock::now();
                        break;
                    }
                }
                if(find)
                {
                    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds> (end-start);
                    cout << "Vector String Time : " << duration2.count() << "ns\n";
                }
            }
            else
            {
                cout << "Can not find\n";
            }
        }
            
    }
}