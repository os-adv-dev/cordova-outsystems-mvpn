//
//  NSURL+Utils.h
//  CitrixMicroVPN
//
//  Created on 2/10/17.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (Utils)

// Returns the all of the url string after the scheme and domain
// e.g. for URL "http://www.subdomain.domain.com:1234/path1/path2?key=value
//      returns "/path1/path2?key=value
// This is necessary because -path and -relativePath perform percent decoding
// This version simply removes the scheme and domain, leaving the path and query (unmodified)
// We need this to resolve BUG0660693 and BUG0670886
- (NSString *)pathAndQuery;

-(NSString*) strippedDownURLString;

@end
