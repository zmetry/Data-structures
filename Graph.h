#pragma once

#include<iostream>
#include<stack>
#include<queue>

#define INF 10000

using namespace std;

#ifndef _GRAPH_H_
#define _GRAPH_H_

enum Visit {
	Visited, Unvisited
};

enum Place {
	headvex, tailvex
};

template <class T>
void SWap(T &x, T &y)
{
	T temp = 0;
	temp = x;
	x = y;
	y = temp;
}

template <class T>
class Edge;

void BuildGraph();

template<class T>
class Vertices
{
	friend class Edge<T>;
public:
	T vexinfo;          //������Ϣ
	Edge<T> *FirstIn;      //��һ���뻡�Ľڵ�
	Edge<T> *FirstOut;      //��һ�������ڵ�
	int flag;         //�ж��Ƿ񱻷���

	T GetVexInfo() {
		return vexinfo;
	}

	Vertices* GetFirstIn() {
		return FirstIn;
	}

	Vertices* FetFirstOut() {
		return FirstOut;
	}

	void SetVexInfo(T Vi) {
		vexinfo = Vi;
	}

	void SetFirstIn(Edge<T> *fi) {
		FirstIn = fi;
	}

	void SetFirstOut(Edge<T> *fo) {
		FirstOut = fo;
	}

	Vertices() {
		FirstIn = NULL;
		FirstOut = NULL;
		flag = Unvisited;
	}

	Vertices(const T &Vi) {
		vexinfo = Vi;
		FirstIn = NULL;
		FirstOut = NULL;
		flag = Unvisited;
	}

	~Vertices() {
		
	}
};

template <class T>
class Edge
{
public:
	int tailvex;              //��β����
	int headvex;              //��ͷ����
	T arcinfo;                //����Ȩ��
	Edge *tnext;              //��β��ͬ����һ����
	Edge *hnext;              //��ͷ��ͬ����һ����


	Edge() {
		tailvex = 0;
		headvex = 0;
		arcinfo = 0;
		tnext = NULL;
		hnext = NULL;
	}

	Edge(int tv, int hv, T ai, Edge *tn, Edge *hn) {
		tailvex = tv;
		headvex = hv;
		arcinfo = ai;
		tnext = tn;
		hnext = hn;
	}
	~Edge() {};

	int GetTailVex() {
		return tailvex;
	}

	int GetHeadVex() {
		return headvex;
	}

	//Ȩ��
	T GetArcInfo() {
		return arcinfo;
	}

	//��β����ͬ����һ����
	Edge* GetTnext() {
		return tnext;
	}

	//��ͷ��ͬ����һ����
	Edge* GetHnext() {
		return hnext;
	}


};

template <class T>
class Grapgh
{
	friend class Edge<T>;
	friend class Vertices<T>;
private:
	int VisitedOrNot;
	int VerCount;           //��¼����Ķ�����Ŀ
	int VerticesNum;         //�������
	int EdgeCount;         //��¼����ߵĸ���
	int EdgeNum;          //�ߵĸ���
	Vertices<T> *vertics;      //��������
	Edge<T> *edge;           //������

public:
	Grapgh() {
		VerticesNum = 0;
		EdgeNum = 0;
		vertics = NULL;
		edge = NULL;
		VerCount = 0;
		EdgeCount = 0;
		VisitedOrNot = 0;
	}

	Grapgh(int vn, int en) {
		VerticesNum = vn;
		EdgeNum = en;
		vertics = (Vertices<T>*)malloc(sizeof(Vertices<T>) * VerticesNum);
		edge = (Edge<T>*)malloc(sizeof(Edge<T>) * EdgeNum);
		memset(vertics, 0, sizeof(Vertices<T>) * VerticesNum);
		memset(edge, 0, sizeof(Edge<T>) * EdgeNum);
		VerCount = 0;
		EdgeCount = 0;
		VisitedOrNot = 0;
	}

	~Grapgh() {
		free(vertics);
		free(edge);
	}

	void AddVertices(Vertices<T> &v){
		if (VerCount < VerticesNum)
			vertics[VerCount++] = v;
		else
			cout << "����������" << endl;
	}

	void AddEdge(Edge<T> &e) {
		if (EdgeCount < EdgeNum)
			edge[EdgeCount++] = e;
		else
			cout << "������������" << endl;
	}

	void ConectEdgeAndVertices();

