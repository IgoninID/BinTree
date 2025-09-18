#pragma once
#include "../BinTreeNode/Node.h"

template <typename T>
class BinaryTree
{
private:
	BinTreeNode<T>* root;
	size_t size;
public:

	BinaryTree()
	{
		size = 0;
	}

	BinaryTree(T data)
	{
		size = 1;
		root = new BinTreeNode<T>(data);
	}

	void print(PATHS choice)
	{
		path<T>(root, choice);
	}

	void insert(T data)
	{
		insertintree<T>(data, root);
		size += 1;
	}

	void remove(T data)
	{
		removeNode<T>(root, data);
		size -= 1;
	}

	T findintree(T data)
	{
		return find<T>(data, root);
	}

	size_t Size()
	{
		if (count(root) == size)
		{
			return size;
		}
		throw 1;
	}

	int Depth()
	{
		return depth(root);
	}

	~BinaryTree()
	{
		deletetree<T>(root)
	}
};