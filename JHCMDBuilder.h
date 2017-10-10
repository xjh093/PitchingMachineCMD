//
//  JHCMDBuilder.h
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHCMDHeader.h"

@class JHRequest;

@interface JHCMDBuilder : NSObject

+ (NSData *)build:(JHRequest *)request;

+ (JHReplyCode)parse:(Byte)byte;

@end
