#ifndef HOMEAUTOMATION_H_
#define HOMEAUTOMATION_H_

#pragma warning(disable : 4996)
#include "Appliance.h"
#define APPLIANCE_MAX_CNT 20
typedef struct Appliance appliance_t;

typedef struct HomeAutomaion {
	appliance_t applianceArray[APPLIANCE_MAX_CNT];	//��ϵ� ������ǰ ��ü�� ���� ����迭
	int applianceCnt;								//��ϵ� ������ǰ�� ���� ����
}homeautomaion_t;


static int menu(char** menuList, int menuCnt);		//���޵� �޴� ���, �޴���ȣ �����ϴ� �Լ�
int controlMenuSelect();							//������ǰ�� ���º���ó�� �Լ�
void screen(homeautomaion_t *hap, list_t* lp);		//�ָ޴� �ݺ� ���, �޴� ���ù޴� �Լ�
void listDisplayAppliance(homeautomaion_t* hap, list_t* lp); //��ϵ� Ư��Ÿ�� ������ǰ ��������Լ�
void addAppliance(homeautomaion_t* hap, list_t* lp);	//Ư��Ÿ�� ������ǰ ����Լ�, ������ǰ�� �߰� �Ұ���
void deleteAppliance(homeautomaion_t* hap, list_t* lp, double* power);	//��ϵ� Ư��Ÿ�� ������ǰ �����Լ�
void controlAppliance(homeautomaion_t* hap, list_t* lp);	//��ϵ� Ư��Ÿ�� ������ǰ ��Ʈ���Լ�

#endif
