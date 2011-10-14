// Copyright 1997-2005, 2008 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Header: svn+ssh://source.omnigroup.com/Source/svn/Omni/tags/OmniSourceRelease/2008-03-20/OmniGroup/Frameworks/OmniFoundation/FileManagement.subproj/OFUnixFile.h 98221 2008-03-04 21:06:19Z kc $

#import <OmniFoundation/OFFile.h>

typedef enum {
    OFFILETYPE_DIRECTORY, OFFILETYPE_CHARACTER, OFFILETYPE_BLOCK, OFFILETYPE_REGULAR, OFFILETYPE_SOCKET
} OFFileType;

@interface OFUnixFile : OFFile
{
    BOOL hasInfo, symLink;
    OFFileType fileType;
    NSNumber *size;
    NSCalendarDate *lastChanged;
}

- (NSString *)shortcutDestination;
- (BOOL)copyToPath:(NSString *)destinationPath;

@end

extern NSString * const OFUnixFileGenericFailureException;
