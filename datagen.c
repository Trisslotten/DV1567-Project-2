#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("ERROR: wrong arg count\n");
		return 1;
	}
	int size = atoi(argv[1]);
	if (size <= 0)
	{
		printf("ERROR: size needs to be larger than 0\n");
		return 1;
	}
	char* filename = argv[2];

	float* data = malloc(sizeof(float) * size);

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		data[i] = rand()/(float)RAND_MAX;
	}

	FILE *file = fopen(filename, "w");
	fwrite(data, size, sizeof(float), file);
	fclose(file);

	return 0;
}
