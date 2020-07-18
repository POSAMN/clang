#include <stdio.h>
#include <stdlib.h>

typedef struct creat_mass_tre
{
    int x;
    int y;
}tre;


int main(int argc, char** argv)
{
    char* inputFileName = argv[1];
    int size = 0;
    int rows = 0;
    FILE* input = fopen(inputFileName, "r");
    if (input == NULL) 
    {
        printf("error open fail %s", inputFileName);
        return 1;
    }
    char c;
    while (!feof(input)) 
    {
        while (!feof(input) && (c = getc(input)) != '\n')//////errrrrroooorrr
        {
            printf("%c", c);
        }
		
		printf("\n!!");
//          getc(input);
	}
    char* outputFileName = argv[2];
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) 
    {
        printf("error open fail %s", outputFileName);
        return 1;
    }
    fclose(outputFile);
    tre** mass;
//     creat_mass_tre(mass, inputFileName);   

}