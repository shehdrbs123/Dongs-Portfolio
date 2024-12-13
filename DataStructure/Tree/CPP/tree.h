#include <iostream>

using namespace std;

int main()
{

}

class C_TREE
{
private :
public :
    C_TREE();
    C_TREE(const C_TREE&) = delete;
    const C_TREE& operator=(const C_TREE&) = delete;
    ~C_TREE();

    template <typename T>
    class C_NODE
    {
    private : 
        T value;
        Node<T>* left;
        Node<T>* right;
    public :
        C_NODE<T>() = default;
        C_NODE<T>(const T&);
        const T& operator=(const T&) = delete;
        T GetValue();
        T* GetLeft();
        T* GetRight();
    };
};

template <typename T>
inline C_TREE::C_NODE<T>::C_NODE(const T & inValue) 
{
    value = inValue;
}
