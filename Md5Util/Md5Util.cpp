//
// (C) Copyright 1974-2015 by Computational Engineering and Information Technology Lab., NTUST.
// 
// Author : Yisheng Kang (M9805508@mail.ntust.edu.tw)
// 2015-03-31
//
#include"Md5Util.h"
using namespace std;

char* Txt2Md5(char* txt) {
	unsigned char c[MD5_DIGEST_LENGTH];

	MD5_CTX mdContext;
	MD5_Init(&mdContext);
	MD5_Update(&mdContext,txt,strlen(txt));
	MD5_Final(c,&mdContext);

	char* result = new char[MD5_DIGEST_LENGTH * 4];
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		sprintf_s(&(result[i * 2]), MD5_DIGEST_LENGTH * 2, "%02x", (unsigned int)c[i]);
	}

	return result;
}

char* File2Md5(char* filename) {
	FILE *inFile;
	fopen_s(&inFile, filename, "rb");
	if(inFile == NULL) {
        printf ("%s can't be opened.\n", filename);
		return NULL;
    }

	int bytes;
	MD5_CTX mdContext;
    unsigned char data[1024];
	unsigned char c[MD5_DIGEST_LENGTH];

	MD5_Init(&mdContext);
    while((bytes = fread(data, 1, 1024, inFile)) != 0) {
        MD5_Update (&mdContext, data, bytes);
	}

	fclose(inFile);
    MD5_Final(c,&mdContext);

	char* result = new char[MD5_DIGEST_LENGTH * 4];
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		sprintf_s(&(result[i * 2]), MD5_DIGEST_LENGTH * 2, "%02x", (unsigned int)c[i]);
	}

	return result;
}