# Crypto Policy Scan Report

- Total findings: 11

## 1. CRYPTO-001 - MD5
- Severity: `critical`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.c:12`
- Matched: `MD5_Init(`
- Source: `MD5_Init(&SHA-3);`
- Recommendation: Use SHA-256 or SHA-3.

## 2. CRYPTO-001 - MD5
- Severity: `critical`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.c:13`
- Matched: `MD5_Update(`
- Source: `MD5_Update(&SHA-3, msg, len);`
- Recommendation: Use SHA-256 or SHA-3.

## 3. CRYPTO-002 - SHA-1
- Severity: `high`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.c:18`
- Matched: `SHA1_Init(`
- Source: `SHA1_Init(&SHA-3);`
- Recommendation: Use SHA-256 or SHA-3.

## 4. CRYPTO-005 - RSA usage
- Severity: `medium`
- Category: `quantum-vulnerable`
- Location: `src/vulnerable_crypto.c:24`
- Matched: `RSA_new(`
- Source: `RSA *rsa = RSA_new();`
- Recommendation: Register this usage in CBOM and plan migration to PQC or hybrid cryptography.

## 5. CRYPTO-006 - ECC usage
- Severity: `medium`
- Category: `quantum-vulnerable`
- Location: `src/vulnerable_crypto.c:31`
- Matched: `EC_KEY_new_by_curve_name(`
- Source: `EC_KEY *ec = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);`
- Recommendation: Consider PQC or hybrid TLS/signature migration.

## 6. CRYPTO-006 - ECC usage
- Severity: `medium`
- Category: `quantum-vulnerable`
- Location: `src/vulnerable_crypto.c:31`
- Matched: `prime256v1`
- Source: `EC_KEY *ec = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);`
- Recommendation: Consider PQC or hybrid TLS/signature migration.

## 7. CRYPTO-003 - DES or ECB mode
- Severity: `high`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.java:9`
- Matched: `Cipher.getInstance("DES`
- Source: `Cipher des = Cipher.getInstance("DES/ECB/PKCS5Padding");`
- Recommendation: Use AES-GCM.

## 8. CRYPTO-003 - DES or ECB mode
- Severity: `high`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.java:10`
- Matched: `AES/ECB`
- Source: `Cipher aesEcb = Cipher.getInstance("AES/ECB/PKCS5Padding");`
- Recommendation: Use AES-GCM.

## 9. CRYPTO-003 - DES or ECB mode
- Severity: `high`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.java:9`
- Matched: `DES/ECB`
- Source: `Cipher des = Cipher.getInstance("DES/ECB/PKCS5Padding");`
- Recommendation: Use AES-GCM.

## 10. CRYPTO-004 - RSA 1024
- Severity: `high`
- Category: `prohibited`
- Location: `src/vulnerable_crypto.java:12`
- Matched: `initialize(1024)`
- Source: `rsa.initialize(1024);`
- Recommendation: Use stronger keys or define a PQC migration plan.

## 11. CRYPTO-005 - RSA usage
- Severity: `medium`
- Category: `quantum-vulnerable`
- Location: `src/vulnerable_crypto.java:11`
- Matched: `KeyPairGenerator.getInstance("RSA"`
- Source: `KeyPairGenerator rsa = KeyPairGenerator.getInstance("RSA");`
- Recommendation: Register this usage in CBOM and plan migration to PQC or hybrid cryptography.
