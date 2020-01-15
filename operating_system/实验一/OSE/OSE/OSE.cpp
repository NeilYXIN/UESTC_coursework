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

//readylist��blocklist�еĵ�Ԫ
typedef struct rblobject {
	struct PCB *rblpcb;
	struct rblobject *next;
}*rblp;

typedef struct resource {
	int RID;
	int numall;
	int numleft;
}*rp;

//��Դ��waitinglist�ĵ�Ԫ
typedef struct reobject {
	struct PCB *repcb;
	struct reobject *next;
}reobject,*rep;

typedef struct PCB
{
	char PID[25];//������ 
	int  resources[4] = {0,0,0,0};//�ý�����ռ����Դ���� 
	char status[25];//����״̬ 
	struct PCB *parent;//ָ��ý��̸����̵�ָ�� 
	struct PCB *child;//ָ��ý����ӽ��̵�ָ�� 
	struct PCB *brother;//ָ��ý����ֵܽ��̵�ָ�� 
	int priority;//���ȼ���0:init 1:user 2system 
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
		//�������в�Ϊ��
		if ((*bl).sys != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			(*sysblockcount) = (*bl).sys;//��ֵ����
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re1).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re1).numleft)
			{
				(*re1).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*sysreadycount = (*rl).sys;
				//���������в�Ϊ��
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysreadycount);
					(*sysreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
				else
				{
					(*rl).sys = *sysblockcount;
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re1).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re1).numleft)
			{
				(*re1).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*userreadycount = (*rl).user;
				//���������в�Ϊ��
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
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
		//�������в�Ϊ��
		if ((*bl).sys != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re2).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re2).numleft)
			{
				(*re2).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*sysreadycount = (*rl).sys;
				//���������в�Ϊ��
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re2).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re2).numleft)
			{
				(*re2).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*userreadycount = (*rl).user;
				//���������в�Ϊ��
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
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
		//�������в�Ϊ��
		if ((*bl).sys != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re3).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re3).numleft)
			{
				(*re3).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*sysreadycount = (*rl).sys;
				//���������в�Ϊ��
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re3).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re3).numleft)
			{
				(*re3).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*userreadycount = (*rl).user;
				//���������в�Ϊ��
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
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
		//�������в�Ϊ��
		if ((*bl).sys != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*sysblockcount = (*bl).sys;
			while ((*sysblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*sysblockcount)->rblpcb->resources[relname - 1]) > (*re4).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*sysblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*sysblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*sysblockcount)->rblpcb->resources[relname - 1]) <= (*re4).numleft)
			{
				(*re4).numleft += (*sysblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*sysblockcount)->rblpcb->resources[relname - 1] = abs((*sysblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*sysblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*sysreadycount = (*rl).sys;
				//���������в�Ϊ��
				if ((*rl).sys != NULL)
				{
					while ((*sysreadycount)->next != NULL)
					{
						(*sysreadycount) = (*sysreadycount)->next;
					}
					(*sysreadycount)->next = (*sysblockcount);
					(*sysreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
				else
				{
					(*rl).sys = (*sysblockcount);
					(*rl).sys->next = NULL;
				}
			}
		}
		else if ((*bl).user != NULL)
		{
			//���ҵ�һ��������Դ�����Ľ���
			*userblockcount = (*bl).user;
			while ((*userblockcount)->rblpcb->resources[relname - 1] > 0 || abs((*userblockcount)->rblpcb->resources[relname - 1]) > (*re4).numleft)//���̱�������������Դ����С��ʣ��
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
			//��û�н����ڵȴ�����Դ
			if ((*userblockcount)->rblpcb->resources[relname - 1] > 0)
			{
			}
			//�����������н����ڵȴ�����Դ
			else if ((*userblockcount)->rblpcb->resources[relname - 1] < 0 && abs((*userblockcount)->rblpcb->resources[relname - 1]) <= (*re4).numleft)
			{
				(*re4).numleft += (*userblockcount)->rblpcb->resources[relname - 1];//ʣ����Դ������Ӧ����
				(*userblockcount)->rblpcb->resources[relname - 1] = abs((*userblockcount)->rblpcb->resources[relname - 1]);
				strcpy_s((*userblockcount)->rblpcb->status, "ready");
				//���ý��̴�blocklist�Ƴ�
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
				//���ý��̲��뵽��������ĩβ						
				*userreadycount = (*rl).user;
				//���������в�Ϊ��
				if ((*rl).user != NULL)
				{
					while ((*userreadycount)->next != NULL)
					{
						(*userreadycount) = (*userreadycount)->next;
					}
					(*userreadycount)->next = (*userblockcount);
					(*userreadycount)->next->next = NULL;
				}
				//��������Ϊ��ʱ
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
		//ɾ��ռ����Դ
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
		//ɾ��readylist��blocklist
		else if ((*deltarget)->priority == 2)//��ǰ�ڵ�������ȼ�Ϊ2��sysʱ
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
		else if ((*deltarget)->priority == 1)//��ǰ�ڵ�������ȼ�Ϊ1��userʱ
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
		else if ((*deltarget)->priority == 0)//��ǰ�ڵ�������ȼ�Ϊ0��initʱ
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
		//ɾ��ռ����Դ
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
		//ɾ��readylist��blocklist
		else if ((*deltarget)->priority == 2)//��ǰ�ڵ�������ȼ�Ϊ2��sysʱ
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
		else if ((*deltarget)->priority == 1)//��ǰ�ڵ�������ȼ�Ϊ1��userʱ
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
		else if ((*deltarget)->priority == 0)//��ǰ�ڵ�������ȼ�Ϊ0��initʱ
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
	char str[100];//��Ŷ����ָ���ַ��� 
	char ins[25][20];//��ָ���ֺ�װ������ 
	int pstr;//�ַ���strָ�� 
	int i = 0;//��ά����i 
	int j = 0;//��ά����j 

	while (1)
	{
		rblobject *initreadycount=new rblobject;
		rblobject *sysreadycount=new rblobject;
		rblobject *userreadycount =new rblobject;
		rblobject *initblockcount=new rblobject;
		rblobject *sysblockcount= new rblobject;
		rblobject *userblockcount=new rblobject;
		printf("shell>");
		fgets(str, 100, stdin);//����ָ�� 
		i = 0;

		for (pstr = 0; str[pstr] != '\n'&&str[pstr] != '\0'&&pstr<100; pstr++)//�ж�pstr��ǰ��ָ ���ǻ��з� �� ��ֹ�� �ҳ��ȺϷ�ʱ ������ѭ�� 
		{
			j = 0;
			while (str[pstr] != ' '&&str[pstr] != '\n')//��ǰ��ָ��ʵ�������Ҳ�Ϊ�ո�ʱ ���������ʲ�ֳ��� 
			{
				ins[i][j++] = str[pstr++];//����ǰ��ָ ��������ins[i]��j����
			}
			if (str[pstr - 1] != ' ')// ����������ѭ�����������⣬���ǰһ���ַ������ݣ���ǰ���ʽ��� 
			{
				ins[i++][j] = '\0';//����������,i���� 							
			}
		}
		if (i <= 0 || i>3)
		{
			printf("invalid command length\n");
		}
		//һ����ָ��
		else if (i == 1)
		{
			//initָ��
			if (!strcmp(ins[0], "init"))
			{
				printf("init ok\n");
				PCB init = { "init",0,0,0,0,"ready",NULL,NULL,NULL,0};
				running = &init;
				pcbp = &init;
	/*			cout << running->PID << endl << "resources:" << running->resources[0]<<running->resources[1]<<running->resources[2]<<running->resources[3] << endl << running->status 
					<<endl << "parent��" << running->parent << endl << "child��" << running->child << endl	<< "brother��" << running->brother << endl << running->priority 
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
			//timeoutָ��
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
			//�޷���ָ���򱨴�
			else {
				printf("invalid command1\n");
			}
		}
		//������ָ��
		else if (i == 2)
		{
			//ɾ������ָ��
			if (!strcmp(ins[0], "de"))
			{
				printf("de ok\n");			
				PCB *depcb = new PCB;//ָ����Ҫɾ���Ľ���
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
		//������ָ��
		else if (i == 3)
		{
			//�����½���
			if (!strcmp(ins[0], "cr"))
			{
				printf("cr ok\n");
				i = atoi(ins[2]);
				PCB  *create=new PCB;
				//��ʼ���½���PCB
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
				//  �������
			
				}
				else if (running->child == NULL)
				{
					running->child = create;
					//�������
			
				}	
				rblobject  *newrblobj = new rblobject;				
				newrblobj->rblpcb = create;
				newrblobj->next = NULL;

				//����readylist����ĩβ
				//���ȼ�Ϊ1ʱ
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
				//���ȼ�Ϊ2ʱ
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
			//������Դ
			else if (!strcmp(ins[0], "req"))
			{
				printf("req ok\n");

				int reqname = atoi(ins[1]);
				int reqnum = atoi(ins[2]);
		//		cout << reqname << endl << reqnum << endl;
				//����1����Դ
				if (reqname==1)
				{
			
					//������Դ����С��ʣ�����������ܹ�����
					if (re1.numleft >= reqnum)
					{
						re1.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//������Դ��������ʣ��������������
					else if (re1.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//�޸ĵ�ǰ����״̬Ϊ����	
						running->resources[reqname - 1] = -reqnum;
						//����ǰ�������ȼ�Ϊ2
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
						//����ǰ�������ȼ�Ϊ1
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
						//����ǰ�������ȼ�Ϊ0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}

				//����2����Դ
				else if (reqname == 2)
				{
					//������Դ����С��ʣ�����������ܹ�����
					if (re2.numleft >= reqnum)
					{
						re2.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
				    //������Դ��������ʣ��������������
					else if (re2.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//�޸ĵ�ǰ����״̬Ϊ����	
						running->resources[reqname - 1] = -reqnum;
						//����ǰ�������ȼ�Ϊ2
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
						//����ǰ�������ȼ�Ϊ1
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
						//����ǰ�������ȼ�Ϊ0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
					
				}
				//����3����Դ
				else if (reqname == 3)
				{
					//������Դ����С��ʣ�����������ܹ�����
					if (re3.numleft >= reqnum)
					{
						re3.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//������Դ��������ʣ��������������
					else if (re3.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//�޸ĵ�ǰ����״̬Ϊ����	
						running->resources[reqname - 1] = -reqnum;	
						//����ǰ�������ȼ�Ϊ2
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
						//����ǰ�������ȼ�Ϊ1
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
						//����ǰ�������ȼ�Ϊ0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}
				//����4����Դ
				else if (reqname == 4)
				{
					//������Դ����С��ʣ�����������ܹ�����
					if (re4.numleft >= reqnum)
					{
						re4.numleft -= reqnum;
						running->resources[reqname - 1] += reqnum;
					}
					//������Դ��������ʣ��������������
					else if (re4.numleft < reqnum)
					{
						strcpy_s(running->status, "blocked");//�޸ĵ�ǰ����״̬Ϊ����	
						running->resources[reqname - 1] = -reqnum;
						//����ǰ�������ȼ�Ϊ2
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
						//����ǰ�������ȼ�Ϊ1
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
						//����ǰ�������ȼ�Ϊ0
						else if (running->priority == 0)
						{
							bl.init = rl.init;
							rl.init = NULL;
						}
					}
				}
		
			}

			//�ͷ���Դ
			else if (!strcmp(ins[0], "rel"))
			{
				printf("rel ok\n");
				int relname = atoi(ins[1]);
				int relnum = atoi(ins[2]);
				rel(&running,relname,relnum,&rl, &bl, &sysreadycount, &sysblockcount, &userreadycount, &userblockcount, &re1, &re2, &re3, &re4);
			}
		}
	
		//���Ⱥ���
		rblobject *schecount = new rblobject;
		int initnull = 0;
		if (running!=NULL)
		{
			switch (running->priority)
			{
			case 0:
			{
				//�������ȼ�Ϊ2��readylist
				if (rl.sys != NULL)
				{
					running = rl.sys->rblpcb;
				}
				//readylist��2���ȼ�����1
				else if (rl.user != NULL)
				{
					running = rl.user->rblpcb;
				}
				//����init
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
				//���������н��̱�����
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
				//�������ȼ�Ϊ2��readylist
				else if (rl.sys != NULL)
				{
					//����ָ��ָ��ǰ����readylistĩβ
					schecount = rl.user;
					while (schecount->next != NULL)
					{
						schecount = schecount->next;
					}
					//readylistĩβ���ӵ�ǰ����
					schecount->next = rl.user;
					rl.user = rl.user->next;
					schecount->next->next = NULL;
					//rl����һ�����̴��浱ǰ���ȵ�λ
					//����runningָ��
					running = rl.sys->rblpcb;
				}
				//���ȼ�Ϊ1or0ˢ��running��
				else if (rl.user != NULL)
				{
					running = rl.user->rblpcb;
				}
				break;
			}
			case 2:
			{
				//���������н��̱�����
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

		//�������
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