// Автор: Игонин В.Ю.

#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    test_void();
    test_one();
    test_deg();
    test_comp();
    test_perf();
    test_mult_beg();
    test_inc();
    test_def();
    test_compar();
    test_iter();
    test_case();
    BinaryTree<int> tree(10);
    tree.insert(6);
    tree.insert(20);
    tree.insert(3);
    tree.insert(8);
    tree.insert(15);
    tree.insert(25);
    for (auto t : tree)
    {
        cout << t << " ";
    }
    cout << endl;
    for (auto it = tree.begin(); it != tree.end(); ++it)
    {
        cout << *it << " ";
    }
}
