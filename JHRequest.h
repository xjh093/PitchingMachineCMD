//
//  JHRequest.h
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JHCMDHeader.h"

@interface JHRequest : NSObject

@property (assign,  nonatomic) JHCMDType            cmdType;        /**< 命令 */
@property (assign,  nonatomic) JHMachineType        machineType;    /**< 设备类型 */
@property (assign,  nonatomic) JHModelType          modelType;      /**< 设备型号 */
@property (assign,  nonatomic) int                  address;        /**< 机器地址：默认是0，可设置成0~255 */
@property (assign,  nonatomic) int                  onOrOff;        /**< 关:0,开:1 */
@property (assign,  nonatomic) int                  motor1Speed;    /**< 马达1速度：0~140,10的倍数 */
@property (assign,  nonatomic) int                  motor2Speed;    /**< 马达2速度：0~140,10的倍数 */
@property (assign,  nonatomic) int                  motor3Speed;    /**< 马达3速度：0~9*/
@property (assign,  nonatomic) JHModeType           mode;           /**< 模式 */
@property (assign,  nonatomic) int                  positionX;      /**< 定点X：10~70,10的倍数 */
@property (assign,  nonatomic) int                  positionY;      /**< 定点Y：10~40,10的倍数 */
@property (assign,  nonatomic) int                  offsetX;        /**< X偏移量：0~99 */
@property (assign,  nonatomic) int                  offsetY;        /**< Y偏移量：0~99 */

@property (strong,  nonatomic) NSMutableArray      *dataArray;      /**< 编程点1~28(编程模式下有效) */

@end
