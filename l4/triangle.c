#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point {
	double x;
	double y;
} point_t;

typedef struct triangle {
	point_t vertA;
	point_t vertB;
	point_t vertC;
} triangle_t;

double len(point_t p1, point_t p2) {
	double delta_x = p1.x - p2.x;
	double delta_y = p1.y - p2.y;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

double getPerimeter(const triangle_t * tr) {
	double sideA = len(tr->vertB, tr->vertC);
	double sideB = len(tr->vertA, tr->vertC);
	double sideC = len(tr->vertA, tr->vertB);
	return sideA + sideB + sideC;
}

double getArea(const triangle_t * tr) {
	double sideA = len(tr->vertB, tr->vertC);
	double sideB = len(tr->vertA, tr->vertC);
	double sideC = len(tr->vertA, tr->vertB);
	double semiPerimeter = getPerimeter(tr)/2;
	return sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
}

triangle_t* readFileForTriangles(FILE* input, int size) {
	double num1 = 0;
	double num2 = 0;
	triangle_t* result = (triangle_t*) malloc(size * sizeof(triangle_t));
	for (int i = 0; i < size; ++i) {
		point_t points[3];
		for (int j = 0; j < 3; j++) {
			fscanf(input,"%lf", &num1);
			fscanf(input,"%lf", &num2);
			points[j].x = num1;
			points[j].y = num2;
		}
		result[i].vertA = points[0];
		result[i].vertB = points[1];
		result[i].vertC = points[2];
	}
	return result;
}

void writeDataToFile(FILE* output, triangle_t* triangles, int size) {
	for (int i = 0; i < size; ++i) {
		fprintf(output, "%f %f\n", getArea(&triangles[i]),getPerimeter(&triangles[i]));
	}
}

int main(int argc, char** argv) {
	if (argc < 4) {
		printf("not enough arguments");
		return 1;
	}
	char* inputName = argv[1];
	char* outputName = argv[2];
	int size = atoi(argv[3]);
	
	FILE* input = fopen(inputName, "r");
	FILE* output = fopen(outputName, "w");
	
	if (input == NULL || output == NULL) {
		printf("can't open file");
		return 2;
	}
	
	triangle_t * triangles = readFileForTriangles(input, size);
	writeDataToFile(output, triangles, size);
	printf("triangle size = %ld", sizeof(triangle_t));
	printf("triangle* size = %ld", sizeof(triangle_t*));
	free(triangles);
	fclose(input);
	fclose(output);
	return 0;
}