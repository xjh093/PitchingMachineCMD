//
//  JHNetManager.h
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHRequest.h"

@interface JHNetManager : NSObject

+ (instancetype)manager;

- (void)sendDataToDevice:(JHRequest *)request callBack:(void(^)(JHReplyCode replyCode))block;  /**< 发送数据 */

@end
