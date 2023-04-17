#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int num = 0;
	if (argc > 1) {
		num = strtol(argv[1], NULL, 10);
	}
	num = (num + 10) * 3;
	printf("hello, %d\n", num);
	return 0;
}
