#include <stdio.h>
#include <stdlib.h>

int main()
{

    char programkod[] = "+++++ +++++[>+++++ ++++<-]>.<+++++[>+++++<-]>.----.---.+++++ +++.<+++++ +++[>----- -----<-]>----.<+++++ +++[>+++++ +++++<-]>+++++ +.----- --.----.<+++++ +++++[>----- -----<-]>-----.";
    //char programkod[] = "megfordito program:>,----------[++++++++++>,----------]++++++++++[<.]";

    char sheet[32768] = {0};
    int i=0, slct=0;

    while (programkod[i]!=0)
    {

        switch (programkod[i])
        {

        case '+':
            sheet[slct]=(sheet[slct]+1)%256;
            i++;
            break;

        case '-':
            sheet[slct]=(sheet[slct]-1)%256;
            i++;
            break;

        case '<':
            if(slct > 0)
            {
                slct--;
            }
            i++;
            break;

        case '>':
            slct++;
            if(slct>32768)
            {
                printf("range error, kiment a haz az ablakon");
            }
            i++;
            break;

        case '.':
            printf("%c", sheet[slct]);
            i++;
            break;

        case ',':
            if(scanf("%c", &sheet[slct]) == EOF){
                sheet[slct]=-1;
            }
            i++;
            break;

        case '[':
            if(sheet[slct]==0)
            {

                int bracket = 1;
                do
                {
                    i++;
                    if(programkod[i]=='[')
                    {
                        bracket++;
                    }

                    if(programkod[i]==']')
                    {
                        bracket--;
                    }
                }
                while(bracket>0);
            }
            i++;
            break;

        case ']':
            ;
            int bracket = 1;
            do
            {
                i--;
                if(programkod[i]==']')
                {
                    bracket++;
                }

                if(programkod[i]=='[')
                {
                    bracket--;
                }
            }
            while(bracket>0);
            break;

        default:
            i++;

        }
    }

    return 0;
}
