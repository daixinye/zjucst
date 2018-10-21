#import <Foundation/Foundation.h>

bool validateYear(int year){
    return year >= 1 && year <= 9999;
}

bool validateMonth(int month){
    return month >= 1 && month <= 12;
}

int getCurrentYear(){
    return 2018;
}

int getCurrentMonth(){
    return 10;
}

void printCal(int month, int year){
    
    NSLog(@"printCal: %d %d", month, year);
}

void printYearCal(int year){
    
    NSLog(@"printYearCal: %d", year);
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
                year = [[NSString stringWithUTF8String:argv[1]] intValue];
                // validate: <year>
                if(!validateYear(year)){
                    NSLog(@"cal: year `%s` not in range 1..9999", argv[1]);
                    return 1;
                }
                printYearCal(year);
                break;
            case 3:
                if(argv[1][0] == '-'){
                    // usecase:3 输入: -m <month> 输出：当年该月
                    if([@"-m" compare: [NSString stringWithUTF8String:argv[1]]] == NSOrderedSame){
                        year = getCurrentYear();
                        month = [[NSString stringWithUTF8String:argv[2]] intValue];
                        printCal(month, year);
                    }else{
                        NSLog(@"cal: illegal option");
                        return 1;
                    }
                }else{
                    // usecase:2 输入：<month> <year> 输出：该年该月月历
                    month = [[NSString stringWithUTF8String:argv[1]] intValue];
                    year = [[NSString stringWithUTF8String:argv[2]] intValue];
                    // validate: <month>
                    if(!validateMonth(month)){
                        NSLog(@"cal: %s is not a month number (1..12)", argv[1]);
                        return 1;
                    }
                    // validate: <year>
                    if(!validateYear(year)){
                        NSLog(@"cal: year `%s` not in range 1..9999", argv[2]);
                        return 1;
                    }
                    printCal(month, year);
                }
                break;
            
        }

    }
}