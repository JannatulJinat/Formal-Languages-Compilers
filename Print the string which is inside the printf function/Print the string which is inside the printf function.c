#include<stdio.h>
int main()
{
    FILE *inFile,*outFile;
    char c;

    inFile=fopen("input.c","r");
    outFile=fopen("Ouput1.txt","w");
    if(!inFile)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(inFile))!=EOF)
        {
            //remove extra whitespace
            if(c==' ')
            {
                while(c==' ')
                {
                    c=fgetc(inFile);

                }
                //fputc(' ',outFile);
                fputc(c,outFile);

            }
            else if(c=='\n')
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


    inFile=fopen("Ouput1.txt","r");
    outFile=fopen("Ouput2.txt","w");

    if(!inFile)
        printf("File can't be opened");
    else
    {
        while((c=fgetc(inFile))!=EOF)
        {
            if(c=='p')
            {

                c=fgetc(inFile);
                if(c=='r')
                {
                    c=fgetc(inFile);
                    if(c=='i')
                    {
                        c=fgetc(inFile);
                        if(c=='n')
                        {
                            c=fgetc(inFile);
                            if(c=='t')
                            {
                                c=fgetc(inFile);
                                if(c=='f')
                                {
                                    c=fgetc(inFile);

                                    if(c=='(')
                                    {
                                        c=fgetc(inFile);
                                        if(c=='"')
                                        {
                                            c=fgetc(inFile);
                                            while(c!='"')
                                            {
                                                fputc(c,outFile);
                                                c=fgetc(inFile);
                                            }
                                            fputc('\n',outFile);



                                        }
                                    }

                                }
                            }

                        }
                    }
                }
            }

        }
    }
    fclose(inFile);
    fclose(outFile);

    //print the output
    outFile=fopen("Ouput2.txt","r");
    while((c=fgetc(outFile))!=EOF)
    {
        printf("%c",c);
    }
    fclose(outFile);
    return 0;
}
