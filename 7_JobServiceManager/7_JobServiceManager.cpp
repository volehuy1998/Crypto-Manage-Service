// 7_JobServiceManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Native-Des-Lib/NativeDesDLL/NativeDes.h"

static void print_data(const char* tittle, unsigned char data[], int len)
{
    printf("%s : ", tittle);
    const unsigned char* p = (const unsigned char*)data;

    for (int i = 0; i < len; ++i)
        printf("%c", *p++);

    printf("\n");
}

int main()
{
    unsigned char input[] = "volehuy11";
    const char *key = "huy";
    const char *key1 = "huy";
    int input_len = strlen((const char*)input);
    bool is_require_padding = DES_KEY_SZ - (input_len % DES_KEY_SZ) >= 0 ? true : false;
    int cipher_len = ((input_len / DES_KEY_SZ) + 1) * DES_KEY_SZ;
    int decrypted_len = cipher_len;
    unsigned char *cipher = (unsigned char*)calloc(cipher_len, 1);
    unsigned char *decrypted = (unsigned char*)calloc(decrypted_len, 1);

    des_ecb_with_str_key(input, input_len, key, cipher, &cipher_len, 1);
    des_ecb_with_str_key(cipher, cipher_len, key1, decrypted, &decrypted_len, 0);
    print_data("Encrypted", cipher, cipher_len);
    print_data("Decrypted", decrypted, decrypted_len);
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //memset(cipher, 0, cipher_len);
    //memset(decrypted, 0, decrypted_len);
    //cipher_len = 0;
    //decrypted_len = 0;
    //unsigned long long my_key = des_random_key();
    //des_ecb(input, input_len, my_key, cipher, &cipher_len, 1);
    //des_ecb(cipher, cipher_len, my_key, decrypted, &decrypted_len, 0);
    //decrypted[decrypted_len] = 0x0;
    //print_data("Encrypted", cipher, cipher_len);
    //print_data("Decrypted", decrypted, decrypted_len);

    free(cipher);
    free(decrypted);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
