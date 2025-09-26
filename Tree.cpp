// јвтор: »гонин ¬.ё.

#include "Tree.h"
#include <cassert>

using namespace std;

/// <summary>
/// “естова€ функци€ дл€ проверки работы пустого дерева
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

	// получение корн€
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
/// “естова€ функци€ дл€ проверки работы дерева из одного элемента
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

	// получение корн€
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
/// “естова€ функци€ дл€ проверки работы совершенного дерева
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

	//получение корн€
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

	// удаление с двум€ потомками
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
/// “естова€ функци€ дл€ проверки работы строгого дерева
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

	//получение корн€
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

	// удаление с двум€ потомками
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
/// “естова€ функци€ дл€ проверки работы вырожденного дерева
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

	//получение корн€
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