#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Appliance.h"
/*--------------------------------------------------------------
Function name	: LightControl() - Light ���� ���� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			: 
--------------------------------------------------------------*/
void LightControl(list_t* lp){
	char input, name[20];
	appliance_t* dp;

	if (lp == NULL) {
		return;
	}
	printf("�����ϰ� ���� ������ǰ�� �̸��� �Է��Ͻÿ�.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("Light ��� �����մϴ�.\n");

	do {
		printf("������ �ѽ÷��� y, ������ n�� �Է����ּ���.(y/n)\n");
		scanf("%c", &input);
		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
		
		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				printf("Light�� ������ �������ϴ�.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				printf("Light�� ������ �������ϴ�.\n");

			}
			break;
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	} while ((input != 'y') || (input != 'n'));

}

/*--------------------------------------------------------------
Function name	: AirConditionerControl() - AirConditioner ���� ���� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void AirConditionerControl(list_t* lp) {
	char input, name[20];
	int state1, state2,res;
	appliance_t* dp;
	printf("�����ϰ� ���� ������ǰ�� �̸��� �Է��Ͻÿ�.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("AirConditioner ��� �����մϴ�.\n");
	do{
	printf("������ �ѽ÷��� y, ������ n�� �Է����ּ���.(y/n)\n");
	scanf("%c", &input);
	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	if ((input == 'y') || (input == 'n')) {
		if (input == 'y') {
			dp->powerFlag = 1;
			dp->state1 = 1;	//�⺻���� ��ǳ
			dp->state2 = 25;	//�⺻���� 25��
			printf("AirConditioner�� ������ �������ϴ�.\n");
		}
		else if (input == 'n') {
			dp->powerFlag = 0;
			dp->state1 = 0;	//���� �����鼭 ���� off
			dp->state2 = 0;	//���� �����鼭 ���� off
			printf("AirConditioner�� ������ �������ϴ�.\n");

		}
		break;
	}
	else {
		printf("�ٽ� �Է����ּ���.\n");
	}
	} while ((input != 'y') || (input != 'n'));

	do{
	printf("��ǰ���¸� �Է����ּ���.(1:��ǳ, 2:�ù�, 3:����)\n");
	scanf("%d", &state1);
	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	if ((state1 == 1) || (state1 == 2) || (state1 == 3)) {
		if (state1 == 1) {
			dp->state1 = 1;
			printf("AirConditioner 1.��ǳ �����Դϴ�.\n");
		}
		else if (state1 == 2) {
			dp->state1 = 2;
			printf("AirConditioner 2.�ù� �����Դϴ�.\n");
		}
		else if (state1 == 3) {
			dp->state1 = 3;
			printf("AirConditioner 3.���� �����Դϴ�.\n");
		}
		break;
	}
	else {
		printf("�ٽ� �Է����ּ���.\n");
	}
	} while ((state1 != 1) || (state1 != 2) || (state1 != 3));

	do{
	printf("�µ��� �Է����ּ���.\n");
	res = scanf("%d", &state2);
	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.
	//������ ������ ����ó�� �ʿ�
	dp->state2 = state2;
	} while (res==0);
	printf("AirConditioner�� �µ��� %d�Դϴ�.\n", dp->state2);
}


/*--------------------------------------------------------------
Function name	: RiceCookerControl() - RiceCooker ���� ���� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void RiceCookerControl(list_t* lp) {
	char input, name[20];
	int state1;
	appliance_t* dp;
	printf("�����ϰ� ���� ������ǰ�� �̸��� �Է��Ͻÿ�.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("RiceCooker ��� �����մϴ�.\n");
	printf("������ �ѽ÷��� y, ������ n�� �Է����ּ���.(y/n)\n");
	do{

		scanf("%c", &input);
		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				dp->state1 = 1;	//������
				printf("RiceCooker�� ������ �������ϴ�.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				dp->state1 = 0;	//���� �����鼭 ���� off
				printf("RiceCooker�� ������ �������ϴ�.\n");

			}
			break;
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	
	} while ((input != 'y') || (input != 'n'));
	do {

		printf("��ǰ���¸� �Է����ּ���.(1:������, 2:����, 3:������, 4:�����)\n");
		scanf("%d", &state1);

		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
	
		if ((state1 == 1) || (state1 == 2) || (state1 == 3) || (state1 == 4)) {
			if (state1 == 1) {
				dp->state1 = 1;
				printf("RiceCooker 1.������ �����Դϴ�.\n");
			}
			else if (state1 == 2) {
				dp->state1 = 2;
				printf("RiceCooker 2.���� �����Դϴ�.\n");
			}
			else if (state1 == 3) {
				dp->state1 = 3;
				printf("RiceCooker 3.������ �����Դϴ�.\n");
			}
			else if (state1 == 4) {
				dp->state1 = 4;
				printf("RiceCooker 4.����� �����Դϴ�.\n");
			}
			break;
	}
	else {
		printf("�ٽ� �Է����ּ���.\n");
	}
	
	} while ((state1 != 1) || (state1 != 2) || (state1 != 3) || (state1 != 4));
}

/*--------------------------------------------------------------
Function name	: WashwerControl() - Washwer ���� ���� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void WashwerControl(list_t* lp) {
	char input, name[20];
	int state1;
	appliance_t* dp;
	printf("�����ϰ� ���� ������ǰ�� �̸��� �Է��Ͻÿ�.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	do {

	printf("Washwer ��� �����մϴ�.\n");
	printf("������ �ѽ÷��� y, ������ n�� �Է����ּ���.(y/n)\n");
	scanf("%c", &input);
	while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
		continue;                    // �ݺ��Ѵ�.

		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				dp->state1 = 1;	//������
				printf("Washwer�� ������ �������ϴ�.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				dp->state1 = 0;	//���� �����鼭 ���� off
				printf("Washwer�� ������ �������ϴ�.\n");

			}
			break;
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	} while ((input != 'y') || (input != 'n'));

	do {
		printf("��ǰ���¸� �Է����ּ���.(1:������, 2:�Ϲݻ���, 3:��������, 4:����)\n");
		scanf("%d", &state1);
		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.

		if ((state1 == 1) || (state1 == 2) || (state1 == 3) || (state1 == 4)) {
			if (state1 == 1) {
				dp->state1 = 1;
				printf("RiceCooker 1.������ �����Դϴ�.\n");
			}
			else if (state1 == 2) {
				dp->state1 = 2;
				printf("RiceCooker 2.�Ϲݻ��� �����Դϴ�.\n");
			}
			else if (state1 == 3) {
				dp->state1 = 3;
				printf("RiceCooker 3.�������� �����Դϴ�.\n");
			}
			else if (state1 == 4) {
				dp->state1 = 4;
				printf("RiceCooker 4.���� �����Դϴ�.\n");
			}
			break;
		}
		else {
			printf("�ٽ� �Է����ּ���.\n");
		}
	}while (((state1 != 1) || (state1 != 2) || (state1 != 3) || (state1 != 4)));

}

/*--------------------------------------------------------------
Function name	: AirConditionerDisplay() - AirConditioner ���� ��� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void AirConditionerDisplay(list_t* lp) {
	///* lp������ NULL check */
	///* ù ��° ������ ��带 ������ �� */
	///* ������ �������� �����͸� ����Ѵ�. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("������ǰ �̸� : %s, Ÿ�� : %d, �������� : %d, ���·� : %d, ��ǰ���� : %d, �����µ� :%d��\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1,tp->state2);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: RiceCookerDisplay() - RiceCooker ���� ��� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void RiceCookerDisplay(list_t* lp) {
	///* lp������ NULL check */
	///* ù ��° ������ ��带 ������ �� */
	///* ������ �������� �����͸� ����Ѵ�. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("������ǰ �̸� : %s, Ÿ�� : %d, �������� : %d, ���·� : %d, ��ǰ���� : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: WashwerDisplay() - Washwer ���� ��� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void WashwerDisplay(list_t* lp) {
	///* lp������ NULL check */
	///* ù ��° ������ ��带 ������ �� */
	///* ������ �������� �����͸� ����Ѵ�. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("������ǰ �̸� : %s, Ÿ�� : %d, �������� : %d, ���·� : %d, ��ǰ���� : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: LightDisplay() - Light ���� ��� �Լ�
Parameters		: lp : ����Ʈ ���� ����ü�� �ּ�
Returns			:
--------------------------------------------------------------*/
void LightDisplay(list_t* lp) {
	///* lp������ NULL check */
	///* ù ��° ������ ��带 ������ �� */
	///* ������ �������� �����͸� ����Ѵ�. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("������ǰ �̸� : %s, Ÿ�� : %d, �������� : %d, ���·� : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption);
		tp = tp->next;
	}
	printf("\n");
}
/*----------------------------------------------------------------
Function name	: createList() - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t createList(list_t* lp) {

	if (lp == NULL) {
		return FALSE;
	}
	lp->head = (appliance_t*)malloc(sizeof(appliance_t));  // head node �Ҵ� 
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (appliance_t*)malloc(sizeof(appliance_t)); // tail node �Ҵ�
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}
	lp->head->next = lp->tail;
	lp->head->prev = lp->head;	//�߰�
	lp->head->powerFlag = 0;
	lp->head->state1 = 0;
	lp->head->state2 = 0;
	lp->tail->next = lp->tail;
	lp->tail->prev = lp->head;	//�߰�
	lp->head->powerFlag = 0;
	lp->head->state1 = 0;
	lp->head->state2 = 0;
	lp->size = 0;

	return TRUE;
}


/*----------------------------------------------------------------
Function name	: 	addLast() - tail node �տ� �� node �߰�(���� ����)
Parameters		: 	lp - ����Ʈ ���� ����ü�� �ּ�
					data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t addLast(list_t* lp, int data) {

	int powerConsumption, res;
	char appName[20] = {};
	appliance_t* new_node;
	if (lp == NULL) {
		return FALSE;
	}
	new_node = (appliance_t*)malloc(sizeof(appliance_t));
	if (new_node == NULL) {
		return FALSE;
	}
	
	new_node->type = data;


	do {

		printf("����� ������ǰ�� �̸��� �Է��Ͻÿ� :\n");
		scanf("%s", appName);

		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
				
	} while (searchNode(lp, appName) != NULL);
	strcpy(new_node->machineName, appName);


	do {
		printf("������ǰ�� �Ҹ����·�(w)�� �Է��Ͻÿ� :\n");
		res = scanf("%d", &powerConsumption);
	
		while (getchar() != '\n')        // ���� ���� �ٹٲ� ���ڰ� �ƴϸ�
			continue;                    // �ݺ��Ѵ�.
		
	} while (res==0);

	new_node->powerConsumption = powerConsumption;
	time(&new_node->startHour);
	//Ÿ�Ժ� �ʱ�ȭ
	if (new_node->type == 4) {
		new_node->powerFlag = 1;
		new_node->state1 = 0;
		new_node->state2 = 0;
	}
	else if (new_node->type == 3) {
		new_node->powerFlag = 1;
		new_node->state1 = 1;
		new_node->state2 = 0;
	}
	else if (new_node->type == 2) {
		new_node->powerFlag = 1;
		new_node->state1 = 1;
		new_node->state2 = 0;
	}
	else if (new_node->type == 1) {
		new_node->powerFlag = 1;
		new_node->state1 = 1;
		new_node->state2 = 25;
	}
	new_node->next = lp->tail;
	lp->tail->prev->next = new_node; //tailnode �ճ���� next
	new_node->prev = lp->tail->prev;//������� prev�� ���� tail ����� �ճ�� �ּ� ����
	lp->tail->prev = new_node;//tail ����� prev�� ����� ����
	lp->size++;
	return TRUE;
}

#if 1
/*----------------------------------------------------------------
Function name	: displayList() - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------*/
void displayList(list_t* lp) {

	///* lp������ NULL check */
	///* ù ��° ������ ��带 ������ �� */
	///* ������ �������� �����͸� ����Ѵ�. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("������ǰ �̸� : %s, Ÿ�� : %d, �������� : %d, ���·� : %d, ���� : (%d,%d)\n", tp->machineName,tp->type,tp->powerFlag,tp->powerConsumption,tp->state1,tp->state2);
		tp = tp->next;
	}
	printf("\n");
}
#endif
/*----------------------------------------------------------------
Function name	: searchNode() - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------*/
appliance_t* searchNode(list_t* lp, char* name) {
	appliance_t* tp;
	if (lp == NULL) {
		return NULL;
	}

	tp = lp->head->next;

	 do{
		//printf("%s %s\n", tp->machineName, name);
		if ( !strcmp((tp->machineName) ,name)) {
			return tp;
		}
		tp = tp->next;

	}while (tp != lp->tail);
	return NULL;
}
/*----------------------------------------------------------------
Function name	: removeNode() - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  name - ������ ����̸�
				  power - ������ �� ���·� ���
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------*/
bool_t removeNode(list_t* lp, char* name, double* power) {
	appliance_t* dp;
	time_t startHour, endHour;
	if (lp == NULL) {
		return FALSE;
	}

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return FALSE;

	}
	startHour = dp->startHour;
	time(&dp->startHour);
	endHour = dp->startHour;
	*power += (double)(endHour - startHour)/3600 * dp->powerConsumption ;
	printf("���ŵ� �������� �Ҹ����� �ѷ�: %lfwh\n", *power);
	dp->prev->next = dp->next;
	dp->next->prev = dp->prev;
	free(dp);
	lp->size--;
	return TRUE;


}
/*----------------------------------------------------------------
Function name	: destoryList - ����Ʈ ���� ��� ���
				  (head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  power - ������ �� ���·� ���
Returns			: ����
----------------------------------------------------------------*/
void destoryList(list_t* lp, double *power) {
	appliance_t* np, * tp;
	time_t startHour, endHour;
	if (lp == NULL) {
		return;
	}
	*power = 0.0;
	tp = lp->head->next;
	while (tp != lp->tail) {
		startHour = tp->startHour;
		time(&tp->startHour);
		endHour = tp->startHour;
		*power += (double)(endHour - startHour) / 3600 * tp->powerConsumption;
		np = tp->next;
		free(tp);
		tp = np;
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	//printf("���ݱ����� �Ҹ����� �ѷ�: %llfwh\n", *power);
}
