#include<stdio.h>
#include<ctype.h>
#include <string.h>
#define max 20
int size =20,i,j,choice,size,count=0,k,global=1,flag,p;
FILE *inFile,*outFile;
char c,lex[20],word1[20];
struct symbolTable
{
    int no;
    char name[max];
    char type[max];
    char keyWord[max];
    char scope[max];
} ST[10];

int matchKw(char lex[size])
{
    if(strcmp(lex,"int")==0 ||strcmp(lex,"float")==0 || strcmp(lex,"double")==0 || strcmp(lex,"char")==0)
    {
        ST[count].no=count+1;

        for(k=0; k<strlen(lex); k++)
        {
            ST[count].keyWord[k]=lex[k];
        }
        flag=1;
        return flag;

    }
    else
    {
        flag=0;
        return flag;
    }
}
void st()
{
    inFile = fopen("input.txt","r");
    // outFile = fopen("o6.txt","w");
    if(!inFile)
        printf("file can't be opened");
    else
    {
        while((c=fgetc(inFile)) != EOF)
        {
            if(c=='[')
            {
                i=0;
                while((c=fgetc(inFile))!=']')
                {
                    lex[i]=c;
                    ++i;
                }
                lex[i]='\0';
                matchKw(lex);
                if(strcmp(lex,"{")==0 )
                    global=0;
                if(strcmp(lex,"}")==0 )
                    global=1;
                if(flag==0)
                {
                    continue;
                }
                c=fgetc(inFile);
                if((c=fgetc(inFile)) =='i')
                {
                    if((c=fgetc(inFile)) =='d')
                    {
                        c=fgetc(inFile);
                        i=0;
                        while((c=fgetc(inFile))!=']')
                        {
                            lex[i]=c;
                            ++i;
                        }
                        lex[i]='\0';
                        c=fgetc(inFile);
                        if((c=fgetc(inFile)) =='(')
                        {
                            strcpy(ST[count].type,"function");
                            for(k=0; k<strlen(lex); k++)
                            {
                                ST[count].name[k]=lex[k];
                            }
                            if(global==1)
                            {
                                strcpy(ST[count].scope,"global");
                                count++;
                            }
                            else
                            {
                                strcpy(ST[count].scope,"local");
                                count++;
                            }
                        }
                        else
                        {
                            strcpy(ST[count].type,"variable");
                            for(k=0; k<strlen(lex); k++)
                            {
                                ST[count].name[k]=lex[k];
                            }
                            if(global==1)
                            {
                                strcpy(ST[count].scope,"global");
                                count++;
                            }
                            else
                            {
                                strcpy(ST[count].scope,"local");
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(inFile);
    fclose(outFile);
}
void display()
{
    printf("-----------------------------------------\n");
    for(k=0; k<10; k++)
    {
        printf("%d\t%s\t%s\t%s\t%s\n",ST[k].no,ST[k].name,ST[k].keyWord,ST[k].scope,ST[k].type);
    }
}
//Step 3
void s3()
{
    int n=0;
    inFile = fopen("input.txt","r");
    outFile = fopen("S3.txt","w");
    if(!inFile)
        printf("file can't be opened");
    else
    {
        while((c=fgetc(inFile)) != EOF)
        {
            if(c=='[')
            {
                c=fgetc(inFile);
                if(c=='i')
                {
                    c=fgetc(inFile);
                    if(c=='d')
                    {
                        c=fgetc(inFile);
                        i=0;
                        while((c=fgetc(inFile))!=']')
                        {
                            lex[i]=c;
                            ++i;
                        }
                        lex[i]='\0';
                        c=fgetc(inFile);
                        c=fgetc(inFile);
                        if(c=='(')
                        {
                            strcpy(word1,"function");
                            for(p=0; p<10; p++)
                            {

                                if((strcmp(ST[p].name,lex)==0)&&(strcmp(ST[p].type,word1)==0))
                                {
                                    n=ST[p].no;
                                    break;
                                }
                            }
                            fprintf(outFile,"[id %d][(",n);

                        }
                        else
                        {
                            strcpy(word1,"variable");
                            for(p=0; p<10; p++)
                            {

                                if((strcmp(ST[p].name,lex)==0)&&(strcmp(ST[p].type,word1)==0))
                                {
                                    n=ST[p].no;
                                    break;
                                }
                            }
                            fprintf(outFile,"[id %d][%c",n,c);

                        }

                    }
                    else
                    {
                        fputc('i',outFile);
                        fputc(c,outFile);
                    }
                }
                else
                {
                    fputc('[',outFile);
                    fputc(c,outFile);
                }
            }
            else
            {
                fputc(c,outFile);
            }

        }
    }
    fclose(inFile);
    fclose(outFile);
    outFile = fopen("S3.txt","r");
    while((c=fgetc(outFile))!=EOF)
        printf("%c",c);
    fclose(outFile);
    printf("\n\n");
}
int main()
{
    printf("\n\n");
    outFile = fopen("input.txt","r");
    printf("Step 1:\n\n");
    while((c=fgetc(outFile))!=EOF)
        printf("%c",c);
    fclose(outFile);
    printf("\n\nStep 2:\n\n");
    printf("\t\tSymbol Table\n");
    st();
    display();
    printf("\n\n");
    printf("Step 3:\n\n");
    s3();

}
