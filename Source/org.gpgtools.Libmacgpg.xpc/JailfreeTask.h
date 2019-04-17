//
//  GPGXPCTask.h
//  Libmacgpg
//
//  Created by Lukas Pitschl on 28.09.12.
//
//
#import "JailfreeProtocol.h"
#import <Foundation/Foundation.h>

@interface JailfreeTask :  NSObject <Jailfree> {
	NSXPCConnection * __weak _xpcConnection;
    id _paddle;
}

- (void)testConnection:(void (^)(BOOL))reply;

#pragma mark - GPGTaskHelper RPC methods
- (void)launchGPGWithArguments:(NSArray *)arguments data:(NSData *)data readAttributes:(BOOL)readAttributes closeInput:(BOOL)closeInput reply:(void (^)(NSDictionary *))reply;
- (void)launchGeneralTask:(NSString *)path withArguments:(NSArray *)arguments wait:(BOOL)wait reply:(void (^)(BOOL))reply;

#pragma mark - GPGWatcher RPC methods
- (void)startGPGWatcher;

#pragma mark - Methods read from 
- (void)loadConfigFileAtPath:(NSString *)path reply:(void (^)(NSString *))reply;
- (void)loadUserDefaultsForName:(NSString *)domainName reply:(void (^)(NSDictionary *))reply;
- (void)setUserDefaults:(NSDictionary *)domain forName:(NSString *)domainName reply:(void (^)(BOOL result))reply;

- (void)isPassphraseForKeyInGPGAgentCache:(NSString *)key reply:(void (^)(BOOL))reply;
- (void)validSupportContractAvailableForProduct:(NSString *)identifier reply:(void (^)(BOOL, NSDictionary *))reply;

@property (nonatomic, weak) NSXPCConnection *xpcConnection;

@end
