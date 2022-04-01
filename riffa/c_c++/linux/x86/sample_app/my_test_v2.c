

#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include "riffa.h"


int main()
{

	fpga_t * fpga;
	//unsigned int send_buffer[4]={4,3,2,1};
	//unsigned int receive_buffer[4]={0,0,0,0};
	
	unsigned int *sendBuffer;
	unsigned int *recvBuffer;

	int sent;
	int recvd;
	GET_TIME_INIT(3);

	int numWords=1000;

	fpga = fpga_open(0);
	if (fpga == NULL) {
               printf("Could not get FPGA");
               return -1;
        }

// Malloc the arrays
        sendBuffer = (unsigned int *)malloc(numWords<<2);
        if (sendBuffer == NULL) {
        	printf("Could not malloc memory for sendBuffer\n");
                fpga_close(fpga);
                return -1;
        }
        recvBuffer = (unsigned int *)malloc(numWords<<2);
        if (recvBuffer == NULL) {
        	printf("Could not malloc memory for recvBuffer\n");
        	free(sendBuffer);
        	fpga_close(fpga);
                return -1;
        }

        // Initialize the data
        for (int i = 0; i < numWords; i++) {
        	sendBuffer[i] = i+1;
                recvBuffer[i] = 0;
        }

        GET_TIME_VAL(0);

        // Send the data
        sent = fpga_send(fpga, 0, sendBuffer, numWords, 0, 1, 25000);
        printf("words sent: %d\n", sent);

        GET_TIME_VAL(1);

        if (sent != 0) {
        	// Recv the data
                recvd = fpga_recv(fpga, 0, recvBuffer, numWords, 25000);
                printf("words recv: %d\n", recvd);
        }

        GET_TIME_VAL(2);


	/*sent = fpga_send(fpga, 0, send_buffer, 4, 0, 1, 25000);
	printf("words sent: %d\n", sent);



        GET_TIME_VAL(0);

        if (sent != 0) {
                // Recv the data
                recvd = fpga_recv(fpga, 0, receive_buffer, 4, 25000);
                printf("words recv: %d\n", recvd);
        }

        GET_TIME_VAL(1);

	printf("elapsed time %f \n",(TIME_VAL_TO_MS(1) - TIME_VAL_TO_MS(0)));*/
	
        printf("buffer [999]: %d \n", recvBuffer[999]);
        printf("buffer [998]: %d \n", recvBuffer[998]);
        printf("buffer [997]: %d \n", recvBuffer[997]);
        printf("buffer [996]: %d \n", recvBuffer[996]);
        printf("buffer [995]: %d \n", recvBuffer[995]);
        printf("buffer [994]: %d \n", recvBuffer[994]);
        printf("buffer [993]: %d \n", recvBuffer[993]);
        printf("buffer [992]: %d \n", recvBuffer[992]);
        printf("buffer [991]: %d \n", recvBuffer[991]);
        printf("buffer [990]: %d \n", recvBuffer[990]);
        printf("buffer [37]: %d \n", recvBuffer[37]);
        printf("buffer [36]: %d \n", recvBuffer[36]);
        printf("buffer [35]: %d \n", recvBuffer[35]);
        printf("buffer [34]: %d \n", recvBuffer[34]);
        printf("buffer [33]: %d \n", recvBuffer[33]);
        printf("buffer [32]: %d \n", recvBuffer[32]);
        printf("buffer [31]: %d \n", recvBuffer[31]);
        printf("buffer [30]: %d \n", recvBuffer[30]);
        printf("buffer [29]: %d \n", recvBuffer[29]);
        printf("buffer [28]: %d \n", recvBuffer[28]);
        printf("buffer [27]: %d \n", recvBuffer[27]);
        printf("buffer [26]: %d \n", recvBuffer[26]);
        printf("buffer [25]: %d \n", recvBuffer[25]);
        printf("buffer [24]: %d \n", recvBuffer[24]);
	printf("buffer [23]: %d \n", recvBuffer[23]);
	printf("buffer [22]: %d \n", recvBuffer[22]);
	printf("buffer [21]: %d \n", recvBuffer[21]);
        printf("buffer [20]: %d \n", recvBuffer[20]);
        printf("buffer [19]: %d \n", recvBuffer[19]);
        printf("buffer [18]: %d \n", recvBuffer[18]);
        printf("buffer [17]: %d \n", recvBuffer[17]);
        printf("buffer [16]: %d \n", recvBuffer[16]);
        printf("buffer [15]: %d \n", recvBuffer[15]);
        printf("buffer [14]: %d \n", recvBuffer[14]);
        printf("buffer [13]: %d \n", recvBuffer[13]);
        printf("buffer [12]: %d \n", recvBuffer[12]);
        printf("buffer [11]: %d \n", recvBuffer[11]);
        printf("buffer [10]: %d \n", recvBuffer[10]);
        printf("buffer [9]: %d \n", recvBuffer[9]);
        printf("buffer [8]: %d \n", recvBuffer[8]);
        printf("buffer [7]: %d \n", recvBuffer[7]);
        printf("buffer [6]: %d \n", recvBuffer[6]);
        printf("buffer [5]: %d \n", recvBuffer[5]);
        printf("buffer [4]: %d \n", recvBuffer[4]);
        printf("buffer [3]: %d \n", recvBuffer[3]);
        printf("buffer [2]: %d \n", recvBuffer[2]);
        printf("buffer [1]: %d \n", recvBuffer[1]);
        printf("buffer [0]: %d \n", recvBuffer[0]);



	fpga_close(fpga);




	return 0;
}
