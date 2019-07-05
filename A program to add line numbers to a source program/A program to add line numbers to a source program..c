//a program to add line numbers to a source program.
#include<stdio.h>
int main()
{
    FILE *inFile,*outFile;
    char c;
    int lineNum=1;
    inFile=fopen("input.c","r");
    outFile=fopen("output.txt","w");

    if(!inFile)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(inFile))!=EOF)
        {
            fprintf(outFile,"%d.",lineNum);

            while((c=fgetc(inFile))!='\n')
            {
                fputc(c,outFile);
            }
            fputc('\n',outFile);
            lineNum++;
        }
    }
    fclose(inFile);
    fclose(outFile);

    outFile=fopen("output.txt","r");
    while((c=fgetc(outFile))!=EOF)
    {
        printf("%c",c);
    }
    fclose(outFile);
    return 0;
}
