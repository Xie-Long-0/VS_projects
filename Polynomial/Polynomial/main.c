#include "Polynomial.h"

int main()
{
	printf("��������ʽha:\n");
	PolyList ha = Poly_make();
	printf("��������ʽhb:\n");
	PolyList hb = Poly_make();
	printf("����ʽ��ӣ�\n");
	ha = Poly_merge(ha, hb);
	Poly_print(ha);
	Poly_Destroy(ha);
	getchar();
	getchar();
	return 0;
}
