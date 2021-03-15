#pragma once

#include<iostream>

#include<stack>

using namespace std;

#ifndef _AVLTREE_H_
#define _AVLTREE_H_

template <class T>
void Swap(T &x, T &y);

template <class T>
class AVLTree;

template <class T>
class AVLTreeNode
{
	friend class AVLTree<T>;
private:
	T element;
	int Balance;   //右子树高度减左子树高度
	AVLTreeNode<T> *LeftChild;
	AVLTreeNode<T> *RightChild;
public:
	AVLTreeNode();            //默认构造函数
	AVLTreeNode(const T &ele);  //给定数据域的值的构造函数
	AVLTreeNode(const T &ele, AVLTreeNode<T> *left = NULL, AVLTreeNode *right = NULL);   //给定数据域和左右孩子节点的构造函数
	AVLTreeNode<T>* GetLeftChild() const;                   //返回左孩子节点
	AVLTreeNode<T>* GetRightChild() const;                   //返回右孩子节点
	AVLTreeNode<T>* GetParent(AVLTreeNode<T> *root);         //返回该节点的父节点
	
	void SetLeftChild(AVLTreeNode<T> *left);               //设置该节点的左孩子节点
	void SetRightChild(AVLTreeNode<T> *left);              //设置该节点的右孩子节点
	T GetValue() const;                                  //返回该节点的数据域
	void SetValue(const T &val);                        //设置该节点的数据域的值
	bool IsLeaf() const;                                //判断该节点是否为叶子节点，若是返回true

	int High(AVLTreeNode<T> *root);
	void CalculateBalance(AVLTreeNode<T> *root);
};

template <class T>
class AVLTree
{
private:
	AVLTreeNode<T> *root;
public:
	AVLTree();
	~AVLTree();
	AVLTreeNode<T>* GetRoot();               //返回节点

	void DeleteAVLTree(AVLTreeNode<T>* root);      //删除以root为根节点的子树

	void LeftSpin(AVLTreeNode<T> *root);           //左单旋
	void RightSpin(AVLTreeNode<T> *root);          //右单旋
	void LeftRightRotation(AVLTreeNode<T> *root);  //左右双旋
	void RightLeftRotation(AVLTreeNode<T> *root);  //右左双旋

	void BuildAVLTree(const T *str,int lenth);    //建立平衡二叉树
	void SetAllBalance(AVLTreeNode<T> *root);     //设置所有树的平衡值

	void AddPoint(const T &ele);    //增加一个节点
	void DeletePoint(const T &ele); //删除一个节点

	bool IsCompleteBinaryTree() const;    //判断是否为完全二叉树
	void PreOrder(AVLTreeNode<T> *root);   //前序遍历
	void InOrder(AVLTreeNode<T>* root);              //后序遍历以root为根节点的子树

	void Spin(AVLTreeNode<T> *root);    //调整二叉树
};

//AVLTree的函数

template <class T>
void AVLTree<T>::DeletePoint(const T &ele)
{
	AVLTreeNode<T> *current = NULL, *PostFirst = NULL, *Parent = NULL;
	int m = 0;
	AVLTreeNode<T> *temp = NULL;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = AVLTreeNodeArray[j]->GetLeftChild();
			Right = AVLTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				AVLTreeNodeArray[count++] = Left;

			if (Right != NULL)
				AVLTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	} while (Left || Right);
	//找到当前节点
	for (int i = 0; i < count; i++)
		if (AVLTreeNodeArray[i]->GetValue() == ele)
		{
			current = AVLTreeNodeArray[i];
			break;
		}
	if (current == NULL)
		cout << "找不到该节点。" << endl;
	else
	{
		//找到后序遍历的第一个节点
		PostFirst = root;
		while (PostFirst->LeftChild || PostFirst->RightChild)
		{
			if (PostFirst->LeftChild)
			{
				PostFirst = PostFirst->LeftChild;
				continue;
			}
			else
				PostFirst = PostFirst->RightChild;
		}

		Swap(PostFirst->element, current->element);
		for(int i = 0;i < count;i++)
			if (AVLTreeNodeArray[i]->LeftChild == PostFirst || AVLTreeNodeArray[i]->RightChild == PostFirst)
			{
				Parent = AVLTreeNodeArray[i];
				break;
			}
		if (Parent->LeftChild == PostFirst)
			Parent->LeftChild = NULL;
		else
			Parent->RightChild = NULL;
		free(PostFirst);
		SetAllBalance(root);
		Spin(root);
	}

}

