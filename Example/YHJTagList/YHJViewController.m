//
//  YHJViewController.m
//  YHJTagList
//
//  Created by 余洪江 on 03/01/2016.
//  Copyright (c) 2016 余洪江. All rights reserved.
//

#import "YHJViewController.h"
#import <MRJTagList/MRJTagList.h>

@interface YHJViewController () <MRJTagListDelegate>

@end

@implementation YHJViewController

- (void)viewDidLoad
{
    [super viewDidLoad];


    MRJTagList *listView = [[MRJTagList alloc] initWithFrame:CGRectMake(0, 100, [UIScreen mainScreen].bounds.size.width, 100)];
    listView.tagDelegate = self;
    listView.automaticResize = YES;
    listView.bottomMargin = 10;
    listView.horizontalPadding = 5;
    listView.verticalPadding = 30;
    listView.minimumWidth = 100;
    listView.cornerRadius = 1.0;
    listView.font = [UIFont systemFontOfSize:11];
    listView.textColor = [UIColor orangeColor];
    [listView setTags:@[@"苹果", @"香蕉", @"西瓜", @"大话西游", @"国产零零零七"]];
    listView.isTouch = NO;
    listView.labelMargin = 10;
    listView.isManySelect = YES;
    [self.view addSubview:listView];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark delegate

- (void)selectedTag:(NSString *)tagName tagIndex:(NSInteger)tagIndex {
    NSLog(@"-=-==-tagName=%@-=-=-=-tagindex=%ld", tagName, tagIndex);
}

- (void)selectedTag:(NSString *)tagName {
    NSLog(@"-------------selectedTag-%@", tagName);
}

- (void)tagListTagsChanged:(MRJTagList *)tagList {
    NSLog(@"-===0909090-=-=-=-%@", tagList);
}

/**
 *  多标签的代理方法
 *
 *  @param tagNames  多标签的名称
 *  @param tagIndexs 多标签的下标值
 */
- (void)selectedTags:(NSArray *)tagNames tagIndex:(NSArray *)tagIndexs {
    NSLog(@"****************%@________________%@", tagNames, tagIndexs);
}

@end
