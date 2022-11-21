/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2010 by Embedded and Real-Time Systems Laboratory
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
 *		プロセッサ依存モジュール アセンブリ言語部（RL78G14用）
 */

#define	TOPPERS_MACRO_ONLY
#define UINT_C(val)			(val)		/* uint_t型の定数を作るマクロ */
#define ULONG_C(val)		(val)		/* ulong_t型の定数を作るマクロ */
#define CAST(type, val)		(val)		/* 型キャストを行うマクロ */
#include "kernel_impl.h"
#include "offset.h"

; real
; GAS defines r0..r7 as aliases for real registers; we want the saddr
; forms here.
r_0	=	0xffef8
r_1 =	0xffef9
r_2	=	0xffefa
r_3	=	0xffefb
r_4	=	0xffefc
r_5	=	0xffefd
r_6	=	0xffefe
r_7	=	0xffeff
#ifdef __RL78_G10__
; clobberable
r8	=	0xffec8
r9	=	0xffec9
r10	=	0xffeca
r11	=	0xffecb
r12	=	0xffecc
r13	=	0xffecd
r14	=	0xffece
r15	=	0xffecf
; preserved
r16	=	0xffed0
r17	=	0xffed1
r18	=	0xffed2
r19	=	0xffed3
r20	=	0xffed4
r21	=	0xffed5
r22	=	0xffed6
r23	=	0xffed7
#else
; clobberable
r8	=	0xffef0
r9 	=	0xffef1
r10	=	0xffef2
r11	=	0xffef3
r12	=	0xffef4
r13	=	0xffef5
r14	=	0xffef6
r15	=	0xffef7
; preserved
r16	=	0xffee8
r17	=	0xffee9
r18	=	0xffeea
r19	=	0xffeeb
r20	=	0xffeec
r21	=	0xffeed
r22	=	0xffeee
r23	=	0xffeef
#endif

/*
 *  タスクディスパッチャ
 */
	.text
	.globl __kernel_dispatch
__kernel_dispatch:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 */
	sel		rb2							/* レジスタを保存 */
	push	ax
	push	bc
	push	de
	push	hl
	sel		rb0
	movw	hl, !__kernel_p_runtsk		/* p_runtskをhlに */
	movw	ax, sp
	movw	[hl+TCB_msp], ax			/* タスクスタックを保存 */
	movw	ax, #dispatch_r
	movw	[hl+TCB_pc], ax				/* 実行再開番地を保存 */
	br		$dispatcher

dispatch_r:
	sel		rb2							/* レジスタを復帰 */
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	movw	ax, [hl+TCB_texptn]			/* texptnが0ならリターン */
	cmpw	ax, #0
	bz		$dispatch_r_1

	movw	ax,	hl
	addw	ax, #TCB_enatex				/* enatexがfalseならリターン */
	movw	hl,	ax
	bf		[hl].TCB_enatex_bit, $dispatch_r_1

	movw	ax, !__kernel_ipmflg
	cmpw	ax, #0						/* ipmflgがtrueであれば            */
	skz
	br		!!__kernel_call_texrtn		/*  タスク例外処理ルーチンの呼出し */

dispatch_r_1:
	ret

/*
 *  ディスパッチャの動作開始（prc_support.S）
 */
	.globl __kernel_start_dispatch
__kernel_start_dispatch:
	/*
	 *  このルーチンは，カーネル起動時に，すべての割込みを禁止した状態
	 * （割込みロック状態と同等）で呼び出される．また，割込みモード（非
	 *  タスクコンテキストと同等）で呼び出されることを想定している．
	 *
	 *  prc_initializeで，lock_flagをtrueに，saved_iipmをIIPM_ENAALLに
	 *  初期化しているため，カーネル管理外の割込みを許可することで，
	 *  CPUロック状態・（モデル上の）割込み優先度マスク全解除状態になる．
	 *  また，initialize_taskでdisdspをfalseに初期化しているため，ディ
	 *  スパッチ許可状態になっている．
	 */
;	movw	ax, #0
	clrw	ax
	movw	!__kernel_int_cnt, ax		/* マスタモードに */
	mov		a, psw						/*  カーネル管理外の割込みを許可 */
	and		a, #0F9h					/* 0x06の反転 */
	or		a, #IIPM_LOCK
	mov		psw, a
	br		$dispatcher_0

