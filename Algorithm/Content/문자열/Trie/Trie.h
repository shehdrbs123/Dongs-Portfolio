#define ALPHABETS 26
#include <string>
#include <memory>

/// 영어 대소문자 구분 X
/// 단어 단위로 검색 가능, 영어 이외의 단어 포함 시 
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