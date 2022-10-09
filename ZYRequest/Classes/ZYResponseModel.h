//
//  ZYResponseModel.h
//  ZYRequest
//
//  Created by XUZY on 2022/1/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//服务器请求提示类型
typedef NS_ENUM(NSUInteger, ZYRequestTipType) {
    ZYRequestTipTypeUnknow = 0,
    ZYRequestTipTypeNone,                  //不提示
    ZYRequestTipTypeToast,                     //toast
    ZYRequestTipTypeAlert,                     //alert
};

@interface ZYResponseModel : NSObject
@property (nonatomic, strong) NSURLSessionDataTask *task;

@property (nonatomic, strong) NSError *networkError;
@property (nonatomic, assign) ZYRequestTipType requestServerBackTipType; //后台返回的提示类型
@property (nonatomic, strong) NSNumber *backCodeNumber;
@property (nonatomic, strong) NSString *backCodeString;
@property (nonatomic, assign) int backCode;
@property (nonatomic, assign) BOOL isSuccess;
@property (nonatomic, strong) NSString *successDesc; //BackMsg
@property (nonatomic, strong) NSString *errorDesc; //BackMsg
@property (nonatomic, strong, nullable) NSObject *responseObject; //完整返回的数据字典
@property (nonatomic, strong) NSDictionary *responseDataDictionary; //解析key为Data字典
@property (nonatomic, strong) NSArray *responseDataArray; //解析key为Data数组
@property (nonatomic, copy) NSString *responseDataString; //解析key为Data字符串
@property (nonatomic, strong) NSNumber *responseDataNumber; //解析key为Data number
@property (nonatomic, assign) ZYRequestTipType requestServerSuccessTipType; //请求服务器成功提示
@property (nonatomic, assign) ZYRequestTipType requestServerFailTipType;  //请求服务器失败提示
@property (nonatomic, assign) ZYRequestTipType requestNetworkFailTipType; //请求服务器网络错误提示，默认toast
@property (nonatomic, assign) ZYRequestTipType requestAllTipType; //所有成功与失败提示统一设置
@property (nonatomic, assign) ZYRequestTipType requestAllFailTipType; //所有失败统一设置 优先级高于 requestAllTipType

/* 成功alert后，点击 确定 按钮后触发 */
@property (nonatomic, strong) void(^successMsgBlock)(void); //成功提示
/* 失败alert后，点击 确定 按钮后触发 */
@property (nonatomic, strong) void(^networkTimeOutBlock)(void); //网络连接失败
@property (nonatomic, strong) void(^serverErrorResponseBlock)(void); //后台返回错误信息
@property (nonatomic, strong) void(^errorBlock)(void); //包含以上两个的失败返回

- (void)autoSetBackCode:(id)backCode; //根据backcode类型自动设置给backCodeNumber，backCodeString backCode
@end

typedef void(^ZYRequestComplete)(ZYResponseModel *responseModel);
NS_ASSUME_NONNULL_END
