//
//  SUInstaller.h
//  Sparkle
//
//  Created by Andy Matuschak on 4/10/08.
//  Copyright 2008 Andy Matuschak. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SUVersionComparisonProtocol.h"

@class SUHost;

@protocol SUInstallerProtocol;

@interface SUInstaller : NSObject

+ (id<SUInstallerProtocol>)installerForHost:(SUHost *)host fileOperationToolPath:(NSString *)fileOperationToolPath updateDirectory:(NSString *)updateDirectory error:(NSError **)error;

+ (NSString *)installSourcePathInUpdateFolder:(NSString *)inUpdateFolder forHost:(SUHost *)host isPackage:(BOOL *)isPackagePtr isGuided:(BOOL *)isGuidedPtr;

@end
