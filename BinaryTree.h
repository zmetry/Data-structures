#pragma once

#include<iostream>
#include<stack>
#include"HuffmanTree.h"
using namespace std;

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <class T>
void FlipArray(T *Array, int first, int last);  // �ߵ�����λ��

template <class T>
void Swap(T &x, T &y);      //��������

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
	BinaryTreeNode();            //Ĭ�Ϲ��캯��
	BinaryTreeNode(const T &ele);  //�����������ֵ�Ĺ��캯��
	BinaryTreeNode(const T &ele, BinaryTreeNode<T> *left = NULL, BinaryTreeNode *right = NULL);   //��������������Һ��ӽڵ�Ĺ��캯��
	BinaryTreeNode<T>* GetLeftChild() const;                   //�������ӽڵ�
	BinaryTreeNode<T>* GetRightChild() const;                   //�����Һ��ӽڵ�
	void SetLeftChild(BinaryTreeNode<T> *left);               //���øýڵ�����ӽڵ�
	void SetRightChild(BinaryTreeNode<T> *left);              //���øýڵ���Һ��ӽڵ�
	T GetValue() const;                                  //���ظýڵ��������
	void SetValue(const T &val);                        //���øýڵ���������ֵ
	bool IsLeaf() const;                                //�жϸýڵ��Ƿ�ΪҶ�ӽڵ㣬���Ƿ���true
};

template <class T>
class BinaryTree {
private:
	int StatisticSum;        //ͳ����Ӧ�ڵ����ܺ�
	int StatisticHigh;       //ͳ�Ƹ߶�
	int StatisticMaxWidth[100];   //ͳ�������
	T StatisticMax;    //ͳ�����ֵ
	BinaryTreeNode<T> *root;               //���������ڵ�
public:
	BinaryTree();                         //Ĭ�Ϲ��캯��
	BinaryTree(const T &ele);            //�������Ĺ��캯��
	~BinaryTree();                          //��������
	bool IsEmpty() const;                   //�ж϶������Ƿ�Ϊ����
	bool IsCompleteBinaryTree() const;    //�ж��Ƿ�Ϊ��ȫ������
	void StatisticNumber(int number);    //ͳ����Ӧ�ڵ����ĸ���
	void MaxNumber();         //ͳ�������ֵ
	void High();           //ͳ�Ƹ߶�
	void MaxWidth();        //�����

	BinaryTreeNode<T>* GetRoot() const;        //���ض������ĸ��ڵ�
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T> *current) const;     //����current�ڵ�ĸ��ڵ�
	BinaryTreeNode<T>* GetLeftSibling(BinaryTreeNode<T> *current) const;   //����current�ڵ�����ֵ�
	BinaryTreeNode<T>* GetRightSibling(BinaryTreeNode<T> *current) const;   //����current�ڵ�����ֵ�
	//ǰ�������������
	BinaryTreeNode<T>* ConstructPreOrderInOrder(const T* preorder,const T* inorder, int length);   
	BinaryTreeNode<T>* ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder);
	//��������������
	BinaryTreeNode<T>* ConstructInOrderPostOrder(T* postorder, T* inorder, int length);
	BinaryTreeNode<T>* ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder);

	void BreadthFirstOrder(BinaryTreeNode<T>* root);    //������ȱ�����rootΪ���ڵ������
	void PreOrder(BinaryTreeNode<T>* root);              //���������rootΪ���ڵ������
	void InOrder(BinaryTreeNode<T>* root);              //���������rootΪ���ڵ������
	void PostOrder(BinaryTreeNode<T>* root);              //���������rootΪ���ڵ������
	void LevelOrder(BinaryTreeNode<T>* root);              //����α�����rootΪ���ڵ������
	void DeleteBinaryTree(BinaryTreeNode<T>* root);      //ɾ����rootΪ���ڵ������
	void SetRoot(BinaryTreeNode<T>* _root); 

	void StatisticsNodesNumber(BinaryTreeNode<T>* root, int number);   //ͳ�Ƹ��ڵ��ָ����
	int Statisticshigh(BinaryTreeNode<T> *root);            //���ĸ߶�
	void StatisticWidth(BinaryTreeNode<T> *root,int k);             //ͳ�������
	void SwapLeftRight(BinaryTreeNode<T> *root);           //������������
	void DeleteLeave(BinaryTreeNode<T> *root);          //ɾ��Ҷ�ӽڵ�
	void StatisticMaxMember(BinaryTreeNode<T> *root);      //ͳ�����Ԫ��
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
	//��Ҫ����
	BinarySearchTreeNode();
	BinarySearchTreeNode(const T&ele);
	BinarySearchTreeNode(const T &ele, BinarySearchTreeNode<T> *left = NULL, BinarySearchTreeNode *right = NULL);
	~BinarySearchTreeNode();

	BinarySearchTreeNode<T>* GetLeftChild() const;                   //�������ӽڵ�
	BinarySearchTreeNode<T>* GetRightChild() const;                   //�����Һ��ӽڵ�
	T GetValue() const;                                  //���ظýڵ��������
	void SetValue(const T &val);                        //���øýڵ���������ֵ
	bool IsLeaf() const;                                //�жϸýڵ��Ƿ�ΪҶ�ӽڵ㣬���Ƿ���true
};

