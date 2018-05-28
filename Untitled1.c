# include <stdio.h>
# include <conio.h>
# include <time.h>
# include <stdlib.h>
# include <ctype.h>
# include <Windows.h>
char symbolupfield=205;
char symbolsidefield=199;
char symbolship=178;
char symboldeadship=35;
char symbolhit=88;
char field[12][14]={
                                "  ##########",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "|          |",
                                "  ##########",
                            };   //# и | это поле
                                //1 корабль
                                //2 мертвый корабль
                                //3 попадание
void init();
void visual();
main(){
    int i=0,j=0;

    init();
    visual();
    printf("Press any key to start");
    getch();
    system("CLS");
    visual();


    //размещение
    int x1,y1,x2,y2,sel,position,k=10;
    int ships[3];
    int triger=0;
    for (i=0;i<4;i++){
        ships[i]=4-i;
    }
    while (k){
    printf("You have:\n");
     for (j=0;j<4;j++){
         printf("Ship%d: %d\n",j+1,ships[j]);
     }
    printf("Select ship(1,2,3,4):");
    scanf("%d",&sel);
    ships[sel]--;
  //  printf("Horizontally(1) or vertically(2)?\n");
   // scanf("%d",&position);
    printf("Beginning x,y of the ship:");
    scanf("%d %d",&x1,&y1);
    x1=x1+2; y1=y1+1;
    printf("End x,y of ship:");
    scanf("%d %d",&x2,&y2);
    x2=x2+2; y2=y2+1;
   // if ()
    k--;
    }
    getch();
}
void init(){
    int i=0,j=0;
    for(i=0;i<12;i++) {
            for(j=0;j<13;j++) {
                char symb=field[i][j];
                switch(symb)
                {
                    case '#':
                    {
                       field[i][j]=symbolupfield;
                       break;
                    }
                    case '|':
                    {
                        field[i][j]=symbolsidefield;
                        break;
                    }
                    case '1':
                    {
                        field[i][j]=symbolship;
                        break;
                    }
                     case '2':
                    {
                        field[i][j]=symboldeadship;
                        break;
                    }
                    default:
                    {
                        field[i][j]=symb;
                        break;
                    }
                }
            }
}
}
void visual(){
    int i=0,j=0;
     printf("\n\t  0123456789\n");
      for(i=0;i<12;i++) {
        printf("\t");
        if(i>0 && i<11){
            printf("%d",i-1);
        }
        for(j=0;j<13;j++)
            printf("%c",field[i][j]);
        printf("\n");
    }
}
