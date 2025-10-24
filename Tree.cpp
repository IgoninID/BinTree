// Автор: Игонин В.Ю.

#include "Tree.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Тестовая функция для проверки работы пустого дерева
/// </summary>
void test_void()
{
	BinaryTree<int> tree;
	vector<int> v;
	vector<int> t;

	// обходы
	tree.print(nlr, v);
	assert(v == t);
	v.clear();

	tree.print(nrl, v);
	assert(v == t);
	v.clear();

	tree.print(lnr, v);
	assert(v == t);
	v.clear();

	tree.print(rnl, v);
	assert(v == t);
	v.clear();

	tree.print(lrn, v);
	assert(v == t);
	v.clear();

	tree.print(rln, v);
	assert(v == t);
	v.clear();

	tree.print(iter, v);
	assert(v == t);
	v.clear();

	// получение корня
	assert(tree.get_root() == nullptr);

	// проверка на пустоту
	assert(tree.empty() == 1);

	//количество и глубина
	assert(tree.Size() == 0);
	assert(tree.Depth() == -1);

	//поиск
	try
	{
		int i = tree.findintree(5);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	// удаление
	tree.remove(5);
	tree.print(nlr, v);
	assert(v == t);

	// удаление дерева
	tree.clear();
	tree.print(nlr, v);
	assert(v == t);

	// вставка
	tree.insert(10);
	tree.print(nlr, v);
	assert(v.size() == 1);
	assert(v[0] == 10);
	v.clear();
}

/// <summary>
/// Тестовая функция для проверки работы дерева из одного элемента
/// </summary>
void test_one()
{
	BinaryTree<int> tree(10);
	vector<int> v;
	vector<int> t{ 10 };
	vector<int> t2;

	// обходы
	tree.print(nlr, v);
	assert(v == t);
	v.clear();

	tree.print(nrl, v);
	assert(v == t);
	v.clear();

	tree.print(lnr, v);
	assert(v == t);
	v.clear();

	tree.print(rnl, v);
	assert(v == t);
	v.clear();

	tree.print(lrn, v);
	assert(v == t);
	v.clear();

	tree.print(rln, v);
	assert(v == t);
	v.clear();

	tree.print(iter, v);
	assert(v == t);
	v.clear();

	// получение корня
	assert(tree.get_root()->data == 10);

	// проверка на пустоту
	assert(tree.empty() == 0);

	//количество и глубина
	assert(tree.Size() == 1);
	assert(tree.Depth() == 0);

	//поиск
	assert(tree.findintree(10) == 10);
	//поиск не существующего
	try
	{
		int i = tree.findintree(5);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// удаление не существующего
	tree.remove(5);
	tree.print(nlr, v);
	assert(v == t);
	v.clear();
	// удаление
	tree.remove(10);
	tree.print(nlr, v);
	assert(v == t2);
	v.clear();

	// вставка
	tree.insert(10);

	tree.insert(15);
	tree.print(nlr, v);
	assert(v.size() == 2);
	assert(v[0] == 10);
	assert(v[1] == 15);
	v.clear();
	tree.remove(15);

	//удаление дерева
	tree.clear();
	tree.print(nlr, v);
	assert(v == t2);

}

/// <summary>
/// Тестовая функция для проверки работы совершенного дерева
/// </summary>
void test_perf()
{
	BinaryTree<int> tree(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3, 8, 20, 15, 25 };
	vector<int> t2{ 10, 20, 25, 15, 6, 8, 3 };
	vector<int> t3{ 3, 6, 8, 10, 15, 20, 25 };
	vector<int> t4{ 25, 20, 15, 10, 8, 6, 3 };
	vector<int> t5{ 3, 8, 6, 15, 25, 20, 10 };
	vector<int> t6{ 25, 15, 20, 8, 3, 6, 10 };
	/*
	*                   10
	*               6       20
	*             3   8   15   25
	*/
	tree.insert(6);
	tree.insert(20);
	tree.insert(3);
	tree.insert(8);
	tree.insert(15);
	tree.insert(25);

	// обходы
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	tree.print(nrl, v);
	assert(v == t2);
	v.clear();

	tree.print(lnr, v);
	assert(v == t3);
	v.clear();

	tree.print(rnl, v);
	assert(v == t4);
	v.clear();

	tree.print(lrn, v);
	assert(v == t5);
	v.clear();

	tree.print(rln, v);
	assert(v == t6);
	v.clear();

	tree.print(iter, v);
	assert(v == t1);
	v.clear();

	//получение корня
	assert(tree.get_root()->data == 10);

	// проверка на пустоту
	assert(tree.empty() == 0);

	//количество и глубина
	assert(tree.Size() == 7);
	assert(tree.Depth() == 2);

	//поиск
	assert(tree.findintree(8) == 8);
	//поиск не существующего
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// удаление не существующего
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// удаление без потомков
	tree.remove(25);
	tree.print(nlr, v);
	vector<int> t7{ 10, 6, 3, 8, 20, 15 };
	assert(v == t7);
	v.clear();

	// удаление с одним потомком
	tree.remove(20);
	tree.print(nlr, v);
	vector<int> t8{ 10, 6, 3, 8, 15 };
	assert(v == t8);
	v.clear();

	// удаление с двумя потомками
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t9{ 10, 8, 3, 15 };
	assert(v == t9);
	v.clear();

	// вставка
	tree.insert(18);
	tree.print(nlr, v);
	vector<int> t10{ 10, 8, 3, 15, 18 };
	assert(v == t10);
	v.clear();

	//удаление дерева
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// Тестовая функция для проверки работы строгого дерева
/// </summary>
void test_comp()
{
	BinaryTree<int> tree(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3, 8, 20 };
	vector<int> t2{ 10, 20, 6, 8, 3 };
	vector<int> t3{ 3, 6, 8, 10, 20 };
	vector<int> t4{ 20, 10, 8, 6, 3 };
	vector<int> t5{ 3, 8, 6, 20, 10 };
	vector<int> t6{ 20, 8, 3, 6, 10 };
	/*
	*                   10
	*               6       20
	*             3   8
	*/
	tree.insert(6);
	tree.insert(20);
	tree.insert(3);
	tree.insert(8);

	// обходы
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	tree.print(nrl, v);
	assert(v == t2);
	v.clear();

	tree.print(lnr, v);
	assert(v == t3);
	v.clear();

	tree.print(rnl, v);
	assert(v == t4);
	v.clear();

	tree.print(lrn, v);
	assert(v == t5);
	v.clear();

	tree.print(rln, v);
	assert(v == t6);
	v.clear();

	tree.print(iter, v);
	assert(v == t1);
	v.clear();

	//получение корня
	assert(tree.get_root()->data == 10);

	// проверка на пустоту
	assert(tree.empty() == 0);

	//количество и глубина
	assert(tree.Size() == 5);
	assert(tree.Depth() == 2);

	//поиск
	assert(tree.findintree(8) == 8);
	//поиск не существующего
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// удаление не существующего
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// удаление без потомков
	tree.remove(20);
	tree.print(nlr, v);
	vector<int> t7{ 10, 6, 3, 8 };
	assert(v == t7);
	v.clear();

	// удаление с двумя потомками
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t9{ 10, 8, 3 };
	assert(v == t9);
	v.clear();

	// удаление с одним потомком
	tree.remove(8);
	tree.print(nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// вставка
	tree.insert(18);
	tree.print(nlr, v);
	vector<int> t10{ 10, 3, 18 };
	assert(v == t10);
	v.clear();

	//удаление дерева
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// Тестовая функция для проверки работы вырожденного дерева
/// </summary>
void test_deg()
{
	BinaryTree<int> tree(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3 };
	vector<int> t2{ 10, 6, 3 };
	vector<int> t3{ 3, 6, 10 };
	vector<int> t4{ 10, 6, 3 };
	vector<int> t5{ 3, 6, 10 };
	vector<int> t6{ 3, 6, 10 };
	/*
	*                   10
	*               6
	*             3
	*/
	tree.insert(6);
	tree.insert(3);

	// обходы
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	tree.print(nrl, v);
	assert(v == t2);
	v.clear();

	tree.print(lnr, v);
	assert(v == t3);
	v.clear();

	tree.print(rnl, v);
	assert(v == t4);
	v.clear();

	tree.print(lrn, v);
	assert(v == t5);
	v.clear();

	tree.print(rln, v);
	assert(v == t6);
	v.clear();

	tree.print(iter, v);
	assert(v == t1);
	v.clear();

	//получение корня
	assert(tree.get_root()->data == 10);

	// проверка на пустоту
	assert(tree.empty() == 0);

	//количество и глубина
	assert(tree.Size() == 3);
	assert(tree.Depth() == 2);

	//поиск
	assert(tree.findintree(3) == 3);
	//поиск не существующего
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// удаление не существующего
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// удаление с одним потомком
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// удаление без потомков
	tree.remove(3);
	tree.print(nlr, v);
	vector<int> t7{ 10 };
	assert(v == t7);
	v.clear();

	// вставка
	tree.insert(1);
	tree.print(nlr, v);
	vector<int> t10{ 10, 1 };
	assert(v == t10);
	v.clear();

	//удаление дерева
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}

void test_mult_beg() 
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		auto it1 = bst.begin();
		auto it2 = bst.begin();
		auto e1 = bst.end();
		auto e2 = bst.end();

		assert(!(it1 != e1));
		assert(!(it2 != e2));

		assert(!(it1 != it2));
	}

	// дерево из одного узла
	{
		BinaryTree<int> bst;
		bst.insert(4);
		auto it1 = bst.begin();
		auto it2 = bst.begin();
		auto e = bst.end();

		// Оба begin() указывают на один и тот же корневой узел
		assert(!(it1 != it2));
		assert(*it1 == 4);
		assert(*it2 == 4);

		// После инкремента оба станут равны end()
		++it1;
		++it2;
		assert(!(it1 != e));
		assert(!(it2 != e));
	}

	// простое дерево
	{
		BinaryTree<int> bst;
		for (int v : {4, 2, 6, 1, 3, 5, 7})
		{
			bst.insert(v);
		}

		auto it1 = bst.begin();
		auto it2 = bst.begin();
		auto it3 = bst.begin();
		auto e = bst.end();

		// Все три итератора начинают с минимального элемента (1)
		assert(*it1 == 1 && *it2 == 1 && *it3 == 1);
		assert(!(it1 != it2));
		assert(!(it2 != it3));

		// Двигаем один — должен измениться current
		++it1;
		assert(it1 != it2);
		assert(*it1 == 2);
		assert(*it2 == 1);
	}

	// дерево из 5 элементов
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 5; ++i)
		{
			bst.insert(i);
		}

		auto it1 = bst.begin();
		auto it2 = bst.begin();
		auto e = bst.end();

		++it1; // теперь it1 указывает на 2
		assert(it1 != it2);
		assert(*it1 == 2);
		assert(*it2 == 1);

		// Оба корректно дойдут до конца независимо
		int steps1 = 0, steps2 = 0;
		while (it1 != e) 
		{ 
			++it1; ++steps1; 
		}
		while (it2 != e) 
		{
			++it2; ++steps2; 
		}
		assert(steps1 == 4);
		assert(steps2 == 5);
	}

	// begin() на разных деревьях
	{
		BinaryTree<int> bst1;
		BinaryTree<int> bst2;
		bst1.insert(10);
		bst2.insert(20);

		auto it1 = bst1.begin();
		auto it2 = bst2.begin();
		assert(it1 != it2);
		assert(*it1 == 10);
		assert(*it2 == 20);
	}
}

void test_inc()
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		auto it = bst.begin();
		auto e = bst.end();
		assert(!(it != e));
	}

	// дерево из одного узла
	{
		BinaryTree<int> bst;
		bst.insert(10);
		auto it = bst.begin();
		auto e = bst.end();
		assert(*it == 10);
		++it;
		assert(!(it != e));
	}

	// простое дерево
	{
		BinaryTree<int> bst;
		for (int v : {4, 2, 6, 1, 3, 5, 7})
		{
			bst.insert(v);
		}
		vector<int> expected = { 1,2,3,4,5,6,7 };
		vector<int> collected;
		for (auto it : bst)
		{
			collected.push_back(it);
		}
		assert(collected == expected);
	}

	// все вправо
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 5; ++i)
		{
			bst.insert(i);
		}
		int expected = 1;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			assert(*it == expected++);
		}
		assert(expected == 6);
	}

	// все влево
	{
		BinaryTree<int> bst;
		for (int i = 5; i >= 1; --i)
		{
			bst.insert(i);
		}
		int expected = 1;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			assert(*it == expected++);
		}
		assert(expected == 6);
	}
}

