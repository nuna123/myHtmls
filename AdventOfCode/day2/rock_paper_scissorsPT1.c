#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char opponent_val;
	char my_val;
	char char_buffer;
	char *filepath;
	int score = 0;

	int file_to_read;
	if(argc ==2){file_to_read = open(argv[1],O_RDONLY);}
	else{file_to_read = open("./file.txt", O_RDONLY);}
	if(!file_to_read){return 1;}

	while(read(file_to_read, &char_buffer, 1))
	{
		if(char_buffer != '\n')
		{
			if (char_buffer != ' ')
			{
				if(!opponent_val)
				opponent_val = char_buffer;
			else
				my_val = char_buffer;
			}
		}
		else if(opponent_val && my_val){
			//add chosen element ((1 for Rock, 2 for Paper, and 3 for Scissors))
			// X for Rock, Y for Paper, and Z for Scissors
			my_val = my_val - 'X' + 1;
			opponent_val = opponent_val - 'A' + 1;

			score += my_val;
			if(my_val == opponent_val)
				score += 3;
			else{
				if(( opponent_val == 1 && my_val == 2)//opp is rock, i am paper
				||(opponent_val == 2 && my_val == 3)//opp is paper, i am scissors
				||(opponent_val == 3 && my_val == 1))//opp is scissors, i am rock
					score += 6;
			}
			opponent_val = 0;
			my_val = 0;
		}
		
	}


	printf("total: %i\n", score);

	close(file_to_read);
	return 0;
}