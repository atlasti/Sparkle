//
//  SUUnarchiver.h
//  Sparkle
//
//  Created by Andy Matuschak on 3/16/06.
//  Copyright 2006 Andy Matuschak. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SUUnarchiverProtocol;

@interface SUUnarchiver : NSObject

+ (id <SUUnarchiverProtocol>)unarchiverForPath:(NSString *)path updatingHostBundlePath:(NSString *)hostPath decryptionPassword:(NSString *)decryptionPassword;

@end

