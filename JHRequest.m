//
//  JHRequest.m
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import "JHRequest.h"

@implementation JHRequest

- (instancetype)init{
    if (self = [super init]) {
        _address = 0x00;  //默认值
        _offsetX = 50;    //默认值
        _offsetY = 50;    //默认值
    }
    return self;
}

@end
