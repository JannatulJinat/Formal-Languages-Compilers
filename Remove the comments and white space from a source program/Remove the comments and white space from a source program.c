//Remove the comments and white space from a source program
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
            if(c=='/')
            {
                c=fgetc(inFile);
                //single comment
                if(c=='/')
                {
                    while(c!='\n')
                    {
                        c=fgetc(inFile);
                    }
                }
                //multiple comment
                else if(c=='*')
                {
                    while((c=fgetc(inFile))!=EOF)
                    {
                        if(c=='*')
                        {
                            c=fgetc(inFile);
                            if(c=='/')
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    fputc('/',outFile);
                    fputc(c,outFile);
                }
            }
            else if(c=='\n')
            {

            }
            //to remove tab
            else if(c=='\t')
            {

			}
            //remove whitespace
            else if(c==' ')
            {

            }
            else
            {
                fputc(c,outFile);
            }
        }
    }
    fclose(inFile);
    fclose(outFile);

    //print the output
    outFile=fopen("output.txt","r");
    while((c=fgetc(outFile))!=EOF)
    {
        printf("%c",c);
    }
    fclose(outFile);
    return 0;
}
