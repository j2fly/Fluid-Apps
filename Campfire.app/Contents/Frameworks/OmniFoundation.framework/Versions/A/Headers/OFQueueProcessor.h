// Copyright 1997-2005, 2008 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Header: svn+ssh://source.omnigroup.com/Source/svn/Omni/tags/OmniSourceRelease/2008-03-20/OmniGroup/Frameworks/OmniFoundation/Scheduling.subproj/OFQueueProcessor.h 98221 2008-03-04 21:06:19Z kc $

#import <OmniFoundation/OFObject.h>

@class NSLock;
@class OFInvocation, OFMessageQueue;

#import <Foundation/NSDate.h>
#import <OmniFoundation/OFMessageQueuePriorityProtocol.h> // For OFMessageQueueSchedulingInfo

@interface OFQueueProcessor : OFObject
{
    OFMessageQueue *messageQueue;

    NSLock *currentInvocationLock;
    OFInvocation *currentInvocation;
    OFMessageQueueSchedulingInfo schedulingInfo;
}

- initForQueue:(OFMessageQueue *)aQueue;

- (void)processQueueUntilEmpty;
- (void)processQueueForever;
- (void)startProcessingQueueInNewThread;

- (void)processQueueUntilEmpty:(BOOL)onlyUntilEmpty forTime:(NSTimeInterval)maximumTime;

- (OFMessageQueueSchedulingInfo)schedulingInfo;

@end

extern BOOL OFQueueProcessorDebug;
