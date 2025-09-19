#pragma once
#include "../BinTreeNode/Node.h"

/// <summary>
/// ��������� ����� �������� ������ ������
/// </summary>
/// <typeparam name="T">��� ������ ����� ������ ������</typeparam>
template <typename T>
class BinaryTree
{
private:
	BinTreeNode<T>* root; // ��������� �� ������ ������
	size_t size; // ���������� ����� ������
public:

	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	BinaryTree()
	{
		size = 0;
	}

	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="data">������, ������������ � ������</param>
	BinaryTree(T data)
	{
		size = 1;
		root = new BinTreeNode<T>(data);
	}

	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="other">������ �������� ������ ������</param>
	BinaryTree(const BinaryTree& other)
	{
		root = copyNodes(other.root);
	}

	/// <summary>
	/// ����������� ����������� ������������
	/// </summary>
	/// <param name="other">������ �������� ������ ������</param>
	BinaryTree(BinaryTree&& other) noexcept : root(other.root), size(other.size)
	{
		other.root = nullptr;
		other.size = 0;
	}

	/// <summary>
	/// �������� ������������ ������������
	/// </summary>
	/// <param name="other">������ �������� ������ ������</param>
	/// <returns>����� ������� ������</returns>
	BinaryTree& operator=(const BinaryTree& other)
	{
		return BinaryTree(other);
	}

	/// <summary>
	/// �������� ������������ ������������
	/// </summary>
	/// <param name="other">������ �������� ������ ������</param>
	/// <returns>������������ ������</returns>
	BinaryTree& operator=(BinaryTree&& other)
	{
		return BinaryTree(other);
	}

	/// <summary>
	/// ����� ������� ������
	/// </summary>
	/// <param name="choice">����� �������</param>
	void print(PATHS choice)
	{
		path<T>(root, choice);
	}


	/// <summary>
	/// ����� ������� ������ � ������
	/// </summary>
	/// <param name="choice">����� �������</param>
	/// <param name="vec">������ ��� ������ ���������� �������</param>
	void print(PATHS choice, vector<T>& vec)
	{
		path<T>(root, choice, vec);
	}

	/// <summary>
	/// ������� � ������
	/// </summary>
	/// <param name="data">������ ��� ������� � ������</param>
	void insert(T data)
	{
		insertintree<T>(data, root);
		size += 1;
	}

	/// <summary>
	/// �������� ���� �� ������
	/// </summary>
	/// <param name="data">��������� ������</param>
	void remove(T data)
	{
		removeNode<T>(root, data);
		size -= 1;
	}

	/// <summary>
	/// ����� ������ � ������
	/// </summary>
	/// <param name="data">������ ��� ������</param>
	/// <returns>������ ���� ��� ���� � ������</returns>
	T findintree(T data)
	{
		return find<T>(data, root);
	}

	/// <summary>
	/// ��������� ���������� ����� ������
	/// </summary>
	/// <returns>���������� ����� ������</returns>
	size_t Size()
	{
		if (count(root) == size)
		{
			return size;
		}
		throw 1;
	}

	/// <summary>
	/// ��������� ������� ������
	/// </summary>
	/// <returns>������� ������</returns>
	int Depth()
	{
		return depth(root);
	}

	/// <summary>
	/// ����������
	/// </summary>
	~BinaryTree()
	{
		deletetree<T>(root);
	}
};

/// <summary>
/// �����
/// </summary>
void test();