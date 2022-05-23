#include <stdio.h>
#include <stdlib.h>

void readMap(char [] );
void dispMap();
void searchStarting();
void dispStarting();
char* orientation(char);
void searchMission();

struct Vehicle{
    int x;
    int y;
    char orientation; // u:up; d:down; r:right; l:left
};

struct Vehicle starting[2];

int map[15][15];

int main()
{

    readMap("input01.txt");

    dispMap();

    searchStarting();
    dispStarting();

    return 0;
}

void readMap(char filename[]){
   FILE *fptr;
   fptr = (fopen(filename, "r"));
   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            fscanf(fptr,"%1d", &map[i][j]);
}

void dispMap(){
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++)
            printf("%d",map[i][j]);
        printf("\n");
    }


}

void searchStarting(){
    for(int i=0; i<13; i++)
        for(int j=0; j<14; j++)
            if ((map[i][j]==2) && (map[i][j+1]==2)&&(map[i+1][j]==2) && (map[i+1][j+1]==2)&&(map[i+2][j]==2) && (map[i+2][j+1]==2)){
                starting[0].x=j;
                starting[0].y=i;
                starting[0].orientation='u';
                starting[1].x=j+1;
                starting[1].y=i+2;
                starting[1].orientation='d';

            }
            else if ((map[i][j]==2) && (map[i][j+1]==2)&&(map[i][j+2]==2) && (map[i+1][j]==2)&&(map[i+1][j+1]==2) && (map[i+1][j+2]==2)){
                starting[0].x=j;
                starting[0].y=i;
                starting[0].orientation='u';
                starting[1].x=j+1;
                starting[1].y=i+2;
                starting[1].orientation='d';
            }

}

void dispStarting(){
    printf("Starting spot:\n");
    printf(" (%d, %d) %s", starting[0].x, starting[0].y, orientation(starting[0].orientation));
    printf("\n (%d, %d) %s", starting[1].x, starting[1].y, orientation(starting[1].orientation));
}

char* orientation(char o){
    if (o=='u')
        return "up";
    else if (o=='d')
        return "down";
    else if (o=='l')
        return 'left';
    else if (o=="r")
        return "right";
}
