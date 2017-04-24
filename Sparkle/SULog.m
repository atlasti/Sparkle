//
//  SULog.m
//  Sparkle
//
//  Created by Mayur Pawashe on 5/18/16.
//  Copyright © 2016 Sparkle Project. All rights reserved.
//

#include "SULog.h"
#include <asl.h>
#import "SUOperatingSystem.h"

// For converting constants to string literals using the preprocessor
#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

#include "AppKitPrevention.h"

void SULog(SULogLevel level, NSString *format, ...)
{
    static aslclient client;
    static dispatch_queue_t queue;
    static dispatch_once_t onceToken;

    static BOOL hasOSLogging = NO;

    dispatch_once(&onceToken, ^{
        NSBundle *mainBundle = [NSBundle mainBundle];

        hasOSLogging = [SUOperatingSystem isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion){10, 12, 0}];

        {
            uint32_t options = ASL_OPT_NO_DELAY;
            // Act the same way os_log() does; don't log to stderr if a terminal device is attached
            if (!isatty(STDERR_FILENO)) {
                options |= ASL_OPT_STDERR;
        }
            
            NSString *displayName = [[NSFileManager defaultManager] displayNameAtPath:mainBundle.bundlePath];
            client = asl_open([displayName stringByAppendingString:@" [Sparkle]"].UTF8String, SPARKLE_BUNDLE_IDENTIFIER, options);
            queue = dispatch_queue_create(NULL, DISPATCH_QUEUE_SERIAL);
        }
    });

    if (!hasOSLogging && client == NULL) {
        return;
    }

    va_list ap;
    va_start(ap, format);
    NSString *logMessage = [[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    
    // Otherwise use ASL
    // Make sure we do not async, because if we async, the log may not be delivered deterministically
    dispatch_sync(queue, ^{
        aslmsg message = asl_new(ASL_TYPE_MSG);
        if (message == NULL) {
            return;
        }

        if (asl_set(message, ASL_KEY_MSG, logMessage.UTF8String) != 0) {
            return;
        }
        
        int levelSetResult;
        switch (level) {
            case SULogLevelDefault:
                // Just use one level below the error level
                levelSetResult = asl_set(message, ASL_KEY_LEVEL, TO_STRING(ASL_LEVEL_WARNING));
                break;
            case SULogLevelError:
                levelSetResult = asl_set(message, ASL_KEY_LEVEL, TO_STRING(ASL_LEVEL_ERR));
                break;
        }
        if (levelSetResult != 0) {
            return;
        }
        
        asl_send(client, message);
    });
}
