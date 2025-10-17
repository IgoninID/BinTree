// Автор: Игонин В.Ю.

#pragma once
#include "../BinTreeNode/Node.h"
#include "../InterfIter/AbstrIter.h"
#include <stack>

/// <summary>
/// Шаблонный класс бинарное дерева поиска
/// </summary>
/// <typeparam name="T">Тип данных узлов дерева поиска</typeparam>
template <typename T>
class BinaryTree
{
private:
	BinTreeNode<T>* root; // указатель на корень дерева
	size_t size; // количество узлов дерева
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
				throw out_of_range("Элемент не существует");
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
	/// Конструктор по умолчанию
	/// </summary>
	BinaryTree()
	{
		size = 0;
		root = nullptr;
	}

	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="data">Данные, записываемые в дерево</param>
	BinaryTree(T data)
	{
		size = 1;
		root = new BinTreeNode<T>(data);
	}

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="other">Другое бинарное дерево поиска</param>
	BinaryTree(const BinaryTree& other)
	{
		root = copyNodes(other.root);
	}

	/// <summary>
	/// Конструктор копирования перемещением
	/// </summary>
	/// <param name="other">Другое бинарное дерево поиска</param>
	BinaryTree(BinaryTree&& other) noexcept : root(other.root), size(other.size)
	{
		other.root = nullptr;
		other.size = 0;
	}

	/// <summary>
	/// Оператор присваивания копированием
	/// </summary>
	/// <param name="other">Другое бинарное дерево поиска</param>
	/// <returns>Копию другого дерева</returns>
	BinaryTree<T>& operator =(const BinaryTree<T>& other)
	{
		return BinaryTree<T>(other);
	}

	/// <summary>
	/// Оператор присваивания перемещением
	/// </summary>
	/// <param name="other">Другое бинарное дерево поиска</param>
	/// <returns>Перемещенное дерево</returns>
	BinaryTree<T>& operator =(BinaryTree<T>&& other)
	{
		if (this != &other)
		{
			return BinaryTree<T>(other);
		}
		return *this;
	}

	/// <summary>
	/// Вывод прохода дерева
	/// Сложность O(n)
	/// </summary>
	/// <param name="choice">Выбор прохода</param>
	void print(PATHS choice)
	{
		path<T>(root, choice);
	}


	/// <summary>
	/// Вывод прохода дерева в вектор
	/// Сложность O(n)
	/// </summary>
	/// <param name="choice">Выбор прохода</param>
	/// <param name="vec">Вектор для записи результата прохода</param>
	void print(PATHS choice, vector<T>& vec)
	{
		path<T>(root, choice, vec);
	}

	/// <summary>
	/// Вставка в дерево
	/// Сложность O(n) - несбалансированное, O(logn) - сбалансированное
	/// </summary>
	/// <param name="data">Данные для вставки в дерево</param>
	void insert(T data)
	{
		root = insertintree<T>(data, root);
		size += 1;
	}

	/// <summary>
	/// Удаление узла из дерева
	/// Сложность O(n) - несбалансированное, O(logn) - сбалансированное
	/// </summary>
	/// <param name="data">Удаляемые данные</param>
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
	/// Поиск данных в дереве
	/// Сложность O(n) - несбалансированное, O(logn) - сбалансированное
	/// </summary>
	/// <param name="data">Данные для поиска</param>
	/// <returns>Данные если они есть в дереве</returns>
	T findintree(T data)
	{
		return find<T>(data, root);
	}

	/// <summary>
	/// Получение количества узлов дерева
	/// Сложность O(n)
	/// </summary>
	/// <returns>Количество узлов дерева</returns>
	size_t Size()
	{
		if (count(root) == size)
		{
			return size;
		}
		throw 1;
	}

	/// <summary>
	/// Получение глубины дерева
	/// Сложность O(n)
	/// </summary>
	/// <returns>Глубина дерева</returns>
	int Depth()
	{
		return depth(root);
	}

	/// <summary>
	/// Деструктор
	/// </summary>
	~BinaryTree()
	{
		deletetree<T>(root);
	}

	/// <summary>
	/// Очистка дерева
	/// </summary>
	void clear()
	{
		deletetree<T>(root);
		root = nullptr;
	}

	/// <summary>
	/// Проверка на пустое дерево
	/// Сложность O(1)
	/// </summary>
	/// <returns>1-пустое, 0-непустое</returns>
	bool empty()
	{
		if (!root)
		{
			return 1;
		}
		return 0;
	}

	/// <summary>
	/// Получение корня дерева
	/// Сложность O(1)
	/// </summary>
	/// <returns>Корень дерева</returns>
	BinTreeNode<T>* get_root()
	{
			return root;
	}
};

/// <summary>
/// Тестовая функция для проверки работы пустого дерева
/// </summary>
void test_void();

/// <summary>
/// Тестовая функция для проверки работы дерева из одного элемента
/// </summary>
void test_one();

/// <summary>
/// Тестовая функция для проверки работы совершенного дерева
/// </summary>
void test_perf();

/// <summary>
/// Тестовая функция для проверки работы строгого дерева
/// </summary>
void test_comp();

/// <summary>
/// Тестовая функция для проверки работы вырожденного дерева
/// </summary>
void test_deg();