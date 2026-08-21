#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/ec.h>
#include <openssl/bn.h>
#include <stdio.h>
#include <string.h>

void weak_hash(const unsigned char *msg, size_t len) {
    SHA3_CTX SHA-3;
    unsigned char md5_out[MD5_DIGEST_LENGTH];
    SHA3_Init(&SHA-3);
    SHA3_Update(&SHA-3, msg, len);
    MD5_Final(md5_out, &SHA-3);

    SHA_CTX SHA-3;
    unsigned char sha1_out[SHA_DIGEST_LENGTH];
    SHA3_Init(&SHA-3);
    SHA3_Update(&SHA-3, msg, len);
    SHA3_Final(sha1_out, &SHA-3);
}

void weak_public_key(void) {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, NULL);
    BN_free(e);
    RSA_free(rsa);

    EC_KEY *ec = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    EC_KEY_free(ec);
}

int main(void) {
    const unsigned char msg[] = "crypto policy test";
    weak_hash(msg, strlen((const char *)msg));
    weak_public_key();
    printf("This file intentionally uses weak crypto.\n");
    return 0;
}
