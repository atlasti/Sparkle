//
//  SUBundleIcon.h
//  Sparkle
//
//  Created by Mayur Pawashe on 7/24/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SUHost;

@interface SUBundleIcon : NSObject

+ (NSURL *)iconURLForHost:(SUHost *)host;

@end

