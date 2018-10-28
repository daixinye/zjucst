//
//  ViewController.m
//  tasklist
//
//  Created by dxy on 2018/10/28.
//  Copyright © 2018年 dxy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UITextField *TaskInputTextField;
@property (weak, nonatomic) IBOutlet UIButton *InsertButton;
@property (weak, nonatomic) IBOutlet UITableView *TaskListTableView;
- (IBAction)onInsert:(id)sender;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    taskList = [[NSMutableArray alloc] init];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table View Data source
- (IBAction)onInsert:(id)sender {
    NSString *text = [self.TaskInputTextField.text copy];
    if([text length]>0){
        [taskList addObject:text];
        [self.TaskListTableView reloadData];
        self.TaskInputTextField.text = @"";
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [taskList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    static NSString *cellIdentifier = @"cellID";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:
                             cellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc]initWithStyle:
                UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    NSString *stringForCell;
    if (indexPath.section == 0) {
        stringForCell= [taskList objectAtIndex:indexPath.row];
        
    }
    else if (indexPath.section == 1){
        stringForCell= [taskList objectAtIndex:indexPath.row+ [taskList count]];
        
    }
    [cell.textLabel setText:stringForCell];
    return cell;
}
@end
