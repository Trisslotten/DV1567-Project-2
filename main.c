#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

float* loadDataset(char* filename, int datasetSize, int bufferSize);
void writeDataset(char* filename, float* dataset, int datasetSize, int bufferSize, float avg, float min, float max);

float average(float* dataset, int datasetSize);
float maxValue(float* dataset, int datasetSize);
float minValue(float* dataset, int datasetSize);

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

	float* dataset = loadDataset(datasetFilename, datasetSize, bufferSize);

	float avg = average(dataset, datasetSize);
	float max = maxValue(dataset, datasetSize);
	float min = minValue(dataset, datasetSize);

	for (int i = 0; i < datasetSize; i++)
	{
		printf("%f\n", dataset[i]);
	}

	float* sortedDataset = insertionSort(dataset, datasetSize);

	writeDataset(outputFilename, sortedDataset, datasetSize, bufferSize, avg, min, max);

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
float maxValue(float* dataset, int datasetSize)
{
	float max = FLT_MIN;
	for(int i = 0; i < datasetSize; i++)
	{
		if(dataset[i] > max)
		{
			max = dataset[i];
		}
	}
	return max;
}
float minValue(float* dataset, int datasetSize)
{
	float min = FLT_MAX;
	for(int i = 0; i < datasetSize; i++)
	{
		if(dataset[i] < min)
		{
			min = dataset[i];
		}
	}
	return min;
}

float* loadDataset(char* filename, int datasetSize, int bufferSize)
{
	FILE* file = fopen(filename, "r");
	float* result = malloc(sizeof(float)*datasetSize);
	for (int i = 0; i < datasetSize; i+=bufferSize)
	{
		if (i >= datasetSize - bufferSize)
		{
			bufferSize = datasetSize - i-1;
			//printf("load:\ndatasetSize = %d\nbufferSize = %d\ni = %d", datasetSize, bufferSize, i);
		}
		fread(result + i, bufferSize, sizeof(float), file);
	}
	fclose(file);
	return result;
}


void writeDataset(char* filename, float* dataset, int datasetSize, int bufferSize, float avg, float min, float max)
{
	FILE* file = fopen(filename, "w");
	float array[3] = {avg, min, max};
	fwrite(array, 3, sizeof(float), file);

	for(int i = 0; i < datasetSize; i+= bufferSize)
	{
		if (i >= datasetSize - bufferSize)
		{
			bufferSize = datasetSize - i-1;
			//printf("write:\ndatasetSize = %d\nbufferSize = %d\ni = %d", datasetSize, bufferSize, i);
		}
		fwrite(dataset + i, bufferSize, sizeof(float), file);
	}
}

float* insertionSort(float* data, int size)
{
	float* result = malloc(sizeof(float)*size);
	return result;
}
