#import <Foundation/Foundation.h>
#import <stdio.h>


bool validateYear(char* cyear){
    int year = [[NSString stringWithUTF8String:cyear] intValue];
    if(year >= 1 && year <= 9999){
        return true;
    }else{
        NSLog(@"cal: year `%s` not in range 1..9999", cyear);
        return false;
    }
}

bool validateMonth(char* cmonth){
    int month = [[NSString stringWithUTF8String: cmonth] intValue];
    if(month >= 1 && month <= 12){
        return true;
    }else{
        NSLog(@"cal: %s is not a month number (1..12)", cmonth);
        return false;
    }
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
    // 注意：星期日是1，星期一是2，以此类推
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
    // 调用rangeOfUnit方法:(返回一样是一个结构体)两个参数一个大单位，一个小单位(.length就是天数，.location就是月)
    NSInteger monthNum = [calendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:date].length;
    return monthNum;
}

void print(NSString *s){
    const char *c = [s UTF8String];
    printf("%s",c);
}

void printCal(int month, int year){
    NSArray *MONTH_MAP = @[@"一月",@"二月",@"三月",@"四月",@"五月",@"六月",@"七月", @"八月", @"九月",@"十月", @"十一月",@"十二月"];

    print([NSString stringWithFormat:@"      %@ %d\n", MONTH_MAP[month-1], year]);
    printf("日 一 二 三 四 五 六\n");
    int firstDayWeekday = getMonthFisrtDaysWeekday(month, year);
    for(int i = 1; i < firstDayWeekday; i++){
        // 前导空格
        printf("   ");
    }
    int lastDay = getMonthLastDay(month, year);
    for(int j = 1; j <= lastDay; j++){
        printf("%2d", j);
        if((j+firstDayWeekday-1)%7 == 0){
            printf("\n");
        }else {
            printf(" ");
        }
    }
    printf("\n\n");
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
                        NSLog(@"cal: illegal option");
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