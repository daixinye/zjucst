#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
#include <string.h>
#define MAX_SIZE 500

void Print_Factorial ( const int N ){

}

char* multiple (char* num, int unit){
  int len = strlen(num);
  int a = 0, b = 0;
  char product[MAX_SIZE];
  
  for(int i = 0; i < len; i++){
    int dig = int(num[i]) - 48;
    
    // 个位数
    a = (dig + b) * unit % 10;
    // 进位数
    b = dig * unit / 10;
    
    product[i] = char(a + 48);
  }
  product[len] = char(b + 48);
  product.reverse();
  
  return product;
}