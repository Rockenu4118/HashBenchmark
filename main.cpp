#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <string>
#include <openssl/sha.h>
#include <openssl/evp.h>

using namespace std;

string SHA3(const string& unhashed) {
	string hashStr;

	EVP_MD_CTX* ctx = EVP_MD_CTX_new();
	
	if (ctx != NULL) {
		if (EVP_DigestInit_ex(ctx, EVP_sha3_256(), nullptr)) {
			if (EVP_DigestUpdate(ctx, unhashed.c_str(), unhashed.length())) {
				unsigned char hash[EVP_MAX_MD_SIZE];
				unsigned int lengthOfHash = 0;

				if (EVP_DigestFinal_ex(ctx, hash, &lengthOfHash)) {
					stringstream ss;

					for (unsigned int i = 0 ; i < lengthOfHash ; i++) {
						ss << hex << setw(2) << setfill('0') << (int)hash[i];
					}
							
					hashStr = ss.str();
				}	
			}
		}
		EVP_MD_CTX_free(ctx);
	}

	return hashStr;
}



int main(int argc, char** argv) {
	cout << "Program Running...\n";


	string hash = SHA3("hello");

	cout << "Hash: " << hash << "\n";

	auto start = chrono::steady_clock::now();

	for (int i = 0 ; i < 1000000 ; i++ )
		hash = SHA3("word");

	auto end = chrono::steady_clock::now();

	auto elapsed_time = chrono::duration<double>(end - start);

	cout << "Elapsed Time: " << elapsed_time.count() << "\n";


	return 0;
}
