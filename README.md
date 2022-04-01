To give some background information, I have been working on creating a communication channel between a host PC and the FPGA, so that I can combine SST simulator with Memulator (emulated memory). This is going to happen over the PCIe as it is the fastest method. I am using the RIFFA IP from github https://github.com/KastnerRG/riffa to achieve this. This folder once unzipped has "HOW_TO_TEST" file in it which describes my test file. With this test, I am taking the trace files generated by running hopscotch benchmark on gem5 and I am feeding data to the FPGA in accordance to estimate the total travel time. This shows us the cost of using the PCIe for communication.
