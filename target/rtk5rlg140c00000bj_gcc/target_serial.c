/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 *
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 *
 *	2022/11/21 Ryutaro Morita
 */

/*
 *		�V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iRTK5RLG140C00000BJ�p�j
 */

#include <kernel.h>
#include <t_syslog.h>
#include "rl78g14.h"
#include "target_syssvc.h"
#include "target_serial.h"

/*
 * ���W�X�^�ݒ�l
 */
#define INDEX_PORT(x)   ((x) - 1)
#define GET_SIOPCB(x)   (&siopcb_table[INDEX_PORT(x)])

/*
 *  �V���A���|�[�g�̊Ǘ��u���b�N
 */
struct sio_port_control_block {
    ID port;
    intptr_t exinf;
};

/*
 * �V���A��I/O�|�[�g�Ǘ��u���b�N�G���A
 */
SIOPCB siopcb_table[TNUM_PORT];

Inline bool_t
sio_putready(SIOPCB* siopcb)
{
    return (!(SSR02 & SSR02_BFF02));
}

Inline bool_t
sio_getready(SIOPCB* siopcb)
{
    return (SSR03 & SSR03_BFF03);
}

/*
 *  SIO�h���C�o�̏�����
 */
void
sio_initialize(intptr_t exinf)
{
    int i;

    for (i = 0; i < TNUM_PORT; i++) {
        siopcb_table[i].port = i;
        siopcb_table[i].exinf = 0;
    }
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB	*siopcb;

    if (siopid > TNUM_PORT) {
        return NULL;
    }

    siopcb = GET_SIOPCB(siopid);
    siopcb->exinf = exinf;

	/* UART1�ʐM�ҋ@��ԂɑJ�� */
	SO0 |= SO0_SO02;		// �V���A���E�f�[�^�o�͒l���g1�h
	SOE0L_bit.no2 = 1;		// �V���A���ʐM����ɂ��o�͋���
	SS0L_bit.no2 = 1;		// SE02�r�b�g��1���Z�b�g���C�ʐM�ҋ@��ԂɑJ�ڂ���
	SS0L_bit.no3 = 1;		// SE03�r�b�g��1���Z�b�g���C�ʐM�ҋ@��ԂɑJ�ڂ���

	/*
	 *  �V���A��I/O�����݂̃}�X�N����������D
	 */
    //ena_int(INTNO_SIO_TX);	// UART1���M�̓]�������C�o�b�t�@�󂫊��荞�݂̋���
    //ena_int(INTNO_SIO_RX);	// UART1��M�̓]���������荞�݂̋���

    return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
	ST0L_bit.no2 = 0;		// UART1(�`���l��2)�����~���
	ST0L_bit.no3 = 0;		// UART1(�`���l��3)�����~���

	/*
	 *  �V���A��I/O�����݂̃}�X�N�D
	 */
    dis_int(INTNO_SIO_TX);	// UART1���M�̓]�������C�o�b�t�@�󂫊��荞�݂̋֎~
	dis_int(INTNO_SIO_RX);	// UART1��M�̓]���������荞�݂̋֎~
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
sio_isr_rx(intptr_t exinf)
{
    SIOPCB* siopcb = GET_SIOPCB(exinf);
    sio_irdy_rcv(siopcb->exinf);
}

void
sio_isr_tx(intptr_t exinf)
{
    SIOPCB* siopcb = GET_SIOPCB(exinf);
    sio_irdy_snd(siopcb->exinf);
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
bool_t
sio_snd_chr(SIOPCB *siopcb, char c)
{
	if (sio_putready(siopcb)) {
		TXD1 = c;
		return true;
	}
	return false;
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
int_t
sio_rcv_chr(SIOPCB *siopcb)
{
	int_t c = -1;

	if (sio_getready(siopcb))
		c = RXD1;

	return c;
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
    switch (cbrtn) {
    case SIO_RDY_SND:
        ena_int(INTNO_SIO_TX);	// UART1���M�̓]�������C�o�b�t�@�󂫊��荞�݂̋���
        break;
    case SIO_RDY_RCV:
        ena_int(INTNO_SIO_RX);	// UART1��M�̓]���������荞�݂̋���
        break;
    default:
        break;
    }
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn)
{
    switch (cbrtn) {
    case SIO_RDY_SND:
        dis_int(INTNO_SIO_TX);	// UART1���M�̓]�������C�o�b�t�@�󂫊��荞�݂̋֎~
        break;
    case SIO_RDY_RCV:
    	dis_int(INTNO_SIO_RX);	// UART1��M�̓]���������荞�݂̋֎~
        break;
    default:
        break;
    }
}
