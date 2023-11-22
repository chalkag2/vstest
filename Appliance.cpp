#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Appliance.h"
/*--------------------------------------------------------------
Function name	: LightControl() - Light 상태 제어 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			: 
--------------------------------------------------------------*/
void LightControl(list_t* lp){
	char input, name[20];
	appliance_t* dp;

	if (lp == NULL) {
		return;
	}
	printf("제어하고 싶은 가전제품의 이름를 입력하시오.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("Light 제어를 시작합니다.\n");

	do {
		printf("전원을 켜시려면 y, 끄려면 n을 입력해주세요.(y/n)\n");
		scanf("%c", &input);
		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
		
		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				printf("Light의 전원이 켜졌습니다.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				printf("Light의 전원이 꺼졌습니다.\n");

			}
			break;
		}
		else {
			printf("다시 입력해주세요.\n");
		}
	} while ((input != 'y') || (input != 'n'));

}

/*--------------------------------------------------------------
Function name	: AirConditionerControl() - AirConditioner 상태 제어 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void AirConditionerControl(list_t* lp) {
	char input, name[20];
	int state1, state2,res;
	appliance_t* dp;
	printf("제어하고 싶은 가전제품의 이름를 입력하시오.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("AirConditioner 제어를 시작합니다.\n");
	do{
	printf("전원을 켜시려면 y, 끄려면 n을 입력해주세요.(y/n)\n");
	scanf("%c", &input);
	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	if ((input == 'y') || (input == 'n')) {
		if (input == 'y') {
			dp->powerFlag = 1;
			dp->state1 = 1;	//기본상태 송풍
			dp->state2 = 25;	//기본상태 25도
			printf("AirConditioner의 전원이 켜졌습니다.\n");
		}
		else if (input == 'n') {
			dp->powerFlag = 0;
			dp->state1 = 0;	//전원 꺼지면서 상태 off
			dp->state2 = 0;	//전원 꺼지면서 상태 off
			printf("AirConditioner의 전원이 꺼졌습니다.\n");

		}
		break;
	}
	else {
		printf("다시 입력해주세요.\n");
	}
	} while ((input != 'y') || (input != 'n'));

	do{
	printf("제품상태를 입력해주세요.(1:송풍, 2:냉방, 3:난방)\n");
	scanf("%d", &state1);
	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	if ((state1 == 1) || (state1 == 2) || (state1 == 3)) {
		if (state1 == 1) {
			dp->state1 = 1;
			printf("AirConditioner 1.송풍 상태입니다.\n");
		}
		else if (state1 == 2) {
			dp->state1 = 2;
			printf("AirConditioner 2.냉방 상태입니다.\n");
		}
		else if (state1 == 3) {
			dp->state1 = 3;
			printf("AirConditioner 3.난방 상태입니다.\n");
		}
		break;
	}
	else {
		printf("다시 입력해주세요.\n");
	}
	} while ((state1 != 1) || (state1 != 2) || (state1 != 3));

	do{
	printf("온도를 입력해주세요.\n");
	res = scanf("%d", &state2);
	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.
	//정수만 들어오게 에러처리 필요
	dp->state2 = state2;
	} while (res==0);
	printf("AirConditioner의 온도는 %d입니다.\n", dp->state2);
}


/*--------------------------------------------------------------
Function name	: RiceCookerControl() - RiceCooker 상태 제어 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void RiceCookerControl(list_t* lp) {
	char input, name[20];
	int state1;
	appliance_t* dp;
	printf("제어하고 싶은 가전제품의 이름를 입력하시오.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	printf("RiceCooker 제어를 시작합니다.\n");
	printf("전원을 켜시려면 y, 끄려면 n을 입력해주세요.(y/n)\n");
	do{

		scanf("%c", &input);
		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				dp->state1 = 1;	//무동작
				printf("RiceCooker의 전원이 켜졌습니다.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				dp->state1 = 0;	//전원 꺼지면서 상태 off
				printf("RiceCooker의 전원이 꺼졌습니다.\n");

			}
			break;
		}
		else {
			printf("다시 입력해주세요.\n");
		}
	
	} while ((input != 'y') || (input != 'n'));
	do {

		printf("제품상태를 입력해주세요.(1:무동작, 2:보온, 3:밥짓기, 4:데우기)\n");
		scanf("%d", &state1);

		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
	
		if ((state1 == 1) || (state1 == 2) || (state1 == 3) || (state1 == 4)) {
			if (state1 == 1) {
				dp->state1 = 1;
				printf("RiceCooker 1.무동작 상태입니다.\n");
			}
			else if (state1 == 2) {
				dp->state1 = 2;
				printf("RiceCooker 2.보온 상태입니다.\n");
			}
			else if (state1 == 3) {
				dp->state1 = 3;
				printf("RiceCooker 3.밥짓기 상태입니다.\n");
			}
			else if (state1 == 4) {
				dp->state1 = 4;
				printf("RiceCooker 4.데우기 상태입니다.\n");
			}
			break;
	}
	else {
		printf("다시 입력해주세요.\n");
	}
	
	} while ((state1 != 1) || (state1 != 2) || (state1 != 3) || (state1 != 4));
}

/*--------------------------------------------------------------
Function name	: WashwerControl() - Washwer 상태 제어 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void WashwerControl(list_t* lp) {
	char input, name[20];
	int state1;
	appliance_t* dp;
	printf("제어하고 싶은 가전제품의 이름를 입력하시오.\n");
	scanf("%s", name);

	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

	dp = searchNode(lp, name);
	if (dp == NULL) {
		return;

	}
	do {

	printf("Washwer 제어를 시작합니다.\n");
	printf("전원을 켜시려면 y, 끄려면 n을 입력해주세요.(y/n)\n");
	scanf("%c", &input);
	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;                    // 반복한다.

		if ((input == 'y') || (input == 'n')) {
			if (input == 'y') {
				dp->powerFlag = 1;
				dp->state1 = 1;	//무동작
				printf("Washwer의 전원이 켜졌습니다.\n");
			}
			else if (input == 'n') {
				dp->powerFlag = 0;
				dp->state1 = 0;	//전원 꺼지면서 상태 off
				printf("Washwer의 전원이 꺼졌습니다.\n");

			}
			break;
		}
		else {
			printf("다시 입력해주세요.\n");
		}
	} while ((input != 'y') || (input != 'n'));

	do {
		printf("제품상태를 입력해주세요.(1:무동작, 2:일반빨래, 3:삶은빨래, 4:건조)\n");
		scanf("%d", &state1);
		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.

		if ((state1 == 1) || (state1 == 2) || (state1 == 3) || (state1 == 4)) {
			if (state1 == 1) {
				dp->state1 = 1;
				printf("RiceCooker 1.무동작 상태입니다.\n");
			}
			else if (state1 == 2) {
				dp->state1 = 2;
				printf("RiceCooker 2.일반빨래 상태입니다.\n");
			}
			else if (state1 == 3) {
				dp->state1 = 3;
				printf("RiceCooker 3.삶은빨래 상태입니다.\n");
			}
			else if (state1 == 4) {
				dp->state1 = 4;
				printf("RiceCooker 4.건조 상태입니다.\n");
			}
			break;
		}
		else {
			printf("다시 입력해주세요.\n");
		}
	}while (((state1 != 1) || (state1 != 2) || (state1 != 3) || (state1 != 4)));

}

/*--------------------------------------------------------------
Function name	: AirConditionerDisplay() - AirConditioner 상태 출력 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void AirConditionerDisplay(list_t* lp) {
	///* lp포인터 NULL check */
	///* 첫 번째 데이터 노드를 지정한 후 */
	///* 마지막 노드까지의 데이터를 출력한다. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("가전제품 이름 : %s, 타입 : %d, 전원상태 : %d, 전력량 : %d, 제품상태 : %d, 설정온도 :%d도\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1,tp->state2);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: RiceCookerDisplay() - RiceCooker 상태 출력 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void RiceCookerDisplay(list_t* lp) {
	///* lp포인터 NULL check */
	///* 첫 번째 데이터 노드를 지정한 후 */
	///* 마지막 노드까지의 데이터를 출력한다. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("가전제품 이름 : %s, 타입 : %d, 전원상태 : %d, 전력량 : %d, 제품상태 : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: WashwerDisplay() - Washwer 상태 출력 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void WashwerDisplay(list_t* lp) {
	///* lp포인터 NULL check */
	///* 첫 번째 데이터 노드를 지정한 후 */
	///* 마지막 노드까지의 데이터를 출력한다. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("가전제품 이름 : %s, 타입 : %d, 전원상태 : %d, 전력량 : %d, 제품상태 : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption, tp->state1);
		tp = tp->next;
	}
	printf("\n");
}

