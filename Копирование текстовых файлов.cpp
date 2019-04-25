#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *fp1 = fopen("text1.txt", "r");//для чтения из первого
	FILE *fp2 = fopen("text2.txt", "w");// для записи во второй
	char cc[256];

	while (!feof(fp1)) //построчно копируем файл
	{
		fgets(cc, 256, fp1);
		fputs(cc, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
