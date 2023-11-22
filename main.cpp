
#include <stdio.h>
#include <string.h>
#include "Appliance.h"
#include "HomeAutomation.h"
#pragma warning(disable : 4996)
int main() {
	homeautomaion_t ha = {};		// 홈케어 구조체변수 선언, 초기화(?)
	list_t list[APPLIANCE_MAX_CNT];	// 가전제품 수만큼 리스트 관리 구조체 선언
	screen(&ha, list);
	return 0;
}