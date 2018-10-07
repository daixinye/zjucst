//
//  ViewController.m
//  MyApp
//
//  Created by dxy on 2018/9/27.
//  Copyright © 2018年 dxy. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *uiLabel;
@property int count;
@end

@implementation ViewController
- (IBAction)btClick:(id)sender {
    self.count++;
    self.uiLabel.text = [NSString stringWithFormat:@"%d", self.count];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
