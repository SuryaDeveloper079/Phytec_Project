#include<stdio.h>
void sum(int a,int b){
    printf("sum=%d\n",a+b);
}
void sub(int a,int b){
    printf("sum=%d\n",a-b);
    // return a-b;
}
void display(void (*fptr)(int, int)){

    (*fptr)(10,20);
    // printf("sub=%d\n",(*fptr2)(10.5,11.5));

}
int main(){
    display(sum);
    display(sub);
}