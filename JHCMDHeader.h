//
//  JHCMDHeader.h
//  JHKit
//
//  Created by HaoCold on 16/8/24.
//  Copyright © 2016年 HaoCold. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, JHCMDType){ /**< 命令类型 */
    JHCMDTypeOne     = 0x00, /**< 不操作 */
    JHCMDTypeTwo     = 0x01, /**< 修改设备热点 WIFI 的 SSID 和 PASSWORD*/
    JHCMDTypeThree   = 0x02, /**< 修改设备热点 WIFI 的 IP 地址 */
};

typedef NS_ENUM(NSInteger, JHMachineType){ /**< 设备类型 */
    JHMachineTypeOne    = 0x01,   /**< 网球机 */
    JHMachineTypeTwo    = 0x02,   /**< 羽毛球机 */
    JHMachineTypeThree  = 0x03,   /**< 乒乓球机 */
    JHMachineTypeFour   = 0x04,   /**< 足球机 */
    JHMachineTypeFive   = 0x05,   /**< 篮球机 */
    JHMachineTypeSix    = 0x06,   /**< 排球机 */
    JHMachineTypeSeven  = 0x07,   /**< 拉线机 */
};

typedef NS_ENUM(NSInteger, JHModelType){  /**< 设备机型 */
    JHModelTypeOne   = 0x01,  /**< 机型一 */
    JHModelTypeTwo   = 0x02,  /**< 机型二 */
    JHModelTypeThree = 0x03,  /**< 机型三 */
};

typedef NS_ENUM(NSInteger, JHModeType){  /**< 发球模式 */
    JHModeTypeOne       = 0x10,   /**< 定点 */
    JHModeTypeTwo       = 0x20,   /**< 高低循环 */
    JHModeTypeThree     = 0x21,   /**< 深浅球 */
    JHModeTypeFour      = 0x30,   /**< 水平循环 */
    JHModeTypeFive      = 0x31,   /**< 宽两线球 */
    JHModeTypeSix       = 0x32,   /**< 中两线球 */
    JHModeTypeSeven     = 0x33,   /**< 窄两线球 */
    JHModeTypeEight     = 0x34,   /**< 三线球 */
    JHModeTypeNine      = 0x40,   /**< 随机模式 */
    JHModeTypeTen       = 0x51,   /**< 交叉循环模式1 */
    JHModeTypeEleven    = 0x52,   /**< 交叉循环模式2 */
    JHModeTypeTwelve    = 0x53,   /**< 交叉循环模式3 */
    JHModeTypeThirteen  = 0x54,   /**< 交叉循环模式4 */
    JHModeTypeFourteen  = 0x55,   /**< 交叉循环模式5 */
    JHModeTypeFifteen   = 0x56,   /**< 交叉循环模式6 */
    JHModeTypeSixteen   = 0x60,   /**< 用户编程模式 */
    JHModeTypeSeventeen = 0x70,   /**< 机械偏移 */
};

typedef NS_ENUM(NSInteger, JHReplyCode){  /**< 发球机返回指令 */
    JHReplyCode_OK              = 0x00,   /**< 无故障 */
    JHReplyCode_ConnectError    = 0x10,   /**< 通信故障 */
    JHReplyCode_Motor1Error     = 0x21,   /**< 马达1故障 */
    JHReplyCode_Motor2Error     = 0x22,   /**< 马达2故障 */
    JHReplyCode_Motor3Error     = 0x23,   /**< 马达3故障 */
    JHReplyCode_XStepMotorError = 0x31,   /**< X步进马达故障 */
    JHReplyCode_YStepMotorError = 0x32,   /**< Y步进马达故障 */
    JHReplyCode_XSensorError    = 0x41,   /**< X传感器故障 */
    JHReplyCode_YSensorError    = 0x42,   /**< Y传感器故障 */
    JHReplyCode_PowerOffError   = 0x50,   /**< 供电不足 */
    JHReplyCode_StartingError   = 0x60,   /**< 正在启动 */
    JHReplyCode_NoBallOrTimeOut = 0x70,   /**< 无球或超时 */
};


