#include "Polynomial.h"

int main()
{
	printf("建立多项式ha:\n");
	PolyList ha = Poly_make();
	printf("建立多项式hb:\n");
	PolyList hb = Poly_make();
	printf("多项式相加：\n");
	ha = Poly_merge(ha, hb);
	Poly_print(ha);
	Poly_Destroy(ha);
	getchar();
	getchar();
	return 0;
}
