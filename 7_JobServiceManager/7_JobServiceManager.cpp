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
        //DES_CBC();
        //DES_ECB();
        unsigned char input[] = "volehuy";
        const char *key = "huy";
        const char *key1 = "huy";
        unsigned char output[sizeof input];
        unsigned char output2[sizeof input];
        des_ecb_with_str_key(input, key, output, 1);
        des_ecb_with_str_key(output, key1, output2, 0);
        print_data("Encrypted", output, sizeof input);
        print_data("Decrypted", output2, sizeof input);

        memset(output, 0, sizeof input);
        memset(output2, 0, sizeof input);
        unsigned long long my_key = des_random_key();
        des_ecb(input, my_key, output, 1);
        my_key -= 1;
        ++my_key;
        des_ecb(output, my_key, output2, 0);
        //des_ecb(input, sizeof input, my_key, output, 1);
        //des_ecb(output, sizeof input, my_key, output2, 0);
        print_data("Encrypted", output, sizeof input);
        print_data("Decrypted", output2, sizeof input);
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
