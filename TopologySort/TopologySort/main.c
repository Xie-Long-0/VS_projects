#include "TopologySort.h"

int main()
{
    LGraph G;
    CreateLGraph(&G);
	Topo_Sort(&G);
	getchar();
    return 0;
}
