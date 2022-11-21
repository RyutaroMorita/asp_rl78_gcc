/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005,2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
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
 *		カーネル対応のスタートアップモジュール（RL78G14用）
 */

#define	TOPPERS_MACRO_ONLY
#include "kernel_impl.h"

    .list
	.globl _start
    .short _start

	.global __rl78_fini
__rl78_fini:
		br $__rl78_fini

	.text
_start:
	/*
	 *  プロセッサモードとスタックポインタの初期化
	 */
;	mov		es, #0
;	movw	de, #__kernel_istkpt
;	movw	ax, es:[de]
	movw	ax, #0FEDCh
	movw	sp, ax

	/*
	 *  hardware_init_hookの呼出し（0でない場合）
	 *
	 *  ターゲットハードウェアに依存して必要な初期化処理がある場合は，
	 *  hardware_init_hookという関数を用意する．
	 */
	movw	ax, #hardware_init_hook
	cmpw	ax, #0
	skz
	call	ax

	/*
	 *  dataセクションの初期化（ROM化対応）
	 */
	movw	de, #__idata_start
	movw	hl, #__data_start
0:
	movw	ax, #__idata_end
	cmpw	ax, de
	bz		$1f
	mov		es, #0
	movw	ax, es:[de]
	mov		es, #0Fh
	movw	es:[hl], ax
	movw	ax, de
	addw	ax, #2
	movw	de, ax
	movw	ax, hl
	addw	ax, #2
	movw	hl, ax
	br		$0b

1:

	/*
	 *  bssセクションのクリア
	 */
	movw	hl, #__bss_start
2:
	movw	ax, #__bss_end
	cmpw	ax, hl
	bz		$3f
;	movw	ax, #0
	clrw	ax
	mov		es, #0Fh
	movw	es:[hl], ax
	movw	ax, hl
	addw	ax, #2
	movw	hl, ax
	br		$2b

3:

	/*
	 *  software_init_hookの呼出し（0でない場合）
	 *
	 *  ソフトウェア環境（特にライブラリ）に依存して必要な初期化処理が
	 *  ある場合は，software_init_hookという関数を用意すればよい．
	 */
	movw	ax, #software_init_hook
	cmpw	ax, #0
	skz
	call	ax

	/*
	 *  カーネルを起動する．
	 */
	br		!!_sta_ker
