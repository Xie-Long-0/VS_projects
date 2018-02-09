#ifndef TOPOLOGYSORT_H_
#define TOPOLOGYSORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCSIZE 64
typedef char VertexType;

//邻接表中表对应的链表的顶点
typedef struct _Enode
{
    int adjvex;                 //该边所指向的顶点的位置
    struct _Enode *next_edge;   //指向下一条弧
} Enode;

//邻接表中表的顶点
typedef struct _Vnode
{
    int indegree;               //顶点入度
    VertexType data[MAXCSIZE];  //顶点信息
    Enode *first_edge;          //指向第一条依附该顶点的弧
} Vnode;

//邻接表
typedef struct _LGraph
{
    int vexnum;         //顶点数
    int edgenum;        //边数
    Vnode *Vexs;        //顶点
}LGraph;

void CreateLGraph(LGraph *G);
int VexLocate(LGraph *G, VertexType e[]);
void Topo_Sort(LGraph *G);
void PrintLgraph(LGraph *G);

#endif // TOPOLOGYSORT_H_