/*--------------------------------------------------------------
Function name	: LightDisplay() - Light 상태 출력 함수
Parameters		: lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void LightDisplay(list_t* lp) {
	///* lp포인터 NULL check */
	///* 첫 번째 데이터 노드를 지정한 후 */
	///* 마지막 노드까지의 데이터를 출력한다. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("가전제품 이름 : %s, 타입 : %d, 전원상태 : %d, 전력량 : %d\n", tp->machineName, tp->type, tp->powerFlag, tp->powerConsumption);
		tp = tp->next;
	}
	printf("\n");
}
/*----------------------------------------------------------------
Function name	: createList() - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------*/
bool_t createList(list_t* lp) {

	if (lp == NULL) {
		return FALSE;
	}
	lp->head = (appliance_t*)malloc(sizeof(appliance_t));  // head node 할당 
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (appliance_t*)malloc(sizeof(appliance_t)); // tail node 할당
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}
	lp->head->next = lp->tail;
	lp->head->prev = lp->head;	//추가
	lp->head->powerFlag = 0;
	lp->head->state1 = 0;
	lp->head->state2 = 0;
	lp->tail->next = lp->tail;
	lp->tail->prev = lp->head;	//추가
	lp->head->powerFlag = 0;
	lp->head->state1 = 0;
	lp->head->state2 = 0;
	lp->size = 0;

	return TRUE;
}