template <class T>
void AVLTree<T>::AddPoint(const T &ele)
{
	AVLTreeNode<T> *current = NULL, *prev = NULL;
	current = root;
	while (current->LeftChild)
		current = current->LeftChild;
	prev = (AVLTreeNode<T>*)malloc(sizeof(AVLTreeNode<T>));
	prev->SetValue(ele);
	prev->Balance = 0;
	prev->LeftChild = NULL;
	prev->RightChild = NULL;
	current->LeftChild = prev;
	SetAllBalance(root);
	Spin(root);
}

template <class T>
void AVLTree<T>::InOrder(AVLTreeNode<T> *root)
{
	cout << "中序遍历为： ";
	stack<AVLTreeNode<T>*>  NodeStack;
	AVLTreeNode<T>* pointer = root;
	while (!NodeStack.empty() || pointer)
	{
		if (pointer)
		{
			NodeStack.push(pointer);
			pointer = pointer->GetLeftChild();
		}
		else
		{
			pointer = NodeStack.top();
			cout << pointer->GetValue() << ' ';
			pointer = pointer->GetRightChild();
			NodeStack.pop();
		}
	}
	cout << endl;
}

template <class T>
void AVLTree<T>::PreOrder(AVLTreeNode<T> *root)
{
	int count = 0;
	int i = 0, flag = 0, j = 0;
	AVLTreeNode<T> *temp = root;
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	//遍历左子树
loopl:while (temp->GetLeftChild())
{
	temp = temp->GetLeftChild();
	AVLTreeNodeArray[count++] = temp;
}
	  if (flag == 0)    //没走到loopr时的操作
	  {
		  i = count;
		  temp = AVLTreeNodeArray[--i];
	  }
	  if (flag == 1)    //做过了loopr的操作
	  {
		  temp = AVLTreeNodeArray[--j];
	  }
	  //遍历右子树
  loopr:while (temp->GetRightChild())
  {
	  temp = temp->GetRightChild();
	  AVLTreeNodeArray[count++] = temp;
	  j = count;
	  //遍历当前节点的所有左子树
	  flag = 1;
	  goto loopl;
  }
		if (i != 0)
		{
			temp = AVLTreeNodeArray[--i];
			goto loopr;
		}
		else
		{
			if (temp->GetRightChild())
				goto loopr;
		}
		cout << "先序遍历为： ";
		for (int i = 0; i < count; i++)
			cout << AVLTreeNodeArray[i]->GetValue() << ' ';
		cout << endl;
}

template <class T>
bool AVLTree<T>::IsCompleteBinaryTree() const
{
	int two = 1;
	int m = 0;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		if (m - ArrayLeft == two)
		{
			two *= 2;
			for (int j = ArrayLeft; j < ArrayRight + 1; j++)
			{
				Left = AVLTreeNodeArray[j]->GetLeftChild();
				Right = AVLTreeNodeArray[j]->GetRightChild();

				if (Left != NULL)
					AVLTreeNodeArray[count++] = Left;

				if (Right != NULL)
					AVLTreeNodeArray[count++] = Right;
			}
			ArrayLeft = m;
			if (count > ArrayLeft)
				ArrayRight = count - 1;
		}
		else
		{
			ArrayRight = ArrayLeft - 1;
			ArrayLeft = ArrayLeft - two / 2;
			for (int j = ArrayLeft; j < ArrayRight + 1; j++)
			{
				Left = AVLTreeNodeArray[j]->GetLeftChild();
				Right = AVLTreeNodeArray[j]->GetRightChild();
				if (Left != NULL && Right != NULL)
					continue;
				else
					return false;
			}
		}
	} while (Left || Right);
	return true;
}

