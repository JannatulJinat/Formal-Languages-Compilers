//a program to print the header files used in a source program
#include<stdio.h>
int main()
{
    FILE *inFile,*outFile;
    char c;
    inFile=fopen("input.c","r");
    outFile=fopen("output.txt","w");

    if(!inFile)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(inFile))!=EOF)
        {
            if((c=='<'))
            {
                while((c=fgetc(inFile))!='>')
                    fputc(c,outFile);
                    fputc('\n',outFile);
            }
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
