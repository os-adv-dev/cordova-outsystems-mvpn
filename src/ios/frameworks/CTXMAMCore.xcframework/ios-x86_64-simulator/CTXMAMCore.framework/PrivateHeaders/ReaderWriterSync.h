//
//  ReaderWriterSync.h
//  QingApp1
//
//  Created by Qing Dai on 9/14/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReaderWriterSync : NSObject <NSCoding>

- (instancetype) initWithLabel: (NSString*)qName;

-(void) read: (dispatch_block_t) readBlock;
- (void) write: (dispatch_block_t) writeBlock;

@end
