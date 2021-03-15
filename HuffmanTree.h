#pragma once

#include<iostream>
#include"BinaryTree.h"
#include<deque>
#include<stack>

using namespace std;

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

template <class T>
struct HuffmanArray
{
	T element;
	int flag;    //标记是数字还是其他的
	HuffmanArray *next;
};

template <class T>
struct Secret
{
	T element;
	int str[100];
};


template <class T>
class HuffmanTree
{
private:
	BinaryTreeNode<T> *root;
	HuffmanArray<T> *Huffarray;
public:
	HuffmanTree();
	~HuffmanTree();
	
	void BuildHuffmanArray(const T *array, int lenth);         //创建一个从大到小排序的数组
	void ShowHuffmanArray();
	void BuildHuffmanTree(const T *array,int lenth);
	void DeCode(const char *array);                        //译码
	void Code(const T *array,int lenth);                             //编码
	void InOrder(BinaryTreeNode<T> *root);
	BinaryTreeNode<T>* GetRoot();
};

template <class T>
void HuffmanTree<T>::Code(const T *array,int lenth)
{
	int i = 0;
	deque<int> NodeDeque;
	stack<BinaryTreeNode<T>*> NodeStack;
	Secret<T> *temp = new Secret<T>[lenth];
	for (int i = 0; i < lenth; i++)
	{
		temp[i].element = 0;
		memset(temp[i].str, 0, sizeof(int));
	}
	int *p = NULL;
	BinaryTreeNode<T>* pointer = root, * prev = root;
	int current = 0, count = 0, k = 0, _temp = 0;
	while (!NodeStack.empty() || pointer)
	{
		if (pointer)
		{
			NodeStack.push(pointer);
			pointer = pointer->GetLeftChild();
			if(pointer)
				NodeDeque.push_back(0);
		}
		else
		{
			pointer = NodeStack.top();
			if (pointer->flag == 0)
			{
				temp[i].element = pointer->element;
				count = NodeDeque.size();
				for (int j = 0; j < count; j++)
				{
					current = NodeDeque.at(0);
					NodeDeque.pop_front();
					NodeDeque.push_back(current);
					if (current == 0)
						temp[i].str[k++] = 0;
					else
						temp[i].str[k++] = 1;
				}
				temp[i++].str[k] = '-1';
				k = 0;
			}
			//如果是在右子树的所有节点上多排一次
			if (pointer == root)
				NodeDeque.pop_back();

			if (pointer == prev && prev->flag == 1)
			{
				_temp = NodeDeque.size() - 1;
				if (_temp > 0)
					while (NodeDeque.at(_temp--) == 0)
						NodeDeque.pop_back();
				prev = pointer->RightChild;
			}

			pointer = pointer->GetRightChild();
			if (pointer)
				NodeDeque.push_back(1);
			else
				NodeDeque.pop_back();
			NodeStack.pop();
			
		}
	}
	
	for (int i = 0; i < lenth; i++)
	{
		for(int m = 0;m < lenth;m++)
			if (array[i] == temp[m].element)
			{
				p = temp[m].str;
				while (*p != '-1')
				{
					cout << *p;
					p++;
				}
				cout << ' ';
				break;
			}
	}

	delete[]temp;
}

template <class T>
void HuffmanTree<T>::DeCode(const char *array)
{
	BinaryTreeNode<T> *current = NULL;
	const char *p = array;
	current = root;
	while (*p != '\0')
	{
		switch (*p)
		{
		case '0':
			current = current->LeftChild;
			break;
		case '1':
			current = current->RightChild;
			break;
		default:
			break;
		}
		if (current->flag == 1)
			p++;
		else
		{
			cout << current->element << ' ';
			current = root;
			p++;
		}
	}
}

template <class T>
void HuffmanTree<T>::InOrder(BinaryTreeNode<T> *root)
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
BinaryTreeNode<T>* HuffmanTree<T>::GetRoot()
{
	return root;
}

