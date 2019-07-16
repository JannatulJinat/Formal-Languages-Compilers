//Remove the comments and extra white space from a source program
#include<stdio.h>
int main()
{
    FILE *inFile,*outFile;
    char c;
    int lineNum=1;
    inFile=fopen("input.c","r");
    outFile=fopen("output1.txt","w");

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
            //to remove tab
            else if(c=='\t')
            {
		
			}
            
            //to remove newline
            else if(c=='\n')
            {
				fputc(' ',outFile);
			}
            else
            {
                fputc(c,outFile);
            }
        }
    }
    fclose(inFile);
    fclose(outFile);
    
 	inFile=fopen("output1.txt","r");
    outFile=fopen("output2.txt","w");
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
				fputc(' ',outFile);
				fputc(c,outFile);
				
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
    outFile=fopen("output2.txt","r");
    while((c=fgetc(outFile))!=EOF)
    {
        printf("%c",c);
    }
    fclose(outFile);
    return 0;
}