template <class T>
void AVLTree<T>::Spin(AVLTreeNode<T> *root)
{
	int flag_ = 0;
	stack<AVLTreeNode<T>*> NodeStack;
	AVLTreeNode<T> *pointer = NULL;
loop:pointer = root;
	SetAllBalance(root);
	while (!NodeStack.empty())
		NodeStack.pop();
	int temp = 0;
	enum From { left, right };
	int flag = left;
	AVLTreeNode<T>* TempSave = NULL;
	while (pointer || !NodeStack.empty())
	{
		if (pointer && temp == 0)
		{
			NodeStack.push(pointer);
			pointer = pointer->LeftChild;
		}
		else
		{
			pointer = NodeStack.top();
			if (pointer->RightChild && flag == left)
			{
				pointer = pointer->RightChild;
				temp = 0;
				flag = right;
			}
			else
			{
				NodeStack.pop();
				if (!NodeStack.empty())
				{
					TempSave = NodeStack.top();
					if (TempSave->LeftChild == pointer)
						flag = left;
					else
						flag = right;
				}
				if (abs(pointer->Balance) > 1)
				{
					flag_ = 1;
					break;
				}
				temp = 1;
				if (NodeStack.empty())
					break;
			}
			if (NodeStack.top() == root && flag == left)
			{
				pointer = root->RightChild;
				temp = 0;
			}
		}
	}
	//判断情况，并进行操作
	if (flag_ == 1)
	{
		if (pointer->Balance == 2)
			LeftSpin(pointer);
		if (pointer->Balance == -2)
			RightSpin(pointer);
		flag_ = 0;
		goto loop;
	}
}

template <class T>
void AVLTree<T>::BuildAVLTree(const T *str, int lenth)
{
	AVLTreeNode<T> *current = NULL, *prev = NULL;
	for (int i = 0; i < lenth; i++)
	{
		current = (AVLTreeNode<T>*)malloc(sizeof(AVLTreeNode<T>));
		current->SetValue(str[i]);
		current->LeftChild = NULL;
		current->RightChild = NULL;
		current->Balance = 0;
		if (root == NULL)
			root = current;
		else
		{
			if (prev->LeftChild == NULL)
				prev->LeftChild = current;
			else
				prev->RightChild = current;
			SetAllBalance(root);
			Spin(root);
		}
		prev = current;
	}
	
}

template <class T>
void AVLTree<T>::SetAllBalance(AVLTreeNode<T> *root)
{
	int m = 0;
	AVLTreeNode<T> *temp = NULL;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = AVLTreeNodeArray[j]->GetLeftChild();
			Right = AVLTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				AVLTreeNodeArray[count++] = Left;

			if (Right != NULL)
				AVLTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	} while (Left || Right);
	for (int i = 0; i < count; i++)
		AVLTreeNodeArray[i]->CalculateBalance(AVLTreeNodeArray[i]);
}

template <class T>
void AVLTree<T>::RightLeftRotation(AVLTreeNode<T> *root)
{
	AVLTreeNode<T> *current = NULL;
	current = root->RightChild;
	RightSpin(current);
	LeftSpin(root);
}

template <class T>
void AVLTree<T>::LeftRightRotation(AVLTreeNode<T> *root)
{
	AVLTreeNode<T> *current = NULL;
	current = root->LeftChild;
	LeftSpin(current);
	RightSpin(root);
}

template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::GetParent(AVLTreeNode<T> *root)
{
	int m = 0;
	AVLTreeNode<T> *temp = NULL;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = AVLTreeNodeArray[j]->GetLeftChild();
			Right = AVLTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				AVLTreeNodeArray[count++] = Left;

			if (Right != NULL)
				AVLTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	} while (Left || Right);
	for (int i = 0; i < count; i++)
		if (AVLTreeNodeArray[i]->LeftChild == root || AVLTreeNodeArray[i]->RightChild == root)
			return AVLTreeNodeArray[i];
}

