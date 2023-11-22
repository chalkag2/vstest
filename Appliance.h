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
	char machineName[20];		//가전제품명
	int type;					//가전제품의 종류
	bool powerFlag;				//전원 on/off 상태
	int powerConsumption;		//시간당 전력소모량
	int state1;					//가전제품의 상태1
	int state2;					//가전제품의 상태2
	time_t startHour;			//제품 사용 시작시간(선택사항2)
	time_t useHour;				//제품 사용 누적시간(선택사항2)
	void (*control)(list_t*);	//컨트롤 함수를 가리키는 함수 포인터
	void (*display)(list_t*);	//가전제품의 상태출력 함수를 가리키는 함수 포인터
	Appliance* next;			//다음 노드 포인터(선택사항1)
	Appliance* prev;			//이전 노드 포인터(선택사항1)

}appliance_t;


typedef struct _list {
	appliance_t* head;			//head 노드 포인터
	appliance_t* tail;			//tail 노드 포인터
	int size;					//등록 노드 수 카운터
} list_t;


void AirConditionerControl(list_t* lp);	//AirConditioner 컨트롤함수
void RiceCookerControl(list_t* lp);		//RiceCooker 컨트롤함수	
void WashwerControl(list_t* lp);		//Washwer 컨트롤함수	
void LightControl(list_t* lp);			//Light 컨트롤함수	

void AirConditionerDisplay(list_t* lp); //AirConditioner 상태출력함수
void RiceCookerDisplay(list_t* lp);		//RiceCooker 상태출력함수
void WashwerDisplay(list_t* lp);		//Washwer 상태출력함수
void LightDisplay(list_t* lp);			//Light 상태출력함수

bool_t createList(list_t* lp);								// 링크드리스트 초기화
bool_t addLast(list_t* lp, int data);						// tail node 앞에 node 추가(정순 저장)
appliance_t* searchNode(list_t* lp, char* name);			// data와 일치하는 node 검색 
bool_t removeNode(list_t* lp, char* name, double* power);	// data 노드 삭제 
void destoryList(list_t* lp, double *power);				// 리스트 내의 모든 노드 삭제 
void displayList(list_t* lp);								// 특정리스트내의 모든 데이터 출력
#endif
