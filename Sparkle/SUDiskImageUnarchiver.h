//
//  SUDiskImageUnarchiver.h
//  Sparkle
//
//  Created by Andy Matuschak on 6/16/08.
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#ifndef SUDISKIMAGEUNARCHIVER_H
#define SUDISKIMAGEUNARCHIVER_H

#import <Foundation/Foundation.h>
#import "SUUnarchiverProtocol.h"

@interface SUDiskImageUnarchiver : NSObject <SUUnarchiverProtocol>

- (instancetype)initWithArchivePath:(NSString *)archivePath decryptionPassword:(NSString *)decryptionPassword;

@end

#endif
