#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HomeAutomation.h"

/*--------------------------------------------------------------
Function name	: menu() - ���޵� �޴��� ����ϰ� ��Ȯ�� �޴���ȣ�� �����ϴ� �Լ�
Parameters		: menuList - �޴����
				  menuCnt - �޴�����
Returns			: �޴���ȣ
--------------------------------------------------------------*/

int listcheck[APPLIANCE_MAX_CNT] = { 0, };
static int menu(const char** menuList, int menuCnt);

static int menu(const char** menuList, int menuCnt) {
	int num, res;
	num = 0;
	while (1) {
		for (int i = 0; i < menuCnt; i++) {
			printf("%d. %s\n", i + 1, menuList[i]);
		}
		printf("\n�޴���ȣ�Է� : ");
		res = scanf("%d", &num);
		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
		if (res!=1) printf("�߸� �Է��Ͽ����ϴ�.\n");
		if (num <= menuCnt) break;
	}
	return num;
}


/*--------------------------------------------------------------
Function name	: screen() - �ָ޴��� ����ϰ� �޴��� ���� �޾� �ݺ������� �ָ޴��� ó���ϴ� �Լ�
Parameters		: hap : Ȩ�ɾ� ����ü�� �ּ�
				  lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void screen(homeautomaion_t *hap, list_t* lp) {

	const char* menuList[] = { "������ǰ ���� Ȯ��",
		                       "������ǰ ����",
		                       "������ǰ ���",
		                       "������ǰ ����",
		                       "����" 
						     };

	int menuNum;
	int menuCnt;
	double totalPower = 0.0, power =0.0;
	bool_t bres;
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	for (int i = 0; i < 20; i++) {

		bres = createList(&lp[i - 1]);					/* ��� �ִ� ����Ʈ �ʱ�ȭ */
		if (bres == TRUE) {								//list ���� ����
			//printf("@ list%d ���� ����!\n",i);
			listcheck[i] += 1;
		}
		else {
			printf("@ list ���� ����!\n");
			return;
		}
	}

	printf("Ȩ�ɾ�ý��� ����\n");
	while (1) {
		menuNum = menu(menuList, menuCnt);

		if (menuNum == menuCnt) break;
		switch (menuNum) {
		case 1:
			listDisplayAppliance(hap, lp);
			break;
		case 2:
			controlAppliance(hap, lp);
			break;
		case 3:
			addAppliance(hap, lp);
			break;
		case 4:
			power = 0.0;
			deleteAppliance(hap, lp, &power);
			totalPower += power;
			break;
		default:
			;
			break;
		}
		
	}
	for (int i = 0; i < 20; i++) {
		power = 0.0;
		destoryList(&lp[i - 1],&power);
		totalPower += power;
	}
	printf("���ݱ����� �Ҹ����� �ѷ� : %lfkwh\n",totalPower);
	printf("Ȩ�ɾ�ý��� ����\n");
}


