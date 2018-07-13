#include"comm.h"

static int commMsgQueue(int flags)
{
	key_t _key=ftok(PATHNAME,PROJ_ID);
	int msgid = msgget(_key,flags);
	return msgid;
}
int createMsgQueue()
{
	return commMsgQueue(IPC_CREAT);
}
int getMsgQueue()
{
	return commMsgQueue(IPC_CREAT);
}
int destroyMsgQueue(int msgid)
{
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
int sendMsg(int msgid,int who,char *msg)
{
	struct msgbuf buf;
	buf.mtype =who;
	strcpy(buf.mtext,msg);

	msgsnd(msgid,(void*)&buf,sizeof(buf.mtext),0);
	return 0;
}
int recvMsg(int msgid,int recvType,char out[])
{
	struct msgbuf buf;
	msgrcv(msgid,(void*)&buf,sizeof(buf.mtext),recvType,0);
	strcpy(out,buf.mtext);
	return 0;
}
