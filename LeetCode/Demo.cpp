#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <fstream>  
#include <algorithm>
#include "SingleList.h"

std::stack<int> input, output;
void push(int x) {
	input.push(x);
}

/** Removes the element from in front of queue and returns that element. */
void pop() {
	//peek();
	output.pop();
}

/** Get the front element. */
int peek() {
	if(output.empty())
		while (input.size())
		{
			output.push(input.top()), input.pop();
		}
	return output.top();
}

/** Returns whether the queue is empty. */
bool empty() {
	return input.empty() && output.empty();
}

int rangeBitwiseAnd(int m, int n) {
	if (m == n)
		return m;
	else
		return rangeBitwiseAnd(m / 2, n / 2) << 1;
}

int countPrimes(int n) {
	if (n < 2)
		return 0;
	int sum = 1;
	std::vector<int>  ivec(n + 1, 0);
	int dataVal = sqrt(n);
	for (int i = 3; i <= n; i++) {
		if (!ivec[i]) {
			++sum;
			//if()
		}
	}
	return sum;
}

float c(float x, float y, float r, float p)
{ return powf(powf(fabsf(x), p) + powf(fabsf(y), p), 1 / p) - r; }

int f(float x, float y) {
	float a = fmaxf(c(x, y, 15, 2), c(x, y + 25, 30, 2)), b = c(x, y - 7, 10, 4);
	if (a < -1) // cap pattern 
		return c(fmodf(x + 20 + 3 * floorf((y + 20) / 6), 6) - 3, fmodf(y + 20, 6) - 3, 2, 2) >= 0; 
	else if (a < 0.0f) // cap 
		return 1; 
	else if (b < -2) // face
		return c(fabsf(x) - 2.5f, y - 7.5f, 1.25f, 2) < 0 || (y > 10 && fabsf(c(x, y - 9, 4, 2)) < 0.5f); 
	else // body 
		return b < 0;
} 

#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型
typedef enum { DG, DN, UDG, UDN }GraphKind;       //枚举图的 4 种类型
typedef struct {
	VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
	InfoType * info;                        //弧或边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
	AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
	int vexnum, arcnum;                      //记录图的顶点数和弧（边）数
	GraphKind kind;                         //记录图的种类
}MGraph;
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G, VertexType v) {
	int i = 0;
	//遍历一维数组，找到变量v
	for (; i<G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	//如果找不到，输出提示语句，返回-1
	if (i>G->vexnum) {
		printf("no such vertex.\n");
		return -1;
	}
	return i;
}
//构造有向图
void CreateDG(MGraph *G) {
	//输入图含有的顶点数和弧的个数
	std::cin >> G->vexnum >> G->arcnum;
	//scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	//依次输入顶点本身的数据
	for (int i = 0; i<G->vexnum; i++) {
		std::cin >> G->vexs[i];
		//scanf("%d", &(G->vexs[i]));
	}
	//初始化二维矩阵，全部归0，指针指向nullptr
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = nullptr;
		}
	}
	//在二维数组中添加弧的数据
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2;
		//输入弧头和弧尾
		std::cin >> v1 >> v2;
		//scanf("%d,%d", &v1, &v2);
		//确定顶点位置
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		//排除错误数据
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		//将正确的弧的数据加入二维数组
		G->arcs[n][m].adj = 1;
	}
}
//构造无向图
void CreateDN(MGraph *G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = nullptr;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2;
		scanf_s("%d,%d", &v1, &v2);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = 1;
		G->arcs[m][n].adj = 1;//无向图的二阶矩阵沿主对角线对称
	}
}
//构造有向网，和有向图不同的是二阶矩阵中存储的是权值。
void CreateUDG(MGraph *G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = nullptr;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2, w;
		scanf_s("%d,%d,%d", &v1, &v2, &w);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = w;
	}
}
//构造无向网。和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph* G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = nullptr;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2, w;
		scanf_s("%d,%d,%d", &v1, &v2, &w);
		int m = LocateVex(G, v1);
		int n = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = w;
		G->arcs[m][n].adj = w;//矩阵对称
	}
}
void CreateGraph(MGraph *G) {
	//选择图的类型
	scanf_s("%d", &(G->kind));
	//根据所选类型，调用不同的函数实现构造图的功能
	switch (G->kind) {
	case DG:
		return CreateDG(G);
		break;
	case DN:
		return CreateDN(G);
		break;
	case UDG:
		return CreateUDG(G);
		break;
	case UDN:
		return CreateUDN(G);
		break;
	default:
		break;
	}
}
//输出函数
void PrintGrapth(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void TestGraph() {
	MGraph G;//建立一个图的变量
	CreateGraph(&G);//调用创建函数，传入地址参数
	PrintGrapth(G);//输出图的二阶矩阵
}

#define N 5
int maze[N][N] = {
{ 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0 },
{ 0, 1, 1, 1, 0 },
{ 1, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0 }
};
int visited[N + 1] = { 0, };
void BFS(int start)
{
	std::queue<int> Q;
	Q.push(start);
	visited[start] = 1;
	while (!Q.empty())
	{
		int front = Q.front();
		std::cout << front << " ";
		Q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && maze[front - 1][i - 1] == 1)
			{
				visited[i] = 1;
				Q.push(i);
			}
		}
	}
}

int TestBFS() {
	BFS(1);
	getchar();
	return 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		BFS(i);
	}
	getchar();
	return 0;
}