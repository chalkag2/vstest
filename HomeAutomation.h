#ifndef HOMEAUTOMATION_H_
#define HOMEAUTOMATION_H_

#pragma warning(disable : 4996)
#include "Appliance.h"
#define APPLIANCE_MAX_CNT 20
typedef struct Appliance appliance_t;

typedef struct HomeAutomaion {
	appliance_t applianceArray[APPLIANCE_MAX_CNT];	//등록된 가전제품 객체의 정보 저장배열
	int applianceCnt;								//등록된 가전제품의 개수 저장
}homeautomaion_t;


static int menu(char** menuList, int menuCnt);		//전달된 메뉴 출력, 메뉴번호 리턴하는 함수
int controlMenuSelect();							//가전제품의 상태변경처리 함수
void screen(homeautomaion_t *hap, list_t* lp);		//주메뉴 반복 출력, 메뉴 선택받는 함수
void listDisplayAppliance(homeautomaion_t* hap, list_t* lp); //등록된 특정타입 가전제품 상태출력함수
void addAppliance(homeautomaion_t* hap, list_t* lp);	//특정타입 가전제품 등록함수, 동일제품명 추가 불가능
void deleteAppliance(homeautomaion_t* hap, list_t* lp, double* power);	//등록된 특정타입 가전제품 삭제함수
void controlAppliance(homeautomaion_t* hap, list_t* lp);	//등록된 특정타입 가전제품 컨트롤함수

#endif
