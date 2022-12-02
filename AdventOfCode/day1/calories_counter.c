#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void compare_to_highest(int *highest_vals, int val)
{
	for (int i = 0; i < 3; i++)
	{
		if(val > highest_vals[i])
		{
			compare_to_highest(highest_vals, highest_vals[i]);
			highest_vals[i] = val;
			break;
		}
	}
	
}

int main(int argc, char *argv[])
{
	//if(argc != 2){return 1;}
	int highest_vals[3];
	int curr_val = 0;
	char char_buffer;
	char buffer[10];
	int index = 0;
	char *filepath;
	int end_of_person = 0;

	int file_to_read;
	if(argc ==2){file_to_read = open(argv[1],O_RDONLY);}
	else{file_to_read = open("./file.txt", O_RDONLY);}
	if(!file_to_read){return 1;}

	while(read(file_to_read, &char_buffer, 1))
	{
		if(char_buffer != '\n')
		{
			end_of_person = 0;
			buffer[index++] = char_buffer;
		}
		else{
			curr_val += atoi(buffer);
			//if already endofperson, this is the person break and val should be compared with max
			if(end_of_person)
			{
				compare_to_highest(&highest_vals[0], curr_val);
				end_of_person = 0;
				curr_val = 0;
			}
			else
				end_of_person = 1;

			while(index > 0){
				buffer[--index] = 0;
			}
		}
		
	}
	compare_to_highest(&highest_vals[0], curr_val);

	printf("val: %i\n", highest_vals[0]);
	printf("val: %i\n", highest_vals[1]);
	printf("val: %i\n", highest_vals[2]);
	printf("total: %i\n", highest_vals[0] + highest_vals[1] + highest_vals[2]);

	close(file_to_read);
	return 0;
}