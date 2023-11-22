#ifndef APPLIANCE_H_
#define APPLIANCE_H_

#pragma warning(disable : 4996)

#include<time.h>
typedef struct _list list_t;
typedef enum _bool { 
	FALSE = 0, 
	TRUE = 1 
} bool_t;

enum Type {
	AIRCONDITIONER,
	RICECOOKER,
	WASHER,
	LIGHT
};
typedef struct Appliance {
	char machineName[20];		//������ǰ��
	int type;					//������ǰ�� ����
	bool powerFlag;				//���� on/off ����
	int powerConsumption;		//�ð��� ���¼Ҹ�
	int state1;					//������ǰ�� ����1
	int state2;					//������ǰ�� ����2
	time_t startHour;			//��ǰ ��� ���۽ð�(���û���2)
	time_t useHour;				//��ǰ ��� �����ð�(���û���2)
	void (*control)(list_t*);	//��Ʈ�� �Լ��� ����Ű�� �Լ� ������
	void (*display)(list_t*);	//������ǰ�� ������� �Լ��� ����Ű�� �Լ� ������
	Appliance* next;			//���� ��� ������(���û���1)
	Appliance* prev;			//���� ��� ������(���û���1)

}appliance_t;


typedef struct _list {
	appliance_t* head;			//head ��� ������
	appliance_t* tail;			//tail ��� ������
	int size;					//��� ��� �� ī����
} list_t;


void AirConditionerControl(list_t* lp);	//AirConditioner ��Ʈ���Լ�
void RiceCookerControl(list_t* lp);		//RiceCooker ��Ʈ���Լ�	
void WashwerControl(list_t* lp);		//Washwer ��Ʈ���Լ�	
void LightControl(list_t* lp);			//Light ��Ʈ���Լ�	

void AirConditionerDisplay(list_t* lp); //AirConditioner ��������Լ�
void RiceCookerDisplay(list_t* lp);		//RiceCooker ��������Լ�
void WashwerDisplay(list_t* lp);		//Washwer ��������Լ�
void LightDisplay(list_t* lp);			//Light ��������Լ�

bool_t createList(list_t* lp);								// ��ũ�帮��Ʈ �ʱ�ȭ
bool_t addLast(list_t* lp, int data);						// tail node �տ� node �߰�(���� ����)
appliance_t* searchNode(list_t* lp, char* name);			// data�� ��ġ�ϴ� node �˻� 
bool_t removeNode(list_t* lp, char* name, double* power);	// data ��� ���� 
void destoryList(list_t* lp, double *power);				// ����Ʈ ���� ��� ��� ���� 
void displayList(list_t* lp);								// Ư������Ʈ���� ��� ������ ���
#endif
