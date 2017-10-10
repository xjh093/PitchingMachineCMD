//
//  JHCMDBuilder.m
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import "JHCMDBuilder.h"
#import "JHRequest.h"

@implementation JHCMDBuilder

+ (NSData *)build:(JHRequest *)request
{
    NSInteger length = 45;           /**< 具体命令长度不同 */
    Byte cmd[length];
    
    cmd[0]  = 0xfa;                         /**< 同步头 */
    cmd[1]  = (Byte)37;                     /**< 数据长度：9+28 */
    cmd[2]  = request.cmdType;              /**< 命令 */
    cmd[3]  = request.machineType;          /**< 设备 */
    cmd[4]  = request.modelType;            /**< 机型 */
    cmd[5]  = (Byte)request.address;        /**< 机器地址 */
    cmd[6]  = (Byte)request.onOrOff;        /**< 开 或 关 */
    cmd[7]  = (Byte)request.motor1Speed;    /**< 马达1速度 */
    cmd[8]  = (Byte)request.motor2Speed;    /**< 马达2速度 */
    cmd[9]  = (Byte)request.motor3Speed;    /**< 马达3速度 */
    cmd[10] = request.mode;                 /**< 模式 */
    cmd[11] = (Byte)request.positionX;      /**< 定点X */
    cmd[12] = (Byte)request.positionY;      /**< 定点Y */
    cmd[13] = (Byte)request.offsetX;        /**< X偏移量 */
    cmd[14] = (Byte)request.offsetY;        /**< Y偏移量 */
    
    /**< 用户编程模式：28个点 */
    NSInteger index = 15;
    if (request.dataArray.count < 28) {   //不够28个点
        for (NSInteger i = 0; i < 28 - request.dataArray.count; i++) {
            [request.dataArray addObject:@(0)];
        }
    }
    
    for (NSInteger i = 0; i < request.dataArray.count ; i++) {
        cmd[index++] = (Byte)[request.dataArray[i] integerValue];
    }
    
    cmd[43] = [self sum:cmd start:1 end:length - 2];     /**< 校验和 */
    cmd[44] = 0xfb;                                      /**< 同步尾 */
    
    return [NSData dataWithBytes:cmd length:length];
}

+ (Byte)sum:(Byte *)cmd start:(NSInteger)start end:(NSInteger)end  /**< 校验和 */
{
    if (cmd == nil || start < 1 || start > end) {
        return 0;
    }
    
    NSInteger sum = 0;
    for (NSInteger i = start; i < end; i++) {
        sum ^= cmd[i];
    }
    
    return (Byte)sum;
}

+ (JHReplyCode)parse:(Byte)byte  /**< 解析 */
{
    JHReplyCode code;
    
    switch (byte) {
        case 0x00:
            code = JHReplyCode_OK;
            break;
        case 0x10:
            code = JHReplyCode_ConnectError;
            break;
        case 0x21:
            code = JHReplyCode_Motor1Error;
            break;
        case 0x22:
            code = JHReplyCode_Motor2Error;
            break;
        case 0x23:
            code = JHReplyCode_Motor3Error;
            break;
        case 0x31:
            code = JHReplyCode_XStepMotorError;
            break;
        case 0x32:
            code = JHReplyCode_YStepMotorError;
            break;
        case 0x41:
            code = JHReplyCode_XSensorError;
            break;
        case 0x42:
            code = JHReplyCode_YSensorError;
            break;
        case 0x50:
            code = JHReplyCode_PowerOffError;
            break;
        case 0x60:
            code = JHReplyCode_StartingError;
            break;
        case 0x70:
            code = JHReplyCode_NoBallOrTimeOut;
            break;
        default:
            break;
    }
    return code;
}

@end
