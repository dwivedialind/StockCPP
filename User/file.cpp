#include<iostream>
using namespace std;
#include <iostream>
#include <string>
#include <cstring> // for memcmp
#include <random> // for secure random number generation

#define MD5_DIGEST_LENGTH 64
#define SALT_LENGTH 32


class User {
private:
    std::string username;
    char hashedPassword[MD5_DIGEST_LENGTH]; // Assuming MD5 for now (consider bcrypt later)
    std::string salt; // Salt for additional security

public:
    // ... other member functions

    void setPassword(const std::string& password) {
        // Generate a random salt
        salt = generateRandomString(SALT_LENGTH);

        // Hash the password with salt
        std::string saltedPassword = password + salt;
        hashPassword(saltedPassword.c_str(), hashedPassword);
    }

    bool verifyPassword(const std::string& password) const {
        // Combine password with stored salt
        std::string saltedPassword = password + salt;

        // Hash the provided password with salt and compare with stored hash
        char tempHash[MD5_DIGEST_LENGTH];
        //hashPassword(saltedPassword.c_str(), tempHash);
        return memcmp(hashedPassword, tempHash, MD5_DIGEST_LENGTH) == 0;
    }

private:
    // Function to generate a random string of specified length for salt
    std::string generateRandomString(int length) {
        std::random_device rd; // Use a secure random number generator
        std::mt19937 gen(rd());
        std::uniform_int_distribution<char> dis('a', 'z' + 'Z' - 'a' + '0' - '9' + 9);

        std::string salt;
        salt.reserve(length);
        for (int i = 0; i < length; ++i) {
            salt += dis(gen);
        }
        return salt;
    }

    // Replace with an actual hashing function call (e.g., using a library for bcrypt)
    void hashPassword(const char* password, char* outputHash);  
};
