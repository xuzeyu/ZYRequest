//
//  ZYResponseModel.m
//  ZYRequest
//
//  Created by XUZY on 2022/1/25.
//

#import "ZYResponseModel.h"

@implementation ZYResponseModel

- (void)autoSetBackCode:(id)backCode {
    if ([backCode isKindOfClass:[NSString class]]) {
        self.backCodeString = backCode;
        self.backCode = ((NSString *)backCode).intValue;
    }else if ([backCode isKindOfClass:[NSNumber class]]) {
        self.backCodeNumber = backCode;
        self.backCode = ((NSNumber *)backCode).intValue;
    }
}

- (void)setRequestAllTipType:(ZYRequestTipType)requestAllTipType {
    _requestAllTipType = requestAllTipType;
    if (requestAllTipType != ZYRequestTipTypeUnknow) {
        _requestServerSuccessTipType = _requestServerFailTipType = _requestNetworkFailTipType = requestAllTipType;
    }
}

- (void)setRequestAllFailTipType:(ZYRequestTipType)requestAllFailTipType {
    _requestAllFailTipType = requestAllFailTipType;
    if (requestAllFailTipType != ZYRequestTipTypeUnknow) {
        _requestServerFailTipType = _requestNetworkFailTipType = requestAllFailTipType;
    }
}

@end