template <class T>
class BinarySearchTree
{
private:
	BinarySearchTreeNode<T> *root;
	int InorderFlag;
public:
	BinarySearchTree();                         //Ĭ�Ϲ��캯��
	BinarySearchTree(const T &ele);            //�������Ĺ��캯��
	~BinarySearchTree();                          //��������
	bool IsEmpty() const;                   //�ж϶������Ƿ�Ϊ����
	void DeleteBinarySearchTree(BinarySearchTreeNode<T>* root);      //ɾ����rootΪ���ڵ������
	void SetRoot(BinarySearchTreeNode<T> *root);
	BinarySearchTreeNode<T>* GetRoot();   

	BinarySearchTree(const T *Array,int lenth);     //��������������

	//ǰ�������������
	BinarySearchTreeNode<T>* ConstructPreOrderInOrder(T* preorder, T* inorder, int length);
	BinarySearchTreeNode<T>* ConstructCorePreOrderInOrder(T *startPreOrder, T *endPreOrder, T *startInOrder, T *endInOrder);
	//��������������
	BinarySearchTreeNode<T>* ConstructInOrderPostOrder(T* postorder, T* inorder, int length);
	BinarySearchTreeNode<T>* ConstructCoreInOrderPostOrder(T *startPostOrder, T *endPostOrder, T *startInOrder, T *endInOrder);

	void InOrder(BinarySearchTreeNode<T>* root);              //���������rootΪ���ڵ������

	//�����������Ľ���
	void BuildMiddleOrderClueBinaryTree();

	//ɾ��һ�ڵ�
	void DeletePoint(const T &ele);

	//����
	BinarySearchTreeNode<T>* FindPoint(const T &ele);

	//����һ�ڵ�
	void AddPoint(const T &ele);

	//�ָ��ɶ�����
	void ResetBinarySearchTree();

	//���������������������
	void InOrderBinarySearchTree();

};

