#include <iostream>
#include <algorithm>
#include "yameList.h"

LinkedList::LinkedList(int num)
{
    m_data = new int[num];
    m_next = new int[num];
    m_pre = new int[num];
    m_used = 0;

    std::fill(m_data,m_data+num,-1);
    std::fill(m_next,m_next+num,-1);
    std::fill(m_pre,m_pre+num,-1);    
}

LinkedList::~LinkedList()
{
    delete [] m_data;
    delete [] m_next;
    delete [] m_pre;
}

void LinkedList::insert(int addr, int num)
{
    ++m_used;

    int idx = m_used+1;

    int curIdx = 0;
    
    for(int i=0;i<addr;++i)
    {
        if(m_next[curIdx] == -1)
        {
            break;
        }

        curIdx = m_next[curIdx];
    }

    m_data[idx] = num;
    m_pre[idx] = curIdx;
    m_next[idx] = m_next[curIdx];
    m_next[curIdx] = idx;
    if(m_next[idx] != -1)
        m_pre[m_next[idx]] = idx;
    
}

void LinkedList::erase(int addr)
{
    int curIdx = 0;
    int nextPreIdx = -1;
    int preNextIdx = -1;
    for(int i=0;i<=addr;++i)
    {
        if(m_next[curIdx] == -1)
        {
            break;
        }

        curIdx = m_next[curIdx];
    }

    if(curIdx <= 0) return;

    m_next[m_pre[curIdx]] = m_next[curIdx];
    m_pre[m_next[curIdx]] = m_pre[curIdx];
}

void LinkedList::traverse()
{
    cout << "print \n";
    int idx = 0;
    int nextIdx = -1;
    while(true)
    {
        nextIdx = m_next[idx];
        
        if(nextIdx == -1)
            break;
        
        cout << m_data[nextIdx] << " ";
        idx = nextIdx;
    }
}
