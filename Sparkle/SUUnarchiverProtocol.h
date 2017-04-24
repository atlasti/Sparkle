//
//  SUUnarchiverProtocol.h
//  Sparkle
//
//  Created by Mayur Pawashe on 3/26/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SUUnarchiverProtocol <NSObject>

+ (BOOL)canUnarchivePath:(NSString *)path;

+ (BOOL)unsafeIfArchiveIsNotValidated;

- (void)unarchiveWithCompletionBlock:(void (^)(NSError *))completionBlock progressBlock:(void (^)(double))progressBlock;

- (NSString *)description;

@end