void test_def()
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		try 
		{
			auto it = bst.begin();
			int x = *it;
			assert(false);
		}
		catch (out_of_range&) 
		{

		}
	}

	// один узел
	{
		BinaryTree<int> bst;
		bst.insert(42);
		auto it = bst.begin();
		assert(*it == 42);
	}

	// простое дерево
	{
		BinaryTree<int> bst;
		for (int v : {4, 2, 6, 1, 3, 5, 7})
		{
			bst.insert(v);
		}
		auto it = bst.begin();
		assert(*it == 1);
		++it;
		assert(*it == 2);
		++it;
		assert(*it == 3);
	}

	// вправо
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 9; ++i)
		{
			bst.insert(i);
		}
		auto it = bst.begin();
		for (int i = 1; i < 5; ++i)
		{
			++it;
		}
		assert(*it == 5);
	}

	// произвольный набор
	{
		BinaryTree<int> bst;
		vector<int> ins = { 10, 5, 15, 3, 7, 12, 18 };
		for (int v : ins)
		{
			bst.insert(v);
		}
		vector<int> expected = {3, 5, 7, 10, 12, 15, 18};
		vector<int> collected;
		for (auto it = bst.begin(); it != bst.end(); ++it)
			collected.push_back(*it);
		assert(collected == expected);
	}
}

