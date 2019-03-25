//
//  DSNetworkDatabase.h
//  Devicescape
//
//  Created by John Gordon on 4/12/16.
//
//

#import <Foundation/Foundation.h>
#import <NetworkExtension/NEHotspotHelper.h>
#import "DSNetworkStore.h"

@interface DSNetworkDatabase : DSNetworkStore

- (id _Nullable) initWithDatabaseName:(NSString * _Nonnull)name;
- (void) close;

// Return the version of the currently installed database
- (NSInteger) databaseVersion;

// Return a matching network; nil if no network matches
- (NSDictionary * _Nullable) matchNetwork:(NEHotspotNetwork * _Nonnull) network;

// Add a locally discovered SSID
- (void) addLocalNetwork:(NEHotspotNetwork * _Nonnull)network;

// Add a network to the local blacklist
- (void) blacklistNetwork:(NEHotspotNetwork * _Nonnull)network;

// Is a network currently blacklisted?
- (BOOL) isBlacklisted:(NEHotspotNetwork * _Nonnull)network;

// Add encrypted profiles returned from WallAPI
- (void) addUpdateEncProfile:(NSDictionary * _Nonnull)encProfiles;

@end
