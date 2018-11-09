#include "fn.h"

int main(){
    srand(time(NULL));
    reset();
    while(1){
        for(int x=0;x<15;++x){
           frame();
            if (kbhit()){
                char ch = getch();
                switch((int)ch){
                    case 100:
                        draw(1);
                        break;
                    case 97:
                        draw(0);
                        break;
                }
            }
            Sleep(10);
        }
        drop();
        if(rand()%2){
            gen();
        }
    }

    return 0;
}
