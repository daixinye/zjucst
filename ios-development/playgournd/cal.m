#import <Foundation/Foundation.h>

void printCal(int month, int year){
    NSLog(@"printCal: %d %d", month, year);
}

void printYearCal(int year){
    NSLog(@"printYearCal: %d", year);
}

int getCurrentYear(){
    return 2018;
}

int getCurrentMonth(){
    return 10;
}

int main(int argc, char* argv[]){
    @autoreleasepool {
        int year, month;

        switch(argc){
            case 1:
                // usecase:1 输出：当月月历
                year = getCurrentYear();
                month = getCurrentMonth();
                printCal(month, year);
                break;
            case 2:
                // usecase:4 输入：<year> 输出：当年年历
                // argv[1] 转成 int：先char* 转 NSString，再 NSString 转 int
                year = [[NSString stringWithUTF8String:argv[1]] intValue];
                printYearCal(year);
                break;
            case 3:
                if([@"-m" compare: [NSString stringWithUTF8String:argv[1]]] == NSOrderedSame){
                    // usecase:3 输入: -m <month> 输出：当年该月
                    year = getCurrentYear();
                    month = [[NSString stringWithUTF8String:argv[2]] intValue];
                    printCal(month, year);
                }else{
                    // usecase:2 输入：<month> <year> 输出：该年该月月历
                    year = [[NSString stringWithUTF8String:argv[1]] intValue];
                    month = [[NSString stringWithUTF8String:argv[2]] intValue];
                    printCal(month, year);
                }
                break;
            
        }

    }
}