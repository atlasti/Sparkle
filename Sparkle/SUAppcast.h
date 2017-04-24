//
//  SUAppcast.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/12/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#ifndef SUAPPCAST_H
#define SUAPPCAST_H

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
#import "SUExport.h"

@class SUAppcastItem;
SU_EXPORT @interface SUAppcast : NSObject<NSURLDownloadDelegate>

@property (copy) NSString *userAgentString;

#if __has_feature(objc_generics)
@property (copy) NSDictionary<NSString *, NSString *> *httpHeaders;
#else
@property (copy) NSDictionary *httpHeaders;
#endif

- (void)fetchAppcastFromURL:(NSURL *)url inBackground:(BOOL)bg completionBlock:(void (^)(NSError *))err;
- (SUAppcast *)copyWithoutDeltaUpdates;

@property (readonly, copy) NSArray *items;
@end

#endif
