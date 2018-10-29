#include <stdio.h>


int main(int argc, char* argv[])
{
	if(argc != 5)
	{
		printf("ERROR: Need 4 arguments, got %d\n", argc-1);
		return 1;
	}

	int datasetSize = atoi(argv[1]);
	int bufferSize = atoi(argv[2]);
	char* datasetFilename = argv[3];
	char* outputFilename = argv[4];

	if(datasetSize <= 0 || bufferSize <= 0)
	{
		printf("ERROR: sizes need to be larger than 0\n");
		return 1;
	}

	float* dataset = loadDataset(datasetSize, bufferSize);

	float avg = average(dataset, datasetSize);
	float max = maxValue(dataset, datasetSize);
	float min = minValue(dataset, datasetSize);

	float* sortedDataset = insertionSort(dataset, datasetSize);

	writeDataset(outputFilename, sortedDataset, bufferSize, avg, min, max);

	free(dataset);
	free(sortedDataset);

	return 0;
}
