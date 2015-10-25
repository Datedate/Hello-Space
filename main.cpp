#include <math.h>
#include "DxLib.h"
#define PI (3.141592654)
int gpUpdateKey(void);
void gpCalc(void);
void gpDraw(void);
int Key[256];			// �L�[��������Ă���t���[�������i�[����
/*int x = 320, y = 240;
int Handle;*/
/*int SelectNum = 0;		// ���݂̑I��ԍ�
int i;
typedef struct {
	int x, y;		// ���W�i�[�p�ϐ�
	char name[128];	// ���ږ��i�[�p�ϐ�
}MenuElement_t;
MenuElement_t MenuElement[5] = {
	{ 80,100,"�Q�[���X�^�[�g" },		// �^�O�̒��g�̏��ԂɊi�[�����Bx��80,y��100���Aname��"�Q�[���X�^�[�g"���B
	{ 100,150,"���܂�" },
	{ 100,200,"�w���v" },
	{ 100,250,"�R���t�B���O" },
	{ 100,300,"�Q�[���I��" },
};*/
int WINAPI WinMain(HINSTANCE histance, HINSTANCE hprevInstance, LPSTR ipCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);	// �E�B���h�E�̏���������ʐݒ�

	//int x = 0;
	int Handle[3];
	int Count = 0;		// �J�E���^
	LoadDivGraph("../Picture_�f��/Material_02.png",3,3,1,14,16,Handle);		// 3�ɉ摜�𕪊����ă��[�h
	float x = 320, y = 240, angle = 0, speed = 1;
	// while(����ʂ�\��ʂɔ��f�A���b�Z�[�W�����A��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 /*&& gpUpdateKey()==0*/) {
	
		x += cos(angle)*speed;						// x���W���X�V
		y += sin(angle)*speed;						// y���W���X�V
		/*gpCalc();							// �v�Z�t�F�[�Y
		gpDraw();							// �`��t�F�[�Y*/
		/*DrawRotaGraph(420, (int)(400 - sin(PI/2/120 * Count) * 300), 1.0, 0.0, Handle, TRUE);	// �摜�̕`��
		DrawRotaGraph(220, (int)(400- (sin(-PI/2+PI/120*Count)+ 1)/2*300),1.0, 0.0, Handle, TRUE);	// �摜�̕`��*/
		/*
		DrawGraph(0, Count % 50, Handle, TRUE);		// ����50�J�E���g�Ń��[�v�\��������
		DrawGraph(100, Count % 100, Handle, TRUE);	// ����100�J�E���g�Ń��[�v�\��������
		DrawGraph(200, Count % 150, Handle, TRUE);	// ����150�J�E���g�Ń��[�v�\��������
		*/
		if (CheckHitKey(KEY_INPUT_Z) == 1) {		// z��������Ă�����ϐ��̒��g��ύX
			x = 320;				// �������W�ɃZ�b�g
			y = 240;
			angle = GetRand(10000) / 10000.f*(PI * 2);	// 0~PI*2�̗����𐶐�
			speed = 0.5f + GetRand(10000) / 10000.f * 2;// 0.5~2.5�̗����𐶐�
		}
		DrawRotaGraph(x, y, 1.0, angle + PI / 2, Handle[0], TRUE);	// �e��`��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "angle=%.2f, speed=%2f\n", angle, speed);
	}
	DxLib_End();									// DX���C�u�����I������
	return 0;
}
/*int gpUpdateKey(void) {
	char tmpKey[256];				// ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);		// �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0;i < 256;i++) {
		if (tmpKey[i] != 0) {		// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;				// ���Z
		}
		else {						// ������Ă��Ȃ����
			Key[i] = 0;				// 0�ɂ���
		}
	}
	return 0;
}*/
/*void gpCalc() {
	if (Key[KEY_INPUT_DOWN] == 1) {			// ���̃L�[�������ꂽ�u�Ԃ�������
		SelectNum = (SelectNum + 1) % 5;	// ���݂̑I�����ڂ�����ɂ��炷�i���[�v����j
	}
	if (Key[KEY_INPUT_UP] == 1) {			// ��̃L�[�������ꂽ�u�Ԃ�������
		SelectNum = (SelectNum + 4) % 5;	// ���݂̑I�����ڂ����ɂ��炷�i���[�v����j
	}
		for (i = 0;i < 5;i++) {			// ���j���[���ڐ��ł���5���[�v����
			if (i == SelectNum) {			// ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
				MenuElement[i].x = 80;		// x���W���@80�ɂ���
			}
			else {							// ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
				MenuElement[i].x = 100;		// x���W���@100�ɂ���
			}
		}
	
}*/
/*
void gpDraw(void) {
	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	for (i = 0;i < 5;i++) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
	}
}*/