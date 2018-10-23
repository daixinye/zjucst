#import <Foundation/Foundation.h>

int main(int argc, char *argv[]) {
	@autoreleasepool {
        //获得当前日期
        NSDate *date = [NSDate date];
        NSCalendar *calendar = [NSCalendar currentCalendar];
        NSDateComponents *comps;
        
        //获取本年
        comps = [calendar components:(NSCalendarUnitYear) fromDate:date];
        NSInteger year = [comps year];
        NSLog(@"本年: %ld", year);

        //获取本月
        comps = [calendar components:(NSCalendarUnitMonth) fromDate:date];
        NSInteger month = [comps month];
        NSLog(@"本月: %ld", month);

        //本月第一天的星期
        NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
        NSTimeZone *timeZone = [NSTimeZone localTimeZone];
        [formatter setTimeZone:timeZone];
        [formatter setDateFormat:@"M/d/yyyy"];
        NSString *firstDay = [NSString stringWithFormat:@"%d/%d/%d",month,1,year];
        NSLog(@"本月：%@", firstDay);
        date = [formatter dateFromString:firstDay];
        [formatter release];
        // 注意：星期日是1，星期一是2，以此类推
        comps = [calendar components:(NSCalendarUnitWeekday) fromDate:date];
        NSInteger weekday = [comps weekday];
        NSLog(@"本月第一天的星期： %ld", weekday);

        //下月第一天
        NSDateComponents *c1 = [[NSDateComponents alloc] init];
        [c1 setMonth:1];
        NSDate *date2 = [calendar dateByAddingComponents:c1 toDate:date options:0];
        [c1 release];
        //本月最后一天
        NSDateComponents *c2 = [[NSDateComponents alloc] init];
        [c2 setDay:-1];
        NSDate *date3 = [calendar dateByAddingComponents:c2 toDate:date2 options:0];
        [c2 release];
        comps = [calendar components:(NSDayCalendarUnit) fromDate:date3];
        NSInteger maxDays = [comps day];
	}
}