#include "fn.h"

int pts=0,ramint=0,miss=0,missint=0;
char world[SIZE][SIZE];
int bowl=SIZE/2;
std::string ram,output;

int food[SIZE-1];

void reset(){
    memset(world,0,sizeof(world));
    for(int y=0;y<SIZE;++y){
        for(int x=0;x<SIZE;++x){
            if(y==0||x==0||y==SIZE-1||x==SIZE-1){
                world[y][x]='#';
            }else{
                world[y][x]=' ';
            }
        }
    }
}

void draw(bool d){
    if(d&&bowl<SIZE-5){
        bowl++;
    }else if(bowl>2&&d==0){
        bowl--;
    }
}

void frame(){
    reset();
    world[SIZE-2][bowl-1]='\\';
    world[SIZE-2][bowl]='_';
    world[SIZE-2][bowl+1]='_';
    world[SIZE-2][bowl+2]='_';
    world[SIZE-2][bowl+3]='/';
    for(int y=0;y<=SIZE-2;++y){
        if(food[y]!=0){
                world[y+1][food[y]]='@';
        }
    }
    output.clear();
    for(int y=0;y<SIZE;++y){
        output+=std::string(world[y],SIZE)+"\n";
    }
    if(ram!=output||ramint!=pts||missint!=miss){
        system("cls");
        std::cout<<output;
        std::cout<<"points:"<<pts<<";"<<"missed:"<<miss<<std::endl;
        ram.clear();
        ram=output;
        ramint=pts;
        missint=miss;
    }
}

void drop(){
    if(food[SIZE-2]!=0){
        miss++;
    }
    if((food[SIZE-4]>=bowl-1&&food[SIZE-4]<=bowl+3)){
        pts++;
        food[SIZE-4]=0;
    }
    if((food[SIZE-3]>=bowl-1&&food[SIZE-3]<=bowl+3)){
        pts++;
        food[SIZE-3]=0;
    }
    for(int y=SIZE-2;y>0;--y){
        food[y]=food[y-1];
    }
    food[0]=0;
}

void gen(){
    int x=rand()%(SIZE-2)+1;
    food[0]=x;
}
