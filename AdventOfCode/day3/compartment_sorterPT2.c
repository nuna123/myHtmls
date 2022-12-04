#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int get_matching_item(char *elf1, char *elf2, char *elf3)
{
	for (int i = 0; i < strlen(elf1); i++)
	{
		//if(elf1[i] == 0){return 0;}
		for (int j = 0; j < strlen(elf2); j++)
		{
			//if(elf2[j] == 0){return 0;}
			if(elf1[i] == elf2[j])
			{
				for (int x = 0; x < strlen(elf3); x++)
				{
					//if(elf3[x] == 0){return 0;}
					if(elf2[j] == elf3[x] && elf3[x] != '\0'){
						printf("matching letter : %c\n", elf1[i]);
						return ((elf1[i] <= 'Z') ? elf1[i] - 'A' + 27 : elf1[i] - 'a' + 1);
						}
				}
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
	char elf1[100];
	char elf2[100];
	char elf3[100];
	int index = 100;
	char *filepath;
	int toadd;

	int file_to_read;
	if(argc ==2){file_to_read = open(argv[1],O_RDONLY);}
	else{file_to_read = open("./file.txt", O_RDONLY);}
	if(!file_to_read){return 1;}

	while(--index >= 0){
		elf1[index] = 0;
		elf2[index] = 0;
		elf3[index] = 0;
		buffer[index] = 0;
	}

	while(read(file_to_read, &char_buffer, 1))
	{
		if(char_buffer != '\n')
			buffer[++index] = char_buffer;
		else{
			index++;
			if (!elf1[0])
				strcpy(elf1, buffer);
			else if (!elf2[0])
				strcpy(elf2, buffer);
			else if (!elf3[0])
			{
				strcpy(elf3, buffer);
				toadd = get_matching_item(elf1, elf2, elf3);

				total += toadd;
				index = 100;
				while(--index >= 0){
					elf1[index] = 0;
					elf2[index] = 0;
					elf3[index] = 0;
					buffer[index] = 0;
				}
			}
				while(index >= 0){
					buffer[index--] = 0;
				}
		}
		
	}

	printf("val: %i\n", total);


	close(file_to_read);
	return 0;
}