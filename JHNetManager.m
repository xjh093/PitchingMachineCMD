//
//  JHNetManager.m
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import "JHNetManager.h"
#import "GCDAsyncSocket.h"
#import "JHCMDBuilder.h"
#import "JHRequest.h"
#import "JHCMDHeader.h"

@interface JHNetManager()<GCDAsyncSocketDelegate>

@property (strong,  nonatomic) GCDAsyncSocket       *socket;
@property (copy,    nonatomic) void (^callBackBlock)(JHReplyCode replyCode);

@end

@implementation JHNetManager

+ (instancetype)manager
{
    static JHNetManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[JHNetManager alloc] init];
    });
    return manager;
}

- (instancetype)init
{
    if (self = [super init]) {
        [self connectToDevice:@"192.169.1.121"];
    }
    return self;
}

- (void)connectToDevice:(NSString *)host
{
    _socket = [[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_main_queue()];
    NSError *error = nil;
    [_socket connectToHost:host onPort:8080 error:&error];
    if (error) {
        NSLog(@"connectToHost error:%@",[error localizedDescription]);
    }
}

- (void)sendDataToDevice:(JHRequest *)request callBack:(void(^)(JHReplyCode replyCode))block
{
    //合成指令
    NSData *sendData = [JHCMDBuilder build:request];
    if (sendData == nil) {
        return;
    }
    
    _callBackBlock = block;
    
    [_socket writeData:sendData withTimeout:-1 tag:0];
}

#pragma mark - GCDAsyncSocketDelegate
- (void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port
{
    //已经连接
}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)err
{
    //断开连接
}

- (void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag
{
    //解析数据
    Byte *bytes = (Byte *)data.bytes;
    
    //用block回传数据
    _callBackBlock([JHCMDBuilder parse:bytes[1]]);
    
    //
    [sock readDataWithTimeout:-1 tag:0];
}

@end





