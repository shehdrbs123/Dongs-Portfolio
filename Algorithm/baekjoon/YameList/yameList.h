
using namespace std;

class LinkedList 
{
private :
    int m_totalLength;
    int * m_data;
    int * m_pre;
    int * m_next;
    int m_used;

public : 
    LinkedList(int num);
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    ~LinkedList();

public :
    void insert(int addr, int num);
    void erase(int addr);
    void traverse();
};