/*
 *  現在のコンテキストを捨ててディスパッチ
 */
	.globl __kernel_exit_and_dispatch
__kernel_exit_and_dispatch:
	/* ディスパッチャ本体（dispatcher）へ */

/*
 *  ディスパッチャ本体
 */
dispatcher:
	/*
	 *  このルーチンは，タスクコンテキスト・CPUロック状態・ディスパッチ
	 *  許可状態・（モデル上の）割込み優先度マスク全解除状態で呼び出さ
	 *  れる．
	 *
	 *  すなわち，マスタモード・lock_flagがtrue・disdspがfalse・dspflg
	 *  がtrue・saved_iipmがIIPM_ENAALLとなっている．実行再開番地へもこ
	 *  の状態のまま分岐する．
	 */
#ifdef LOG_DSP_ENTER
	movw	ax, #__kernel_p_runtsk
	movw	[sp], ax
	call	!!_log_dsp_enter

#endif /* LOG_DSP_ENTER */
dispatcher_0:
	movw	hl, !__kernel_p_schedtsk	/* p_schedtskをp_runtskに */
	movw	ax, hl
	movw	!__kernel_p_runtsk, ax		/* p_runtskがNULLならdispatcher_1へ */
	cmpw	ax, #0
	bz		$dispatcher_1

	movw	ax, [hl+TCB_msp]			/* タスクスタックを復帰 */
	movw	sp, ax
#ifdef LOG_DSP_LEAVE
	movw	ax, #__kernel_p_runtsk
	movw	[sp], ax
	call	!!_log_dsp_leave

#endif /* LOG_DSP_LEAVE */
	movw	ax, [hl+TCB_pc]				/* 実行再開番地へ分岐 */
	br		ax

dispatcher_1:
	/*
	 *  CPUロック状態を解除する準備をする．
	 */
	onew	ax							/* 割込みモードに */
	movw	!__kernel_int_cnt, ax
	movw	ax, !__kernel_istkpt		/* 割込み用のスタックへ切替え */
	movw	sp, ax
	mov		a, psw						/* pswをbに保存 */
	mov		b, a
	clrw	ax
	movw	!__kernel_lock_flag, ax		/* CPUロック解除状態に */
//#if 0
	mov		a, psw						/* 優先度0の割込み処理中を偽装 */
	and		a, #0F9h
	mov		x, a
	mov		a, #06h
	or		a, x
	mov		psw, a
//#endif

dispatcher_2:
	/*
	 *  割込みを許可し，割込みモードに切り換えて，割込みを待つ．
	 *
	 *  ここで割込みモードに切り換えるのは，ここで発生する割込み処理に
	 *  どのスタックを使うかという問題の解決と，割込みハンドラ内でのタ
	 *  スクディスパッチの防止という2つの意味がある．
	 *
	 *  プロセッサを割込み待ちに移行させる処理と，割込み許可とは，不可
	 *  分に行なう必要がある．これを不可分に行なわない場合，割込みを許
	 *  可した直後に割込みが入り，その中でタスクが実行可能状態になると
	 *  実行すべきタスクがあるにもかかわらずプロセッサが割込み待ちにな
	 *  ってしまう．
	 *
	 *  割込み待ちの間は，p_runtskをNULL（＝0）に設定しなければならな
	 *  い．このように設定しないと，割込みハンドラからiget_tidを呼び出
	 *  した際の動作が仕様に合致しなくなる．
	 */
	ei									/* 割込み待ち */
	nop
	di
	nop
	movw	ax, !__kernel_reqflg		/* reqflgがfalseならdispatcher_2へ */
	cmpw	ax, #0
	bz		$dispatcher_2

	mov		a, b						/* 元の状態に戻す */
	mov		psw, a
	clrw	ax
	movw	!__kernel_reqflg, ax		/* reqflgをfalseに */
	/*
	 *  CPUロック状態に戻す．割込み待ちの間に実行した割込みハンドラによ
	 *  り，saved_iipmが書き換えられる可能性があるため，元の値に戻す必
	 *  要がある．dispatcherが実行される時は，saved_iipmがIIPM_ENAALL
	 *  となっているため，ここではsaved_iipmをIIPM_ENAALL（＝0）に戻せ
	 *  ばよい．
	 */
