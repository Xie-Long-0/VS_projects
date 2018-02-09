#ifndef TOPOLOGYSORT_H_
#define TOPOLOGYSORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCSIZE 64
typedef char VertexType;

//�ڽӱ��б��Ӧ������Ķ���
typedef struct _Enode
{
    int adjvex;                 //�ñ���ָ��Ķ����λ��
    struct _Enode *next_edge;   //ָ����һ����
} Enode;

//�ڽӱ��б�Ķ���
typedef struct _Vnode
{
    int indegree;               //�������
    VertexType data[MAXCSIZE];  //������Ϣ
    Enode *first_edge;          //ָ���һ�������ö���Ļ�
} Vnode;

//�ڽӱ�
typedef struct _LGraph
{
    int vexnum;         //������
    int edgenum;        //����
    Vnode *Vexs;        //����
}LGraph;

void CreateLGraph(LGraph *G);
int VexLocate(LGraph *G, VertexType e[]);
void Topo_Sort(LGraph *G);
void PrintLgraph(LGraph *G);

#endif // TOPOLOGYSORT_H_
