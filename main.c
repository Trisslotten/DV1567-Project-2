#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float* loadDataset(int datasetSize, bufferSize);
float* writeDataset(char* filename, float* dataset, int bufferSize, float avg, float min, float max);

float average(float* dataset, int datasetSize);
float max(float* dataset, int datasetSize);
float min(float* dataset, int datasetSize);

float* insertionSort(float* dataset, int datasetSize);


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
float average(float* dataset, int datasetSize)
{
	float avg = 0;
	for(int i = 0; i < datasetSize; i++)
	{
		avg += dataset[i];
	}
	return (avg / datasetSize);
}
float max(float* dataset, int datasetSize)
{
	int mx = INT_MIN;
	for(int i = 0; i < datasetSize; i++)
	{
		if(datasetSize[i] > mx)
		{
			mx = datasetSize[i];
		}
	}
	return max;
}
float min(float* dataset, int datasetSize)
{
	int mi = INT_MAX;
	for(int i = 0; i < datasetSize; i++)
	{
		if(datasetSize[i] < mi)
		{
			mi = datasetSize[i];
		}
	}
	return mi;
}
