#include <string>
#include <iostream>

template<class T>
class BSNode
{
public:

    //constructors and destructor and copy constructor
    BSNode(const T& data);
    BSNode(const BSNode& other);
    ~BSNode();

    void insert(const T& value);
    BSNode& operator=(const BSNode& other);

    //getters
    T getData()const;
    int getCount()const;
    BSNode* getLeft()const;
    BSNode* getRight()const;
    int getHeight()const;
    int getDepth(const BSNode& root)const;

    //bool functions
    bool isLeaf()const;
    bool search(const T& val)const;
    
    //print
    void printNodes()const;

private:
    T _data;
    BSNode* _left;
    BSNode* _right;

    int _count;
};

//BSNODE

//constructor
template<class T>
inline BSNode<T>::BSNode(const T& data) : _data(data), _left(nullptr), _right(nullptr), _count(1){}

//copy constructor
template<class T>
inline BSNode<T>::BSNode(const BSNode& other) : _data(other._data), _left(nullptr), _right(nullptr), _count(1)
{
    _left = other._left ? new BSNode(*other._left) : nullptr;
    _right = other._right ? new BSNode(*other._right) : nullptr;
}

//destructor
template<class T>
inline BSNode<T>::~BSNode()
{
    delete _left;
    delete _right;
}

template<class T>
inline void BSNode<T>::insert(const T& value)
{
    if (value == _data)
    {
        _count++;
    }
    else if (value < _data)
    {
        if (_left)
        {
            _left->insert(value);
        }
        else
        {
            _left = new BSNode(value);
        }
    }
    else
    {
        if (_right)
        {
            _right->insert(value);
        }
        else
        {
            _right = new BSNode(value);
        }
    }
}

template<class T>
inline BSNode<T>& BSNode<T>::operator=(const BSNode& other)
{
    if (this == &other)
    {
        return *this;
    }

    _data = other._data;
    _count = other._count;

    delete _left;
    delete _right;

    _left = other._left ? new BSNode(*other._left) : nullptr;
    _right = other._right ? new BSNode(*other._right) : nullptr;

    return *this;
}

template<class T>
inline T BSNode<T>::getData() const
{
    return _data;
}

template<class T>
inline int BSNode<T>::getCount() const
{
    return _count;
}

template<class T>
inline BSNode<T>* BSNode<T>::getLeft() const
{
    return _left;
}

template<class T>
inline BSNode<T>* BSNode<T>::getRight() const
{
    return _right;
}

template<class T>
inline int BSNode<T>::getHeight() const
{
    int leftH = 0, rightH = 0;

    if (_left)
        leftH = _left->getHeight();

    if (_right)
        rightH = _right->getHeight();

    return 1 + std::max(leftH, rightH);
}

template<class T>
inline int BSNode<T>::getDepth(const BSNode& root) const
{
    int leftDepth, rightDepth;

    if (this == &root)
    {
        return 0;
    }

    if (_left)
    {
        leftDepth = _left->getDepth(root);
        if (leftDepth != -1)
        {
            return 1 + leftDepth;
        }
    }

    if (_right)
    {
        rightDepth = _right->getDepth(root);
        if (rightDepth != -1)
        {
            return 1 + rightDepth;
        }
    }

    return -1;
}

template<class T>
inline bool BSNode<T>::isLeaf() const
{
    return !_right && !_left;
}

template<class T>
inline bool BSNode<T>::search(const T& val) const
{
    if (val == _data)
    {
        return true;
    }
    if (val < _data)
    {
        return _left ? _left->search(val) : false;
    }
    return _right ? _right->search(val) : false;
}

template<class T>
inline void BSNode<T>::printNodes() const
{
    if (_left)
    {
        _left->printNodes();
    }

    std::cout << _data << " (" << _count << ") ";

    if (_right)
    {
        _right->printNodes();
    }
}