template <class T>
void AVLTree<T>::LeftSpin(AVLTreeNode<T> *root)
{
	//current代表A，root代表C
	AVLTreeNode<T> *current = NULL;  
	current = root->RightChild; 
	Swap(current->element, root->element);
	Swap(root->LeftChild, root->RightChild);
	Swap(current->RightChild, current->LeftChild);
	Swap(current->LeftChild, root->RightChild);
}

template <class T>
void AVLTree<T>::RightSpin(AVLTreeNode<T> *root)
{
	AVLTreeNode<T> *current = NULL;
	current = root->LeftChild;
	Swap(current->element, root->element);
	Swap(root->LeftChild, root->RightChild);
	Swap(current->LeftChild, current->RightChild);
	Swap(current->RightChild, root->LeftChild);
}

template <class T>
void AVLTree<T>::DeleteAVLTree(AVLTreeNode<T>* root)
{
	int m = 0;
	AVLTreeNode<T> *temp = NULL;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	AVLTreeNode<T>* AVLTreeNodeArray[100];
	memset(AVLTreeNodeArray, 0, sizeof(AVLTreeNodeArray));
	AVLTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = AVLTreeNodeArray[j]->GetLeftChild();
			Right = AVLTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				AVLTreeNodeArray[count++] = Left;

			if (Right != NULL)
				AVLTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	} while (Left || Right);
	for (int i = 0; i < count; i++)
	{
		free(AVLTreeNodeArray[i]);
	}
}

template <class T>
AVLTree<T>::AVLTree()
{
	root = NULL;
}

template <class T>
AVLTree<T>::~AVLTree()
{
	DeleteAVLTree(root);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::GetRoot()
{
	return root;
}

//AVLTreeNode的函数

template <class T>
void AVLTreeNode<T>::CalculateBalance(AVLTreeNode<T> *root)
{
	Balance = High(root->RightChild) - High(root->LeftChild);
}

template <class T>
int AVLTreeNode<T>::High(AVLTreeNode<T> *root)
{
	if (root == NULL)
		return 0;
	int l = High(root->LeftChild);
	int r = High(root->RightChild);
	return l > r ? l + 1 : r + 1;
}

template <class T>
AVLTreeNode<T>::AVLTreeNode()
{
	element = 0;
	Balance = 0;
	LeftChild = NULL;
	RightChild = NULL;
}

template <class T>
AVLTreeNode<T>::AVLTreeNode(const T &ele)
{
	element = ele;
	Balance = 0;
	LeftChild = NULL;
	RightChild = NULL;
}

template <class T>
AVLTreeNode<T>::AVLTreeNode(const T &ele, AVLTreeNode<T> *left, AVLTreeNode *right)
{
	element = ele;
	LeftChild = left;
	RightChild = right;
}

template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::GetLeftChild() const
{
	return LeftChild;
}

template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::GetRightChild() const
{
	return RightChild;
}

template <class T>
void AVLTreeNode<T>::SetLeftChild(AVLTreeNode<T> *left)
{
	LeftChild = left;
}

template <class T>
void AVLTreeNode<T>::SetRightChild(AVLTreeNode<T> *right)
{
	RightChild = right;
}

template <class T>
T AVLTreeNode<T>::GetValue() const
{
	return element;
}

template <class T>
void AVLTreeNode<T>::SetValue(const T &val)
{
	element = val;
}

template <class T>
bool AVLTreeNode<T>::IsLeaf() const
{
	AVLTreeNode<T> *TempLeft = NULL, *TempRight = NULL;
	TempLeft = GetLeftChild();
	TempRight = GetRightChild();
	if (!TempLeft && !TempRight)
		return true;
	else
		return false;
}

//其他函数
template <class T>
void Swap(T &x, T &y)
{
	T temp = 0;
	temp = x;
	x = y;
	y = temp;
}

#endif // !_AVLTREE_H_
