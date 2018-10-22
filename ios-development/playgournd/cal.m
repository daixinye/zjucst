#import <Foundation/Foundation.h>
#import <stdio.h>

// todo: 精简代码
char* NSStringToChar(NSString *s){
    char* c = [s UTF8String];
    return c;
}

bool validateYear(char* cyear){
    int year = [[NSString stringWithUTF8String:cyear] intValue];
    if(year >= 1 && year <= 9999){
        return true;
    }else{
        printf("cal: year `%s` not in range 1..9999", cyear);
        return false;
    }
}

bool validateMonth(char* cmonth){
    int month = [[NSString stringWithUTF8String: cmonth] intValue];
    if(month >= 1 && month <= 12){
        return true;
    }else{
        printf("cal: %s is not a month number (1..12)", cmonth);
        return false;
    }
}

int getCurrentDay(){
    //获得当前日期
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *comps;
    
    //获取本日
    comps = [calendar components:(NSCalendarUnitDay) fromDate:date];
    NSInteger day = [comps day];
    return day;
}

int getCurrentYear(){
    //获得当前日期
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *comps;
    
    //获取本年
    comps = [calendar components:(NSCalendarUnitYear) fromDate:date];
    NSInteger year = [comps year];
    return year;
}

int getCurrentMonth(){
    //获得当前日期
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *comps;

    //获取本月
    comps = [calendar components:(NSCalendarUnitMonth) fromDate:date];
    NSInteger month = [comps month];
    return month;
}

int getMonthFisrtDaysWeekday(int month, int year){
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *comps;
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    NSTimeZone *timeZone = [NSTimeZone localTimeZone];
    [formatter setTimeZone:timeZone];
    [formatter setDateFormat:@"M/d/yyyy"];
    NSString *firstDay = [NSString stringWithFormat:@"%d/%d/%d",month,1,year];
    date = [formatter dateFromString:firstDay];
    [formatter release];
    comps = [calendar components:(NSCalendarUnitWeekday) fromDate:date];
    NSInteger weekday = [comps weekday];
    return weekday;
}

int getMonthLastDay(int month, int year){
    NSDate *date = [NSDate date];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *comps;
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    NSTimeZone *timeZone = [NSTimeZone localTimeZone];
    [formatter setTimeZone:timeZone];
    [formatter setDateFormat:@"M/d/yyyy"];
    NSString *firstDay = [NSString stringWithFormat:@"%d/%d/%d",month,1,year];
    date = [formatter dateFromString:firstDay];
    NSInteger monthNum = [calendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:date].length;
    return monthNum;
}

void printMonthLine(int month, int year, int line){
    if(line == 0){
        printf("日 一 二 三 四 五 六");
        return;
    }

    int firstDayWeekday = getMonthFisrtDaysWeekday(month, year);
    int lastDay = getMonthLastDay(month, year);
    int curDay = getCurrentDay();
    int curMonth = getCurrentMonth();
    int curYear = getCurrentYear();
    
    int day = 7*(line-1) - firstDayWeekday + 2;
    int stop = day+7;
    
    while(1){
        if(day <= 0 || day>lastDay){
            printf("  ");
        }else{
            if(day == curDay && month == curMonth && year == curYear){
                printf("\033[0m\033[47;30m%2d\033[0m", day);
            }else{
                printf("%2d", day);
            }
        }
        day++;
        if(day < stop){
            printf(" ");
        }else{
            break;
        }
    }
}

// todo: 部分年份的月历显示有误，需要排查原因
void printCal(int month, int year){
    NSArray *MONTH_MAP = @[@"一月",@"二月",@"三月",@"四月",@"五月",@"六月",@"七月", @"八月", @"九月",@"十月", @"十一月",@"十二月"];
    printf("      %s %d\n", NSStringToChar(MONTH_MAP[month-1]), year);
    
    for(int i = 0;i<7;i++){
        printMonthLine(month, year, i);
        printf("\n");
    }
}

void printYearCal(int year){
    NSArray *MONTH_MAP = @[@"一月",@"二月",@"三月",@"四月",@"五月",@"六月",@"七月", @"八月", @"九月",@"十月", @"十一月",@"十二月"];
    printf("                            %d\n",year);

    for(int m = 3; m<=12; m+=3){
        for(int line = -1; line < 7; line++){
            for(int month = m-2; month<=m; month++){
                if(line == -1){
                    printf("%17s        ", NSStringToChar(MONTH_MAP[month-1]));
                }else{
                    printMonthLine(month ,year, line);
                    printf("  ");
                }
            }
            printf("\n");
        }
        if(m!=12){
            printf("\n");
        }
    }
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
                // validate: <year>
                if(validateYear(argv[1])){
                    year = [[NSString stringWithUTF8String:argv[1]] intValue];
                    printYearCal(year);
                    return 1;
                }
                break;
            case 3:
                if(argv[1][0] == '-'){
                    // usecase:3 输入: -m <month> 输出：当年该月
                    if([@"-m" compare: [NSString stringWithUTF8String:argv[1]]] == NSOrderedSame){
                        // validate: <month>
                        if(validateMonth(argv[2])){
                            year = getCurrentYear();
                            month = [[NSString stringWithUTF8String:argv[2]] intValue];
                            printCal(month, year);
                        }
                    }else{
                        // validate: <option>
                        printf("cal: illegal option");
                        return 1;
                    }
                }else{
                    // usecase:2 输入：<month> <year> 输出：该年该月月历
                    // validate: <month> & <year>
                    if(validateMonth(argv[1]) && validateYear(argv[2])){
                        month = [[NSString stringWithUTF8String:argv[1]] intValue];
                        year = [[NSString stringWithUTF8String:argv[2]] intValue];
                        printCal(month, year);
                    }
                }
                break;
            
        }

    }
}