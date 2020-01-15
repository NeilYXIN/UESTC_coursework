#include<iostream> 
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct readylist {
	struct rblobject *sys;//2
	struct rblobject *user;//1
	struct rblobject *init;//0
}*rlp;

typedef struct blocklist {
	struct rblobject *sys;//2
	struct rblobject *user;//1
	struct rblobject *init;//0
}*blp;

//readylist和blocklist中的单元
typedef struct rblobject {
	struct PCB *rblpcb;
	struct rblobject *next;
}*rblp;

typedef struct resource {
	int RID;
	int numall;
	int numleft;
}*rp;

//资源中waitinglist的单元
typedef struct reobject {
	struct PCB *repcb;
	struct reobject *next;
}reobject,*rep;

typedef struct PCB
{
	char PID[25];//进程名 
	int  resources[4] = {0,0,0,0};//该进程所占用资源数量 
	char status[25];//进程状态 
	struct PCB *parent;//指向该进程父进程的指针 
	struct PCB *child;//指向该进程子进程的指针 
	struct PCB *brother;//指向该进程兄弟进程的指针 
	int priority;//优先级，0:init 1:user 2system 
}PCB,*pcb;

PCB *pcbp=new PCB;
PCB *running=new PCB;

void finddel(PCB *delpcb,char pid[],PCB **temp)
{
	if (strcmp(delpcb->PID,pid))
	{
		if (delpcb->brother==NULL&& delpcb->child==NULL)
		{
			//return;
		}
		else if (delpcb->brother!=NULL)
		{			
			finddel(delpcb->brother,pid,temp);
		}
		else if (delpcb->child!=NULL)
		{
			finddel(delpcb->child,pid,temp);
		}		
	}
	else
	{
		*temp = delpcb;
		cout<<delpcb->PID<<endl<<delpcb<<endl;
	}
	return;
}

