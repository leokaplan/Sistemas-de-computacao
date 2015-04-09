
#ifndef MINIXORIGINAL
#define MAXMSG 10
int MQ[10][MAXMSG];
int IndicesI[10];
int IndicesF[10];

void incr(int* v, int id){
  v[id]=(v[id]+1)%MAXMSG;
}

void add(int id, int num){
  if(count(id)>=MAXMSG){ //overflow
    MQ[id][IndiceI[id]] = msg;//apagar mais antigo
    incr(IndiceI,id);
    incr(IndiceF,id);
  }
  else{//tem espaço livre
    incr(IndiceF,id);
    MQ[id][IndiceF[id]] = msg;
  }
}
void rem(int id){
  incr(IndiceI,id);
}
int count(int id){
  if(IndiceI[id]<=IndiceF[id]){
    return IndiceF[id]-IndiceI[id];
  }
  else{
    return MAXMSG+IndiceF[id]-IndiceI[id];
  }
}

int MQsend (int mqID, int msg){
  if(mqID>9||mqID<0) return 0;
  add(mqID,msg);
}
int MQrecv (int mqID, int* msg){
  if(mqID>9||mqID<0) return 0;
  *msg = MQ[mqID][IndiceF[mqID]];
  rem(mqID);
}
int MQcount (int mqID){
  if(mqID>9||mqID<0) return 0;
  return count(mqID);
}
int MQinspect(int mqID, int entry){
  if(mqID>9||mqID<0) return 0;
  return (MQ[mqID][IndiceI[mqID]]+entry)%MAXMSG;
}
#endif
