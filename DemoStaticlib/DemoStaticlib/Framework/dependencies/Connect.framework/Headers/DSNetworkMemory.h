//
//  DSNetworkStore.h
//  Devicescape
//
//  Created by John Gordon on 4/12/16.
//
//

#import <Foundation/Foundation.h>
#import <NetworkExtension/NEHotspotHelper.h>
#import "DSNetworkStore.h"

@interface DSNetworkMemory : DSNetworkStore

- (id _Nullable) initWithNetworks:(NSDictionary * _Nonnull)networks;
- (void) close;

// Return a matching network; nil if no network matches
- (NSDictionary * _Nullable) matchNetwork:(NEHotspotNetwork * _Nonnull) network;

// Add a locally discovered network
- (void) addLocalNetwork:(NEHotspotNetwork * _Nonnull)network;

// Add a network to the local blacklist
- (void) blacklistNetwork:(NEHotspotNetwork * _Nonnull)network;

// Is a network currently blacklisted?
- (BOOL) isBlacklisted:(NEHotspotNetwork * _Nonnull)network;

@end
