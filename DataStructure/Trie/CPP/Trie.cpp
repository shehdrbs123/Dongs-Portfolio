#define ALPHABETS 26
#include <string>
// 문자열을 빠르게 검색하고
// 자동완성 문자열을 
struct Trie
{
private :
    bool isTerminate;
    Trie * children[ALPHABETS];
public :
    void insert(std::string strWord);
    Trie * find(std::string strWord);
    
    
}