#include<iostream>
#include <string.h>
#include <sodium.h>
#include <assert.h>

#define OUTSIZE 4000 // Output hash size
#define OUTLEN 30 //Max length of output hash to be printed
#define INSIZE 1000 // Max input string size

int main(int argc,char** argv){
	if(argc!=3){
		std::cout<<"<Usage> ./test <String> <Key>"<<std::endl;
		exit(0);
	}
	const unsigned char in[INSIZE]={0};
	//Retreive the first argument and store it in input string
	strcpy((char*)in,argv[1]);
	std::cout<<"Entered String: "<<in<<std::endl;
	size_t inlen;
	inlen = strlen(argv[1]);

	unsigned char* out = (unsigned char*) malloc(OUTSIZE);//just giving 1000*4. Should make it generic later
	size_t outlen=OUTLEN;

	//Retreive the second argument and store it in key string
	const unsigned char key[INSIZE]={0};
	strcpy((char*)key,argv[2]);
	std::cout<<"Entered Key: "<<key<<std::endl;
	size_t keylen = strlen(argv[2]);

	//Call to sodium crypto generichash
	int returnedHash = 	crypto_generichash(out,outlen,in,inlen,key, keylen);
	assert(returnedHash==0);
	//std::cout <<"Returned hash: "<<returnedHash<<std::endl;
	//Not printing the ascii equivalent here 
	std::cout<<"After hashing: ";
	for(int i=0;i<inlen;i++)
		std::cout<<out[i];
	std::cout<<std::endl;

	return 0;
}