/*--------------------------------------------------------------
Function name	: listDisplayAppliance() - ��ϵ� ������ǰ�� �������
Parameters		: hap : Ȩ�ɾ� ����ü�� �ּ�
				  lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/

void listDisplayAppliance(homeautomaion_t* hap, list_t* lp) {
	int type, res;
	do {
		printf("����� ������ǰ�� ������ �Է��Ͻÿ� :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // ���� �Է½� ����
			while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
				continue;                    // �ݺ��Ѵ�.
			break;
		}

	} while (type > 4);
	printf("��ϵ� ������ǰ�� ���� ��Ȳ�Դϴ�.\n");

	switch (type) {
	case 1:
		lp[type - 1].head->display = AirConditionerDisplay;
		lp[type - 1].head->display(&lp[type - 1]);
		break;
	case 2:
		lp[type - 1].head->display = RiceCookerDisplay;
		lp[type - 1].head->display(&lp[type - 1]);
		break;
	case 3:
		lp[type - 1].head->display = WashwerDisplay;
		lp[type - 1].head->display(&lp[type - 1]);
		break;
	case 4:

		lp[type - 1].head->display = LightDisplay;
		lp[type - 1].head->display(&lp[type - 1]);
		break;
	default:
		break;
	}
	

}
/*--------------------------------------------------------------
Function name	: addAppliance() - ������ǰ ���, ������ ��ǰ�� �߰� �Ұ���
Parameters		: hap : Ȩ�ɾ� ����ü�� �ּ�
				  lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void addAppliance(homeautomaion_t* hap, list_t* lp) {
	int type;
	char appName[20] = {};
	int res;	/* scanf()�Լ��� ���� �� ���� */
	bool_t bres;
	appliance_t* napt =NULL;
	do {
		printf("����� ������ǰ�� ������ �Է��Ͻÿ� :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // ���� �Է½� ����
			while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
				continue;                    // �ݺ��Ѵ�.
			printf("���ڰ� �ԷµǾ����ϴ�.\n");
			return;
		}
		
	} while (type > 4);

	bres = addLast(&lp[type - 1], type);	/* tail ��� �տ� ������ �߰�  */
	if (bres == TRUE)
		printf("@ ������ �߰� ����!\n");
	else
		printf("@ ������ �߰� ����!\n");
}
/*--------------------------------------------------------------
Function name	: deleteAppliance() - ������ǰ ����
Parameters		: hap : Ȩ�ɾ� ����ü�� �ּ�
				  lp : ����Ʈ ���� ����ü�� �ּ�
				  power : ���·��� ���ϱ� ���� ������ �ּ�
Returns			:
--------------------------------------------------------------*/
void deleteAppliance(homeautomaion_t* hap, list_t* lp, double* power) {
	char appName[20] = {};
	int bres,type,res;
	*power = 0.0;
	do {
		printf("������ ������ǰ�� Ÿ���� �Է��Ͻÿ� :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // ���� �Է½� ����
			while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
				continue;                    // �ݺ��Ѵ�.
			printf("���ڰ� �ԷµǾ����ϴ�.\n");
			return;
		}

	} while (type > 4);

	displayList(&lp[type-1]);
	printf("������ ������ǰ�� �̸��� �Է��Ͻÿ� :\n");
	scanf("%s", appName);

	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;					 // �ݺ��Ѵ�.
	
	bres = removeNode(&lp[type - 1], appName, power);
	if (bres == TRUE) {
		printf("@ ���� ����!\n");
		listcheck[type - 1] -= 1;
	}
	else {
		printf("@ ���� ����!\n");
	}
}
/*--------------------------------------------------------------
Function name	: controlAppliance() - ��ϵ� ������ǰ �����ϱ�
Parameters		: hap : Ȩ�ɾ� ����ü�� �ּ�
				  lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void controlAppliance(homeautomaion_t* hap, list_t* lp) {
	int type, res;

	do {
		printf("�����ϰ� ���� ������ǰ�� Ÿ���� �Է��Ͻÿ�.\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // ���� �Է½� ����
			while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
				continue;                    // �ݺ��Ѵ�.
			printf("���ڰ� �ԷµǾ����ϴ�.\n");
			return;
		}
	} while (type > 4);

	displayList(&lp[type-1]);	
	
	switch(type) {
	case 1:
		lp[type-1].head->control = AirConditionerControl;
		lp[type - 1].head->control(&lp[type - 1]);
		break;
	case 2:
		lp[type - 1].head->control = RiceCookerControl;
		lp[type - 1].head->control(&lp[type - 1]);
		break;
	case 3:
		lp[type - 1].head->control = WashwerControl;
		lp[type - 1].head->control(&lp[type - 1]);
		break;
	case 4:
		lp[type - 1].head->control = LightControl;
		lp[type - 1].head->control(&lp[type - 1]);
		break;
	default:
		break;
	}
}
