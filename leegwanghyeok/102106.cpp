#include <stdio.h>
#include <stdlib.h>


void readfile(char* fileName);
void zoomIn();

int main(){

	
	void zoomIn();

	return 0;
}

void readfile(char* filename) {

	FILE *fp;
	fp = fopen("lena.img", "rb");  //open image
	FILE *fp2;
	fp2 = fopen("lena2.img", "wb");
	int i;


	unsigned char **input;
	input = (unsigned char**)malloc(sizeof(unsigned char*) * 512);
	for (i = 0;i<512;i++)
	{
		input[i] = (unsigned char*)malloc(sizeof(unsigned char) * 512);



	}
	//allocating imageMemory for input image.This is 2D
	for (i = 0;i < 512;i++) {

		fread(input[i], sizeof(unsigned char), 512, fp);
	}

	for (i = 0;i < 512;i++) {

		fwrite(input[i], sizeof(unsigned char), 512, fp2); //input에 있는 값으로 파일 만들기

	}

	printf("success to write");

	for (i = 0;i < 512; i++) {

		free(input[i]);

	}free(input);

	printf("free memory");


	fclose(fp);
	fclose(fp2);



}

void zoomIn() {



	FILE *fp;
	fp = fopen("lena.img", "rb");  //open image
	FILE *fp2;
	fp2 = fopen("lena2.img", "wb");
	int i,j;
	int scaleValue=2;
	int height = 512;
	int width=512;
	int outputHeight = height / scaleValue;
	int outputWidth = width / scaleValue;
	
///////////////////////파일 읽기//////////////////
	unsigned char **input;
	input = (unsigned char**)malloc(sizeof(unsigned char*) * height);
	for (i = 0;i<height;i++)
	{
		input[i] = (unsigned char*)malloc(sizeof(unsigned char) * width);



	}
	//allocating imageMemory for input image.This is 2D
	for (i = 0;i < height;i++) {

		fread(input[i], sizeof(unsigned char), width, fp);
	}

	
	unsigned char **output;
	output = (unsigned char**)malloc(sizeof(unsigned char*)*outputHeight);
	for (i = 0;i < outputHeight;i++) {

		output[i] = (unsigned char*)malloc(sizeof(unsigned char)*outputWidth);
	}

	for (i = 0;i < height;i += scaleValue) {

		for (j = 0;j < width;j += scaleValue) {

			output[i / scaleValue][j / scaleValue] = input[i][j];

		}
	}



	for (i = 0;i <outputHeight;i++) {

		fwrite(output[i], sizeof(unsigned char), outputWidth, fp2); //input에 있는 값으로 파일 만들기

	}

	printf("success to write");

	for (i = 0;i < 512; i++) {

		free(input[i]);

	}free(input);

	printf("free memory");


	fclose(fp);
	fclose(fp2);
}