#include "Trie.h"

void Trie::Init()
{
    for(int i=0;i<26;++i)
    {
        m_children[i] = nullptr;
    }

}
bool Trie::insert(const std::string& strWord)
{
    for(int i=0;i<strWord.length();++i)
    {
        int idx = GetIdx(strWord[i]);
        if(idx == -1)
        {
            return false;
        }
    }

    int idx = GetIdx(strWord[0]);

    std::shared_ptr<Trie> preTrie = m_children[idx];
    if(preTrie == nullptr)
    {
        preTrie = std::make_shared<Trie>(new Trie{});
        preTrie->Init();
        m_children[idx] = preTrie;
    }

    for(int i=1;i<strWord.length();++i)
    { 
        int idx = GetIdx(strWord[i]);
        auto trie = preTrie->m_children[idx];
        if(trie == nullptr)
        {
            trie = std::make_shared<Trie>(new Trie{});
            trie->Init();
            preTrie->m_children[idx] = trie;
        }   

        preTrie = trie;
    }

    return true;
}

std::shared_ptr<Trie> Trie::find(char c)
{
    int idx = GetIdx(c);
    if(idx == -1)
        return nullptr;
    return m_children[idx];
}


bool Trie::find(const std::string& strWord)
{
    std::shared_ptr<Trie> preTrie;
    int idx = GetIdx(strWord[0]);        
    if(idx == -1)
        return false;

    preTrie = m_children[idx];
    if(preTrie == nullptr)
        return false;

    for(int i=1;i<strWord.length();++i)
    {
        std::shared_ptr<Trie> trie;
        int idx = GetIdx(strWord[i]);        
        if(idx == -1)
            return false;

        trie = preTrie->m_children[idx];
        if(trie == nullptr)
            return false;

        preTrie = trie;
    }
    return true;
}

int Trie::GetIdx(const char c)
{
    char convertC = c;
    if( (convertC < 'a' || convertC > 'z'))
    {
        if(convertC < 'A' || convertC > 'Z')
            return -1;
        
        convertC += 'a' - 'A';
    }
    convertC -= 'a';
    return 0;
}
