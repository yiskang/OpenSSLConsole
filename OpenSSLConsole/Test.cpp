//
// (C) Copyright 1974-2015 by Computational Engineering and Information Technology Lab., NTUST.
// 
// Author : Yisheng Kang (M9805508@mail.ntust.edu.tw)
// 2015-03-31
//
#include"Md5Util.h"
#include<iostream>
using namespace std;

void md5File() {
	unsigned char c[MD5_DIGEST_LENGTH];
    char *filename="C:\\Users\\Administrator\\Documents\\Visual Studio 2012\\Projects\\OpenSSLConsole\\OpenSSLConsole\\Debug\\test.txt";
    int i;
	FILE *inFile;
	fopen_s(&inFile, filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL) {
        printf ("%s can't be opened.\n", filename);
        return;
    }

    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    for(i = 0; i < MD5_DIGEST_LENGTH; i++) printf("%02x", c[i]);
	printf("\n");
    printf (" %s\n", filename);
    fclose (inFile);
}

void md5Txt(char* txt) {
	unsigned char c[MD5_DIGEST_LENGTH];

	MD5_CTX mdContext;
	MD5_Init (&mdContext);
	MD5_Update (&mdContext, txt, strlen(txt));
	MD5_Final (c,&mdContext);

	char result[256];
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		//printf("%02x", (unsigned int)c[i]);

		sprintf_s(&(result[i*2]), 16*2, "%02x", (unsigned int)c[i]);
	}

	cout<<result<<endl;
}