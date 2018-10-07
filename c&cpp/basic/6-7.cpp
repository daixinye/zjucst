#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber( const int N ){
  int n, root;
  n = N;
  root = ceil(sqrt(n));
  
  // 判断是否是完全平方数
  if( root*root != n ){
    return 0;
  }
  
  // 判断是否有两位数字相同
  int bitmap = 0;
  while( n ){
    int dig = n % 10;
    n = n /10;
    
    if( bitmap & (1 << dig)){
	printf("%d\n", N);
      return 1;
    }else {
      bitmap = bitmap | (1 << dig);
    }
  }
}
