#pragma once

#include<iostream>
#include<stack>

using namespace std;

#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

template <class T>
class MaxHeap
{
private:
	T *maxheap;
	int lenth;
public:
	void Swap(T &x, T &y);
	MaxHeap();
	MaxHeap(const T *m,int lenth);
	~MaxHeap();

	void Initializer();       //初始化
	void DeleteMaxPoint();    //删除最大元素
	void MaxHeapSort();      //堆排序
	void AddPoint(const T x);      //添加节点
	void DeletePoint(const T &x);   //删除指定节点
	void Show();
};

template <class T>
void MaxHeap<T>::DeletePoint(const T &x)
{
	int flag = 0;
	lenth--;
	T *temp = (T*)malloc(sizeof(T)*lenth);
	for (int i = 0; i < lenth + 1; i++)
		if (maxheap[i] == x)
			flag = i;
	Swap(maxheap[flag], maxheap[lenth]);
	for (int i = 0; i < lenth; i++)
		temp[i] = maxheap[i];
	free(maxheap);
	maxheap = (T*)malloc(sizeof(T)*lenth);
	for (int i = 0; i < lenth; i++)
		maxheap[i] = temp[i];
	free(temp);
	Initializer();
}

template <class T>
void MaxHeap<T>::MaxHeapSort()
{
	while (lenth > 0)
	{
		cout << maxheap[0] << ' ';
		DeleteMaxPoint();
		Initializer();
	}
	cout << endl;
}

template <class T>
void MaxHeap<T>::AddPoint(const T x)
{
	lenth++;
	T *temp = (T*)malloc(sizeof(T)*lenth);
	for (int i = 0; i < lenth - 1; i++)
		temp[i] = maxheap[i];
	free(maxheap);
	temp[lenth - 1] = x;
	maxheap = (T*)malloc(sizeof(T)*lenth);
	for (int i = 0; i < lenth; i++)
		maxheap[i] = temp[i];
	free(temp);
	Initializer();
}

template <class T>
void MaxHeap<T>::DeleteMaxPoint()
{
	lenth--;
	T *temp = (T*)malloc(sizeof(T)*lenth);
	Swap(maxheap[0], maxheap[lenth]);
	for (int i = 0; i < lenth; i++)
		temp[i] = maxheap[i];
	free(maxheap);
	maxheap = (T*)malloc(sizeof(T)*lenth);
	for (int i = 0; i < lenth; i++)
		maxheap[i] = temp[i];
	free(temp);
}

template <class T>
void MaxHeap<T>::Show()
{
	for (int i = 0; i < lenth; i++)
		cout << maxheap[i] << ' ';
	cout << endl;
}

template <class T>
void MaxHeap<T>::Initializer()
{
	stack<int> Stack;    //记录i的值
	int max = 0;     //储存左右节点的最大值
	int count = 0;   //储存走了几次
	int i = lenth - 1;
	while (i > 0)
	{
loop:	if (i < lenth)
		{
			if (maxheap[i] > maxheap[(i + 1) / 2 - 1])
			{
				Swap(maxheap[i], maxheap[(i + 1) / 2 - 1]);
				if (i * 2 < lenth || i * 2 + 1 < lenth)
				{
					Stack.push(i);
					i = i * 2 + 1;
					goto loop;
				}
			}
		}
		if(!Stack.empty())
			if (i == Stack.top() * 2)
			{
				i = Stack.top();
				Stack.pop();
			}
		i--;
	}
}

template <class T>
void MaxHeap<T>::Swap(T &x, T &y)
{
	T temp = 0;
	temp = x;
	x = y;
	y = temp;
}

template <class T>
MaxHeap<T>::MaxHeap()
{
	maxheap = NULL;
	lenth = 0;
}

template <class T>
MaxHeap<T>::MaxHeap(const T *m,int _lenth)
{
	maxheap = (T *)malloc(sizeof(T) * _lenth);
	for (int i = 0; i < _lenth; i++)
		maxheap[i] = m[i];
	lenth = _lenth;
	Initializer();
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
	free(maxheap);
}

#endif // !_MAXHEAP_H_