;	movw	ax, #0						/* マスタモードに（スタック切換え） */
	clrw	ax							/* マスタモードに（スタック切換え） */
	movw	!__kernel_int_cnt, ax
	mov		a, #06h
	mov		!__kernel_saved_iipm, a		/* saved_iipmを06hにする */
	onew	ax							/* CPUロック状態に */
	movw	!__kernel_lock_flag, ax
	br		$dispatcher_0

/*
 *  カーネルの終了処理の呼出し
 */
	.globl __kernel_call_exit_kernel
__kernel_call_exit_kernel:
;	movw	ax, #1						/* 割込みモードに */
	onew	ax							/* 割込みモードに */
	movw	!__kernel_int_cnt, ax
	br		!!__kernel_exit_kernel		/* カーネルの終了処理を呼ぶ */

/*
 *  タスク開始時処理
 *
 *  dispatcherから呼び出されるため，TCBのアドレスはhlに入っている
 */
	.text
	.globl __kernel_start_r
__kernel_start_r:
;	movw	ax, #0						/* CPUロック解除状態に */
	clrw	ax							/* CPUロック解除状態に */
	movw	!__kernel_lock_flag, ax
	mov		a, psw
	or		a, #06h
	mov		psw, a
	ei
	movw	ax, [hl+TCB_p_tinib]		/* p_runtsk->p_tinibをhlに */
	movw	hl, ax
	movw	ax, [hl+TINIB_exinf]		/* exinfをスタックに積む */
	movw	[sp], ax
	mov		a, psw						/* ext_tskをスタックに積む */
;	mov		x, #0
	clrb	x
	push	ax
	movw	ax, #_ext_tsk
	push	ax
	movw	ax, [hl+TINIB_task]			/* タスクの起動番地をaxに */
	br		ax

/*
 *  割込みエントリ（rb0のbcにエントリ番号が入る）
 */
	.global inthdr_entry
inthdr_entry:
	sel		rb0							/* レジスタを退避 */
	push	ax
;	push	bc
	push	de
	push	hl
	sel		rb1
	push	ax
	push	bc
	push	de
	push	hl
;	sel		rb2
;	push	ax
;	push	bc
;	push	de
;	push	hl
	sel		rb0
	mov     a, es
	mov		x, a
	mov		a, cs
	push	ax

	movw	ax, !__kernel_int_cnt		/* 割込みモードに */
	incw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #1						/* 加算前が0でなければ多重割込み */
	bnz		$interrupt_from_int

	movw	ax, sp
	movw	!__kernel_int_sp, ax
	movw	ax, !__kernel_istkpt
	movw	sp, ax
	br		$inthdr_entry_0

interrupt_from_int:						/* 多重割込み */
	br		$inthdr_entry_0

inthdr_entry_0:
	ei									/* 割込み許可(CPUロック解除状態) */
	movw	ax, #__kernel_exc_tbl
	addw	ax, bc
	addw	ax, bc
	movw	de, ax
	movw	ax, [de]
#ifdef LOG_INH_ENTER
	push	ax
	subw	sp, #2						/* 引数の格納場所を確保 */
	movw	ax, bc
	movw	[sp], ax
	call	!!__kernel_log_inh_enter	/* log_inh_enterを呼び出す */

	addw	sp, #2						/* スタック上の引数を捨てる */
	pop		ax
#endif /* LOG_INH_ENTER */
#ifdef LOG_INH_LEAVE
	push	bc
#endif
;	mov		cs, #0
	call	ax

#ifdef LOG_INH_LEAVE
	pop		bc
	subw	sp, #2						/* 引数の格納場所を確保 */
	movw	ax, bc
	movw	[sp], ax
	call	!!_kernel_log_inh_leave		/* log_inh_leaveを呼び出す */

	addw	sp, #2						/* スタック上の引数を捨てる */
#endif /* LOG_INH_LEAVE */

/*
 *  割込みハンドラ出口処理
 *
 *  ret_intは，割込みハンドラから戻った直後に実行するルーチンで，
 *  INTHDR_ENTRYマクロで展開する割込みハンドラの入口処理で，割込みハン
 *  ドラからの戻り番地に設定される．
 */
	.text
	.globl ret_int