void test_compar()
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		auto b = bst.begin();
		auto e = bst.end();
		assert(!(b != e));
	}

	// один элемент
	{
		BinaryTree<int> bst;
		bst.insert(7);
		auto b = bst.begin();
		auto e = bst.end();
		assert(b != e);
		++b;
		assert(!(b != e));
	}

	// копии итераторов
	{
		BinaryTree<int> bst;
		for (int v : {2, 1, 3})
		{
			bst.insert(v);
		}
		auto it1 = bst.begin();
		auto it2 = it1;
		assert(!(it1 != it2));
		++it1;
		assert(it1 != it2);
	}

	// end дважды
	{
		BinaryTree<int> bst;
		bst.insert(100);
		auto e1 = bst.end();
		auto e2 = bst.end();
		assert(!(e1 != e2));
	}

	// разные деревья
	{
		BinaryTree<int> a, b;
		a.insert(1);
		b.insert(2);
		auto itA = a.begin();
		auto itB = b.begin();
		assert(itA != itB);
	}

}

void test_iter()
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		vector<int> result;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			result.push_back(*it);
		}
		assert(result.empty());
	}

	// один элемент
	{
		BinaryTree<int> bst;
		bst.insert(11);
		vector<int> result;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			result.push_back(*it);
		}
		assert(result.size() == 1 && result[0] == 11);
	}

	// простое дерево
	{
		BinaryTree<int> bst;
		vector<int> ins = { 4,2,6,1,3,5,7 };
		for (int v : ins)
		{
			bst.insert(v);
		}
		vector<int> expected = {1, 2, 3, 4, 5, 6, 7};
		vector<int> result;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			result.push_back(*it);
		}
		assert(result == expected);
	}

	// вырожденное вправо
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 8; ++i)
		{
			bst.insert(i);
		}
		int expected = 1;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			assert(*it == expected++);
		}
	}

	// произвольное дерево
	{
		BinaryTree<int> bst;
		for (int v : {20, 10, 30, 5, 15, 25, 35})
		{
			bst.insert(v);
		}
		vector<int> expected = { 5,10,15,20,25,30,35 };
		vector<int> result;
		for (auto it = bst.begin(); it != bst.end(); ++it)
		{
			result.push_back(*it);
		}
		assert(result == expected);
	}

}

