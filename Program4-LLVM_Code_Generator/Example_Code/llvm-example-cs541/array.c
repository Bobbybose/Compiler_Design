#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	float sum = 0.3;
	int i;

	for (i = 1; i < argc; ++i) {
		sum += strtol(argv[i], NULL, 10);
	}

	printf("sum = %f\n", sum);
	return 0;
}
