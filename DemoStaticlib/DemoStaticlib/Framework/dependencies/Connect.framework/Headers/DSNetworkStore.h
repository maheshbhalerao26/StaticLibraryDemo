//
//  DSNetworkStore.h
//  Devicescape
//
//  Created by John Gordon on 4/12/16.
//
//

#import <Foundation/Foundation.h>
#import <NetworkExtension/NEHotspotHelper.h>

// Keys for the matchNetwork dictionary
extern NSString * _Nonnull kDSNetworkStoreSSID;
extern NSString * _Nonnull kDSNetworkStoreBSSID;
extern NSString * _Nonnull kDSNetworkStoreSecret;
extern NSString * _Nonnull kDSNetworkStoreAdded;
extern NSString * _Nonnull kDSNetworkStoreSource;
extern NSTimeInterval BlacklistingPeriod;

@interface DSNetworkStore : NSObject

- (id _Nullable) init;
- (void) close;

// Return a matching network; nil if no network matches
- (NSDictionary * _Nullable) matchNetwork:(NEHotspotNetwork * _Nonnull) network;

// Add a locally discovered network
- (void) addLocalNetwork:(NEHotspotNetwork * _Nonnull)network;

// Add a network to the local blacklist
- (void) blacklistNetwork:(NEHotspotNetwork * _Nonnull)network;

// Is a network currently blacklisted?
- (BOOL) isBlacklisted:(NEHotspotNetwork * _Nonnull)network;

// Add encrypted profiles returned from WallAPI
- (void) addUpdateEncProfile:(NSDictionary * _Nonnull)encProfiles;

@end