/*----------------------------------------------------------------
Function name	: 	addLast() - tail node 앞에 새 node 추가(정순 저장)
Parameters		: 	lp - 리스트 관리 구조체의 주소
					data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
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

		printf("등록할 가전제품의 이름을 입력하시오 :\n");
		scanf("%s", appName);

		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
				
	} while (searchNode(lp, appName) != NULL);
	strcpy(new_node->machineName, appName);


	do {
		printf("가전제품의 소모전력량(w)을 입력하시오 :\n");
		res = scanf("%d", &powerConsumption);
	
		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
		
	} while (res==0);

	new_node->powerConsumption = powerConsumption;
	time(&new_node->startHour);
	//타입별 초기화
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
	lp->tail->prev->next = new_node; //tailnode 앞노드의 next
	new_node->prev = lp->tail->prev;//새노드의 prev에 기존 tail 노드의 앞노드 주소 저장
	lp->tail->prev = new_node;//tail 노드의 prev에 새노드 저장
	lp->size++;
	return TRUE;
}

#if 1
/*----------------------------------------------------------------
Function name	: displayList() - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------*/
void displayList(list_t* lp) {

	///* lp포인터 NULL check */
	///* 첫 번째 데이터 노드를 지정한 후 */
	///* 마지막 노드까지의 데이터를 출력한다. */
	appliance_t* tp;
	if (lp == NULL) {
		return;
	}
	tp = lp->head->next;
	while (tp != lp->tail) {
		printf("가전제품 이름 : %s, 타입 : %d, 전원상태 : %d, 전력량 : %d, 상태 : (%d,%d)\n", tp->machineName,tp->type,tp->powerFlag,tp->powerConsumption,tp->state1,tp->state2);
		tp = tp->next;
	}
	printf("\n");
}
#endif
/*----------------------------------------------------------------
Function name	: searchNode() - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
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
Function name	: removeNode() - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
				  name - 삭제할 노드이름
				  power - 가전의 현 전력량 계산
Returns			: 성공 - TRUE / 실패 - FALSE
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
	printf("제거된 가전들의 소모전력 총량: %lfwh\n", *power);
	dp->prev->next = dp->next;
	dp->next->prev = dp->prev;
	free(dp);
	lp->size--;
	return TRUE;


}
/*----------------------------------------------------------------
Function name	: destoryList - 리스트 내의 모든 노드
				  (head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
				  power - 가전의 현 전력량 계산
Returns			: 없음
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
	//printf("지금까지의 소모전력 총량: %llfwh\n", *power);
}