ret_int:
	di
	movw	ax, !__kernel_int_cnt		/* 戻り先が割込みモードなら */
	decw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #0
	skz
	br		$ret_int_1_d				/*           すぐにリターン */

	/*
	 *  カーネル管理の割込みを禁止する．この時点では，CPUロック状態に
	 *  はならない（lock_flagとsaved_iipmは更新しない）．
	 *
	 *  reqflgをチェックする前に割込みを禁止するのは，reqflgをチェック
	 *  した直後に割込みハンドラが起動され，その中でディスパッチが要求
	 *  された場合に，すぐにディスパッチされないという問題が生じるため
	 *  である．
	 */
	mov		a, psw						/* カーネル管理の割込みを禁止 */
	and		a, #0F9h					/* 0x06の反転 */
	or		a, #IIPM_LOCK
	mov		psw, a
	ei
	movw	ax, !__kernel_reqflg		/* reqflgがtrueであればret_int_2へ */
	cmpw	ax, #0
	skz
	br		$ret_int_2

	movw	ax, !__kernel_int_sp		/* マスタモードに（スタック切換え） */
	movw	sp, ax

ret_int_1:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよう
	 *  準備する．割込み優先度マスクは，RTE命令により元の値に戻るため，
	 *  lock_flagをfalseにしておけばよい（lock_flagをfalseにするのは，
	 *  CPUロック状態のまま割込みハンドラから戻った時の対策）．
	 */
;	movw	ax, #0						/* CPUロック解除の準備 */
	clrw	ax							/* CPUロック解除の準備 */
	movw	!__kernel_lock_flag, ax

	pop		ax							/* レジスタを復帰 */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	reti

ret_int_1_d:
	br		$ret_int_1

ret_int_2:
	movw	ax, !__kernel_int_sp		/* マスタモードに（スタック切換え） */
	movw	sp, ax

ret_int_3:
	/*
	 *  ここへは，CPU例外ハンドラの出口処理からも分岐してくる．
	 *
	 *  ここでは，戻り先がタスクであり，スタックは，例外スタックフレー
	 *  ムの上にスクラッチレジスタのみが保存された状態になっている．ま
	 *  た，プロセッサは，マスタモード・カーネル管理の割込みを禁止した
	 *  状態となっている．
	 */
//	movw	ax, #0
	clrw	ax
	movw	!__kernel_reqflg, ax
	/*
	 *  CPUロック状態に移行し，割込み優先度マスクを割込み処理前の値に設
	 *	定する．カーネル管理の割込みはすでに禁止しているので，lock_flag
	 *  とsaved_iipmを更新する．saved_iipmは，戻り先の割込み優先度マス
	 *  ク（の内部表現）に設定する．
	 *
	 *  この時点でCPUロック状態とするのは，dispatcherへ分岐する時と，
	 *  call_texrtnを呼び出す時に，CPUロック状態になっている必要がある
	 *  ためである．
	 */
	movw	ax, [sp+20]					/* 戻り先のpswをD0に */
	and		a, #06h						/* IPMを取り出してsaved_iipmに */
	mov		!__kernel_saved_iipm, a
;	movw	ax, #1						/* lock_flagをtrueに */
	onew	ax							/* lock_flagをtrueに */
	movw	!__kernel_lock_flag, ax
	/*
	 *  dspflgがfalseである場合と，p_runtskとp_schedtskが同じ場合には，
	 *  ディスパッチを行わない．このチェックが必要なのは，タスク例外処
	 *  理ルーチンの呼出しが必要な場合に，ディスパッチが必要なくても，
	 *  reqflgをtrueにするためである．
	 */
	movw	hl, !__kernel_p_runtsk		/* p_runtskをhlに */
	movw	ax, !__kernel_dspflg		/* dspflgがfalseならret_int_4へ */
	cmpw	ax, #0
	bz		$ret_int_4

	movw	ax, !__kernel_p_schedtsk	/* p_runtskとp_schedtskが同じなら */
	cmpw	ax, hl
	bz		$ret_int_4					/*                    ret_int_4へ */

	sel		rb2							/* 残りのレジスタを保存 */
	push	ax
	push	bc
	push	de
	push	hl
	sel		rb0

	movw	ax, sp						/* タスクスタックを保存 */
	movw	[hl+TCB_msp], ax
	movw	ax, #ret_int_r				/* 実行再開番地を保存 */
	movw	[hl+TCB_pc], ax
	br		!!dispatcher

