/*
separate and mark the lexemes as 
different types of tokens like keywords,identifiers,
operators,separators,parenthesis,numbers etc.
*/
#include<stdio.h>
#include<ctype.h>
int size =20;
int keywordCheck(char lex[size]);
int identifierCheck(char lex[size]);
int operatorCheck(char lex[size]);
int separatorCheck(char lex[size]);
int numberCheck(char lex[size]);
int parenthesisCheck(char lex[size]);
int main()
{
    FILE *inFile,*outFile;
    char c,lex[size];
    int i;

    inFile = fopen("scanned.txt","r");
    outFile = fopen("o1.txt","w");

    if(!inFile)
        printf("\nFile can't be opened!");

    else
    {
        while((c=fgetc(inFile)) != EOF)
        {
            if(!isalnum(c) && c!='_'&& c!='.'&& c!=' ')
            {
                fputc(' ',outFile);

            }
            fputc(c,outFile);

            if(c=='='||c=='!'||c=='<'||c=='>')
            {
                c=fgetc(inFile);
                if(c=='=')
                {
                    fputc(c,outFile);
                    if(!isalnum(c) && c!='_'&& c!='.'&& c!=' ')
                        fputc(' ',outFile);
                }
                else
                {
                    fputc(' ',outFile);
                    fputc(c,outFile);
                    if(!isalnum(c) && c!='_'&& c!='.'&& c!=' ')
                        fputc(' ',outFile);
                }
            }
            else if(!isalnum(c) && c!='_'&& c!='.'&& c!=' ')
                fputc(' ',outFile);

        }
    }
    fclose(inFile);
    fclose(outFile);

    inFile = fopen("o1.txt","r");
    outFile = fopen("o2.txt","w");
    if(!inFile)
        printf("\nFile can't be opened!");

    else
    {
        while((c=fgetc(inFile)) != EOF)
        {
            if(c==' '||c=='\t')
            {
                fputc(' ', outFile);
                c=fgetc(inFile);
                while(c==' ' || c=='\t')
                {
                    c=fgetc(inFile);
                }
                if(c!=EOF)
                    fputc(c, outFile);
            }
            else
                fputc(c, outFile);
        }

    }
     fclose(inFile);
    fclose(outFile);

    inFile = fopen("o2.txt","r");
    outFile = fopen("o3.txt","w");
    if(!inFile)
        printf("file can't be opened");
    else
    {
        while((c=fgetc(inFile)) != EOF)
        {
            i=0;
            while(c!=' ' && c!=EOF)
            {
                lex[i]=c;
                ++i;
                c=fgetc(inFile);
            }
            lex[i]='\0';
            if (keywordCheck(lex))
                fprintf(outFile,"[kw %s]",lex);
            else if (identifierCheck(lex))
                fprintf(outFile,"[id %s]",lex);
            else if (operatorCheck(lex))
                fprintf(outFile,"[op %s]",lex);
            else if (separatorCheck(lex))
                fprintf(outFile,"[sep %s]",lex);
            else if (numberCheck(lex))
                fprintf(outFile,"[num %s]",lex);
            else if (parenthesisCheck(lex))
                fprintf(outFile,"[par %s]",lex);
            else
                fprintf(outFile,"[unkn %s]",lex);
        }
    }
    fclose(inFile);
    fclose(outFile);

    outFile = fopen("scanned.txt","r");
    printf("Input:\n\n");
    while((c=fgetc(outFile))!=EOF)
        printf("%c",c);
    fclose(outFile);

    printf("\n\n");

    outFile = fopen("o1.txt","r");
    printf("Step 1:\n\n");
    while((c=fgetc(outFile))!=EOF)
        printf("%c",c);
    fclose(outFile);

    printf("\n\n");


    outFile = fopen("o3.txt","r");
    printf("Step 2:\n\n");
    while((c=fgetc(outFile))!=EOF)
        printf("%c",c);
    fclose(outFile);

    printf("\n\n");

    return 0;
}
int keywordCheck(char lex[size])
{
    int i,s;
    if(!strcmp(lex,"int")||!strcmp(lex,"char")||!strcmp(lex,"float")||!strcmp(lex,"double")||!strcmp(lex,"void")||!strcmp(lex,"if")||!strcmp(lex,"else"))
    {
        s=1;
        return s;
    }
    else
    {
        s=0;
        return s;
    }
}
int identifierCheck(char lex[size])
{
    int i,s=0;
    if(isalpha(lex[0]) || lex[0]=='_')
        s=1;
    if(s==1)
    {
        for(i=1; i<strlen(lex); i++)
        {
            if(!isalnum(lex[i]) && lex[i]!='_'&& !isalpha(lex[i]))
            {
                s=0;
                break;
            }
        }
    }
    return s;
}
int operatorCheck(char lex[size])
{
    int s;
    if(!strcmp(lex,"+")||!strcmp(lex,"-")||!strcmp(lex,"*")||!strcmp(lex,"/")||!strcmp(lex,"<")||!strcmp(lex,">")||!strcmp(lex,"<=")||!strcmp(lex,">=")||!strcmp(lex,"="))
        return 1;
    else
        return 0;
}
int separatorCheck(char lex[size])
{
    if(!strcmp(lex,"'")||!strcmp(lex,",")||!strcmp(lex,";"))
        return 1;
    else
        return 0;
}
int numberCheck(char lex[size])
{
    int i, l, s;
    i=0;
    if(isdigit(lex[i]))
    {
        s=1;
        i++;
    }
    else if(lex[i]=='.')
    {
        s=2;
        i++;
    }
    else s=0;
    l=strlen(lex);

    if(s==1)
        for(; i<l; i++)
        {
            if(isdigit(lex[i]))
                s=1;
            else if(lex[i]=='.')

            {
                s=2;
                i++;
                break;
            }
            else
            {
                s=0;
                break;
            }
        }

    if(s==2)
        if(isdigit(lex[i]))
        {
            s=3;
            i++;
        }
        else s=0;

    if(s==3) s=1;
    return s;
}
int parenthesisCheck(char lex[size])
{
    if(!strcmp(lex,"(")||!strcmp(lex,")")||!strcmp(lex,"{")||!strcmp(lex,"}")||!strcmp(lex,"[")||!strcmp(lex,"]"))
        return 1;
    else
        return 0;
}
