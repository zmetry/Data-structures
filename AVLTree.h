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
	int Balance;   //�������߶ȼ��������߶�
	AVLTreeNode<T> *LeftChild;
	AVLTreeNode<T> *RightChild;
public:
	AVLTreeNode();            //Ĭ�Ϲ��캯��
	AVLTreeNode(const T &ele);  //�����������ֵ�Ĺ��캯��
	AVLTreeNode(const T &ele, AVLTreeNode<T> *left = NULL, AVLTreeNode *right = NULL);   //��������������Һ��ӽڵ�Ĺ��캯��
	AVLTreeNode<T>* GetLeftChild() const;                   //�������ӽڵ�
	AVLTreeNode<T>* GetRightChild() const;                   //�����Һ��ӽڵ�
	AVLTreeNode<T>* GetParent(AVLTreeNode<T> *root);         //���ظýڵ�ĸ��ڵ�
	
	void SetLeftChild(AVLTreeNode<T> *left);               //���øýڵ�����ӽڵ�
	void SetRightChild(AVLTreeNode<T> *left);              //���øýڵ���Һ��ӽڵ�
	T GetValue() const;                                  //���ظýڵ��������
	void SetValue(const T &val);                        //���øýڵ���������ֵ
	bool IsLeaf() const;                                //�жϸýڵ��Ƿ�ΪҶ�ӽڵ㣬���Ƿ���true

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
	AVLTreeNode<T>* GetRoot();               //���ؽڵ�

	void DeleteAVLTree(AVLTreeNode<T>* root);      //ɾ����rootΪ���ڵ������

	void LeftSpin(AVLTreeNode<T> *root);           //����
	void RightSpin(AVLTreeNode<T> *root);          //�ҵ���
	void LeftRightRotation(AVLTreeNode<T> *root);  //����˫��
	void RightLeftRotation(AVLTreeNode<T> *root);  //����˫��

	void BuildAVLTree(const T *str,int lenth);    //����ƽ�������
	void SetAllBalance(AVLTreeNode<T> *root);     //������������ƽ��ֵ

	void AddPoint(const T &ele);    //����һ���ڵ�
	void DeletePoint(const T &ele); //ɾ��һ���ڵ�

	bool IsCompleteBinaryTree() const;    //�ж��Ƿ�Ϊ��ȫ������
	void PreOrder(AVLTreeNode<T> *root);   //ǰ�����
	void InOrder(AVLTreeNode<T>* root);              //���������rootΪ���ڵ������

	void Spin(AVLTreeNode<T> *root);    //����������
};

//AVLTree�ĺ���

template <class T>
void AVLTree<T>::DeletePoint(const T &ele)
{
	AVLTreeNode<T> *current = NULL, *PostFirst = NULL, *Parent = NULL;
	int m = 0;
	AVLTreeNode<T> *temp = NULL;
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	//�ҵ���ǰ�ڵ�
	for (int i = 0; i < count; i++)
		if (AVLTreeNodeArray[i]->GetValue() == ele)
		{
			current = AVLTreeNodeArray[i];
			break;
		}
	if (current == NULL)
		cout << "�Ҳ����ýڵ㡣" << endl;
	else
	{
		//�ҵ���������ĵ�һ���ڵ�
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
	cout << "�������Ϊ�� ";
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
	//����������
loopl:while (temp->GetLeftChild())
{
	temp = temp->GetLeftChild();
	AVLTreeNodeArray[count++] = temp;
}
	  if (flag == 0)    //û�ߵ�looprʱ�Ĳ���
	  {
		  i = count;
		  temp = AVLTreeNodeArray[--i];
	  }
	  if (flag == 1)    //������loopr�Ĳ���
	  {
		  temp = AVLTreeNodeArray[--j];
	  }
	  //����������
  loopr:while (temp->GetRightChild())
  {
	  temp = temp->GetRightChild();
	  AVLTreeNodeArray[count++] = temp;
	  j = count;
	  //������ǰ�ڵ������������
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
		cout << "�������Ϊ�� ";
		for (int i = 0; i < count; i++)
			cout << AVLTreeNodeArray[i]->GetValue() << ' ';
		cout << endl;
}

template <class T>
bool AVLTree<T>::IsCompleteBinaryTree() const
{
	int two = 1;
	int m = 0;
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	//�ж�����������в���
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
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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
	//current����A��root����C
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
	int count = 0;   //countΪ�ܵĸ���
	int ArrayLeft = 0, ArrayRight = 0;     //��ǰλ�õĶȵ�����ߺ����ұ�
	AVLTreeNode<T> *Left = NULL, *Right = NULL;
	//����һ����ʱ�����鴢���߹���·����������ջ
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

//AVLTreeNode�ĺ���

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

//��������
template <class T>
void Swap(T &x, T &y)
{
	T temp = 0;
	temp = x;
	x = y;
	y = temp;
}

#endif // !_AVLTREE_H_
