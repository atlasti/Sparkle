//
//  SUUnarchiverNotifier.h
//  Sparkle
//
//  Created by Mayur Pawashe on 12/21/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SUUnarchiverNotifier : NSObject

- (instancetype)initWithCompletionBlock:(void (^)(NSError *))completionBlock progressBlock:(void (^)(double))progressBlock;

- (void)notifySuccess;

- (void)notifyFailureWithError:(NSError *)reason;

- (void)notifyProgress:(double)progress;

@end

