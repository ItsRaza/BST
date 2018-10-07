#include<iostream>
#include<string>
using namespace std;
class BSTnode
{
protected:
	int value;
	BSTnode *left;
	BSTnode *right;
public:
	BSTnode(){}
	int getVal()
	{
		return this->value;
	}
	void insert(int val_in, BSTnode **root)
	{
		BSTnode *ptr;
		ptr = new(BSTnode);
		ptr->value = val_in;
		ptr->left = NULL;
		ptr->right = NULL;
		if (*root == NULL)
		{
			*root = ptr;
			cout << "Root created " << ptr->value << endl;
		}
		else
		{
			BSTnode *curr = *root;
			BSTnode *parent=NULL;
			while (curr!=NULL)
			{
				if (curr->value<=ptr->value)
				{
					parent = curr;
					curr = curr->right;
				}
				else if (curr->value>ptr->value)
				{
					parent = curr;
					curr = curr->left;
				}
			}
			if (parent->value<=ptr->value)
			{
				parent->right = ptr;
				cout << "inserted on right " << ptr->value << endl;
			}
			if (parent->value>ptr->value)
			{
				parent->left = ptr;
				cout << "inserted on left " << ptr->value << endl;
			}
		}
	}
	BSTnode* search(int val_in, BSTnode **root)
	{
		int flag = 0;
		if (*root == NULL)
		{
			cout << "TREE IS EMPTY!" << endl;
		}
		if ((*root)->value == val_in)
		{
			cout << "found" << endl;
			flag++;
			return *root;
		}

		else
		{
			BSTnode *curr = *root;
			BSTnode *parent = curr;
			while (curr != NULL)
			{
				if (parent->value == val_in)
				{
					cout << "found" << endl;
					flag++;
					return parent;
				}
				if (curr->value <=val_in)
				{
					parent = curr;
					curr = curr->right;
				}
				else if (curr->value>val_in)
				{
					parent = curr;
					curr = curr->left;
				}
			}
			if (parent->value == val_in)
			{
				cout << "found" << endl;
				flag++;
				return parent;
			}
			if (flag == 0)
			{
				cout << "NOT FOUND" << endl;
				return 0;
			}
		}
	}
	BSTnode* ReturnPre(int val_in, BSTnode **root)
	{
		int flag = 0;
		BSTnode *curr = *root;
		BSTnode *parent = curr;
		BSTnode *pre = NULL;
		while ((curr->left!=NULL)||(curr->right!=NULL))
		{
			if (curr->value <= val_in)
			{
				if (curr->value == val_in)
				{
					break;
				}
				parent = curr;
				curr = curr->right;
			}
			else if (curr->value>val_in)
			{
				if (curr->value == val_in)
				{
					break;
				}
				parent = curr;
				curr = curr->left;
			}
		}
		return parent;
		/*if (parent->value == val_in)
		{
		//	cout << "found" << endl;
			flag++;
			return parent;
		}
		if (flag == 0)
		{
			//cout << "NOT FOUND" << endl;
			return 0;
		}*/
	}
	void insertR(int val_in, BSTnode **root)
	{
		
		BSTnode *ptr;
		ptr = new(BSTnode);
		ptr->value = val_in;
		ptr->left = NULL;
		ptr->right = NULL;
		if (*root == NULL)
		{
			*root = ptr;
			cout << "inserted:" << ptr->value << endl;
		}
		if (val_in < (*root)->value)
		{
			insertR(val_in, &((*root)->left));
		}
		else if (val_in >(*root)->value)
		{
			insertR(val_in, &((*root)->right));
		}
		return;
	}
	void SearchR(BSTnode** root, int val_in)
	{
		if (*root == NULL||(*root)->value==val_in)
		{
			cout << "found!" << endl;
			
		}
		if ((*root)->value < val_in)
		{
			SearchR(&((*root)->right), val_in);
		}	
		SearchR(&((*root)->left), val_in);
		return;
	}
	BSTnode* findGreatest(BSTnode **root)
	{
		BSTnode *curr = *root;
		while (curr->right!=NULL)
		{
			curr = curr->right;
		}
		return curr;
	}
	void dele(int val_in, BSTnode **root)
	{
		BSTnode *ser = search(val_in, &*root);
		BSTnode *pre = ReturnPre(val_in, &*root);
		if (*root == NULL)
		{
			return;
		}
		if ((ser->right == NULL) && (ser->left == NULL))
		{
			cout << "Searched Value is a leaf" << endl;
			if ((pre->left)->value == ser->value)
			{
				pre->left = NULL;
			}
			else if ((pre->right)->value == ser->value)
			{
				pre->right = NULL;
			}
			//pre->left = NULL;
			//pre->right = NULL;
			free(ser);
			cout << "DELETED" << endl;
			return;
		}
		
		else if ((ser->right != NULL) && (ser->left != NULL))
		{
			cout << "Searched value is two childed branch" << endl;
			BSTnode *gre = findGreatest(&(ser->left));
			ser->value = gre->value;
			gre = NULL;
			free(gre);
			cout << "DELETED" << endl;
			return;
		}

		else if ((ser->right != NULL) || (ser->left != NULL))
		{
			cout << "Searched value is one childed branch" << endl;
			if (ser->left == NULL)
			{
				cout << "Child is on the right of searched node" << endl;
				if (pre->value > (ser->right)->value)
				{
					pre->left = ser->right;
					free(ser);
					cout << "Searched value deleted" << endl;
					return;
				}
				if (pre->value < (ser->right)->value)
				{
					pre->right = ser->right;
					free(ser);
					cout << "Searched value deleted" << endl;
					return;
				}
			}
			if (ser->right == NULL)
			{
				cout << "Child is on the left of searched node" << endl;
				if (pre->value > (ser->left)->value)
				{
					pre->left = ser->left;
					free(ser);
					cout << "Searched value deleted" << endl;
					return;
				}
				if (pre->value < (ser->left)->value)
				{
					pre->right = ser->left;
					free(ser);
					cout << "Searched value deleted" << endl;
					return;
				}
			}
		}
	}
	void Inorder(BSTnode *root)
	{
		if (root == NULL)
		{
			return;
		}
		Inorder(root->left);
		cout << root->value << endl;
		Inorder(root->right);
	}
	void Preorder(BSTnode *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->value << endl;
		Preorder(root->left);
		Preorder(root->right);
	}
	void Postorder(BSTnode *root)
	{
		if (root == NULL)
		{
			return;
		}
		Postorder(root->left);
		Postorder(root->right);
		cout << root->value << endl;
	}
};