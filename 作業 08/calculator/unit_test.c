#include <stdio.h>
#include <assert.h>

int plus(int a,int b){
	return a+b;
}

int minus(int a,int b){
	return a-b;
}

int multiply(int a,int b){
	return a*b;
}

int divide(int a,int b){
	return a/b;
}

void test(){
	assert(plus(1,1)==2);
	assert(plus(2,2)==4);
	assert(minus(1,1)==0);
	assert(minus(2,1)==1);
	assert(multiply(1,2)==2);
	assert(multiply(2,2)==4);
	assert(divide(1,1)==1);
	assert(divide(4,2)==2);
}

void main(){
	test();
}