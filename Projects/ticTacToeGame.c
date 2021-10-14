#include <stdio.h>
int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, choice, player;
char mark;
int setup()
{
    printf("     |     |   \n");
    printf(" %d   | %d   | %d\n", a[0], a[1], a[2]);
    printf("_____|_____|_____\n");
    printf("     |     |   \n");
    printf(" %d   | %d   | %d\n", a[3], a[4], a[5]);
    printf("_____|_____|_____\n");
    printf("     |     |   \n");
    printf(" %d   | %d   | %d\n", a[6], a[7], a[8]);
    printf("     |     |   \n");
    printf("\n");
}
int main()
{

    int player = 1;
    setup();
    while(10)
    {
        if (player % 2 == 1)
        {
            player = 1;
            mark=0;
        }
        else
        {
            player = 2;
            mark= 1;
        }
        printf(" player %d enter your choice:", player);
        scanf("%d", &choice);

        if (choice == 1 && a[0] == 1)
            a[0] = mark;
        else if (choice == 2 && a[1] == 2)
            a[1] = mark;
        else if (choice == 3 & a[2] == 3)
            a[2] = mark;
        else if (choice == 4 && a[3] == 4)
            a[3] = mark;
        else if (choice == 5 && a[4] == 5)
            a[4] = mark;
        else if (choice == 6 && a[5] == 6)
            a[5] = mark;
        else if (choice == 7 && a[6] == 7)
            a[6] = mark;
        else if (choice == 8 && a[7] == 8)
            a[7] = mark;
        else if (choice == 9 && a[8] == 9)
            a[8] = mark;
        else{
            printf("Invalid!!\n");
            player--;
        }
        setup();

        //checking winner
        if(a[0]==a[1]==a[2])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[3]==a[4]==a[5])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[6]==a[7]==a[8])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[0]==a[3]==a[6])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[1]==a[4]==a[7])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[2]==a[5]==a[8])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n"),player;
        return 1;
        }
        else if(a[0]==a[4]==a[8])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[2]==a[4]==a[6])
        {
    printf("CONGRATULATIONS Player %d\nYou have WON the match\n",player);
        return 1;
        }
        else if(a[0]!=1&& a[1]!=2&& a[2]!=3&& a[3]!=4&& a[4]!=5&& a[5]!=6&& a[6]!=7&& a[7]!=8&& a[8]!=9)
        {
         printf("______DRAW______\n");
        return 0;
        }


        player++;
    }
    
    
    
    

    

    return 0;
}
