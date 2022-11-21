/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2008 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 *
 *	2022/11/21 Ryutaro Morita
 */

/*
 *		sil.hのプロセッサ依存部（RL78G14用）
 */

#ifndef TOPPERS_PRC_SIL_H
#define TOPPERS_PRC_SIL_H

#ifndef TOPPERS_MACRO_ONLY

/*
 *  NMIを除くすべての割込みの禁止
 */
extern uint16_t TOPPERS_disint(void);
asm(".text \n\t"
"_TOPPERS_disint: \n\t"
"	subw sp,#2 \n\t"
"	bf psw.7,$0f \n\t"
"	di \n\t"
"	onew ax \n\t"
"	br $1f \n\t"
"0:	\n\t"
"	clrw ax \n\t"
"1:	\n\t"
"	movw [sp],ax \n\t"
"	movw 0xffef0,ax \n\t"
"	addw sp,#2 \n\t"
"	ret \n\t"
);

extern void TOPPERS_enaint(bool_t locked);
asm(".text \n\t"
"_TOPPERS_enaint: \n\t"
"	movw ax,[sp+4] \n\t"
"	movw 0xffef0,ax \n\t"
"	cmpw ax,#0 \n\t"
"	bz $0f \n\t"
"	ei \n\t"
"0:	\n\t"
"	ret \n\t"
);

/*
 *  割込み優先度マスク（内部表現）の現在値の設定
 */
Inline void
TOPPERS_set_iipm(uint16_t TOPPERS_iipm)
{
	uint16_t	TOPPERS_sr;

	Asm("move.w %%sr, %0" : "=g"(TOPPERS_sr));
	Asm("move.w %0, %%sr" : : "g"((TOPPERS_sr & ~0x0700U) | TOPPERS_iipm)
							: "memory");
}

/*
 *  全割込みロック状態の制御
 */
#define SIL_PRE_LOC      bool_t  TOPPERS_locked
#define SIL_LOC_INT()    ((void)(TOPPERS_locked = TOPPERS_disint()))
#define SIL_UNL_INT()    (TOPPERS_enaint(TOPPERS_locked))

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  プロセッサのエンディアン
 */
#define SIL_ENDIAN_LITTLE				/* リトルエンディアン */

/*
 *  割込み優先度のビット幅
 */
#define TBITW_IPRI     2

#endif /* TOPPERS_PRC_SIL_H */
