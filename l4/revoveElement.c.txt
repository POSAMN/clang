#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
входной файл: первая строка содержит число N и далее N строк, на каждой слово, и символ X.
В выходном файле записать N слов в новой строке, исключив при этом все включения символа X из слова( если он присутствовал)
*/

void addToFile(char* word, FILE* output, char ch)
{
    size_t cnt =  strlen(word);
    for (size_t i = 0; i < cnt; i++)
    {
        if (word[i] != ch)
        {
            if (word[i] != ch)
                fprintf(output, "%c", word[i]);
        }
    }
}

void addInformationToFile(FILE* input, FILE* output)
{
    int cnt = 0;
    char ch;
    char* word = (char*)malloc(100);
    fscanf(input, "%d\n", &cnt);
    for (int i = 0; i < cnt; i++)
    {          
          char ch;
          fscanf(input, "%s %c\n", word, &ch );
          addToFile(word, output, ch);
    }
    free(word);
}

int main(int argc, char** argv)
{
    if (argc > 3) printf("error: get infotmation");
    
    char* inputFileName = argv[1];
    FILE* inputFile =fopen(inputFileName, "r");
    if (inputFile == NULL) 
    {
        printf("error: can not open file");
        return 4;
    }
    char* outputFileName = argv[2];
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        printf("error: can not open file");
        return 6;
    }
    addInformationToFile(inputFile, outputFile);
    
    fclose(inputFile);
    fclose(outputFile);
}
