//Extracting the sequence of occurrences of a specified character from a source program
#include<stdio.h>
int main()
{
    FILE *inFile,*outFile;
    char c;
    inFile=fopen("input.txt","r");
    outFile=fopen("output.txt","w");

    if(!inFile)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(inFile))!=EOF)
        {
            if((c=='(')||(c==')'))
            fputc(c,outFile);
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
