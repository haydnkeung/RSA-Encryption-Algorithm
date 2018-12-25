# RSA-Encryption-Algorithm
This RSA Encryption implementation is by Haydn Keung.

Please note that Euler's totient is implemented instead of Carmichea's totient for the setup of RSA
All implementation of the RSA utilizes only the naive algorithm.
Systems of linear congruences are solved by converting them into linear diophantine equations and applying the Extended Euculidan Algorithm (EEA)
/Bezout's Lemma with back subsitution.

It is recommended that you have a data type that can store the keys before using. This program by defaults utilizes int (4-bytes)
for setup and encryption, and unsigned long (4 bytes).

Constant Macros are defined in encryption and decryption as an example on how to use to program. Please change as approtiate.
All variables used in the program is consistent to the RSA algorithm found on wikipedia. https://simple.wikipedia.org/wiki/RSA_algorithm

All software are provided as is.