/*BinarySearchTree�ĺ���*/

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
	cout << "�������Ϊ�� ";
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
	////�ҵ����һ��Ҷ�ӽڵ�
	//for (int i = 0; i < j; i++)
	//	if (BinaryTreeNodeArray[i]->LeftTag == 1 || BinaryTreeNodeArray[i]->RightTag == 1)
	//	{
	//		last = i;
	//		break;
	//	}
	//switch (BinaryTreeNodeArray[last]->LeftTag)
	//{
	//case 0:
	//	//�����ӣ��嵽�ұ�
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
	//	//�����ӣ��嵽���
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
	////Ѱ�Ҹýڵ�
	//for (int i = 0; i < j; i++)
	//{
	//	//�ҵ��ýڵ�
	//	if (BinaryTreeNodeArray[i]->GetValue() == ele)
	//		temp = i;
	//	//�ҵ����һ��Ҷ�ӽڵ�
	//	if (BinaryTreeNodeArray[i]->RightTag == 1 && BinaryTreeNodeArray[i]->LeftTag == 1)
	//		last = i;
	//}

	////�ҵ��丸�ڵ�
	//for (int i = 0; i < j; i++)
	//	if (BinaryTreeNodeArray[i]->LeftChild == BinaryTreeNodeArray[last] || BinaryTreeNodeArray[i]->RightChild == BinaryTreeNodeArray[last])
	//	{
	//		current = BinaryTreeNodeArray[i];
	//		break;
	//	}
	//
	////��ʼɾ������,�Ȱ�Ҷ�ӽڵ㻻��ȥ
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
		cout << "û�иýڵ㡣" << endl;

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
	// ǰ������ĵ�һ������Ϊ���ڵ�
	BinarySearchTreeNode<T>* root = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	root->element = rootVal;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	root->LeftTag = 0;
	root->RightTag = 0;
	// ��������ֻ��һ������
	if (startPreOrder == endPreOrder)
	{
		// ����������Ҳֻ��һ�����ֲ����������������
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
	}

	// ������������ҵ����ڵ�λ��
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
	//����������һ���ڵ�Ϊ���ڵ�
	BinarySearchTreeNode<T>* root = (BinarySearchTreeNode<T>*)malloc(sizeof(BinarySearchTreeNode<T>));
	root->element = rootval;
	root->LeftTag = 0;
	root->RightTag = 0;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	//���ֻ��һ������
	if (startPostOrder == endPostOrder)
	{
		// ����������Ҳֻ��һ�����ֲ����������������
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
	//����һ����ʱ�����鴢���߹���·����������ջ
	BinarySearchTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));

	if (InorderFlag == 0)
	{
		int m = 0;
		BinarySearchTreeNode<T> *temp = NULL;
		int count = 0;   //countΪ�ܵĸ���
		int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
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

/*BinarySearchTreeNode�ĺ���*/

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

/*BinaryTree�ĺ���*/

template <class T>
bool BinaryTree<T>::IsCompleteBinaryTree() const
{
	int two = 1;
	int m = 0;
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	cout << "���ÿ��Ϊ" << max << "��" << endl;
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
	cout << "�����Ϊ" << StatisticMax << "��" << endl;
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
	cout << "�߶�Ϊ" << StatisticHigh << "��" << endl;
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
	cout << "�ڵ���Ϊ" << number << "�Ľڵ���" << StatisticSum << "����" << endl;
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
	//����������һ���ڵ�Ϊ���ڵ�
	BinaryTreeNode<T>* root = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
	root->element = rootval;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	//���ֻ��һ������
	if (startPostOrder == endPostOrder)
	{
		// ����������Ҳֻ��һ�����ֲ����������������
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
	// ǰ������ĵ�һ������Ϊ���ڵ�
	BinaryTreeNode<T>* root = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
	root->element = rootVal;
	root->LeftChild = NULL;
	root->RightChild = NULL;
	// ��������ֻ��һ������
	if (startPreOrder == endPreOrder)
	{
		// ����������Ҳֻ��һ�����ֲ����������������
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
		{
			return root;
		}
	}

	// ������������ҵ����ڵ�λ��
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
	cout << "�������Ϊ�� ";
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
	cout << "����Ϊ�� ";
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
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	cout << "��α���Ϊ�� ";
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
	//����������
loopl:while (temp->GetLeftChild())
	{
		temp = temp->GetLeftChild();
		BinaryTreeNodeArray[count++] = temp;
	}
	  if (flag == 0)    //û�ߵ�looprʱ�Ĳ���
	  {
		  i = count;
		  temp = BinaryTreeNodeArray[--i];
	  }
	  if (flag == 1)    //������loopr�Ĳ���
	  {
		  temp = BinaryTreeNodeArray[--j];
	  }
	 //����������
loopr:while (temp->GetRightChild())
	{
		temp = temp->GetRightChild();
		BinaryTreeNodeArray[count++] = temp;
		j = count;
		//������ǰ�ڵ������������
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
	  cout << "�������Ϊ�� ";
	  for (int i = 0; i < count; i++)
		  cout << BinaryTreeNodeArray[i]->GetValue() << ' ';
	  cout << endl;
}

template <class T>
void BinaryTree<T>::BreadthFirstOrder(BinaryTreeNode<T>* root)
{
	int m = 0;
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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

	cout << "������ȱ���Ϊ�� ";
	for (int i = 0; i < count; i++)
		cout << BinaryTreeNodeArray[i]->GetValue() << ' ';
	cout << endl;
}

template <class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)
{
	int m = 0;
	BinaryTreeNode<T> *temp = NULL;
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	BinaryTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	BinaryTreeNode<T> *Left = NULL, *Right = NULL, *temp = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
		cout << "�ýڵ������ֵܽڵ㡣" << endl;
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
		cout << "�ýڵ������ֵܽڵ㡣" << endl;
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

/*BinaryTreeNode�ĺ���*/

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

/*��������*/

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
	/*����һ������ı���*/
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));
	while (1)
	{
		cout << "���������ݣ�";
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
	loop1:	cout << "������Ϊ�ڼ����ڵ��������";
		cin >> number;
		if (BinaryTreeNodeArray[number] == NULL)
		{
			cout << "�ýڵ�Ϊ�ա�";
			goto loop1;
		}
		cout << "��������������������������L��R����";
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
			cout << "������Ч�����������롣" << endl;
			goto loop2;
			break;
		}
		cout << "�Ƿ������";
		cin >> ch;
		if (ch == 'N' || ch == 'n')
			break;
		system("pause");
		system("cls");
	}
	//�����������
	tree.BreadthFirstOrder(tree.GetRoot());
	tree.PreOrder(tree.GetRoot());
	tree.InOrder(tree.GetRoot());
	tree.PostOrder(tree.GetRoot());
}

#endif // !_BINARYTREE_H_
