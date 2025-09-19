#pragma once
#include "../BinTreeNode/Node.h"

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

	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	BinaryTree()
	{
		size = 0;
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
	BinaryTree& operator=(const BinaryTree& other)
	{
		return BinaryTree(other);
	}

	/// <summary>
	/// Оператор присваивания перемещением
	/// </summary>
	/// <param name="other">Другое бинарное дерево поиска</param>
	/// <returns>Перемещенное дерево</returns>
	BinaryTree& operator=(BinaryTree&& other)
	{
		return BinaryTree(other);
	}

	/// <summary>
	/// Вывод прохода дерева
	/// </summary>
	/// <param name="choice">Выбор прохода</param>
	void print(PATHS choice)
	{
		path<T>(root, choice);
	}


	/// <summary>
	/// Вывод прохода дерева в вектор
	/// </summary>
	/// <param name="choice">Выбор прохода</param>
	/// <param name="vec">Вектор для записи результата прохода</param>
	void print(PATHS choice, vector<T>& vec)
	{
		path<T>(root, choice, vec);
	}

	/// <summary>
	/// Вставка в дерево
	/// </summary>
	/// <param name="data">Данные для вставки в дерево</param>
	void insert(T data)
	{
		insertintree<T>(data, root);
		size += 1;
	}

	/// <summary>
	/// Удаление узла из дерева
	/// </summary>
	/// <param name="data">Удаляемые данные</param>
	void remove(T data)
	{
		removeNode<T>(root, data);
		size -= 1;
	}

	/// <summary>
	/// Поиск данных в дереве
	/// </summary>
	/// <param name="data">Данные для поиска</param>
	/// <returns>Данные если они есть в дереве</returns>
	T findintree(T data)
	{
		return find<T>(data, root);
	}

	/// <summary>
	/// Получение количества узлов дерева
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
};

/// <summary>
/// Тесты
/// </summary>
void test();