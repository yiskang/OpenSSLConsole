//
// (C) Copyright 1974-2015 by Computational Engineering and Information Technology Lab., NTUST.
// 
// Author : Yisheng Kang (M9805508@mail.ntust.edu.tw)
// 2015-03-31
//
#ifndef _MD5UTIL_H_
#define _MD5UTIL_H_
#include<openssl/md5.h>
#include<string.h>
#include<stdio.h>

char* Txt2Md5(char* txt);

char* File2Md5(char* filename);
#endif