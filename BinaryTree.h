#pragma once

#include<iostream>
#include<stack>
#include"HuffmanTree.h"
using namespace std;

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <class T>
void FlipArray(T *Array, int first, int last);  // 颠倒数组位置

template <class T>
void Swap(T &x, T &y);      //交换函数

template <class T>
class BinaryTree;

template <class T>
class HuffmanTree;

template <class T>
class BinarySearchTree;

template <class T>
class BinaryTreeNode 
{
	friend class BinaryTree<T>;
	friend class HuffmanTree<T>;
private:
	T element;
	int flag;
	BinaryTreeNode<T> *LeftChild;
	BinaryTreeNode<T> *RightChild;
public:
	BinaryTreeNode();            //默认构造函数
	BinaryTreeNode(const T &ele);  //给定数据域的值的构造函数
	BinaryTreeNode(const T &ele, BinaryTreeNode<T> *left = NULL, BinaryTreeNode *right = NULL);   //给定数据域和左右孩子节点的构造函数
	BinaryTreeNode<T>* GetLeftChild() const;                   //返回左孩子节点
	BinaryTreeNode<T>* GetRightChild() const;                   //返回右孩子节点
	void SetLeftChild(BinaryTreeNode<T> *left);               //设置该节点的左孩子节点
	void SetRightChild(BinaryTreeNode<T> *left);              //设置该节点的右孩子节点
	T GetValue() const;                                  //返回该节点的数据域
	void SetValue(const T &val);                        //设置该节点的数据域的值
	bool IsLeaf() const;                                //判断该节点是否为叶子节点，若是返回true
};

template <class T>
class BinaryTree {
private:
	int StatisticSum;        //统计相应节点数总和
	int StatisticHigh;       //统计高度
	int StatisticMaxWidth[100];   //统计最大宽度
	T StatisticMax;    //统计最大值
	BinaryTreeNode<T> *root;               //二叉树根节点
public:
	BinaryTree();                         //默认构造函数
	BinaryTree(const T &ele);            //给参数的构造函数
	~BinaryTree();                          //析构函数
	bool IsEmpty() const;                   //判断二叉树是否为空树
	bool IsCompleteBinaryTree() const;    //判断是否为完全二叉树
	void StatisticNumber(int number);    //统计相应节点数的个数
	void MaxNumber();         //统计最大数值
	void High();           //统计高度
	void MaxWidth();        //最大宽度

	BinaryTreeNode<T>* GetRoot() const;        //返回二叉树的根节点
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T> *current) const;     //返回current节点的父节点
	BinaryTreeNode<T>* GetLeftSibling(BinaryTreeNode<T> *current) const;   //返回current节点的左兄弟
	BinaryTreeNode<T>* GetRightSibling(BinaryTreeNode<T> *current) const;   //返回current节点的右兄弟
	//前序中序构造二叉树
	BinaryTreeNode<T>* ConstructPreOrderInOrder(const T* preorder,const T* inorder, int length);   
	BinaryTreeNode<T>* ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder);
	//中序后序构造二叉树
	BinaryTreeNode<T>* ConstructInOrderPostOrder(T* postorder, T* inorder, int length);
	BinaryTreeNode<T>* ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder);

	void BreadthFirstOrder(BinaryTreeNode<T>* root);    //广度优先遍历以root为根节点的子树
	void PreOrder(BinaryTreeNode<T>* root);              //先序遍历以root为根节点的子树
	void InOrder(BinaryTreeNode<T>* root);              //中序遍历以root为根节点的子树
	void PostOrder(BinaryTreeNode<T>* root);              //后序遍历以root为根节点的子树
	void LevelOrder(BinaryTreeNode<T>* root);              //按层次遍历以root为根节点的子树
	void DeleteBinaryTree(BinaryTreeNode<T>* root);      //删除以root为根节点的子树
	void SetRoot(BinaryTreeNode<T>* _root); 

	void StatisticsNodesNumber(BinaryTreeNode<T>* root, int number);   //统计各节点的指定度
	int Statisticshigh(BinaryTreeNode<T> *root);            //树的高度
	void StatisticWidth(BinaryTreeNode<T> *root,int k);             //统计最大宽度
	void SwapLeftRight(BinaryTreeNode<T> *root);           //交换左右子树
	void DeleteLeave(BinaryTreeNode<T> *root);          //删除叶子节点
	void StatisticMaxMember(BinaryTreeNode<T> *root);      //统计最大元素
};

template <class T>
class BinarySearchTreeNode
{
	friend class BinarySearchTree<T>;
private:
	T element;
	int LeftTag;
	BinarySearchTreeNode<T> *LeftChild;
	int RightTag;
	BinarySearchTreeNode<T> *RightChild;

public:
	//主要函数
	BinarySearchTreeNode();
	BinarySearchTreeNode(const T&ele);
	BinarySearchTreeNode(const T &ele, BinarySearchTreeNode<T> *left = NULL, BinarySearchTreeNode *right = NULL);
	~BinarySearchTreeNode();

