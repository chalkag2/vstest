#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HomeAutomation.h"

/*--------------------------------------------------------------
Function name	: menu() - 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
Parameters		: menuList - 메뉴목록
				  menuCnt - 메뉴개수
Returns			: 메뉴번호
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
		printf("\n메뉴번호입력 : ");
		res = scanf("%d", &num);
		while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
			continue;                    // 반복한다.
		if (res!=1) printf("잘못 입력하였습니다.\n");
		if (num <= menuCnt) break;
	}
	return num;
}


/*--------------------------------------------------------------
Function name	: screen() - 주메뉴를 출력하고 메뉴를 선택 받아 반복적으로 주메뉴를 처리하는 함수
Parameters		: hap : 홈케어 구조체의 주소
				  lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void screen(homeautomaion_t *hap, list_t* lp) {

	const char* menuList[] = { "가전제품 상태 확인",
		                       "가전제품 제어",
		                       "가전제품 등록",
		                       "가전제품 삭제",
		                       "종료" 
						     };

	int menuNum;
	int menuCnt;
	double totalPower = 0.0, power =0.0;
	bool_t bres;
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	for (int i = 0; i < 20; i++) {

		bres = createList(&lp[i - 1]);					/* 비어 있는 리스트 초기화 */
		if (bres == TRUE) {								//list 생성 성공
			//printf("@ list%d 생성 성공!\n",i);
			listcheck[i] += 1;
		}
		else {
			printf("@ list 생성 실패!\n");
			return;
		}
	}

	printf("홈케어시스템 시작\n");
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
	printf("지금까지의 소모전력 총량 : %lfkwh\n",totalPower);
	printf("홈케어시스템 종료\n");
}


/*--------------------------------------------------------------
Function name	: listDisplayAppliance() - 등록된 가전제품의 상태출력
Parameters		: hap : 홈케어 구조체의 주소
				  lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/

void listDisplayAppliance(homeautomaion_t* hap, list_t* lp) {
	int type, res;
	do {
		printf("출력할 가전제품의 종류를 입력하시오 :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // 문자 입력시 종료
			while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
				continue;                    // 반복한다.
			break;
		}

	} while (type > 4);
	printf("등록된 가전제품의 상태 현황입니다.\n");

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
Function name	: addAppliance() - 가전제품 등록, 동일한 제품명 추가 불가능
Parameters		: hap : 홈케어 구조체의 주소
				  lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void addAppliance(homeautomaion_t* hap, list_t* lp) {
	int type;
	char appName[20] = {};
	int res;	/* scanf()함수의 리턴 값 저장 */
	bool_t bres;
	appliance_t* napt =NULL;
	do {
		printf("등록할 가전제품의 종류를 입력하시오 :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // 문자 입력시 종료
			while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
				continue;                    // 반복한다.
			printf("문자가 입력되었습니다.\n");
			return;
		}
		
	} while (type > 4);

	bres = addLast(&lp[type - 1], type);	/* tail 노드 앞에 데이터 추가  */
	if (bres == TRUE)
		printf("@ 데이터 추가 성공!\n");
	else
		printf("@ 데이터 추가 실패!\n");
}
/*--------------------------------------------------------------
Function name	: deleteAppliance() - 가전제품 삭제
Parameters		: hap : 홈케어 구조체의 주소
				  lp : 리스트 관리 구조체의 주소
				  power : 전력량을 구하기 위한 변수의 주소
Returns			:
--------------------------------------------------------------*/
void deleteAppliance(homeautomaion_t* hap, list_t* lp, double* power) {
	char appName[20] = {};
	int bres,type,res;
	*power = 0.0;
	do {
		printf("삭제할 가전제품의 타입을 입력하시오 :\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // 문자 입력시 종료
			while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
				continue;                    // 반복한다.
			printf("문자가 입력되었습니다.\n");
			return;
		}

	} while (type > 4);

	displayList(&lp[type-1]);
	printf("삭제할 가전제품의 이름을 입력하시오 :\n");
	scanf("%s", appName);

	while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
		continue;					 // 반복한다.
	
	bres = removeNode(&lp[type - 1], appName, power);
	if (bres == TRUE) {
		printf("@ 삭제 성공!\n");
		listcheck[type - 1] -= 1;
	}
	else {
		printf("@ 삭제 실패!\n");
	}
}
/*--------------------------------------------------------------
Function name	: controlAppliance() - 등록된 가전제품 제어하기
Parameters		: hap : 홈케어 구조체의 주소
				  lp : 리스트 관리 구조체의 주소
Returns			:
--------------------------------------------------------------*/
void controlAppliance(homeautomaion_t* hap, list_t* lp) {
	int type, res;

	do {
		printf("제어하고 싶은 가전제품의 타입을 입력하시오.\n");
		printf("(Airconditioner : 1, Ricecooker : 2, Washer : 3, Light : 4)\n");
		res = scanf("%d", &type);
		if (res == 0) {						 // 문자 입력시 종료
			while (getchar() != '\n')        // 읽은 값이 줄바꿈 문자가 아니면
				continue;                    // 반복한다.
			printf("문자가 입력되었습니다.\n");
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
