

#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include "riffa.h"
#include <string.h>

#define MAX_LINE_LENGTH 80



int main()
{

    fpga_t * fpga;
    GET_TIME_INIT(2);

    fpga = fpga_open(0);
    if (fpga == NULL) {
               printf("Could not get FPGA");
           return -1;
    }


    char *path="hopscotch_traces/w_stride_2.trace";
    char line[MAX_LINE_LENGTH] = {0};
    char line2[MAX_LINE_LENGTH] = {0};
    
    /* Open file */
    FILE *file = fopen(path, "r");
    FILE *file2 = fopen(path, "r");
    
    if (!file)
    {
        perror(path);
        return EXIT_FAILURE;
    }
    if (!file2)
    {
        perror(path);
        return EXIT_FAILURE;
    }
    
    fgets(line2, MAX_LINE_LENGTH, file2);

   
    int count=0;
    char *word="";
    char *word2="";

    int same_tick=1;
    //char tick_buf[20];

    int total_line=1; 

    GET_TIME_VAL(0);
    
    while (fgets(line, MAX_LINE_LENGTH, file) && fgets(line2, MAX_LINE_LENGTH, file2) )
    {
	total_line++;
	
	int len = strlen(line);
	if( line[len-1] == '\n' )
    		line[len-1] = 0;

	int len2 = strlen(line2);
        if( line2[len-1] == '\n' )
                line2[len-1] = 0;

    	
	char *found;
	char *found2;

	char *rest = line;
	char *rest2 = line2;

    	while( (found=strtok_r(rest," ",&rest)) && (found2=strtok_r(rest2," ",&rest2)) )
    	{
		count++;
        	
		if(count==3)
		{
			word=found;
			word2=found2;
			count=0;
			
			if(!strcmp(word,word2))
			{
				same_tick++;
			}
			else
			{
				unsigned int *sendBuffer;
        			int sent;

				int numWords=same_tick*17;

        			sendBuffer = (unsigned int *)malloc(numWords<<2);
        			if (sendBuffer == NULL) {
                			printf("Could not malloc memory for sendBuffer\n");
                			fpga_close(fpga);
                			return -1;
        			}

        			// Initialize the data
        			for (int i = 0; i < numWords; i++) {
                			sendBuffer[i] = i+1;
        			}

				sent = fpga_send(fpga, 0, sendBuffer, numWords, 0, 1, 25000);
        			//printf("words sent: %d\n", sent);

        			//printf("elapsed time %f \n",(TIME_VAL_TO_MS(1) - TIME_VAL_TO_MS(0)));
				same_tick=1;
				
			}
		}
    	} 

	
        
    }

    GET_TIME_VAL(1);

    printf("elapsed time 1 %f \n",((TIME_VAL_TO_MS(1) - TIME_VAL_TO_MS(0))/1000));
    
    
    /* Close file */
    if (fclose(file))
    {
        return EXIT_FAILURE;
        perror(path);
    }

	return 0;
}