	BinarySearchTreeNode<T>* GetLeftChild() const;                   //返回左孩子节点
	BinarySearchTreeNode<T>* GetRightChild() const;                   //返回右孩子节点
	T GetValue() const;                                  //返回该节点的数据域
	void SetValue(const T &val);                        //设置该节点的数据域的值
	bool IsLeaf() const;                                //判断该节点是否为叶子节点，若是返回true
};

template <class T>
class BinarySearchTree
{
private:
	BinarySearchTreeNode<T> *root;
	int InorderFlag;
public:
	BinarySearchTree();                         //默认构造函数
	BinarySearchTree(const T &ele);            //给参数的构造函数
	~BinarySearchTree();                          //析构函数
	bool IsEmpty() const;                   //判断二叉树是否为空树
	void DeleteBinarySearchTree(BinarySearchTreeNode<T>* root);      //删除以root为根节点的子树
	void SetRoot(BinarySearchTreeNode<T> *root);
	BinarySearchTreeNode<T>* GetRoot();   

	BinarySearchTree(const T *Array,int lenth);     //构建二叉搜索树

	//前序中序构造二叉树
	BinarySearchTreeNode<T>* ConstructPreOrderInOrder(T* preorder, T* inorder, int length);
	BinarySearchTreeNode<T>* ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder);
	//中序后序构造二叉树
	BinarySearchTreeNode<T>* ConstructInOrderPostOrder(T* postorder, T* inorder, int length);
	BinarySearchTreeNode<T>* ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder);

	void InOrder(BinarySearchTreeNode<T>* root);              //中序遍历以root为根节点的子树

	//中序线索树的建立
	void BuildMiddleOrderClueBinaryTree();

	//删除一节点
	void DeletePoint(const T &ele);

	//查找
	BinarySearchTreeNode<T>* FindPoint(const T &ele);

	//增加一节点
	void AddPoint(const T &ele);

	//恢复成二叉树
	void ResetBinarySearchTree();

	//中序遍历线索二叉树遍历
	void InOrderBinarySearchTree();

};

/*BinarySearchTree的函数*/

