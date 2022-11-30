#include "reverse_print_array.h"

int ReversePrintArray(int a[10])
{
	for (int i = 9; i >= 0; i--) {
		printf("%d ", a[i]);
	}
	return 0;
}