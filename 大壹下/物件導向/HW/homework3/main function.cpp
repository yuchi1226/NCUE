//��u�@ ���|�X S0954016 �t�dAccount,Surgery
//��u�@ �����o S0954024 �t�dPharmacy,main fuction(�tdebug)
//�J�쪺�x��1.�^���D�ؤ@�}�l�~�ѤF�D�N �ѨM��k:�h�ݤF�X���ðO���U�ӡA�ٰݤF�P��
//2.�X�{�Z�h�ŧi�W�����D �ѨM��k:�ϥκ����d�ߡA�T�{���ӭn��bprivate/public
//3.�̲ת�sum�X���� �ѨM��k:�v��debug�íץ� 
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "Surgery.h"
#include "Pharmacy.h"


using namespace std;


int main()
{
	
	Account act;
	Surgery sgy;
	Pharmacy pmy;
	sgy.surgery_type(act);//�o��Surgery���O�Υ[��account�� 
	pmy.choosephar(act);//�o��Pharmacy���O�Υ[��account��
	act.sevices();//�o��f�Ъ������� 
	act.count();//��X�̲�sum 
	return 0;
	
}
