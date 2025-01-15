#include "BSNode.h"
#include <iostream>
#include "printTreeToFile.h"

//constructor
BSNode::BSNode(std::string data) : _data(data), _left(nullptr), _right(nullptr), _count(1) {}

//copy
BSNode::BSNode(const BSNode& other) : _data(other._data), _count(other._count)
{
	//checking if its nullptr or not and if not creating new node
	_left = other._left ? new BSNode(*other._left) : nullptr;
	_right = other._right ? new BSNode(*other._right) : nullptr;

}

//deftructor
BSNode::~BSNode()
{
	delete _left;
	delete _right;
}

void BSNode::insert(std::string value)
{
	//upadating by 1 if same
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

//copy op
BSNode& BSNode::operator=(const BSNode& other)
{
	if (this == &other)
	{
		return *this;
	}
	_data = other._data;
	_count = other._count;

	//deleting nodes
	delete _left;
	delete _right;

	//copy left and right kids
	_left = other._left ? new BSNode(*other._left) : nullptr;
	_right = other._right ? new BSNode(*other._right) : nullptr;
	
	return *this;
}

bool BSNode::isLeaf() const
{
	//checking ikf there is left and right then its leaf
	return !_left && !_right;
}

std::string BSNode::getData() const
{
	return _data;
}

int BSNode::getCount() const
{
	return _count;
}

BSNode* BSNode::getLeft() const
{
	return _left;
}

BSNode* BSNode::getRight() const
{
	return _right;
}

bool BSNode::search(std::string val) const
{
	//searching for the value in the nodes(left right)
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

int BSNode::getHeight() const
{
	int leftH;
	int rightH;
	if (isLeaf())
	{
		return 0;
	}
	leftH = _left ? _left->getHeight() : 0;
	rightH = _right ? _right->getHeight() : 0;

	//returning the height of the cur node
	return 1 + std::max(leftH, rightH);
}

int BSNode::getDepth(const BSNode& root) const
{
	int leftDepth, rightDepth;

	if (this == &root) // checking if node is root
	{
		return 0;
	}
	
	//for left leaf
	if (_left)
	{
		leftDepth = _left->getDepth(root);
		if (leftDepth != -1)
		{
			return 1 + leftDepth;
		}
		
	}

	//for right leaf
	if (_right)
	{
		rightDepth = _right->getDepth(root);
		if (rightDepth != -1)
		{
			return 1 + rightDepth;
		}

	}

	return -1; //node not found
}

void BSNode::printNodes() const
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

int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	return getDepth(*node);
}
