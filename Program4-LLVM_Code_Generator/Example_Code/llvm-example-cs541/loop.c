#include <stdio.h>
#include <stdlib.h>

int sum = 0;

int main(int argc, char **argv) {
	int num = 5;
	int i;

	if (argc > 1) {
		num = strtol(argv[1], NULL, 10);
	}

	for (i = 0; i <= num; ++i) {
		printf("%d\n", i);
		sum += i;
	}

	printf("\\sum_i=0^%d i = %d\n", num, sum);
	return 0;
}
