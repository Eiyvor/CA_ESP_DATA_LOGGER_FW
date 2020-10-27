#ifndef AmazonSecrets_h
#define AmazonSecrets_h

// Amazon's root CA. This should be the same for everyone.
const char AWS_CERT_CA[] = "-----BEGIN CERTIFICATE-----\n" \
"\n"\
"-----END CERTIFICATE-----\n";

// The private key for your device
const char AWS_CERT_PRIVATE[] ="-----BEGIN RSA PRIVATE KEY-----\n" \
"\n"\
"-----END RSA PRIVATE KEY-----\n";



// The certificate for your device
const char AWS_CERT_CRT[] ="-----BEGIN CERTIFICATE-----\n" \
"\n" \
"-----END CERTIFICATE-----\n";






#endif
