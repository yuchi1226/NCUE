//Made by ��u�@ S0954007 �L���E, S0954010 �«ɫ�, S0954044 ������, S0954046 �x��Ķ
// S0954007 �L���E: main, S0954010 �«ɫ�: pharmacy, S0954044 ������: surgery, S0954046 �x��Ķ: patientaccount.
//�J�쪺�x��: 1.�^���D�ئb�\Ū�W�|���@�ǧx���C �ѨM��k:�Э^����n���խ���½Ķ�D�ث�A���u�Q�סC
//			  2. 

#include <iostream>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

int main()
{
	PatientAccount act;
	Surgery sgy;
	pharmacy pmy;
	sgy.surgery_type(act);
	pmy.pharmacy_type(act);
	act.count();
	return 0;
}
