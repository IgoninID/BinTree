// �����: ������ �.�.

#include "Tree.h"
#include <cassert>

using namespace std;

/// <summary>
/// �������� ������� ��� �������� ������ ������� ������
/// </summary>
void test_void()
{
	BinaryTree<int> tree;
	vector<int> v;
	vector<int> t;

	// ������
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

	// ��������� �����
	assert(tree.get_root() == nullptr);

	// �������� �� �������
	assert(tree.empty() == 1);

	//���������� � �������
	assert(tree.Size() == 0);
	assert(tree.Depth() == -1);

	//�����
	try
	{
		int i = tree.findintree(5);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	// ��������
	tree.remove(5);
	tree.print(nlr, v);
	assert(v == t);

	// �������� ������
	tree.clear();
	tree.print(nlr, v);
	assert(v == t);

	// �������
	tree.insert(10);
	tree.print(nlr, v);
	assert(v.size() == 1);
	assert(v[0] == 10);
	v.clear();
}

/// <summary>
/// �������� ������� ��� �������� ������ ������ �� ������ ��������
/// </summary>
void test_one()
{
	BinaryTree<int> tree(10);
	vector<int> v;
	vector<int> t{ 10 };
	vector<int> t2;

	// ������
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

	// ��������� �����
	assert(tree.get_root()->data == 10);

	// �������� �� �������
	assert(tree.empty() == 0);

	//���������� � �������
	assert(tree.Size() == 1);
	assert(tree.Depth() == 0);

	//�����
	assert(tree.findintree(10) == 10);
	//����� �� �������������
	try
	{
		int i = tree.findintree(5);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	tree.remove(5);
	tree.print(nlr, v);
	assert(v == t);
	v.clear();
	// ��������
	tree.remove(10);
	tree.print(nlr, v);
	assert(v == t2);
	v.clear();

	// �������
	tree.insert(10);

	tree.insert(15);
	tree.print(nlr, v);
	assert(v.size() == 2);
	assert(v[0] == 10);
	assert(v[1] == 15);
	v.clear();
	tree.remove(15);

	//�������� ������
	tree.clear();
	tree.print(nlr, v);
	assert(v == t2);

}

/// <summary>
/// �������� ������� ��� �������� ������ ������������ ������
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

	// ������
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

	//��������� �����
	assert(tree.get_root()->data == 10);

	// �������� �� �������
	assert(tree.empty() == 0);

	//���������� � �������
	assert(tree.Size() == 7);
	assert(tree.Depth() == 2);

	//�����
	assert(tree.findintree(8) == 8);
	//����� �� �������������
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// �������� ��� ��������
	tree.remove(25);
	tree.print(nlr, v);
	vector<int> t7{ 10, 6, 3, 8, 20, 15 };
	assert(v == t7);
	v.clear();

	// �������� � ����� ��������
	tree.remove(20);
	tree.print(nlr, v);
	vector<int> t8{ 10, 6, 3, 8, 15 };
	assert(v == t8);
	v.clear();

	// �������� � ����� ���������
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t9{ 10, 8, 3, 15 };
	assert(v == t9);
	v.clear();

	// �������
	tree.insert(18);
	tree.print(nlr, v);
	vector<int> t10{ 10, 8, 3, 15, 18 };
	assert(v == t10);
	v.clear();

	//�������� ������
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// �������� ������� ��� �������� ������ �������� ������
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

	// ������
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

	//��������� �����
	assert(tree.get_root()->data == 10);

	// �������� �� �������
	assert(tree.empty() == 0);

	//���������� � �������
	assert(tree.Size() == 5);
	assert(tree.Depth() == 2);

	//�����
	assert(tree.findintree(8) == 8);
	//����� �� �������������
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// �������� ��� ��������
	tree.remove(20);
	tree.print(nlr, v);
	vector<int> t7{ 10, 6, 3, 8 };
	assert(v == t7);
	v.clear();

	// �������� � ����� ���������
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t9{ 10, 8, 3 };
	assert(v == t9);
	v.clear();

	// �������� � ����� ��������
	tree.remove(8);
	tree.print(nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// �������
	tree.insert(18);
	tree.print(nlr, v);
	vector<int> t10{ 10, 3, 18 };
	assert(v == t10);
	v.clear();

	//�������� ������
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// �������� ������� ��� �������� ������ ������������ ������
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

	// ������
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

	//��������� �����
	assert(tree.get_root()->data == 10);

	// �������� �� �������
	assert(tree.empty() == 0);

	//���������� � �������
	assert(tree.Size() == 3);
	assert(tree.Depth() == 2);

	//�����
	assert(tree.findintree(3) == 3);
	//����� �� �������������
	try
	{
		int i = tree.findintree(100);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	tree.remove(100);
	tree.print(nlr, v);
	assert(v == t1);
	v.clear();

	// �������� � ����� ��������
	tree.remove(6);
	tree.print(nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// �������� ��� ��������
	tree.remove(3);
	tree.print(nlr, v);
	vector<int> t7{ 10 };
	assert(v == t7);
	v.clear();

	// �������
	tree.insert(1);
	tree.print(nlr, v);
	vector<int> t10{ 10, 1 };
	assert(v == t10);
	v.clear();

	//�������� ������
	tree.clear();
	tree.print(nlr, v);
	vector<int> t11;
	assert(v == t11);
}