template <class T>
void HuffmanTree<T>::BuildHuffmanTree(const T *array,int lenth)
{
	BuildHuffmanArray(array, lenth);
	int j = 0, k = 0;
	BinaryTreeNode<T>* BinaryTreeNodeArray[100];
	memset(BinaryTreeNodeArray, 0, sizeof(BinaryTreeNodeArray));

	HuffmanArray<T> *first = NULL, *second = NULL, *temp = NULL;   //指向数组的头两个
	BinaryTreeNode<T> *LeftChild = NULL, *RightChild = NULL, *Parent = NULL;
	HuffmanArray<T> *current = NULL;
	if (Huffarray)
	{
		while (Huffarray)
		{
			//初始化
			first = Huffarray;
			second = first->next;
			Huffarray = second->next;
			LeftChild = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
			RightChild = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
			Parent = (BinaryTreeNode<T>*)malloc(sizeof(BinaryTreeNode<T>));
			memset(LeftChild, 0, sizeof(LeftChild));
			memset(RightChild, 0, sizeof(RightChild));
			memset(Parent, 0, sizeof(Parent));
			LeftChild->LeftChild = NULL;
			LeftChild->RightChild = NULL;
			RightChild->LeftChild = NULL;
			RightChild->RightChild = NULL;
			

			//取最小的两个节点作为左右节点
			if (first->flag == 1)
			{
				for (int i = 0; i < j; i++)
					if (BinaryTreeNodeArray[i]->element == first->element)
					{
						LeftChild = BinaryTreeNodeArray[i];
						k = i;
						break;
					}
				for (int i = k; i < j; i++)
					BinaryTreeNodeArray[i] = BinaryTreeNodeArray[i + 1];
				j -= 1;
				LeftChild->flag = 1;
			}
			else
			{
				LeftChild->element = first->element;
				LeftChild->flag = 0;
			}

			if (second->flag == 1)
			{
				for (int i = 0; i < j; i++)
					if (BinaryTreeNodeArray[i]->element == second->element)
					{
						RightChild = BinaryTreeNodeArray[i];
						k = i;
						break;
					}
				for (int i = k; i < j; i++)
					BinaryTreeNodeArray[i] = BinaryTreeNodeArray[i + 1];
				j -= 1;
				RightChild->flag = 1;
			}
			else
			{
				RightChild->element = second->element;
				RightChild->flag = 0;
			}
			//构建父亲节点
			Parent->element = LeftChild->element + RightChild->element;
			Parent->LeftChild = LeftChild;
			Parent->RightChild = RightChild;
			Parent->flag = 1;
			free(first);
			free(second);

			BinaryTreeNodeArray[j++] = Parent;

			//将父节点插入到数组中
			temp = (HuffmanArray<T>*)malloc(sizeof(HuffmanArray<T>));
			temp->flag = 1;
			temp->element = Parent->element;
			temp->next = NULL;
			current = Huffarray;
			if (current)
			{
				if (temp->element < current->element)
				{
					temp->next = current;
					Huffarray = temp;
				}
				else
				{
					while (current->element < temp->element && current->next)
						current = current->next;
					if (current->next == NULL)
						current->next = temp;
					else
					{
						temp->next = current->next;
						current->next = temp;
					}
				}
			}	
		}

		root = Parent;
	}
}

template <class T>
void HuffmanTree<T>::ShowHuffmanArray()
{
	HuffmanArray<T> *current = NULL;
	if (Huffarray)
	{
		current = Huffarray;
		while (current)
		{
			cout << current->element << ' ';
			current = current->next;
		}
	}
	else
		cout << "数组为空。";
	cout << endl;
}

template <class T>
void HuffmanTree<T>::BuildHuffmanArray(const T *array, int lenth)
{
	HuffmanArray<T> *current = NULL, *prev = NULL;
	T min = 0, temp = -1;    //min用来存当前的最小值，temp用来存上一个最小值
	for (int i = 0; i < lenth; i++)
	{
		min = 100;
		for (int i = 0; i < lenth; i++)
			if (min > array[i] && array[i] > temp)
				min = array[i];
		temp = min;
		current = (HuffmanArray<T>*)malloc(sizeof(HuffmanArray<T>));
		current->element = min;
		current->flag = 0;
		current->next = NULL;
		if (Huffarray == NULL)
			Huffarray = current;
		else
			prev->next = current;
		prev = current;
	}
}

template <class T>
HuffmanTree<T>::HuffmanTree()
{
	root = NULL;
	Huffarray = NULL;
}

template <class T>
HuffmanTree<T>::~HuffmanTree()
{
	if (Huffarray)
	{
		HuffmanArray<T> *temp = NULL;
		temp = Huffarray;
		while (temp)
		{
			if (Huffarray)
				Huffarray = Huffarray->next;
			free(temp);	
			temp = Huffarray;
		}
	}

	if (root)
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
		} while (Left || Right);
		for (int i = 0; i < count; i++)
		{
			free(BinaryTreeNodeArray[i]);
		}
	}
}

#endif // !_HUFFMAN_H_
