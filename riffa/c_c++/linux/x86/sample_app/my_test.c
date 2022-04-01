

#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include "riffa.h"


int main()
{

	fpga_t * fpga;
	unsigned int send_buffer[8]={100,20,80,40,50,10,5,25};
	unsigned int receive_buffer[8]={0,0,0,0,0,0,0,0};
	int sent;
	int recvd;
	GET_TIME_INIT(2);

	fpga = fpga_open(0);
	if (fpga == NULL) {
               printf("Could not get FPGA");
               return -1;
        }

	sent = fpga_send(fpga, 0, send_buffer, 8, 0, 1, 25000);
	printf("words sent: %d\n", sent);



        GET_TIME_VAL(0);

        if (sent != 0) {
                // Recv the data
                recvd = fpga_recv(fpga, 0, receive_buffer, 8, 25000);
                printf("words recv: %d\n", recvd);
        }

        GET_TIME_VAL(1);

	printf("elapsed time %f \n",(TIME_VAL_TO_MS(1) - TIME_VAL_TO_MS(0)));
        printf("buffer [7]: %d \n", receive_buffer[7]);
        printf("buffer [6]: %d \n", receive_buffer[6]);
        printf("buffer [5]: %d \n", receive_buffer[5]);
        printf("buffer [4]: %d \n", receive_buffer[4]);
	printf("buffer [3]: %d \n", receive_buffer[3]);
	printf("buffer [2]: %d \n", receive_buffer[2]);
	printf("buffer [1]: %d \n", receive_buffer[1]);
	printf("buffer [0]: %d \n", receive_buffer[0]);


	fpga_close(fpga);




	return 0;
}
