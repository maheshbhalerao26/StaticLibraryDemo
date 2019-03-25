#ifndef IP_SPAP_H
#define IP_SPAP_H

#define SUCCESS			0
#define UNSUPPORTED_ALGORITHM	1
#define INSUFFICIENT_MEMORY		2
#define BUFFER_TOO_SMALL		3

int ip_spap_genkey(const char *algorithm,
					char*,
					unsigned int*,
					char*,
					unsigned int*);


char * ip_secure_pap_encrypt(
			const char *algorithm,
			const char *public_key,
			const char *password,
			const char *dialer_id,
			const char *counter,
			char **point,
			char **encrypted_point,
			int *ret_code);

char * ip_secure_pap_decrypt(
			const char *algorithm,
			const char *private_key,
			const char *eccString,
			const char *dialer_id,
			const char *counter,
			int *ret_code);


#endif


