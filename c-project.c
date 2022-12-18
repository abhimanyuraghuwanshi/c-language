#include <stdio.h>
#include <string.h>
#include <windows.h>
struct data
{
    char id[15], p[10];
};

int main()
{
    int num, repeat = 1, count;
    char id[15], pass[10];
    while (repeat)
    {

        printf("\nHELLO this is a program to directly post a comment into a website comment box \n as the program is password protected please register or login from below\n\n");
        printf("press 1 For login. \n press 2 For signup.\n press 3 to delete.\n press 4 to quit.");
        scanf("%d", &num);

        struct data obj[15];

        switch (num)
        {
        case 4: // Quit--------
            repeat = 0;
            break;

        case 3: // delet user
            getchar();
            int performdelete = 0;
            printf("type the name for of user ID---(beware :if you entered anything thing you will we thrown out fron program)\n");
            gets(id);
            printf("type your password\n");
            gets(pass);

            FILE *file;
            file = fopen("data.xls", "r");
            for (size_t i = 0;; i++)
            {
                fscanf(file, "%s", obj[i].id);
                fscanf(file, "%s", obj[i].p);
                if (feof(file) != 0)
                {
                    count = i;
                    break;
                }
            }fclose(file);

            for (size_t i = 0; i <= count; i++)
            {
                if (strcmpi(obj[i].id, id) == 0)
                {
                    if (strcmp(obj[i].p, pass) == 0)
                    { // delete user id-----------
                        performdelete = 1;
                        while (i <= count)
                        {
                            strcpy(obj[i].id, obj[i + 1].id);
                            strcpy(obj[i].p, obj[i + 1].p);
                            i++;
                        }
                    }
                }
            }
             FILE *file2;
                file2 = fopen("data.xls", "w");
            for (size_t i = 0; i < count; i++)
              {  fprintf(file2, "\n%s\t", obj[i].id);
                fprintf(file2, "%s", obj[i].p);
                
            }
            fclose(file2);
            printf("delete succesfull");

            break;

        case 2: // create id-----------
            getchar();

            printf("type the name for your user ID\n");
            gets(id);
            printf("type your password\n");
            gets(pass);

            FILE *f;
            f = fopen("data.xls", "a+");
            fprintf(f, "\n%s\t", id);
            fprintf(f, "%s", pass);
            fclose(f);
            printf("ID created succesfully");
            break;

        case 1: // login-------------
            getchar();
            int count;
            printf("type the name for of user ID---(beware :if you entered anything thing you will we thrown out fron program)\n");
            gets(id);
            printf("type your password\n");
            gets(pass);

            FILE *fl;
            fl = fopen("data.xls", "r");
            for (size_t i = 0;; i++)
            {
                fscanf(fl, "%s", obj[i].id);
                fscanf(fl, "%s", obj[i].p);
                if (feof(fl) != 0)
                {
                    count = i;
                    break;
                }
            }
            fclose(fl);

            for (size_t i = 0; i <= count; i++)
            {
                if (strcmpi(obj[i].id, id) == 0)
                {
                    if (strcmp(obj[i].p, pass) == 0)
                    { // post comment-----------
                        system("cls");
                        printf("Welcome\nYou have entered into comment page");
                        char com[250];
                        printf("please enter your comment:");
                        gets(com);
                        FILE *h;
                        h = fopen("comment.html", "a");
                        fprintf(h, "\n\n<h2>Comment:</h2>\n");
                        fprintf(h, "<h5>%s</h5>", com);
                        fprintf(h, "This is written by %s.", obj[i].id);
                        fclose(h);
                        printf("Comment has been added. plz check your folder for HTML file");
                    }
                }
            }

            break;
        }
    }
}