void rel(PCB **reltarget,int relname, int relnum, readylist *rl, blocklist *bl, rblobject **sysreadycount, rblobject **sysblockcount, rblobject **userreadycount, rblobject **userblockcount, resource *re1, resource *re2, resource *re3, resource *re4)
{
	switch (relname)
	{
	case 1:
	{
		(*reltarget)->resources[relname - 1] -= relnum;
		(*re1).numleft += relnum;
		//阻塞队列不为空
		if ((*bl).sys != NULL)
		{
			//查找第一个被该资源阻塞的进程
			(*sysblockcount) = (*bl).sys;//赋值疑问
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re1).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*sysblockcount)->next != NULL)
				{
					(*sysblockcount) = (*sysblockcount)->next;
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re1).numleft)
			{
				(*re1).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).sys;
				if (tempcount->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
				{
					if ((*bl).sys->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*sysblockcount)->next;
					}
					else
					{
						(*bl).sys = NULL;
					}
				}
				else
				{
					(*bl).sys = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*sysreadycount = (*rl).sys;
				//若就绪队列不为空
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysreadycount);
					(*sysreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).sys = *sysblockcount;
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re1).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*userblockcount)->next != NULL)
				{
					(*userblockcount) = (*userblockcount)->next;
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re1).numleft)
			{
				(*re1).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).user;
				if (tempcount->rblpcb->PID != (*userblockcount)->rblpcb->PID)
				{
					if ((*bl).user->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*userblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*userblockcount)->next;
					}
					else
					{
						(*bl).user = NULL;
					}
				}
				else
				{
					(*bl).user = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*userreadycount = (*rl).user;
				//若就绪队列不为空
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).user = *userblockcount;
					(*rl).user->next = NULL;
				}
			}
		}
		else if ((*bl).init != NULL && (*bl).init->rblpcb->resources[relname - 1] < 0 && (*bl).init->rblpcb->resources[relname - 1] < (*re1).numleft)
		{
			(*re1).numleft += (*bl).init->rblpcb->resources[relname - 1];
			(*rl).init = (*bl).init;
			(*bl).init = NULL;
		}
		break;
	}
	case 2:
	{
		(*reltarget)->resources[relname - 1] -= relnum;
		(*re2).numleft += relnum;
		//阻塞队列不为空
		if ((*bl).sys != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re2).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*sysblockcount)->next != NULL)
				{
					if ((*sysblockcount)->next != NULL)
					{
						(*sysblockcount) = (*sysblockcount)->next;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re2).numleft)
			{
				(*re2).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).sys;
				if (tempcount->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
				{
					if ((*bl).sys->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*sysblockcount)->next;
					}
					else
					{
						(*bl).sys = NULL;
					}
				}
				else
				{
					(*bl).sys = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*sysreadycount = (*rl).sys;
				//若就绪队列不为空
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re2).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*userblockcount)->next != NULL)
				{
					(*userblockcount) = (*userblockcount)->next;
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re2).numleft)
			{
				(*re2).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).user;
				if (tempcount->rblpcb->PID != (*userblockcount)->rblpcb->PID)
				{
					if ((*bl).user->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*userblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*userblockcount)->next;
					}
					else
					{
						(*bl).user = NULL;
					}
				}
				else
				{
					(*bl).user = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*userreadycount = (*rl).user;
				//若就绪队列不为空
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).user = *userblockcount;
					(*rl).user->next = NULL;
				}
			}
		}
		else if ((*bl).init != NULL && (*bl).init->rblpcb->resources[relname - 1] < 0 && (*bl).init->rblpcb->resources[relname - 1] < (*re2).numleft)
		{
			(*re2).numleft += (*bl).init->rblpcb->resources[relname - 1];
			(*rl).init = (*bl).init;
			(*bl).init = NULL;
		}
		break;
	}
	case 3:
	{	
		(*reltarget)->resources[relname - 1] -= relnum;
		(*re3).numleft += relnum;
		//阻塞队列不为空
		if ((*bl).sys != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re3).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*sysblockcount)->next != NULL)
				{
					if ((*sysblockcount)->next != NULL)
					{
						(*sysblockcount) = (*sysblockcount)->next;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re3).numleft)
			{
				(*re3).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).sys;
				if (tempcount->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
				{
					if ((*bl).sys->next != NULL)
					{

						while (tempcount->next->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*sysblockcount)->next;
					}
					else
					{
						(*bl).sys = NULL;
					}
				}
				else
				{
					(*bl).sys = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*sysreadycount = (*rl).sys;
				//若就绪队列不为空
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re3).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*userblockcount)->next != NULL)
				{
					(*userblockcount) = (*userblockcount)->next;
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re3).numleft)
			{
				(*re3).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).user;
				if (tempcount->rblpcb->PID != (*userblockcount)->rblpcb->PID)
				{
					if ((*bl).user->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*userblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*userblockcount)->next;
					}
					else
					{
						(*bl).user = NULL;
					}
				}
				else
				{
					(*bl).user = (*tempcount).next;
				}				
				//将该进程插入到就绪队列末尾						
				*userreadycount = (*rl).user;
				//若就绪队列不为空
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).user = *userblockcount;
					(*rl).user->next = NULL;
				}
			}
		}
		else if ((*bl).init != NULL && (*bl).init->rblpcb->resources[relname - 1] < 0 && (*bl).init->rblpcb->resources[relname - 1] < (*re3).numleft)
		{
			(*re3).numleft += (*bl).init->rblpcb->resources[relname - 1];
			(*rl).init = (*bl).init;
			(*bl).init = NULL;
		}
		break;
	}
	case 4:
	{
		(*reltarget)->resources[relname - 1] -= relnum;
		(*re4).numleft += relnum;
		//阻塞队列不为空
		if ((*bl).sys != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re4).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*sysblockcount)->next != NULL)
				{
					if ((*sysblockcount)->next != NULL)
					{
						(*sysblockcount) = (*sysblockcount)->next;
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re4).numleft)
			{
				(*re4).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).sys;
				if (tempcount->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
				{
					if ((*bl).sys->next != NULL)
					{
						while (tempcount->next->rblpcb->PID != (*sysblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*sysblockcount)->next;
					}
					else
					{
						(*bl).sys = NULL;
					}
				}
				else
				{
					(*bl).sys = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*sysreadycount = (*rl).sys;
				//若就绪队列不为空
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//查找第一个被该资源阻塞的进程
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re4).numleft)//进程被阻塞且所需资源数量小于剩余
			{
				if ((*userblockcount)->next != NULL)
				{
					(*userblockcount) = (*userblockcount)->next;
				}
				else
				{
					break;
				}
			}
			//若没有进程在等待该资源
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//阻塞队列中有进程在等待该资源
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re4).numleft)
			{
				(*re4).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//剩余资源数量相应减少
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//将该进程从blocklist移除
				rblobject *tempcount = (*bl).user;
				if (tempcount->rblpcb->PID != (*userblockcount)->rblpcb->PID)
				{
					if ((*bl).user->next != NULL)
					{

						while (tempcount->next->rblpcb->PID != (*userblockcount)->rblpcb->PID)
						{
							tempcount = tempcount->next;
						}
						tempcount->next = (*userblockcount)->next;
					}
					else
					{
						(*bl).user = NULL;
					}
				}
				else
				{
					(*bl).user = (*tempcount).next;
				}
				//将该进程插入到就绪队列末尾						
				*userreadycount = (*rl).user;
				//若就绪队列不为空
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//就绪队列为空时
				else
				{
					(*rl).user = *userblockcount;
					(*rl).user->next = NULL;
				}
			}
		}
		else if ((*bl).init != NULL && (*bl).init->rblpcb->resources[relname - 1] < 0 && (*bl).init->rblpcb->resources[relname - 1] < (*re4).numleft)
		{
			(*re4).numleft += (*bl).init->rblpcb->resources[relname - 1];
			(*rl).init = (*bl).init;
			(*bl).init = NULL;
		}
		break;
	}
	default:
	{
		printf("invalid release\n");
		break;
	}
	}
}


