//
// (C) Copyright 1974-2015 by Computational Engineering and Information Technology Lab., NTUST.
// 
// Author : Yisheng Kang (M9805508@mail.ntust.edu.tw)
// 2015-03-31
//
#include<openssl/md5.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include"Md5Util.h"
using namespace std;

int main(int argc, char *argv[]) {

	if(argc > 1) {
		char* md5 = NULL;

		if(argc == 3 && argv[1] == "-f" && strlen(argv[2]) > 0) {
			md5 = File2Md5(argv[2]);
		} else if(strlen(argv[1]) > 0) {
			md5 = Txt2Md5(argv[1]);
		}

		if(md5 != NULL) {
			cout<<md5<<endl;
			delete md5;
		}
	} else {
		cout<<"\nUsage:\n\n"
			<<"OpenSSLConsole -f [File Full Path]\n"
			<<"or\n"
			<<"OpenSSLConsole [Text]\n"
			<<"\n\nAuthor: Eason Kang<M9805508@mail.ntust.edu.tw> 2015-03\n\n";
	}

	return 0;
}