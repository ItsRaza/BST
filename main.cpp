#include<iostream>
#include<string>
#include"BSTnode.h"
using namespace std;
void main()
{
	BSTnode *root = NULL;
	BSTnode T1;
	T1.insert(80, &root);
	T1.insert(70, &root);
	T1.insert(75, &root);
	T1.insert(90, &root);
	T1.insert(60, &root);
	T1.insert(119, &root);
	T1.insert(23, &root);
	T1.insert(15, &root);
	cout << "Inorder" << endl;
	T1.Inorder(root);
	cout << "Preorder" << endl;
	T1.Preorder(root);
	cout << "Postorder" << endl;
	T1.Postorder(root);
	//BSTnode *ser=T1.ReturnPre(75,&root);
	T1.dele(90,&root);
	T1.Inorder(root);
	//cout << ser->getVal();
	system("pause");
}