template<class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::FindPoint(const T &ele)
{
	BinarySearchTreeNode<T>* current = NULL, *prev = NULL;
	prev = root;
	while (1 || prev)
	{
		if (prev->element < ele)
			prev = prev->RightChild;
		if (prev->element > ele)
			prev = prev->LeftChild;
		if (prev->element == ele)
			break;
	}
	return prev;
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::GetRoot()
{
	return root;
}

template <class T>
void BinarySearchTree<T>::InOrder(BinarySearchTreeNode<T>* root)
{
	cout << "中序遍历为： ";
	stack<BinarySearchTreeNode<T>*>  NodeStack;
	BinarySearchTreeNode<T>* pointer = root;
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
BinarySearchTree<T>::BinarySearchTree(const T *Array,int lenth)
{
	BinarySearchTreeNode<T> *current = NULL, *prev = NULL;
	int flag = 0;
	for (int i = 0; i < lenth; i++)
	{
		current = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
		current->SetValue(Array[i]);
		current->LeftChild = NULL;
		current->RightChild = NULL;
		current->LeftTag = 0;
		current->RightTag = 0;
		if (root == NULL)
			root = current;
		else
		{
			prev = root;

loop:		while (prev->element > current->element)
				if (prev->LeftChild)
					prev = prev->LeftChild;
				else
					if (prev->RightChild && prev->RightChild->element < current->element)
						prev = prev->RightChild;
					else
						prev->LeftChild = current;

			while (prev->element < current->element)
				if (prev->RightChild)
					prev = prev->RightChild;
				else
					if (prev->LeftChild && prev->LeftChild->element > current->element)
						prev = prev->LeftChild;
					else
						prev->RightChild = current;
			if (flag == 0)
			{
				flag = 1;
				goto loop;
			}
			else
				flag = 0;
		}
	}
}

template <class T>
void BinarySearchTree<T>::AddPoint(const T &ele)
{
	//BinarySearchTreeNode<T> *prev = NULL;
	//prev = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	//memset(prev, 0, sizeof(BinarySearchTreeNode<T>));
	//prev->SetValue(ele);

	//int j = 0, last = 0;
	//BinarySearchTreeNode<T> *current = root;
	//BinarySearchTreeNode<T>* BinaryTreeNodeArray[100];
	//memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	//while (current->LeftTag == 0)
	//	current = current->LeftChild;
	//while (current)
	//{
	//	BinaryTreeNodeArray[j++] = current;
	//	if (current->RightTag == 1)
	//		current = current->RightChild;
	//	else
	//	{
	//		current = current->RightChild;
	//		while (current&&current->LeftTag == 0)
	//			current = current->LeftChild;
	//	}
	//}
	////找到最后一个叶子节点
	//for (int i = 0; i < j; i++)
	//	if (BinaryTreeNodeArray[i]->LeftTag == 1 || BinaryTreeNodeArray[i]->RightTag == 1)
	//	{
	//		last = i;
	//		break;
	//	}
	//switch (BinaryTreeNodeArray[last]->LeftTag)
	//{
	//case 0:
	//	//有左孩子，插到右遍
	//	BinaryTreeNodeArray[last]->RightTag = 0;
	//	BinaryTreeNodeArray[last]->RightChild = prev;
	//	prev->LeftTag = 1;
	//	prev->LeftChild = BinaryTreeNodeArray[last];
	//	prev->RightTag = 1;
	//	if (last + 1 < j)
	//	{
	//		prev->RightChild = BinaryTreeNodeArray[last + 1];
	//		if (BinaryTreeNodeArray[last + 1]->LeftTag == 1)
	//			BinaryTreeNodeArray[last + 1]->LeftChild = prev;
	//	}
	//	break;
	//case 1:
	//	//无左孩子，插到左边
	//	BinaryTreeNodeArray[last]->LeftTag = 0;
	//	BinaryTreeNodeArray[last]->LeftChild = prev;
	//	prev->RightTag = 1;
	//	prev->RightChild = BinaryTreeNodeArray[last];
	//	prev->LeftTag = 1;
	//	if (last - 1 > 0)
	//	{
	//		prev->LeftChild = BinaryTreeNodeArray[last - 1];
	//		if (BinaryTreeNodeArray[last - 1]->RightTag == 1)
	//			BinaryTreeNodeArray[last - 1]->RightChild = prev;
	//	}
	//	break;
	//default:
	//	break;
	//}

	BinarySearchTreeNode<T>* current = NULL, *prev = NULL;
	current = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	current->SetValue(ele);
	current->LeftChild = NULL;
	current->RightChild = NULL;
	current->LeftTag = 0;
	current->RightTag = 0;
	prev = root;
	while (1)
	{
		if (prev->element < ele)
			if (prev->RightChild)
				prev = prev->RightChild;
			else
			{
				prev->RightChild = current;
				break;
			}
		else
			if (prev->LeftChild)
				prev = prev->LeftChild;
			else
			{
				prev->LeftChild = current;
				break;
			}
	}
}

template <class T>
void BinarySearchTree<T>::ResetBinarySearchTree()
{
	int j = 0;
	BinarySearchTreeNode<T> *current = root;
	BinarySearchTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	while (current->LeftTag == 0)
		current = current->LeftChild;
	while (current)
	{
		BinaryTreeNodeArray[j++] = current;
		if (current->RightTag == 1)
			current = current->RightChild;
		else
		{
			current = current->RightChild;
			while (current&&current->LeftTag == 0)
				current = current->LeftChild;
		}
	}
	for (int i = 0; i < j; i++)
	{
		if (BinaryTreeNodeArray[i]->LeftTag == 1)
		{
			BinaryTreeNodeArray[i]->LeftTag = 0;
			BinaryTreeNodeArray[i]->LeftChild = NULL;
		}
		if (BinaryTreeNodeArray[i]->RightTag == 1)
		{
			BinaryTreeNodeArray[i]->RightTag = 0;
			BinaryTreeNodeArray[i]->RightChild = NULL;
		}
	}
}

template <class T>
void BinarySearchTree<T>::DeletePoint(const T &ele)
{
	//int j = 0, temp = 0, last = 0;
	//BinarySearchTreeNode<T> *current = root;
	//BinarySearchTreeNode<T>* BinaryTreeNodeArray[100];
	//memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	//while (current->LeftTag == 0)
	//	current = current->LeftChild;
	//while (current)
	//{
	//	BinaryTreeNodeArray[j++] = current;
	//	if (current->RightTag == 1)
	//		current = current->RightChild;
	//	else
	//	{
	//		current = current->RightChild;
	//		while (current&&current->LeftTag == 0)
	//			current = current->LeftChild;
	//	}
	//}
	////寻找该节点
	//for (int i = 0; i < j; i++)
	//{
	//	//找到该节点
	//	if (BinaryTreeNodeArray[i]->GetValue() == ele)
	//		temp = i;
	//	//找到最后一个叶子节点
	//	if (BinaryTreeNodeArray[i]->RightTag == 1 && BinaryTreeNodeArray[i]->LeftTag == 1)
	//		last = i;
	//}

	////找到其父节点
	//for (int i = 0; i < j; i++)
	//	if (BinaryTreeNodeArray[i]->LeftChild == BinaryTreeNodeArray[last] || BinaryTreeNodeArray[i]->RightChild == BinaryTreeNodeArray[last])
	//	{
	//		current = BinaryTreeNodeArray[i];
	//		break;
	//	}
	//
	////开始删除操作,先把叶子节点换上去
	//int k = BinaryTreeNodeArray[last]->GetValue();
	//BinaryTreeNodeArray[last]->SetValue(BinaryTreeNodeArray[temp]->GetValue());
	//BinaryTreeNodeArray[temp]->SetValue(k);

	//if (current->LeftChild == BinaryTreeNodeArray[last])
	//	current->LeftChild = NULL;
	//else
	//	current->RightChild = NULL;
	//if (current->LeftTag != 1)
	//{
	//	current->LeftTag = 1;
	//	current->LeftChild = BinaryTreeNodeArray[last]->LeftChild;
	//}
	//if (current->RightTag != 1)
	//{
	//	current->RightTag = 1;
	//	current->RightChild = BinaryTreeNodeArray[last]->RightChild;
	//}
	//free(BinaryTreeNodeArray[last]);
	BinarySearchTreeNode<T>* current = NULL, *prev = NULL, *temp = NULL;
	prev = root;
	while (1 || prev)
	{
		if (prev->element < ele)
			prev = prev->RightChild;
		if (prev->element > ele)
			prev = prev->LeftChild;
		if (prev->element == ele)
			break;
	}
	if (prev)
	{
		current = prev;
		if (prev->IsLeaf())
		{
			
			while (1)
			{
				if (current->element > prev->element)
					if (current->LeftChild == prev)
						break;
					else
						current = current->LeftChild;
				if (current->element < prev->element)
					if (current->RightChild == prev)
						break;
					else
						current = current->RightChild;
			}
			if (current->LeftChild == prev)
				current->LeftChild = NULL;
			else
				current->RightChild = NULL;
			free(current);
		}
		if (prev->element < root->element)
		{
			temp = current;
			current = current->LeftChild;
			while (current->RightChild)
			{
				temp = current;
				current = current->RightChild;
			}
			Swap(prev->element, current->element);
			if (temp->LeftChild == current)
				temp->LeftChild = current->LeftChild;
			else
				temp->RightChild = current->LeftChild;
		}
		if (prev->element > root->element)
		{
			temp = current;
			current = current->RightChild;
			while (current->LeftChild)
			{
				temp = current;
				current = current->LeftChild;
			}
			Swap(current->element, prev->element);
			if (temp->LeftChild == current)
				temp->LeftChild = current->RightChild;
			else
				temp->RightChild = current->RightChild;
		}
	}
	else
		cout << "没有该节点。" << endl;

}

template <class T>
void BinarySearchTree<T>::SetRoot(BinarySearchTreeNode<T> *_root)
{
	root = _root;
}

template <class T>
void BinarySearchTree<T>::InOrderBinarySearchTree()
{
	BinarySearchTreeNode<T> *current = root;
	while (current->LeftTag == 0)
		current = current->LeftChild;
	while (current)
	{
		cout << current->GetValue() << ' ';
		if (current->RightTag == 1)
			current = current->RightChild;
		else
		{
			current = current->RightChild;
			while (current&&current->LeftTag == 0)
				current = current->LeftChild;
		}
	}
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::BuildMiddleOrderClueBinaryTree()
{
	InorderFlag = 1;
	stack<BinarySearchTreeNode<T>*>  NodeStack;
	BinarySearchTreeNode<T>* pointer = root;
	int j = 0;
	BinarySearchTreeNode<T> *BinarySearchTreeNodeArray[100];
	memset(BinarySearchTreeNodeArray, 0, sizeof(BinarySearchTreeNodeArray));
	
	while (!NodeStack.empty() || pointer)
	{
		if (pointer)
		{
			NodeStack.push(pointer);
			if (pointer->RightTag == 0)
				pointer = pointer->GetLeftChild();
			else
				pointer = NULL;
		}
		else
		{
			pointer = NodeStack.top();
			BinarySearchTreeNodeArray[j++] = pointer;
			if (pointer->RightTag == 0)
				pointer = pointer->GetRightChild();
			else
				pointer = NULL;
			NodeStack.pop();
		}
	}
	BinarySearchTreeNodeArray[0]->LeftTag = 1;
	BinarySearchTreeNodeArray[0]->LeftChild = NULL;
	BinarySearchTreeNodeArray[j - 1]->RightTag = 1;
	BinarySearchTreeNodeArray[j - 1]->RightChild = NULL;
	for (int i = 0; i < j - 1; i++)
	{
		if (BinarySearchTreeNodeArray[i]->RightChild == NULL)
		{
			BinarySearchTreeNodeArray[i]->RightTag = 1;
			BinarySearchTreeNodeArray[i]->RightChild = BinarySearchTreeNodeArray[i + 1];
		}
		if (BinarySearchTreeNodeArray[i + 1]->LeftChild == NULL)
		{
			BinarySearchTreeNodeArray[i + 1]->LeftTag = 1;
			BinarySearchTreeNodeArray[i + 1]->LeftChild = BinarySearchTreeNodeArray[i];
		}
	}
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructPreOrderInOrder(T *preorder, T *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return nullptr;
	}
	return ConstructCorePreOrderInOrder(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder)
{
	int rootVal = startPreOrder[0];
	// 前序遍历的第一个数字为根节点
	BinarySearchTreeNode<T>* root = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	root->element = rootVal;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	root->LeftTag = 0;
	root->RightTag = 0;
	// 如果输入的只有一个数字
	if (startPreOrder == endPreOrder)
	{
		// 如果中序遍历也只有一个数字并且这两个数字相等
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
	}

	// 在中序遍历中找到根节点位置
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootVal)
		rootInOrder++;
	/*if (rootinorder > endinorder || *rootinorder != rootval)
	{
		throw exception("invalid input");
	}*/
	int leftLength = rootInOrder - startInOrder;
	int* leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0)
	{
		root->LeftChild = ConstructCorePreOrderInOrder(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - startPreOrder)
	{
		root->RightChild = ConstructCorePreOrderInOrder(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	return root;
}


template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructInOrderPostOrder(T* preorder, T* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return nullptr;
	}
	return ConstructCoreInOrderPostOrder(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder)
{
	int rootval = *endPostOrder;
	//后序遍历最后一个节点为根节点
	BinarySearchTreeNode<T>* root = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	root->element = rootval;
	root->LeftTag = 0;
	root->RightTag = 0;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	//如果只有一个数字
	if (startPostOrder == endPostOrder)
	{
		// 如果中序遍历也只有一个数字并且这两个数字相等
		if (startInOrder == endInOrder && *startInOrder == *startInOrder)
		{
			return root;
		}
	}
	int *rootinorder = startInOrder;
	while (*rootinorder != rootval && rootinorder <= endInOrder)
		rootinorder++;
	int leftlength = rootinorder - startInOrder;
	int *postStleft = startPostOrder + (rootinorder - startInOrder);
	int* postStright = startPostOrder + (rootinorder - startInOrder) - 1;
	if (leftlength > 0)
	{
		root->LeftChild = ConstructCoreInOrderPostOrder(startPostOrder, postStright, startInOrder, rootinorder - 1);
	}
	if ((leftlength < endPostOrder - startPostOrder) && (endInOrder > startInOrder))
	{
		root->RightChild = ConstructCoreInOrderPostOrder(postStleft, endPostOrder - 1, rootinorder + 1, endInOrder);
	}
	return root;
}

template <class T>
void BinarySearchTree<T>::DeleteBinarySearchTree(BinarySearchTreeNode<T>* root)
{
	//创造一个临时的数组储存走过的路径，类似与栈
	BinarySearchTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));

	if (InorderFlag == 0)
	{
		int m = 0;
		BinarySearchTreeNode<T> *temp = NULL;
		int count = 0;   //count为总的个数
		int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
		BinarySearchTreeNode<T> *Left = NULL, *Right = NULL;
		BinaryTreeNodeArray[count++] = root;
		do
		{
			m = ArrayRight + 1;
			for (int j = ArrayLeft; j < ArrayRight + 1; j++)
			{
				Left = BinaryTreeNodeArray[j]->GetLeftChild();
				Right = BinaryTreeNodeArray[j]->GetRightChild();

				if (Left != NULL)
					BinaryTreeNodeArray[count++] = Left;

				if (Right != NULL)
					BinaryTreeNodeArray[count++] = Right;
			}
			ArrayLeft = m;
			ArrayRight = count - 1;
		} while (Left || Right);
		for (int i = 0; i < count; i++)
		{
			free(BinaryTreeNodeArray[i]);
		}
	}
	else
	{
		int j = 0;
		BinarySearchTreeNode<T> *current = root;
		while (current->LeftTag == 0)
			current = current->LeftChild;
		while (current)
		{
			BinaryTreeNodeArray[j++] = current;
			if (current->RightTag == 1)
				current = current->RightChild;
			else
			{
				current = current->RightChild;
				while (current&&current->LeftTag == 0)
					current = current->LeftChild;
			}
		}
		for (int i = 0; i < j; i++)
		{
			free(BinaryTreeNodeArray[i]);
		}
	}
}

template <class T>
bool  BinarySearchTree<T>::IsEmpty() const
{
	if (root == NULL)
		return true;
	else
		return false;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	DeleteBinarySearchTree(root);
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T &ele)
{
	root = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	root->SetValue(ele);
	InorderFlag = 0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	InorderFlag = 0;
	root = NULL;
}

/*BinarySearchTreeNode的函数*/

template <class T>
bool BinarySearchTreeNode<T>::IsLeaf() const
{
	if (LeftChild == NULL && RightChild == NULL)
		return true;
	else
		return false;
}

template <class T>
void BinarySearchTreeNode<T>::SetValue(const T &val)
{
	element = val;
}

template <class T>
T BinarySearchTreeNode<T>::GetValue() const
{
	return element;
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::GetRightChild() const
{
	return RightChild;
}

template <class T>
BinarySearchTreeNode<T>* BinarySearchTreeNode<T>::GetLeftChild() const
{
	return LeftChild;
}

template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T &ele, BinarySearchTreeNode<T> *left, BinarySearchTreeNode *right)
{
	element = ele;
	LeftTag = 0;
	RightTag = 0;
	if (left)
		LeftChild = left;
	else
		LeftChild = NULL;
	if (right)
		RightChild = right;
	else
		RightChild = NULL;
}

template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode(const T &ele)
{
	element = ele;
	LeftTag = 0;
	LeftChild = NULL;
	RightTag = 0;
	RightChild = NULL;
}

template <class T>
BinarySearchTreeNode<T>::BinarySearchTreeNode()
{
	element = 0;
	LeftTag = 0;
	LeftChild = NULL;
	RightTag = 0;
	RightChild = NULL;
}

template <class T>
BinarySearchTreeNode<T>::~BinarySearchTreeNode()
{
	if (LeftChild)
		free(LeftChild);
	if (RightChild)
		free(RightChild);
}

/*BinaryTree的函数*/

template <class T>
bool BinaryTree<T>::IsCompleteBinaryTree() const
{
	int two = 1;
	int m = 0;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		if (m - ArrayLeft == two)
		{
			two *= 2;
			for (int j = ArrayLeft; j < ArrayRight + 1; j++)
			{
				Left = BinaryTreeNodeArray[j]->GetLeftChild();
				Right = BinaryTreeNodeArray[j]->GetRightChild();

				if (Left != NULL)
					BinaryTreeNodeArray[count++] = Left;

				if (Right != NULL)
					BinaryTreeNodeArray[count++] = Right;
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
				Left = BinaryTreeNodeArray[j]->GetLeftChild();
				Right = BinaryTreeNodeArray[j]->GetRightChild();
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
void BinaryTree<T>::MaxWidth()
{
	memset(StatisticMaxWidth, 0, sizeof(StatisticMaxWidth));
	StatisticWidth(root, 0);
	int max = 0, k = 0;
	while (StatisticMaxWidth[k++])
		if (max < StatisticMaxWidth[k - 1])
			max = StatisticMaxWidth[k - 1];
	cout << "最大得宽度为" << max << "。" << endl;
}

template <class T>
void BinaryTree<T>::StatisticWidth(BinaryTreeNode<T> *root,int k)
{
	if (root)
	{
		StatisticMaxWidth[k]++;
		StatisticWidth(root->LeftChild, k + 1);
		StatisticWidth(root->RightChild, k + 1);
	}
}

template <class T>
void BinaryTree<T>::DeleteLeave(BinaryTreeNode<T> *root)
{
	int count = 0;
	BinaryTreeNode<T> *temp = NULL;
	if (root)
	{
		if(root->LeftChild)
			if (root->LeftChild->IsLeaf())
			{
				temp = root->LeftChild;
				root->LeftChild = NULL;
			}
		if(root->RightChild)
			if (root->RightChild->IsLeaf())
			{
				temp = root->RightChild;
				root->RightChild = NULL;
			}
		if (temp)
		{
			free(temp);
			temp = NULL;
		}
		DeleteLeave(root->LeftChild);
		DeleteLeave(root->RightChild);
		
	}
}

template <class T>
void BinaryTree<T>::SwapLeftRight(BinaryTreeNode<T> *root)
{
	BinaryTreeNode<T>*temp = NULL;
	if (root)
	{
		temp = root->LeftChild;
		root->LeftChild = root->RightChild;
		root->RightChild = temp;
		SwapLeftRight(root->LeftChild);
		SwapLeftRight(root->RightChild);
	}
}

template<class T>
void BinaryTree<T>::MaxNumber()
{
	StatisticMaxMember(root);
	cout << "最大数为" << StatisticMax << "。" << endl;
}

template <class T>
void BinaryTree<T>::StatisticMaxMember(BinaryTreeNode<T> *root)
{
	if (root)
	{
		if (root->element > StatisticMax)
			StatisticMax = root->element;
		StatisticMaxMember(root->LeftChild);
		StatisticMaxMember(root->RightChild);
	}
}

template <class T>
void BinaryTree<T>::High()
{
	StatisticHigh = Statisticshigh(root);
	cout << "高度为" << StatisticHigh << "。" << endl;
}

template <class T>
int BinaryTree<T>::Statisticshigh(BinaryTreeNode<T> *root)
{
	if (root == NULL) 
		return 0;
	int l = Statisticshigh(root->LeftChild);
	int r = Statisticshigh(root->RightChild);
	return l > r ? l + 1 : r + 1;
}

template <class T>
void BinaryTree<T>::StatisticNumber(int number)
{
	StatisticsNodesNumber(root, number);
	cout << "节点数为" << number << "的节点有" << StatisticSum << "个。" << endl;
}

template <class T>
void BinaryTree<T>::StatisticsNodesNumber(BinaryTreeNode<T>* root, int number)
{

	int temp = 0;
	if (root)
	{
		if (root->LeftChild)
			temp++;
		if (root->RightChild)
			temp++;
		if (temp == number)
			StatisticSum++;
		StatisticsNodesNumber(root->LeftChild, number);
		StatisticsNodesNumber(root->RightChild, number);
	}
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::ConstructInOrderPostOrder(T* preorder, T* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return nullptr;
	}
	return ConstructCoreInOrderPostOrder(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder)
{
	int rootval = *endPostOrder;
	//后序遍历最后一个节点为根节点
	BinaryTreeNode<T>* root = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
	root->element = rootval;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	//如果只有一个数字
	if (startPostOrder == endPostOrder)
	{
		// 如果中序遍历也只有一个数字并且这两个数字相等
		if (startInOrder == endInOrder && *startInOrder == *startInOrder)
		{
			return root;
		}
	}
	int *rootinorder = startInOrder;
	while (*rootinorder != rootval && rootinorder <= endInOrder)
		rootinorder++;
	int leftlength = rootinorder - startInOrder;
	int *postStleft = startPostOrder + (rootinorder - startInOrder);
	int* postStright = startPostOrder + (rootinorder - startInOrder) - 1;
	if (leftlength > 0)
	{
		root->LeftChild = ConstructCoreInOrderPostOrder(startPostOrder , postStright, startInOrder, rootinorder - 1);
	}
	if ((leftlength < endPostOrder - startPostOrder) && (endInOrder > startInOrder))
	{
		root->RightChild = ConstructCoreInOrderPostOrder(postStleft, endPostOrder - 1, rootinorder + 1, endInOrder);
	}
	return root;
}

template <class T>
void BinaryTree<T>::SetRoot(BinaryTreeNode<T> *_root)
{
	root = _root;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::ConstructPreOrderInOrder(const T *preorder,const T *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return nullptr;
	}
	return ConstructCorePreOrderInOrder(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder)
{
	int rootVal = startPreOrder[0];
	// 前序遍历的第一个数字为根节点
	BinaryTreeNode<T>* root = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
	root->element = rootVal;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	// 如果输入的只有一个数字
	if (startPreOrder == endPreOrder)
	{
		// 如果中序遍历也只有一个数字并且这两个数字相等
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
	}

	// 在中序遍历中找到根节点位置
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootVal)
		rootInOrder++;
	/*if (rootinorder > endinorder || *rootinorder != rootval)
	{
		throw exception("invalid input");
	}*/
	int leftLength = rootInOrder - startInOrder;
	int* leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0)
	{
		root->LeftChild = ConstructCorePreOrderInOrder(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - startPreOrder)
	{
		root->RightChild = ConstructCorePreOrderInOrder(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	return root;
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root)
{
	cout << "中序遍历为： ";
	stack<BinaryTreeNode<T>*>  NodeStack;
	BinaryTreeNode<T>* pointer = root;
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
BinaryTree<T>::BinaryTree(const T &ele)
{
	root = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
	root->SetValue(ele);
	root->SetLeftChild(NULL);
	root->SetRightChild(NULL);
	StatisticSum = 0;
	StatisticHigh = 0;
	memset(StatisticMaxWidth, 0, sizeof(StatisticMaxWidth));
	StatisticMax = 0;
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *root)
{
	cout << "后序为： ";
	int temp = 0;
	enum From { left, right };
	int flag = left;
	stack<BinaryTreeNode<T>*> NodeStack;
	BinaryTreeNode<T>* TempSave = NULL;
	BinaryTreeNode<T>* pointer = root;
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
				cout << pointer->element << ' ';
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
	cout << endl;
}

template <class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)
{
	int m = 0;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = BinaryTreeNodeArray[j]->GetLeftChild();
			Right = BinaryTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				BinaryTreeNodeArray[count++] = Left;

			if (Right != NULL)
				BinaryTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		if (count > ArrayLeft)
			ArrayRight = count - 1;
	} while (Left || Right);
	cout << "层次遍历为： ";
	for (int i = 0; i < count; i++)
		cout << BinaryTreeNodeArray[i]->GetValue() << ' ';
	cout << endl;
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *root)
{
	int count = 0;
	int i = 0, flag = 0, j = 0;
	BinaryTreeNode<T> *temp = root;
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	//遍历左子树
loopl:while (temp->GetLeftChild())
	{
		temp = temp->GetLeftChild();
		BinaryTreeNodeArray[count++] = temp;
	}
	  if (flag == 0)    //没走到loopr时的操作
	  {
		  i = count;
		  temp = BinaryTreeNodeArray[--i];
	  }
	  if (flag == 1)    //做过了loopr的操作
	  {
		  temp = BinaryTreeNodeArray[--j];
	  }
	 //遍历右子树
loopr:while (temp->GetRightChild())
	{
		temp = temp->GetRightChild();
		BinaryTreeNodeArray[count++] = temp;
		j = count;
		//遍历当前节点的所有左子树
		flag = 1;
		goto loopl;
	}
	  if (i != 0)
	  {
		  temp = BinaryTreeNodeArray[--i];
		  goto loopr;
	  }
	  else
	  {
		if (temp->GetRightChild())
			  goto loopr;
	  }
	  cout << "先序遍历为： ";
	  for (int i = 0; i < count; i++)
		  cout << BinaryTreeNodeArray[i]->GetValue() << ' ';
	  cout << endl;
}

template <class T>
void BinaryTree<T>::BreadthFirstOrder(BinaryTreeNode<T>* root)
{
	int m = 0;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = BinaryTreeNodeArray[j]->GetLeftChild();
			Right = BinaryTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				BinaryTreeNodeArray[count++] = Left;

			if (Right != NULL)
				BinaryTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		if (count > ArrayLeft)
			ArrayRight = count - 1;
	} while (Left || Right);

	cout << "广度优先遍历为： ";
	for (int i = 0; i < count; i++)
		cout << BinaryTreeNodeArray[i]->GetValue() << ' ';
	cout << endl;
}

template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)
{
	int m = 0;
	BinaryTreeNode<T> *temp = NULL;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	do
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = BinaryTreeNodeArray[j]->GetLeftChild();
			Right = BinaryTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
				BinaryTreeNodeArray[count++] = Left;

			if (Right != NULL)
				BinaryTreeNodeArray[count++] = Right;
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	}while (Left || Right);
	for (int i = 0; i < count; i++)
	{
		free(BinaryTreeNodeArray[i]);
	}
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T> *current) const
{
	int m = 0;
	int count = 0;   //count为总的个数
	int ArrayLeft = 0, ArrayRight = 0;     //当前位置的度的最左边和最右边
	BinaryTreeNode<T> *Left = NULL, *Right = NULL, *temp = NULL;
	//创造一个临时的数组储存走过的路径，类似与栈
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	BinaryTreeNodeArray[count++] = root;
	while (Left != current && Right != current)
	{
		m = ArrayRight + 1;
		for (int j = ArrayLeft; j < ArrayRight + 1; j++)
		{
			Left = BinaryTreeNodeArray[j]->GetLeftChild();
			Right = BinaryTreeNodeArray[j]->GetRightChild();

			if (Left != NULL)
			{
				if (Left != current)
					BinaryTreeNodeArray[count++] = Left;
				else
					temp = Left;
			}
			
			if (Right != NULL)
			{
				if (Right != current)
					BinaryTreeNodeArray[count++] = Right;
				else
					temp = Right;
			}	
		}
		ArrayLeft = m;
		ArrayRight = count - 1;
	}
	return temp;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetRightSibling(BinaryTreeNode<T> *current) const
{
	BinaryTreeNode<T> *temp = NULL;
	temp = GetParent(this);
	if (temp->RightChild == this)
	{
		cout << "该节点无右兄弟节点。" << endl;
		return NULL;
	}
	else
		return temp->RightChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetLeftSibling(BinaryTreeNode<T> *current) const
{
	BinaryTreeNode<T> *temp = NULL;
	temp = GetParent(this);
	if (temp->LeftChild == this)
	{
		cout << "该节点无左兄弟节点。" << endl;
		return NULL;
	}
	else
		return temp->LeftChild;
}

template <class T>
bool BinaryTree<T>::IsEmpty() const
{
	return root ? false : true;
}

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
	StatisticSum = 0;
	StatisticHigh = 0;
	memset(StatisticMaxWidth, 0, sizeof(StatisticMaxWidth));
	StatisticMax = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	if (!IsEmpty())
		DeleteBinaryTree(root);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetRoot() const
{
	return root;
}

/*BinaryTreeNode的函数*/

template <class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	element = 0;
	flag = 0;
	LeftChild = NULL;
	RightChild = NULL;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele)
{
	element = ele;
	LeftChild = NULL;
	RightChild = NULL;
	flag = 0;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *left, BinaryTreeNode *right)
{
	element = ele;
	LeftChild = left;
	RightChild = right;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeftChild() const
{
	return LeftChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::GetRightChild() const
{
	return RightChild;
}

template <class T>
void BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode<T> *left)
{
	LeftChild = left;
}

template <class T>
void BinaryTreeNode<T>::SetRightChild(BinaryTreeNode<T> *right)
{
	RightChild = right;
}

template <class T>
T BinaryTreeNode<T>::GetValue() const
{
	return element;
}

template <class T>
void BinaryTreeNode<T>::SetValue(const T &val)
{
	element = val;
}

template <class T>
bool BinaryTreeNode<T>::IsLeaf() const
{
	BinaryTreeNode<T> *TempLeft = NULL, *TempRight = NULL;
	TempLeft = GetLeftChild();
	TempRight = GetRightChild();
	if (!TempLeft && !TempRight)
		return true;
	else
		return false;
}

/*其他函数*/

template <class T>
void FlipArray(T *Array, int first, int last)
{
	for (int i = first; i <= (first + last) / 2; i++)
		Swap(Array[i], Array[last - i + first]);
}

template <class T>
void Swap(T &x, T &y)
{
	T temp = 0;
	temp = x;
	x = y;
	y = temp;
}

template <class T>
void ShowOn(T initialize)
{
	int count = 0;
	int ArrayCount = 1;
	BinaryTreeNode<T> *temp = NULL, *current = NULL;;
	T element = 0;
	int number = 0;
	char ch;
	BinaryTree<T> tree(initialize);
	/*创造一个储存的变量*/
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	while (1)
	{
		cout << "请输入数据；";
		cin >> element;
		if (count == 0)
		{
			temp = tree.GetRoot();
			BinaryTreeNodeArray[ArrayCount++] = tree.GetRoot();
		}
		count++;
		current = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
		current->SetValue(element);
		current->SetLeftChild(NULL);
		current->SetRightChild(NULL);
	loop1:	cout << "请输入为第几个节点的下属：";
		cin >> number;
		if (BinaryTreeNodeArray[number] == NULL)
		{
			cout << "该节点为空。";
			goto loop1;
		}
		cout << "请输入是左下属还是右下属（L或R）：";
loop2:	cin >> ch;
		switch (ch)
		{
		case 'L':
		case 'l':
			BinaryTreeNodeArray[number]->SetLeftChild(current);
			BinaryTreeNodeArray[ArrayCount++] = current;
			break;
		case 'r':
		case 'R':
			BinaryTreeNodeArray[number]->SetRightChild(current);
			BinaryTreeNodeArray[ArrayCount++] = current;
			break;
		default:
			cout << "输入无效，请重新输入。" << endl;
			goto loop2;
			break;
		}
		cout << "是否继续：";
		cin >> ch;
		if (ch == 'N' || ch == 'n')
			break;
		system("pause");
		system("cls");
	}
	//几种排序输出
	tree.BreadthFirstOrder(tree.GetRoot());
	tree.PreOrder(tree.GetRoot());
	tree.InOrder(tree.GetRoot());
	tree.PostOrder(tree.GetRoot());
}

#endif // !_BINARYTREE_H_
