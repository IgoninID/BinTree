// �����: ������ �.�.

#pragma once
#include "../BinTreeNode/Node.h"
#include "../InterfIter/AbstrIter.h"
#include <stack>

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

	class Iterator : public AbstrIter<T>
	{
		stack<BinTreeNode<T>*> nodes;
		BinTreeNode<T>* curr;
	private:
		void next()
		{
			if (nodes.empty())
			{
				curr = nullptr;
				return;
			}
			curr = nodes.top();
			nodes.pop();
			if (curr->right)
			{
				pushLeft(curr->right);
			}

		}
	public:

		Iterator(BinTreeNode<T>* root = nullptr) : curr(nullptr) 
		{
			pushLeft(root);
			next();
		}

		void pushLeft(BinTreeNode<T>* node)
		{
			while (node)
			{
				nodes.push(node);
				node = node->left;
			}
		}

		Iterator& operator ++() override
		{
			next();
			return *this;
		}

		T& operator *() const override
		{
			if (!curr)
			{
				throw out_of_range("������� �� ����������");
			}
			return curr->data;
		}

		bool operator !=(const AbstrIter<T>& other) const override
		{
			const Iterator* it = dynamic_cast<const Iterator*>(&other);
			if (!it)
			{
				return true;
			}
			return this->curr != it->curr;
		}
	};

	Iterator begin() const
	{
		return Iterator(root);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}

	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	BinaryTree()
	{
		size = 0;
		root = nullptr;
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
	BinaryTree<T>& operator =(const BinaryTree<T>& other)
	{
		return BinaryTree<T>(other);
	}

	/// <summary>
	/// �������� ������������ ������������
	/// </summary>
	/// <param name="other">������ �������� ������ ������</param>
	/// <returns>������������ ������</returns>
	BinaryTree<T>& operator =(BinaryTree<T>&& other)
	{
		if (this != &other)
		{
			return BinaryTree<T>(other);
		}
		return *this;
	}

	/// <summary>
	/// ����� ������� ������
	/// ��������� O(n)
	/// </summary>
	/// <param name="choice">����� �������</param>
	void print(PATHS choice)
	{
		path<T>(root, choice);
	}


	/// <summary>
	/// ����� ������� ������ � ������
	/// ��������� O(n)
	/// </summary>
	/// <param name="choice">����� �������</param>
	/// <param name="vec">������ ��� ������ ���������� �������</param>
	void print(PATHS choice, vector<T>& vec)
	{
		path<T>(root, choice, vec);
	}

	/// <summary>
	/// ������� � ������
	/// ��������� O(n) - ������������������, O(logn) - ����������������
	/// </summary>
	/// <param name="data">������ ��� ������� � ������</param>
	void insert(T data)
	{
		root = insertintree<T>(data, root);
		size += 1;
	}

	/// <summary>
	/// �������� ���� �� ������
	/// ��������� O(n) - ������������������, O(logn) - ����������������
	/// </summary>
	/// <param name="data">��������� ������</param>
	void remove(T data)
	{
		//if (size == 1)
		//{
		//	removeNode<T>(root, data);
		//	size -= 1;
		//	root == nullptr;
		//}
		//removeNode<T>(root, data);
		//size -= 1;

		try
		{
			findintree(data);
			removeNode<T>(root, data);
			size -= 1;
			if (size == 0)
			{
				root = nullptr;
			}
		}
		catch (out_of_range)
		{
			return;
		}
	}

	/// <summary>
	/// ����� ������ � ������
	/// ��������� O(n) - ������������������, O(logn) - ����������������
	/// </summary>
	/// <param name="data">������ ��� ������</param>
	/// <returns>������ ���� ��� ���� � ������</returns>
	T findintree(T data)
	{
		return find<T>(data, root);
	}

	/// <summary>
	/// ��������� ���������� ����� ������
	/// ��������� O(n)
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
	/// ��������� O(n)
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

	/// <summary>
	/// ������� ������
	/// </summary>
	void clear()
	{
		deletetree<T>(root);
		root = nullptr;
	}

	/// <summary>
	/// �������� �� ������ ������
	/// ��������� O(1)
	/// </summary>
	/// <returns>1-������, 0-��������</returns>
	bool empty()
	{
		if (!root)
		{
			return 1;
		}
		return 0;
	}

	/// <summary>
	/// ��������� ����� ������
	/// ��������� O(1)
	/// </summary>
	/// <returns>������ ������</returns>
	BinTreeNode<T>* get_root()
	{
			return root;
	}
};

/// <summary>
/// �������� ������� ��� �������� ������ ������� ������
/// </summary>
void test_void();

/// <summary>
/// �������� ������� ��� �������� ������ ������ �� ������ ��������
/// </summary>
void test_one();

/// <summary>
/// �������� ������� ��� �������� ������ ������������ ������
/// </summary>
void test_perf();

/// <summary>
/// �������� ������� ��� �������� ������ �������� ������
/// </summary>
void test_comp();

/// <summary>
/// �������� ������� ��� �������� ������ ������������ ������
/// </summary>
void test_deg();