	//����
	void Zeroing(){
		for (int i = 0; i < VerticesNum; i++)
			vertics[i].flag = Unvisited;
		VisitedOrNot = 0;
	}

	//�ݹ�
	void DFS(Grapgh<T> & G, int v);
	//�ǵݹ�
	void DFS(int v);

	//��ȱ���
	void BFS(int v);

	//Prim�㷨
	void Prim(int v);

	//Kruskal�㷨
	void Kruskal(int v);

	//Dijkstra�㷨
	void Dijkstra(int v);

	//Floyd�㷨
	void Floyd(int v);
};

template <class T>
void Grapgh<T>::Floyd(int v)
{
	//������ά����
	int **Adj = NULL;
	Adj = new int*[VerticesNum];
	for (int i = 0; i < VerticesNum; i++)
		Adj[i] = new int[VerticesNum];
	int **Path = NULL;
	Path = new int*[VerticesNum];
	for (int i = 0; i < VerticesNum; i++)
		Path[i] = new int[VerticesNum];

	for (int i = 0; i < VerticesNum; i++)
		for (int j = 0; j < VerticesNum; j++)
			Adj[i][j] = INF;

	//��ʼ��Adj�����Path����
	for (int i = 0; i < EdgeNum; i++)
	{
		Adj[edge[i].tailvex - 1][edge[i].headvex - 1] = edge[i].arcinfo;
	}
	for (int i = 0; i < VerticesNum; i++)
		Adj[i][i] = 0;

	for (int i = 0; i < VerticesNum; i++)
		for (int j = 0; j < VerticesNum; j++)
			Path[i][j] = i + 1;

	//���м���

	for (int k = 0; k < VerticesNum; k++)
		for (int i = 0; i < VerticesNum; i++)
			for (int j = 0; j < VerticesNum; j++)
				if (Adj[i][j] > Adj[i][k] + Adj[k][j])
				{
					Adj[i][j] = Adj[i][k] + Adj[k][j];
					Path[i][j] = Path[k][j];
				}


	//���

	for (int i = 0; i < VerticesNum; i++)
	{
		for (int j = 0; j < VerticesNum; j++)
			cout << Adj[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < VerticesNum; i++)
	{
		for (int j = 0; j < VerticesNum; j++)
			cout << Path[i][j] << "  ";
		cout << endl;
	}

	for (int i = 0; i < VerticesNum; i++)
		delete[] Adj[i];
	delete[]Adj;

	for (int i = 0; i < VerticesNum; i++)
		delete[]Path[i];
	delete[]Path;
}

template <class T>
void Grapgh<T>::Dijkstra(int v)
{
	//����һ�����鴢�����·��
	int k = 0; //k������ʾ��ǰ���ڽڵ��λ��
	int min = 0;   //������Сֵ���±�
	int Min = INF;
	Edge<T> *EdgeTemp = NULL;
	int *temp = NULL;
	int *ShortestPath = NULL;
	int *Visit = NULL;
	int *Next = NULL;
	ShortestPath = new int[VerticesNum];
	temp = new int[VerticesNum];
	Visit = new int[VerticesNum];
	Next = new int[VerticesNum];
	for (int i = 0; i < VerticesNum; i++)
		if (i != v)
		{
			ShortestPath[i] = INF;
			temp[i] = INF;
			Visit[i] = Unvisited;
			Next[i] = INF;
		}

	k = v;
	//ÿ�����һ������
	for (int i = 0; i < VerticesNum - 1; i++)
	{
		//��һ������ֱ�����
		if (k == v)
		{
			EdgeTemp = vertics[k].FirstOut;
			while (EdgeTemp)
			{
				temp[EdgeTemp->headvex] = EdgeTemp->arcinfo;
				EdgeTemp = EdgeTemp->tnext;
			}
		}
		else
		{
			//����ڵ���Ҫ�Ƚ�
			EdgeTemp = vertics[k].FirstOut;
			for (int i = 0; i < VerticesNum; i++)
				Next[i] = INF;

			while (EdgeTemp)
			{
				Next[EdgeTemp->headvex] = EdgeTemp->arcinfo;
				EdgeTemp = EdgeTemp->tnext;
			}
			for (int i = 0; i < VerticesNum; i++)
			{
				if (temp[i] > Next[i] + temp[k])
					temp[i] = Next[i] + temp[k];
			}

		}

		//�������·������
		for (int i = 0; i < VerticesNum; i++)
			if (temp[i] < Min && Visit[i] == Unvisited)
			{
				Min = temp[i];
				min = i;
			}
		ShortestPath[min] = temp[min];
		Visit[min] = Visited;
		k = min;
		Min = INF;
	}

	for (int i = 0; i < VerticesNum; i++)
		if (i != v)
			if (ShortestPath[i] == INF)
				cout << i << ' ' << "������" << endl;
			else
				cout << i << ' ' << ShortestPath[i] << endl;

	delete[]temp;
	delete[]ShortestPath;
	delete[]Next;
	delete[]Visit;
}

template <class T>
void Grapgh<T>::Kruskal(int v)
{
	//�����ĸ�����
	int EdgeI = 0, min = 100, temp = 0;     //���浱ǰ�ı߽ڵ�
	int k = 0;
	T *root = NULL;            //��ʾ��ǰ�ڵ�ĸ��ڵ�
	int *next = NULL;          //��ʾ��ǰ�ڵ����һ���ڵ�
	int *lenth = NULL;         //�����ܹ��ĳ���
	Edge<T> *KruskalEdge = NULL;
	int *Visit = NULL;

	KruskalEdge = new Edge<T>[VerticesNum - 1];
	root = new T[VerticesNum];
	next = new int[VerticesNum];
	lenth = new int[VerticesNum];
	Visit = new int[EdgeNum];
	
	//��ʼ��
	for (int i = 0; i < VerticesNum; i++)
	{
		root[i] = i;
		next[i] = i;
		lenth[i] = 1;
	}
	for (int i = 0; i < EdgeNum; i++)
		Visit[i] = Unvisited;
	memset(KruskalEdge, 0, sizeof(KruskalEdge));

	//��� VerticesNum - 1 ����
	for (int i = 0; i < VerticesNum - 1; i++)
	{
		for (int j = 0; j < EdgeNum; j++)
		{
			if ((min > edge[j].arcinfo) && (Visit[j] == Unvisited))
			{
				min = edge[j].arcinfo;
				temp = j;
			}
		}
		
		//���м���
		{
			Visit[temp] = Visited;
			for (int i = 0; i < EdgeNum; i++)
				if (edge[i].headvex == edge[temp].tailvex && edge[i].tailvex == edge[temp].headvex)
					Visit[i] = Visited;
			KruskalEdge[EdgeI++] = edge[temp];
			min = 100;
			if (lenth[edge[temp].headvex - 1] > lenth[edge[temp].tailvex - 1])
			{
				//��ӵ�����
				SWap(next[edge[temp].headvex - 1], next[edge[temp].tailvex - 1]);
				lenth[edge[temp].headvex - 1] += lenth[edge[temp].tailvex - 1];
				k = next[edge[temp].headvex - 1];
				do {
					root[k] = edge[temp].headvex - 1;
					k = next[k];
				} while (k != edge[temp].headvex - 1);
			}
			else
			{
				SWap(next[edge[temp].headvex - 1], next[edge[temp].tailvex - 1]);
				lenth[edge[temp].tailvex - 1] += lenth[edge[temp].headvex - 1];
				k = next[edge[temp].tailvex - 1];
				do {
					root[k] = edge[temp].tailvex - 1;
					k = next[k];
				} while (k != root[edge[temp].tailvex - 1]);
			}
			temp = 0;
		}

		cout << KruskalEdge[EdgeI - 1].tailvex << "��" << KruskalEdge[EdgeI - 1].headvex << "ȨֵΪ" << KruskalEdge[EdgeI - 1].arcinfo << "�Ľڵ㡣";
		cout << endl;
	}

	

	delete[]root;
	delete[]next;
	delete[]lenth;
	delete[]KruskalEdge;
	delete[]Visit;
}

template <class T>
void Grapgh<T>::Prim(int v)
{
	//��������ı�����Ͷ������鲢��ʼ��
	int min = 100, temp = 0;//temp���浱ǰ�ı������λ��
	int flag = 0;//�ж��Ƿ���������
	int place = headvex;      //�õ���ͷ����β
	int k = headvex;
	int EdgeI = 0, VerticesI = 0;         //��¼����ı����Ͷ�����
	Edge<T> *PrimEdge = NULL;
	Vertices<T> *PrimVertices = NULL;
	PrimEdge = new Edge<T>[VerticesNum - 1];
	PrimVertices = new Vertices<T>[VerticesNum];
	memset(PrimEdge, 0, sizeof(PrimEdge));
	memset(PrimVertices, 0, sizeof(PrimVertices));

	//��ӵ�һ���ڵ�
	PrimVertices[VerticesI++] = vertics[v];

	//��ӱߵ�������
	for (int i = 0; i < VerticesNum - 1; i++)
	{
		//������СȨ�صı�
		for (int j = 0; j < EdgeCount; j++)
		{
			if (min > edge[j].arcinfo)
			{
				//�ж��Ƿ�������������
				for (int m = 0; m < VerticesI; m++)
					if (edge[j].headvex == PrimVertices[m].vexinfo || edge[j].tailvex == PrimVertices[m].vexinfo)
					{
						flag += 1;
						if (edge[j].headvex == PrimVertices[m].vexinfo)
							place = tailvex;
						else
							place = headvex;
					}
				//flag = 2ʱ����ʾ�������㶼��������
				//flag = 1ʱ����ʾֻ��һ������������
				if (flag >= 2)
					flag = 0;
				if(flag == 1)
				{
					min = edge[j].arcinfo;
					temp = j;
					flag = 0;
					k = place;
				}
			}
		}
		//�����ڵ�
		if (k == headvex)
			PrimVertices[VerticesI++] = vertics[edge[temp].headvex - 1];
		else
			PrimVertices[VerticesI++] = vertics[edge[temp].tailvex - 1];
		min = 100;
		edge[EdgeI++] = edge[temp];

		for (int i = 0; i < VerticesI; i++)
			cout << PrimVertices[i].vexinfo << ' ';
		cout << "            ";
	}
	cout << endl;
	delete[]PrimEdge;
	delete[]PrimVertices;
}

template <class T>
void Grapgh<T>::BFS(int v)
{
	VerCount = 1;
	int Judge = 0;
	queue<Vertices<T>*> VerticeQueqe;
	vertics[v].flag = Visited;
	Edge<T> *Etemp = NULL, *Ktemp = NULL;
	Vertices<T> *temp = NULL;
	cout << vertics[v].vexinfo << endl;
	Etemp = vertics[v].FirstOut;
	do
	{
		if (Etemp)
		{
			if (vertics[Etemp->headvex - 1].flag == Unvisited)
			{
				vertics[Etemp->headvex - 1].flag = Visited;
				cout << vertics[Etemp->headvex - 1].vexinfo << ' ';
				VerCount++;
				VerticeQueqe.push(&vertics[Etemp->headvex - 1]);
				Etemp = Etemp->GetTnext();
			}
			else
				Etemp = Etemp->GetTnext();
		}
		else
		{
			temp = VerticeQueqe.front();
			Etemp = temp->FirstOut;
			VerticeQueqe.pop();
			
			Ktemp = Etemp;
			while (Ktemp)
			{
				if (vertics[Ktemp->tailvex - 1].flag == Unvisited)
				{
					Judge = 1;
					Ktemp = Ktemp->tnext;
				}
				else
					Ktemp = Ktemp->tnext;
			}
			if (Judge == 0 && VerCount < VerticesNum)
				cout << endl;
			else
				Judge = 0;
			
		}


	} while (!VerticeQueqe.empty());
	cout << endl;
	VerCount = 0;
	Zeroing();
}

template <class T>
void Grapgh<T>::DFS(int v)
{
	stack<Vertices<T>*> VerticeStack;
	vertics[v].flag = Visited;
	Edge<T> *Etemp = NULL;
	Vertices<T> *temp = NULL;
	cout << vertics[v].vexinfo << ' ';
	Etemp = vertics[v].FirstOut;
	do
	{
		if (Etemp)
		{
			if (vertics[Etemp->headvex - 1].flag == Unvisited)
			{
				vertics[Etemp->headvex - 1].flag = Visited;
				cout << vertics[Etemp->headvex - 1].vexinfo << ' ';
				Etemp = vertics[Etemp->headvex - 1].FirstOut;
				if (Etemp)
					VerticeStack.push(&vertics[Etemp->tailvex - 1]);
			}
			else
				Etemp = Etemp->GetTnext();
		}
		else
		{
			temp = VerticeStack.top();
			Etemp = temp->FirstOut;
			VerticeStack.pop();
		}
	} while (!VerticeStack.empty());
	cout << endl;
	Zeroing();
}

template <class T>
void Grapgh<T>::DFS(Grapgh<T> &G, int v)
{
	G.vertics[v].flag = Visited;         	// �����λ����ΪVISITED
	VisitedOrNot += 1;
	cout << G.vertics[v].vexinfo << ' ';
	for (Edge<T> *e = G.vertics[v].FirstOut; VisitedOrNot < G.VerticesNum; e = G.vertics[G.vertics[v].FirstOut->headvex].FirstOut)
		if (G.vertics[e->tailvex].flag == Unvisited)
			DFS(G, e->tailvex);
}

template <class T>
void Grapgh<T>::ConectEdgeAndVertices()
{
	if (vertics && edge)
	{
		int j = 0;  //��¼���������λ��

		//���ȹ��춥�ĵ�һ�������ڵ�
		for (int i = 0; i < EdgeCount; i++)
		{
			if (edge[i].tailvex == vertics[j].vexinfo)
			{
				vertics[j++].FirstOut = &edge[i];
				continue;
			}
			if (j >= VerCount)
				break;
		}
		j = 0;
		//���춥�ĵ�һ���뻡�ڵ�
		for (int i = 0; i < EdgeCount; i++)
		{
			if (edge[i].headvex == vertics[j].vexinfo)
			{
				vertics[j++].FirstIn = &edge[i];
				continue;
			}
			if (j >= VerCount)
				break;
		}

		//������������������
		Edge<T> *current = NULL;
		j = 0;
		while (j < VerCount)
		{
			current = vertics[j++].FirstOut;
			if (current)
			{
				current->tnext = NULL;
				for (int i = 0; i < EdgeCount; i++)
					if (edge[i].tailvex == current->tailvex && (&edge[i] != current))
					{
						current->tnext = &edge[i];
						current = current->tnext;
						current->tnext = NULL;
					}
			}
		}

		//�������뻡��������
		j = 0;
		while (j < VerCount)
		{
			current = vertics[j++].FirstIn;
			if (current)
			{
				current->hnext = NULL;
				for (int i = 0; i < EdgeCount; i++)
					if (edge[i].headvex == current->headvex && (&edge[i] != current))
					{
						current->hnext = &edge[i];
						current = current->hnext;
						current->hnext = NULL;
					}
			}
		}
	}
}

void BuildGraph()
{
	int VerticesCount = 6, EdgeCount = 20;  //��¼�Ѿ����������
	Grapgh<int> graph(VerticesCount, EdgeCount);

	//Prim�㷨��Kruskal�㷨����
	/*{
		//�����㼯��
		{
			//��������ļ���
			Vertices<int> v1(1);
			Vertices<int> v2(2);
			Vertices<int> v3(3);
			Vertices<int> v4(4);
			Vertices<int> v5(5);
			Vertices<int> v6(6);
			//���
			graph.AddVertices(v1);
			graph.AddVertices(v2);
			graph.AddVertices(v3);
			graph.AddVertices(v4);
			graph.AddVertices(v5);
			graph.AddVertices(v6);
		}

		//����߼���
		{
			//�����
			Edge<int> e1(1, 2, 6, NULL, NULL);
			Edge<int> e2(1, 3, 1, NULL, NULL);
			Edge<int> e3(1, 4, 5, NULL, NULL);
			Edge<int> e4(2, 1, 6, NULL, NULL);
			Edge<int> e5(2, 3, 5, NULL, NULL);
			Edge<int> e6(2, 5, 3, NULL, NULL);
			Edge<int> e7(3, 1, 1, NULL, NULL);
			Edge<int> e8(3, 2, 5, NULL, NULL);
			Edge<int> e9(3, 4, 5, NULL, NULL);
			Edge<int> e10(3, 5, 6, NULL, NULL);
			Edge<int> e11(3, 6, 4, NULL, NULL);
			Edge<int> e12(4, 1, 5, NULL, NULL);
			Edge<int> e13(4, 3, 5, NULL, NULL);
			Edge<int> e14(4, 6, 2, NULL, NULL);
			Edge<int> e15(5, 2, 3, NULL, NULL);
			Edge<int> e16(5, 3, 6, NULL, NULL);
			Edge<int> e17(5, 6, 6, NULL, NULL);
			Edge<int> e18(6, 3, 4, NULL, NULL);
			Edge<int> e19(6, 4, 2, NULL, NULL);
			Edge<int> e20(6, 5, 6, NULL, NULL);

			//����ͼ
			graph.AddEdge(e1);
			graph.AddEdge(e2);
			graph.AddEdge(e3);
			graph.AddEdge(e4);
			graph.AddEdge(e5);
			graph.AddEdge(e6);
			graph.AddEdge(e7);
			graph.AddEdge(e8);
			graph.AddEdge(e9);
			graph.AddEdge(e10);
			graph.AddEdge(e11);
			graph.AddEdge(e12);
			graph.AddEdge(e13);
			graph.AddEdge(e14);
			graph.AddEdge(e15);
			graph.AddEdge(e16);
			graph.AddEdge(e17);
			graph.AddEdge(e18);
			graph.AddEdge(e19);
			graph.AddEdge(e20);

		}
	}*/
	

	//Dijkstra�㷨����
	/*
	{
		//�����㼯��
		{
			//��������ļ���
			Vertices<int> v0(0);
			Vertices<int> v1(1);
			Vertices<int> v2(2);
			Vertices<int> v3(3);
			Vertices<int> v4(4);
			Vertices<int> v5(5);
			//���
			graph.AddVertices(v0);
			graph.AddVertices(v1);
			graph.AddVertices(v2);
			graph.AddVertices(v3);
			graph.AddVertices(v4);
			graph.AddVertices(v5);

		}

		//�����߼���
		{
			//�����
			Edge<int> e1(0, 2, 10, NULL, NULL);
			Edge<int> e2(0, 4, 30, NULL, NULL);
			Edge<int> e3(0, 5, 100, NULL, NULL);
			Edge<int> e4(1, 2, 5, NULL, NULL);
			Edge<int> e5(2, 3, 50, NULL, NULL);
			Edge<int> e6(3, 5, 10, NULL, NULL);
			Edge<int> e7(4, 3, 20, NULL, NULL);
			Edge<int> e8(4, 5, 60, NULL, NULL);

			//�����
			graph.AddEdge(e1);
			graph.AddEdge(e2);
			graph.AddEdge(e3);
			graph.AddEdge(e4);
			graph.AddEdge(e5);
			graph.AddEdge(e6);
			graph.AddEdge(e7);
			graph.AddEdge(e8);
		}
	}
	*/
	

	//Floyd�㷨����
	/*{
		//�����㼯��
		{
			//��������ļ���
			Vertices<int> v1(1);
			Vertices<int> v2(2);
			Vertices<int> v3(3);
			Vertices<int> v4(4);
			//���
			graph.AddVertices(v1);
			graph.AddVertices(v2);
			graph.AddVertices(v3);
			graph.AddVertices(v4);
		}

		//�����ߵļ���
		{
			//�����
			Edge<int> e1(1, 2, 10, NULL, NULL);
			Edge<int> e2(1, 3, 5, NULL, NULL);
			Edge<int> e3(1, 4, 1, NULL, NULL);
			Edge<int> e4(2, 1, 9, NULL, NULL);
			Edge<int> e5(2, 3, 6, NULL, NULL);
			Edge<int> e6(2, 4, 15, NULL, NULL);
			Edge<int> e7(3, 1, 2, NULL, NULL);
			Edge<int> e8(3, 2, 13, NULL, NULL);
			Edge<int> e9(3, 4, 15, NULL, NULL);
			Edge<int> e10(4, 1, 11, NULL, NULL);
			Edge<int> e11(4, 2, 12, NULL, NULL);
			Edge<int> e12(4, 3, 7, NULL, NULL);
			//��ӱ�
			graph.AddEdge(e1);
			graph.AddEdge(e2);
			graph.AddEdge(e3);
			graph.AddEdge(e4);
			graph.AddEdge(e5);
			graph.AddEdge(e6);
			graph.AddEdge(e7);
			graph.AddEdge(e8);
			graph.AddEdge(e9);
			graph.AddEdge(e10);
			graph.AddEdge(e11);
			graph.AddEdge(e12);

		}
	}
	*/


	//�߼��Ϻ͵㼯����������
	graph.ConectEdgeAndVertices();
	
	//graph.Prim(0);

	//graph.Kruskal(0);

	//graph.Dijkstra(0);

	//graph.Floyd(0);
}

#endif // !_GRAPH_H_
