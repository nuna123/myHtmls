#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int get_matching_item(char *pt1, char *pt2, int part_size)
{
	int toadd;
	for (int i = 0; i < part_size; i++)
	{
		for (int j = 0; j < part_size; j++)
		{
			if(pt1[i] == pt2[j] && pt1[i] != '\0'){
				printf("pt1: %c; pt2: %c;\n", pt1[i], pt2[j]);
/* 				if(pt1[i] <= 'z')
				{
					toadd = pt1[i] - 'a' + 1;
				}
				else{
					toadd = pt1[i] - 'A' + 1;
				} */
				//toadd = ((pt1[i] <= 'z') ? pt1[i] - 'a' + 1 : pt1[i] - 'A' + 1);
				return ((pt1[i] <= 'Z') ? pt1[i] - 'A' + 27 : pt1[i] - 'a' + 1);
				}
		}
	}
	return 0;
	
}

int main(int argc, char *argv[])
{

	int total = 0;
	char char_buffer;
	char buffer[100];
	char pt1[100];
	char pt2[100];
	int index = 0;
	char *filepath;
	int toadd;

	int file_to_read;
	if(argc ==2){file_to_read = open(argv[1],O_RDONLY);}
	else{file_to_read = open("./file.txt", O_RDONLY);}
	if(!file_to_read){return 1;}

	while(read(file_to_read, &char_buffer, 1))
	{
		if(char_buffer != '\n')
			buffer[index++] = char_buffer;
		else{
			strncpy(pt1, buffer, index/2);
			strncpy(pt2, &buffer[index/2], index/2);
			toadd = get_matching_item(pt1,pt2, index/2);

			total += toadd;
			while(index > 0){
				pt1[index] =0;
				pt2[index] = 0;
				buffer[--index] = 0;
			}
		}
		
	}

	printf("val: %i\n", total);


	close(file_to_read);
	return 0;
}