ret_int_r:
	sel		rb2							/* レジスタを復帰 */
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0

ret_int_4:
	/*
	 *  enatexがtrueで，texptnが0でなく，ipmflgがtrueであれば，タスク
	 *  例外処理ルーチンを呼び出す．
	 */
	movw	ax, [hl+TCB_texptn]			/* texptnが0ならret_int_5へ */
	cmpw	ax, #0
	bz		$ret_int_5

;	movw	ax, [hl+TCB_enatex]			/* enatexがfalseならret_int_5へ */
	movw	ax, hl						/* enatexがfalseならret_int_5へ */
	addw	ax, #TCB_enatex
	movw	hl, ax
	bf		[hl].TCB_enatex_bit, $ret_int_5

	movw	ax, !__kernel_ipmflg		/* ipmflgがfalseならret_int_5へ */
	cmpw	ax, #0
	bz		$ret_int_5

	call	!!__kernel_call_texrtn		/* タスク例外処理ルーチンの呼出し */

ret_int_5:
	/*
	 *  割込み処理からのリターンにより，CPUロック解除状態に移行するよ
	 *  う準備する．割込み優先度マスクは，RTE命令により元の値に戻るた
	 *  め，lock_flagをfalseにしておけばよい．
	 */
;	movw	ax, #0						/* CPUロック解除の準備 */
	clrw	ax							/* CPUロック解除の準備 */
	movw	!__kernel_lock_flag, ax

	pop		ax							/* レジスタを復帰 */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	reti

/*
 *  CPU例外ハンドラ出入口処理
 *
 *  exchdr_entryは，CPU例外が発生した時に実行するルーチンで，EXCHDR_ENTRY
 *  マクロで展開するCPU例外ハンドラの入口処理から，CPU例外ハンドラの番地を
 *  A1に，CPU例外ハンドラ番号をbcに入れて分岐してくる．
 *
 *  CPU例外ハンドラは，非タスクコンテキストで実行する．そのため，CPU例
 *  外ハンドラを呼び出す前に割込みモードに移行し，リターンしてきた後に
 *  元のモードに戻す．元のモードに戻すために，割込みモードに移行する前
 *  のSRを割込みスタック上に保存する（リターン先のSRを参照する手もある
 *  が，タスクスタック上に保存される場合があり，参照するのが面倒）．
 */
	.text
	.globl exchdr_entry
exchdr_entry:
	sel		rb0							/* レジスタを退避 */
	push	ax
;	push	bc
	push	de
	push	hl
	sel		rb1
	push	ax
	push	bc
	push	de
	push	hl
;	sel		rb2
;	push	ax
;	push	bc
;	push	de
;	push	hl
	sel		rb0
	mov     a, es
	mov		x, a
	mov		a, cs
	push	ax

	movw	ax, [sp + 20]				/* 例外発生前のpswをlに */
	mov		l, a
	mov		h, #0

	movw	ax, !__kernel_int_cnt		/* 割込みモードに */
	incw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #1						/* 加算前が0でなければ多重割込み */
	bnz		$exception_from_int

	movw	ax, sp
	movw	!__kernel_int_sp, ax		/* スタック切換え */
	movw	ax, !__kernel_istkpt
	movw	sp, ax
	br		$exchdr_entry_0

exception_from_int:						/* 多重割込み */
	br		$exchdr_entry_0

