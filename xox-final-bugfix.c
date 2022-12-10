#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char xox[3][3]={{'0','0','0'},{'0','0','0'},{'0','0','0'}};
int i,b,x1,x2,o1,o2,tur;
char sira='x';
int bi=0;
char yeniden;

void yaz(void){
    for(i=0;i<=2;i++){
        for(b=0;b<=2;b++){
            printf("%c ",xox[i][b]);
        }
    printf("\n");
    }
}

int say(void){
    int i,b;
    tur=0;
    for(i=0;i<=2;i++){
        for(b=0;b<=2;b++){
            if(xox[i][b]=='0'){
                tur++;
            }
        }
    }
    return 10-tur;
}

void bitir(char c){
    system("cls");
    printf("\n%d. tur\n",say());
    yaz();
    printf("\n%c KAZANDI\n",c);
    system("pause");
    for(i=0;i<=2;i++){
        for(b=0;b<=2;b++){
            xox[i][b]='0';
        }
    }
    sira='x';
}

void xsira (int x1,int x2){
    if(xox[x1-1][x2-1]=='O'||xox[o1-1][o2-1]=='X'){
        system("cls");
        printf("\n%d. tur\n",say());
        yaz();
        printf("\nX'in hamlesi= ");
        scanf("%d %d",&x1,&x2);
        xsira(x1,x2);
        sira='o';
    }else{
        xox[x1-1][x2-1]='X';
    }
}

void osira (int o1,int o2){
    if(xox[o1-1][o2-1]=='X'||xox[o1-1][o2-1]=='O'){
        system("cls");
        printf("\n%d. tur\n",say());
        yaz();
        printf("\nO'nun hamlesi= ");
        scanf("%d %d",&o1,&o2);
        osira(o1,o2);
        sira='x';
    }else{
        xox[o1-1][o2-1]='O';
    }
}

void xdene(void){
    if(xox[1][1]=='X'){
        if (xox[0][0]=='X'){
            if (xox[2][2]=='X'){
                bi=1;
            }
        } else if (xox[2][0]=='X'){
            if (xox[0][2]=='X'){
                bi=1;
            }
        } else if (xox[0][1]=='X'){
            if(xox[2][1]=='X'){
               bi=1; 
            }
        } else if (xox[1][0]=='X'){
            if(xox[1][2]=='X'){
                bi=1;
            }
        }
    } else if (xox[0][0]=='X'){
        if (xox[1][0]=='X'){
            if(xox[2][0]=='X'){
                bi=1;
            }
        } else if (xox[0][1]=='X'){
            if(xox[0][2]=='X'){
                bi=1;
            }
        }
    } else if (xox[2][2]=='X'){
        if (xox[2][0]=='X'){
            if(xox[2][1]=='X'){
                bi=1;
            }
        } else if (xox[0][2]=='X'){
            if(xox[1][2]=='X'){
                bi=1;
            }
        }
    }
}

void odene(void){
    if(xox[1][1]=='O'){
        if (xox[0][0]=='O'){
            if(xox[2][2]=='O'){
                bi=2;
            }
        } else if (xox[2][0]=='O'){
            if(xox[0][2]=='O'){
                bi=2;
            }
        } else if (xox[0][1]=='O'){
            if(xox[2][1]=='O'){
                bi=2;
            }
        } else if (xox[1][0]=='O'){
            if(xox[1][2]=='O'){
                bi=2;
            }
        }
    } else if (xox[0][0]=='O'){
        if (xox[1][0]=='O'){
            if(xox[2][0]=='O'){
                bi=2;
            }
        } else if (xox[0][1]=='O'){
            if(xox[0][2]=='O'){
                bi=2;
            }
        }
    } else if (xox[2][2]=='O'){
        if (xox[2][0]=='O'){
            if(xox[2][1]=='O'){
                bi=2;
            }
        } else if (xox[0][2]=='O'){
            if(xox[1][2]=='O'){
                bi=2;
            }
        }
    }

}

int main (void){
    while (1==1){
        int s=say();
        if(s==10){
            system("cls");
            yaz();
            printf("\nBERABERE\n");
            system("pause");
            for(i=0;i<=2;i++){
                for(b=0;b<=2;b++){
                    xox[i][b]='0';
                }
            }
            sira='x';
        }else if(s>4){
            if(s%2==0){
                xdene();
                if (bi==1){
                    yaz();
                    sira='b';
                }
            }else{
                odene();
                if(bi==2){
                    yaz();
                    sira='b';
                }
            }
        }
        
        if(sira=='x'){
            system("cls");
            printf("\n%d. tur\n",s);
            yaz();
            printf("\nX'in hamlesi= ");
            scanf("%d %d",&x1,&x2);
            xsira(x1,x2);
            sira='o';
        }else if(sira=='o'){
            system("cls");
            printf("\n%d. tur\n",s);
            yaz();
            printf("\nO'nun hamlesi= ");
            scanf("%d %d",&o1,&o2);
            osira(o1,o2);
            sira='x'; 
        }else if(sira=='b'){
            if (tur%2==0){
                bitir('X');
            } else {
                bitir('O');
            }
            
        }
    }
    return 0;
}
