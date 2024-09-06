#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int x =3;

void* routine(){
    x++;
    sleep(2);
printf("Value of x %d\n",x);
}

void* routine2(){
sleep(2);
printf("Value of x %d\n",x);
}


int main(int arg, char* argv[]){
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &routine, NULL )!=0){return 1;}
    if(pthread_create(&t2, NULL, &routine2, NULL )!=0){return 2;}
    if(pthread_join(t1, NULL)!=0){return 3;}
    if(pthread_join(t2, NULL)!=0){return 4;}

    return 0;
}
