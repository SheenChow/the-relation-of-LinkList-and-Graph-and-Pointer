
	1. “如果传递的参数在函数执行过程中会被改变值，那么应当传递这个参数的地址（比如增、删、创建）；而对于那些不会改变参数值的操作（比如，查找、遍历）则传递这个参数值就可以了”
	2. 链表的存储结构
		1. typedef struct Node {
             ElemType data;
             struct Node *next;
          } LNode, *LinkList;

      创建链表的时候是这样写的，InitList（LinkList *L）{}

	3. 图（邻接法）存储结构

		1.   typedef struct {
              /*顶点表*/
              VertexType vexs[MAXVEX];
              /*邻接矩阵，可以看作表*/
               EdgeType arc[MAXVEX][MAXVEX];
               int numVertex, numEdges;
            } MGraph;

    在创建图时，函数是这样写的，CreateMGraph（MGraph *G）{}


单看函数，是满足第一条规则的;
不过我一直很奇怪为什么LinkList本身就是指针类型的了，后续还要用LinkList *L。
今天好像想明白了一点：这个差异是因为链表与图的性质引起的:
   链表有很多结点，而几乎所有的操作都会涉及到从一个结点到另一个结点，这时候用指针来指向结点更加方便处理移动问题.

比如，用指针的时候处理结点的删除操作时，可以p->next = p->next->next,而且这时候p与next都是指向结点的指针，风格保持统一。
   而如果直接用Node类型的变量来表示头结点，此时应该写成p.next = (*(p.next) ).next 或者 p.next =（p.next）->next，
   而这两种风格都不统一，操作起来需要来回转换指针和非指针;
   或者把next也改变成Node类型的变量，但是这个时候无法直接用Node类型来定义next，详情参见 结构体的嵌套问题 
     http://www.cnblogs.com/renyuan/archive/2012/11/30/2796792.html
