#ifndef MINIXORIGINAL
int MQsend (int mqID, int msg);
int MQrecv (int mqID, int* msg);
int MQcount (int mqID);
int MQinspect(int mqID, int entry);
#endif