void test_case()
{
	// пустое дерево
	{
		BinaryTree<int> bst;
		try 
		{
			*bst.begin();
			assert(false);
		}
		catch (out_of_range&) 
		{

		}
	}

	// разыменование end
	{
		BinaryTree<int> bst;
		bst.insert(7);
		auto e = bst.end();
		try 
		{
			*e;
			assert(false);
		}
		catch (out_of_range&) 
		{

		}
	}

	// после прохода до конца
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 3; ++i)
		{
			bst.insert(i);
		}
		auto it = bst.begin();
		auto e = bst.end();
		while (it != e)
		{
			++it;
		}
		try 
		{
			*it;
			assert(false);
		}
		catch (out_of_range&) 
		{

		}
	}

	// ++ за пределы end
	{
		BinaryTree<int> bst;
		for (int i : {2, 1, 3})
		{
			bst.insert(i);
		}
		auto it = bst.begin();
		auto e = bst.end();
		for (int i = 0; i < 10; ++i)
		{
			++it; // не должно быть исключений
		}
		try 
		{
			*it;
			assert(false);
		}
		catch (const out_of_range&) 
		{
			
		}
	}

	//  копия итератора после ++ ведёт себя корректно
	{
		BinaryTree<int> bst;
		for (int i = 1; i <= 5; ++i)
		{
			bst.insert(i);
		}
		auto it = bst.begin();
		++it; // теперь указывает на второй
		auto it_copy = it; // копия
		assert(*it == *it_copy);
		++it;
		assert(*it != *it_copy);
	}
}