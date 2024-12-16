#define ALPHABETS 26
#include <string>
#include <memory>

// 문자열을 빠르게 검색하고
// 자동완성 문자열을 
struct Trie
{
private :
    std::shared_ptr<Trie> m_children[ALPHABETS];
public :
    Trie() { };
    Trie(const Trie*) { };

    void Init();
    bool insert(const std::string& strWord);
    bool find(const std::string& strWord);
    
private :
    std::shared_ptr<Trie> find(char c);
    int GetIdx(const char c);
};