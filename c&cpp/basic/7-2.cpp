#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int startTime, flowTime;
    scanf("%d %d", &startTime, &flowTime);

    int h, m;
    h = startTime / 100;
    m = startTime % 100;

    int flowH, flowM;
    flowH = flowTime / 60;
    flowM = flowTime % 60;

    flowM = flowM + m;
    if(flowM >= 60){
        flowH = flowH + 1;
        flowM = flowM - 60;
    }else if(flowM < 0){
        flowH = flowH - 1;
        flowM = flowM + 60;
    }

    h = h + flowH;
    m = flowM;

    printf("%d\n", h*100 + m);

    return 0;
    
}