void delpcbson(PCB **deltarget,readylist *ready,blocklist *block,resource *r1,resource *r2,resource *r3,resource *r4,rblobject **readycount,rblobject **blockcount,rblobject **temp,PCB **run,rblobject **sysreadycount, rblobject **sysblockcount, rblobject **userreadycount, rblobject **userblockcount)
{
	if ((*deltarget)->brother == NULL&& (*deltarget)->child == NULL)
	{
		//删除占用资源
		if ((*deltarget)->resources[0] > 0)
		{
			
			rel(deltarget,1, (*deltarget)->resources[0], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[1] > 0)
		{
			
			rel(deltarget,2, (*deltarget)->resources[1], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[2] > 0)
		{
		
			rel(deltarget,3, (*deltarget)->resources[2], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[3] > 0)
		{
			
			rel(deltarget,4, (*deltarget)->resources[3], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*run)->PID==(*deltarget)->PID)
		{
			switch ((*run)->priority)
			{
			case 2:
			{
				*ready->sys = *ready->sys->next;
				
				break;
			}
			case 1:
			{
				*ready->user = *ready->user->next;
				break;
			}
			case 0:
			{
				break;
			}
			default:
				break;
			}
			*run = NULL;

		}
		//删除readylist、blocklist
		else if ((*deltarget)->priority == 2)//当前节点进程优先级为2：sys时
		{
			(*temp) = ready->sys;
			(*readycount) = ready->sys;
			if ((*readycount) != NULL)
			{
				if ((*readycount)->next != NULL)
				{
					if ((*readycount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = ready->sys;
						if ((*temp)->rblpcb->PID != (*readycount)->rblpcb->PID)
						{
							while ((*temp)->next != (*readycount))
							{
								(*temp) = (*temp)->next;
							}

							(*temp)->next = (*readycount)->next;
							delete(*readycount);
						}
						else
						{
							ready->sys = (*temp)->next;
							delete(*readycount);
						}
					}
				}
				else if ((*readycount)->next == NULL && (*readycount)->rblpcb->PID == (*deltarget)->PID)
				{
					ready->sys = NULL;
					delete(*readycount);
					return;
				}
			}
			(*blockcount) = block->sys;
			if ((*blockcount) != NULL)
			{
				if ((*blockcount)->next != NULL)
				{
					while ((*blockcount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*blockcount)->next != NULL)
						{
							(*blockcount) = (*blockcount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*blockcount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = block->sys;
						if ((*temp)->rblpcb->PID != (*blockcount)->rblpcb->PID)
						{
							while ((*temp)->next != (*blockcount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*blockcount)->next;
							delete(*blockcount);
						}
						else
						{
							block->sys = (*temp)->next;
							delete(*blockcount);
						}
					}
				}
				else if ((*blockcount)->next == NULL && (*blockcount)->rblpcb->PID == (*deltarget)->PID)
				{
					block->sys = NULL;
					delete(*blockcount);
				}
			}
		}
		else if ((*deltarget)->priority == 1)//当前节点进程优先级为1：user时
		{
			(*temp) = ready->user;
			(*readycount) = ready->user;
			if ((*readycount) != NULL)
			{
				if ((*readycount)->next != NULL)
				{
					while ((*readycount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*readycount)->next != NULL)
						{
							(*readycount) = (*readycount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*readycount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = ready->user;
						if ((*temp)->rblpcb->PID != (*readycount)->rblpcb->PID)
						{
							while ((*temp)->next != (*readycount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*readycount)->next;
							delete(*readycount);
						}
						else
						{
							ready->user = (*temp)->next;
							delete(*readycount);
						}
					}
				}
				else if ((*readycount)->next == NULL && (*readycount)->rblpcb->PID == (*deltarget)->PID)
				{
					ready->user = NULL;
					delete(*readycount);
					return;
				}
			}
			(*blockcount) = block->user;
			if ((*blockcount) != NULL)
			{
				if ((*blockcount)->next != NULL)
				{
					while ((*blockcount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*blockcount)->next != NULL)
						{
							(*blockcount) = (*blockcount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*blockcount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = block->user;
						if ((*temp)->rblpcb->PID != (*blockcount)->rblpcb->PID)
						{
							while ((*temp)->next != (*blockcount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*blockcount)->next;
							delete(*blockcount);
						}
						else
						{
							block->user = (*temp)->next;
							delete(*blockcount);
						}
					}
				}
				else if ((*blockcount)->next == NULL && (*blockcount)->rblpcb->PID == (*deltarget)->PID)
				{
					block->user = NULL;
					delete(*blockcount);
				}
			}
		}
		else if ((*deltarget)->priority == 0)//当前节点进程优先级为0：init时
		{
			ready->init = NULL;
			block->init = NULL;
		}
		delete(*deltarget);
	}
	else if ((*deltarget)->brother != NULL&&(*deltarget)->child==NULL)
	{
		delpcbson(&(*deltarget)->brother, ready,block,r1,r2,r3,r4,readycount,blockcount,temp,run,sysreadycount, sysblockcount, userreadycount, userblockcount);
	}
	else if ((*deltarget)->child != NULL&&(*deltarget)->brother==NULL)
	{
		delpcbson(&(*deltarget)->child, ready, block, r1, r2, r3, r4,readycount,blockcount,temp,run, sysreadycount, sysblockcount, userreadycount, userblockcount);
	}
}


void delpcb(PCB **deltarget, readylist *ready, blocklist *block, resource *r1, resource *r2, resource *r3, resource *r4, rblobject **readycount, rblobject **blockcount, rblobject **temp, PCB **run,   rblobject **sysreadycount, rblobject **sysblockcount, rblobject **userreadycount, rblobject **userblockcount)
{
	if ((*deltarget)->child == NULL)
	{
		//删除占用资源
		if ((*deltarget)->resources[0] > 0)
		{
			rel(deltarget,1, (*deltarget)->resources[0], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[1] > 0)
		{
			rel(deltarget,2, (*deltarget)->resources[1], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[2] > 0)
		{
			rel(deltarget,3, (*deltarget)->resources[2], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*deltarget)->resources[3] > 0)
		{
			rel(deltarget,4, (*deltarget)->resources[3], ready, block, sysreadycount, sysblockcount, userreadycount, userblockcount, r1, r2, r3, r4);
		}
		if ((*run)->PID == (*deltarget)->PID)
		{
			switch ((*run)->priority)
			{
			case 2:
			{
				if ((*ready).sys->next != NULL)
				{
					*ready->sys = *ready->sys->next;
				}
				else
				{
					ready->sys = NULL;
				}
				break;
			}
			case 1:
			{
				if (ready->user->next != NULL)
				{
					*ready->user = *ready->user->next;
				}
				else
				{
					ready->user = NULL;
				}
				break;
			}
			case 0:
			{
				break;
			}
			default:
				break;
			}
			*run = NULL;
		}
		//删除readylist、blocklist
		else if ((*deltarget)->priority == 2)//当前节点进程优先级为2：sys时
		{
			(*temp) = ready->sys;
			(*readycount) = ready->sys;
			if ((*readycount) != NULL)
			{
				if ((*readycount)->next != NULL)
				{
					if ((*readycount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = ready->sys;
						if ((*temp)->rblpcb->PID != (*readycount)->rblpcb->PID)
						{
							while ((*temp)->next != (*readycount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*readycount)->next;
							delete(*readycount);
						}
						else
						{
							ready->sys = (*temp)->next;
							delete(*readycount);
						}
					}
				}
				else if ((*readycount)->next == NULL && (*readycount)->rblpcb->PID == (*deltarget)->PID)
				{
					ready->sys = NULL;
					delete(*readycount);
					return;
				}
			}
			(*blockcount) = block->sys;
			if ((*blockcount) != NULL)
			{
				if ((*blockcount)->next != NULL)
				{
					while ((*blockcount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*blockcount)->next != NULL)
						{
							(*blockcount) = (*blockcount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*blockcount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = block->sys;
						if ((*temp)->rblpcb->PID != (*blockcount)->rblpcb->PID)
						{
							while ((*temp)->next != (*blockcount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*blockcount)->next;
							delete(*blockcount);
						}
						else
						{
							block->sys = (*temp)->next;
							delete(*blockcount);
						}
					}
				}
				else if ((*blockcount)->next == NULL && (*blockcount)->rblpcb->PID == (*deltarget)->PID)
				{
					block->sys = NULL;
					delete(*blockcount);
				}
			}
		}
		else if ((*deltarget)->priority == 1)//当前节点进程优先级为1：user时
		{
			(*temp) = ready->user;
			(*readycount) = ready->user;
			if ((*readycount) != NULL)
			{
				if ((*readycount)->next != NULL)
				{
					while ((*readycount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*readycount)->next != NULL)
						{
							(*readycount) = (*readycount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*readycount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = ready->user;
						if ((*temp)->rblpcb->PID != (*readycount)->rblpcb->PID)
						{
							while ((*temp)->next != (*readycount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*readycount)->next;
							delete(*readycount);
						}
						else
						{
							ready->user = (*temp)->next;
							delete(*readycount);
						}
					}
				}
				else if ((*readycount)->next == NULL && (*readycount)->rblpcb->PID == (*deltarget)->PID)
				{
					ready->user = NULL;
					delete(*readycount);
					return;
				}
			}
			(*blockcount) = block->user;
			if ((*blockcount) != NULL)
			{
				if ((*blockcount)->next != NULL)
				{
					while ((*blockcount)->rblpcb->PID != (*deltarget)->PID)
					{
						if ((*blockcount)->next != NULL)
						{
							(*blockcount) = (*blockcount)->next;
						}
						else
						{
							break;
						}
					}
					if ((*blockcount)->rblpcb->PID == (*deltarget)->PID)
					{
						(*temp) = block->user;
						if ((*temp)->rblpcb->PID!=(*blockcount)->rblpcb->PID)
						{
							while ((*temp)->next != (*blockcount))
							{
								(*temp) = (*temp)->next;
							}
							(*temp)->next = (*blockcount)->next;
							delete(*blockcount);
						}
						else
						{
							block->user = (*temp)->next;
							delete(*blockcount);
						}			
					}
				}
				else if ((*blockcount)->next == NULL && (*blockcount)->rblpcb->PID == (*deltarget)->PID)
				{
					block->user = NULL;
					delete(*blockcount);
				}
			}
		}
		else if ((*deltarget)->priority == 0)//当前节点进程优先级为0：init时
		{
			ready->init = NULL;
			block->init = NULL;
		}
	}
	delete(*deltarget);
}

int main()
{
	readylist rl = { NULL,NULL,NULL };
	blocklist bl = { NULL,NULL,NULL };
	resource re1 = { 1,1,1 };
	resource re2 = { 2,2,2 };
	resource re3 = { 3,3,3 };
	resource re4 = { 4,4,4 };
	char str[100];//存放读入的指令字符串 
	char ins[25][20];//将指令拆分后装入数组 
	int pstr;//字符串str指针 
	int i = 0;//二维数组i 
	int j = 0;//二维数组j 

	while (1)
	{
		rblobject *initreadycount=new rblobject;
		rblobject *sysreadycount=new rblobject;
		rblobject *userreadycount =new rblobject;
		rblobject *initblockcount=new rblobject;
		rblobject *sysblockcount= new rblobject;
		rblobject *userblockcount=new rblobject;
		printf("shell>");
		fgets(str, 100, stdin);//读入指令 
		i = 0;

		for (pstr = 0; str[pstr] != '\n'&&str[pstr] != '\0'&&pstr<100; pstr++)//判断pstr当前所指 不是换行符 或 终止符 且长度合法时 ，进入循环 
		{
			j = 0;
			while (str[pstr] != ' '&&str[pstr] != '\n')//当前所指有实际内容且不为空格时 ，即将单词拆分出来 
			{
				ins[i][j++] = str[pstr++];//将当前所指 存入数组ins[i]，j自增
			}
			if (str[pstr - 1] != ' ')// 不满足上面循环则跳出到这，如果前一个字符有内容，则当前单词结束 
			{
				ins[i++][j] = '\0';//结束本单词,i自增 							
			}
		}
		if (i <= 0 || i>3)
		{
			printf("invalid command length\n");
		}
		//一单词指令
		else if (i == 1)
		{
			//init指令
			if (!strcmp(ins[0], "init"))
			{
				printf("init ok\n");
				PCB init = { "init",0,0,0,0,"ready",NULL,NULL,NULL,0};
				running = &init;
				pcbp = &init;
	/*			cout << running->PID << endl << "resources:" << running->resources[0]<<running->resources[1]<<running->resources[2]<<running->resources[3] << endl << running->status 
					<<endl << "parent：" << running->parent << endl << "child：" << running->child << endl	<< "brother：" << running->brother << endl << running->priority 
					<< endl << running << endl;
					*/
				rblobject  *newinitobj = new rblobject;
				newinitobj->rblpcb = &init;
				newinitobj->next = NULL;
				rl.init = newinitobj;
				initreadycount = rl.init;
				running = rl.init->rblpcb;
		//		cout << "initreadylist:" << initreadycount->rblpcb->PID<<endl;
			}
			//timeout指令
			else if (!strcmp(ins[0], "to"))
			{
				printf("to ok\n");
				switch (running->priority)
				{
				case 2:
				{
					sysreadycount = rl.sys;
					while (sysreadycount->next!=NULL)
					{
						sysreadycount = sysreadycount->next;
					}
					sysreadycount->next = rl.sys;
					rl.sys = rl.sys->next;
					sysreadycount->next->next = NULL;

					break;
				}
				case 1:
				{
					userreadycount = rl.user;
					while (userreadycount->next != NULL)
					{
						userreadycount = userreadycount->next;
					}
					
					userreadycount->next = rl.user;
					rl.user = rl.user->next;
					userreadycount->next->next = NULL;
					break;
				}
				case 0:
				{
					
					break;
				}
				default:
					cout << "timeout priority error" << endl;
					break;
				}

			}
			//无符合指令则报错
			else {
				printf("invalid command1\n");
			}
		}
		//二单词指令
		else if (i == 2)
		{
			//删除进程指令
			if (!strcmp(ins[0], "de"))
			{
				printf("de ok\n");			
				PCB *depcb = new PCB;//指向需要删除的进程
				PCB *depcbson = new PCB;
				PCB *findinit = new PCB;
				PCB *temp =new PCB;
				rblobject *rlcount = new rblobject;
				rblobject *blcount = new rblobject;
				rblobject *tempcount = new rblobject;
				int relname ;
				int relnum;
				findinit = running;
				while (findinit->parent!=NULL)
				{
					findinit = findinit->parent;
				}
				depcb = findinit;
				finddel(depcb,ins[1],&temp);
				depcb = temp;
				if (depcb->child!=NULL)
				{
					depcbson = depcb->child;
					delpcbson(&depcbson, &rl, &bl, &re1, &re2, &re3, &re4, &rlcount, &blcount, &tempcount, &running,&sysreadycount,&sysblockcount,&userreadycount,&userblockcount);
				}
				depcb->child = NULL;
		
				delpcb(&depcb, &rl, &bl, &re1, &re2, &re3, &re4, &rlcount, &blcount, &tempcount, &running,  &sysreadycount, &sysblockcount, &userreadycount, &userblockcount);
			}
			else {
				printf("invalid command2\n");
			}
		}
		//三单词指令
		else if (i == 3)
		{
			//创建新进程
			if (!strcmp(ins[0], "cr"))
			{
				printf("cr ok\n");
				i = atoi(ins[2]);
				PCB  *create=new PCB;
				//初始化新建的PCB
				strcpy_s(create->PID, ins[1]);			
				strcpy_s(create->status, "ready");
				create->parent = running;
				create->child = NULL;
				create->brother = NULL;
				create->priority = i;
				if (running->child != NULL)
				{
					PCB *count = running->child;
					while (count->brother != NULL)
					{
						count = count->brother;
					}
					count->brother = create;
				//  测试输出
			
				}
				else if (running->child == NULL)
				{
					running->child = create;
					//测试输出
			
				}	
				rblobject  *newrblobj = new rblobject;				
				newrblobj->rblpcb = create;
				newrblobj->next = NULL;

				//插入readylist队列末尾
				//优先级为1时
				if (create->priority == 1)
				{
					if (rl.user == NULL)
					{
						rl.user = newrblobj;
						//	usercount = rl.user;
					}
					else
					{
						userreadycount = rl.user;
						while (userreadycount->next != NULL)
						{
							userreadycount = userreadycount->next;
						}
						userreadycount->next = newrblobj;
					}
				}
				//优先级为2时
				else if (create->priority == 2)
				{
					if (rl.sys == NULL)
					{
						rl.sys = newrblobj;
						//syscount = rl.sys;
					}
					else
					{
						sysreadycount = rl.sys;
						while (sysreadycount->next != NULL)
						{
							sysreadycount = sysreadycount->next;
						}
						sysreadycount->next = newrblobj;
					}
				}
			}
			//申请资源
			else if (!strcmp(ins[0], "req"))
			{
				printf("req ok\n");

				int reqname = atoi(ins[1]);
				int reqnum = atoi(ins[2]);
		//		cout << reqname << endl << reqnum << endl;
				//申请1号资源
				if (reqname==1)
				{
			
					//申请资源数量小于剩余数量，即能够申请
					if (re1.numleft >= reqnum)
					{
						re1.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//申请资源数量大于剩余数量，被阻塞
					else if (re1.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//修改当前进程状态为阻塞	
						running->resources[reqname - 1] = -reqnum;
						//若当前进程优先级为2
						if (running->priority == 2)
						{
							sysblockcount = bl.sys;
							if (sysblockcount != NULL)
							{
								while (sysblockcount->next != NULL)
								{
									sysblockcount = sysblockcount->next;
								}
								sysblockcount->next = rl.sys;
								rl.sys = rl.sys->next;
								sysblockcount->next->next = NULL;
							}
							else
							{
								bl.sys = rl.sys;
								rl.sys = rl.sys->next;
								bl.sys->next = NULL;
							}
							
						}
						//若当前进程优先级为1
						else if (running->priority == 1)
						{

							userblockcount = bl.user;
							if (userblockcount != NULL)
							{
								while (userblockcount->next != NULL)
								{
									userblockcount = userblockcount->next;
								}
								userblockcount->next = rl.user;
								rl.user = rl.user->next;
								userblockcount->next->next = NULL;
							}
							else
							{
								bl.user = rl.user;
								rl.user = rl.user->next;
								bl.user->next = NULL;
							}
							

						}
						//若当前进程优先级为0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}

				//申请2号资源
				else if (reqname == 2)
				{
					//申请资源数量小于剩余数量，即能够申请
					if (re2.numleft >= reqnum)
					{
						re2.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
				    //申请资源数量大于剩余数量，被阻塞
					else if (re2.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//修改当前进程状态为阻塞	
						running->resources[reqname - 1] = -reqnum;
						//若当前进程优先级为2
						if (running->priority == 2)
						{
							sysblockcount = bl.sys;
							if (sysblockcount != NULL)
							{
								while (sysblockcount->next != NULL)
								{
									sysblockcount = sysblockcount->next;
								}
								sysblockcount->next = rl.sys;
								rl.sys = rl.sys->next;
								sysblockcount->next->next = NULL;
							}
							else
							{
								bl.sys = rl.sys;
								rl.sys = rl.sys->next;
								bl.sys->next = NULL;
							}
							
						}
						//若当前进程优先级为1
						else if (running->priority == 1)
						{

							userblockcount = bl.user;
							if (userblockcount != NULL)
							{
								while (userblockcount->next != NULL)
								{
									userblockcount = userblockcount->next;
								}
								userblockcount->next = rl.user;
								rl.user = rl.user->next;
								userblockcount->next->next = NULL;
							}
							else
							{
								bl.user = rl.user;
								rl.user = rl.user->next;
								bl.user->next = NULL;
							}
							

						}
						//若当前进程优先级为0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
					
				}
				//申请3号资源
				else if (reqname == 3)
				{
					//申请资源数量小于剩余数量，即能够申请
					if (re3.numleft >= reqnum)
					{
						re3.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//申请资源数量大于剩余数量，被阻塞
					else if (re3.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//修改当前进程状态为阻塞	
						running->resources[reqname - 1] = -reqnum;	
						//若当前进程优先级为2
						if (running->priority == 2)
						{
							sysblockcount = bl.sys;
							if (sysblockcount != NULL)
							{
								while (sysblockcount->next != NULL)
								{
									sysblockcount = sysblockcount->next;
								}
								sysblockcount->next = rl.sys;
								rl.sys = rl.sys->next;
								sysblockcount->next->next = NULL;
							}
							else
							{
								bl.sys = rl.sys;
								rl.sys = rl.sys->next;
								bl.sys->next = NULL;
							}
							
						}
						//若当前进程优先级为1
						else if (running->priority == 1)
						{

							userblockcount = bl.user;
							if (userblockcount != NULL)
							{
								while (userblockcount->next != NULL)
								{
									userblockcount = userblockcount->next;
								}
								userblockcount->next = rl.user;
								rl.user = rl.user->next;
								userblockcount->next->next = NULL;
							}
							else
							{
								bl.user = rl.user;
								rl.user = rl.user->next;
								bl.user->next = NULL;
							}
							

						}
						//若当前进程优先级为0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}
				//申请4号资源
				else if (reqname == 4)
				{
					//申请资源数量小于剩余数量，即能够申请
					if (re4.numleft >= reqnum)
					{
						re4.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//申请资源数量大于剩余数量，被阻塞
					else if (re4.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//修改当前进程状态为阻塞	
						running->resources[reqname - 1] = -reqnum;
						//若当前进程优先级为2
						if (running->priority == 2)
						{
							sysblockcount = bl.sys;
							if (sysblockcount != NULL)
							{
								while (sysblockcount->next != NULL)
								{
									sysblockcount = sysblockcount->next;
								}
								sysblockcount->next = rl.sys;
								rl.sys = rl.sys->next;
								sysblockcount->next->next = NULL;
							}
							else
							{
								bl.sys = rl.sys;
								rl.sys = rl.sys->next;
								bl.sys->next = NULL;
							}
							
						}
						//若当前进程优先级为1
						else if (running->priority == 1)
						{
							userblockcount = bl.user;
							if (userblockcount != NULL)
							{
								while (userblockcount->next != NULL)
								{
									userblockcount = userblockcount->next;
								}
								userblockcount->next = rl.user;
								rl.user = rl.user->next;
								userblockcount->next->next = NULL;
							}
							else
							{
								bl.user = rl.user;
								rl.user = rl.user->next;
								bl.user->next = NULL;
							}
							
						}
						//若当前进程优先级为0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}
		
			}

			//释放资源
			else if (!strcmp(ins[0], "rel"))
			{
				printf("rel ok\n");
				int relname = atoi(ins[1]);
				int relnum = atoi(ins[2]);
				rel(&running,relname,relnum,&rl, &bl, &sysreadycount, &sysblockcount, &userreadycount, &userblockcount, &re1, &re2, &re3, &re4);
			}
		}
	
		//调度函数
		rblobject *schecount = new rblobject;
		int initnull = 0;
		if (running!=NULL)
		{
			switch (running->priority)
			{
			case 0:
			{
				//存在优先级为2的readylist
				if (rl.sys != NULL)
				{
					running = rl.sys->rblpcb;
				}
				//readylist无2优先级仅有1
				else if (rl.user != NULL)
				{
					running = rl.user->rblpcb;
				}
				//仅有init
				else if (rl.init != NULL)
				{
				}
				else if (bl.init != NULL)
				{
					if (!strcmp(bl.init->rblpcb->PID, "init"))
					{
						initnull = 1;
					}
				}
				break;
			}
			case 1:
			{
				//若正在运行进程被阻塞
				if (!strcmp(running->status, "blocked"))
				{
					if (rl.sys != NULL)
					{
						running = rl.sys->rblpcb;
					}
					else if (rl.user != NULL)
					{
						running = rl.user->rblpcb;
					}
					else if (rl.init != NULL)
					{
						running = rl.init->rblpcb;
					}
				}
				//存在优先级为2的readylist
				else if (rl.sys != NULL)
				{
					//解析指针指向当前进程readylist末尾
					schecount = rl.user;
					while (schecount->next != NULL)
					{
						schecount = schecount->next;
					}
					//readylist末尾增加当前进程
					schecount->next = rl.user;
					rl.user = rl.user->next;
					schecount->next->next = NULL;
					//rl中下一个进程代替当前优先地位
					//重置running指针
					running = rl.sys->rblpcb;
				}
				//优先级为1or0刷新running、
				else if (rl.user != NULL)
				{
					running = rl.user->rblpcb;
				}
				break;
			}
			case 2:
			{
				//若正在运行进程被阻塞
				if (!strcmp(running->status, "blocked"))
				{
					if (rl.sys != NULL)
					{
						running = rl.sys->rblpcb;
					}
					else if (rl.user != NULL)
					{
						running = rl.user->rblpcb;
					}
					else if (rl.init != NULL)
					{
						running = rl.init->rblpcb;
					}
				}
				else
				{
					running = rl.sys->rblpcb;
				}
				break;
			}
			default:
				printf("running priority error/n");
				break;
			}
		}
		else
		{
			if (rl.sys!=NULL)
			{
				running = rl.sys->rblpcb;
			}
			else if (rl.user!=NULL)
			{
				running = rl.user->rblpcb;
			}
			else
			{
				running = rl.init->rblpcb;
			}
		}

		//输出测试
		rblobject *test=new rblobject;
	//	cout << "readylist.Init:";
		if (rl.init == NULL)
		{
//			cout << rl.init << endl;
		}
		else
		{
			test = rl.init;
	//		cout << test->rblpcb->PID;
			while (test->next!=NULL)
			{
//				cout << test->next->rblpcb->PID;
				test = test->next;
			}
	//		cout << endl;
		}
	//	cout << "readylist.User:";
		if (rl.user == NULL)
		{
	//		cout << rl.user << endl;
		}
		else
		{
			test = rl.user;
	//		cout << test->rblpcb->PID;
			while (test->next != NULL)
			{
	//			cout << test->next->rblpcb->PID;
				test = test->next;
			}
	//		cout << endl;
		}
	//	cout << "readylist.Sys:";
		if (rl.sys == NULL)
		{
	//		cout << rl.sys << endl;
		}
		else
		{
			test = rl.sys;
	//		cout << test->rblpcb->PID;
			while (test->next != NULL)
			{
	//			cout << test->next->rblpcb->PID ;
				test = test->next;
			}
	//		cout << endl;
		}
	//	cout << "blocklist.Init:";
		if (bl.init == NULL)
		{
	//		cout << bl.init << endl;
		}
		else
		{
			test = bl.init;
	//		cout << test->rblpcb->PID;
			while (test->next != NULL)
			{
	//			cout << test->next->rblpcb->PID ;
				test = test->next;
			}
	//		cout << endl;
		}
	//	cout << "blocklist.User:";
		if (bl.user == NULL)
		{
	//		cout << bl.user << endl;
		}
		else
		{
			test = bl.user;
	//		cout << test->rblpcb->PID;
			while (test->next != NULL)
			{
//				cout << test->next->rblpcb->PID ;
				test = test->next;
			}
//			cout << endl;
		}
	//	cout << "blocklist.Sys:";
		if (bl.sys == NULL)
		{
	//		cout << bl.sys << endl;
		}
		else
		{
			test = bl.sys;
	//		cout << test->rblpcb->PID;
			while (test->next != NULL)
			{
	//			cout << test->next->rblpcb->PID ;
				test = test->next;
			}
//			cout << endl;
		}
		if (initnull==1)
		{
			running = NULL;
		}
		if (running!=NULL)
		{
			cout << "running:" << running->PID << endl;
		}
		else
		{
			cout << "running:" << running << endl;
		}

		
	}
}