exchdr_entry_0:
	ei									/* 割込み許可(CPUロック解除状態) */
	movw	ax, #__kernel_exc_tbl
	addw	ax, bc
	addw	ax, bc
	movw	de, ax
	movw	ax, [de]
	movw	de, ax
	mov		a, l
	and		a, #06h
	cmp		a, #INT_IPM(TMIN_INTPRI)	/* IPMがINT_IPM(TMIN_INTPRI) */
	skz									/*    より小さければ，カーネル */
	br		$exchdr_entry_1				/*    管理のCPU例外の処理へ */

	/*
	 *  カーネル管理外のCPU例外ハンドラの呼出し
	 */

	push	hl							/* 例外発生前のpswを退避 */
	movw	ax, !__kernel_lock_flag		/* 元のlock_flagをスタックに保存 */
	push	ax
	subw	sp, #2						/* 引数の格納場所を確保 */
	movw	ax, sp
	addw	ax, #4						/* 例外発生前のpswとコンテキストの参照先（事前にスタックに積まれた hl の値を指す） */
	movw	[sp], ax					/* 引数（p_excinf）を設定 */
	call	de							/* CPU例外ハンドラを呼び出す */

	addw	sp, #2						/* スタック上の引数を捨てる */
	pop		ax							/* lock_flagを元に戻す */
	movw	!__kernel_lock_flag, ax
	pop		hl							/* 例外発生前のpswを復帰 */
	mov		a, l
	mov		psw, a						/* pswを元に戻す */
	movw	ax, !__kernel_int_sp		/* マスタモードに（スタック切換え） */
	movw	sp, ax

	pop		ax							/* レジスタを復帰 */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	retb

	/*
	 *  カーネル管理のCPU例外ハンドラの呼出し
	 */
exchdr_entry_1:
#ifdef LOG_EXC_LEAVE
	push	bc							/* excno_numをパラメータに */
#endif
	push	hl							/* 例外発生前のpswを退避 */
	subw	sp, #2						/* 引数の格納場所を確保 */
	movw	ax, sp
	addw	ax, #2						/* 例外発生前のpswとコンテキストの参照先（事前にスタックに積まれた hl の値を指す） */
	movw	[sp], ax					/* 引数（p_excinf）を設定 */
#ifdef LOG_EXC_ENTER
	push	de							/* deを保存 */
	push	bc							/* excno_numをパラメータに */
	call	_kernel_log_exc_enter		/* log_exc_enterを呼び出す */

	addw	sp, #2						/* スタック上の引数を捨てる */
	pop		de							/* deを復帰 */
#endif /* LOG_EXC_ENTER */
	call	de							/* CPU例外ハンドラを呼び出す */

	addw	sp, #4						/* スタック上の引数を捨てる */
#ifdef LOG_EXC_LEAVE
	call	_kernel_log_exc_leave		/* log_exc_leaveを呼び出す */

	addw	sp, #2						/* スタック上の引数を捨てる */
#endif /* LOG_EXC_LEAVE */

ret_exc:
	di
	movw	ax, !__kernel_int_cnt		/* 戻り先が割込みモードなら */
	decw	ax
	movw	!__kernel_int_cnt, ax
	cmpw	ax, #0
	skz
	br		$ret_exc_1_d				/*           すぐにリターン */

	/*
	 *  カーネル管理の割込みを禁止し，マスタモードに戻す．この時点では，
	 *  CPUロック状態にはならない（lock_flagとsaved_iipmは更新しない）．
	 *
	 *  reqflgをチェックする前に割込みを禁止するのは，reqflgをチェック
	 *  した直後に割込みハンドラが起動され，その中でディスパッチが要求
	 *  された場合に，すぐにディスパッチされないという問題が生じるため
	 *  である．
	 */
	movw	ax, !__kernel_int_sp		/* マスタモードに（スタック切換え） */
	movw	sp, ax
	mov		a, psw						/* カーネル管理の割込みを禁止 */
	and		a, #0F9h					/* 0x06の反転 */
	or		a, #IIPM_LOCK
	mov		psw, a
	ei
	movw	ax, !__kernel_reqflg		/* reqflgがtrueであればret_int_3へ */
	cmpw	ax, #0
	skz
	br		!!ret_int_3

ret_exc_1:
	pop		ax							/* レジスタを復帰 */
	mov		cs, a
	mov		a, x
	mov		es, a
;	sel		rb2
;	pop		hl
;	pop		de
;	pop		bc
;	pop		ax
	sel		rb1
	pop		hl
	pop		de
	pop		bc
	pop		ax
	sel		rb0
	pop		hl
	pop		de
;	pop		bc
	pop		ax

	pop		bc

	retb

ret_exc_1_d:
	br		$ret_exc_1
