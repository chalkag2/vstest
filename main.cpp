
#include <stdio.h>
#include <string.h>
#include "Appliance.h"
#include "HomeAutomation.h"
#pragma warning(disable : 4996)
int main() {
	homeautomaion_t ha = {};		// Ȩ�ɾ� ����ü���� ����, �ʱ�ȭ(?)
	list_t list[APPLIANCE_MAX_CNT];	// ������ǰ ����ŭ ����Ʈ ���� ����ü ����
	screen(&ha, list);
	return 0;
}