#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

	/*int cnt_down = 10;
	while(cnt_down > 0) {
		printf("%d...\n", cnt_down);
		cnt_down--;
		sleep(1);
	}
	printf("Go!\n");*/

	int curr_time = time((time_t *) 0x0) + 3600 * 4 * 0 - 7;
	printf("%d\n", curr_time);
	srand(curr_time);
	fflush(stdout);
	for(int i = 0; i < 30; i++)
	{
		printf("%d\n", rand() & 0xf);
		//sprintf("echo %d\n", rand() & 0xf)
	}
	/*
	printf("\n");
	
	curr_time++;
	printf("%d\n", curr_time);
	srand(curr_time);
	fflush(stdout);
	for(int i = 0; i < 30; i++)
	{
		printf("%d\n", rand() & 0xf);
		//sprintf("echo %d\n", rand() & 0xf)
	}
	
	printf("\n");
	
	curr_time -= 2;
	printf("%d\n", curr_time);
	srand(curr_time);
	fflush(stdout);
	for(int i = 0; i < 30; i++)
	{
		printf("%d\n", rand() & 0xf);
		//sprintf("echo %d\n", rand() & 0xf)
	}*/
	system("nc 2019shell1.picoctf.com 12269");

}
