#include <cstdio>

int main(){
  int hour, min;
  scanf("%d:%d", &hour, &min);
  
  if(hour >= 12){
    printf("%d:%d PM\n", hour > 12 ? hour % 12 : 12, min);
  }else{
    printf("%d:%d AM\n", hour, min);
  }
  
  return 0;
}