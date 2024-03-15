;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.9.0 #11195 (MINGW64)
;--------------------------------------------------------
	.module cooperative
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _Bootstrap
	.globl _main
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _temp_for_SP
	.globl _created_Thread_SP
	.globl _created_ThreadID
	.globl _CurrentThreadID
	.globl _bitmap_for_Thread
	.globl _saved_SP_Thread3
	.globl _saved_SP_Thread2
	.globl _saved_SP_Thread1
	.globl _saved_SP_Thread0
	.globl _ThreadCreate
	.globl _ThreadYield
	.globl _ThreadExit
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_saved_SP_Thread0	=	0x0030
_saved_SP_Thread1	=	0x0031
_saved_SP_Thread2	=	0x0032
_saved_SP_Thread3	=	0x0033
_bitmap_for_Thread	=	0x0034
_CurrentThreadID	=	0x0035
_created_ThreadID	=	0x0020
_created_Thread_SP	=	0x0021
_temp_for_SP	=	0x0022
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Bootstrap'
;------------------------------------------------------------
;	cooperative.c:87: void Bootstrap(void) {
;	-----------------------------------------
;	 function Bootstrap
;	-----------------------------------------
_Bootstrap:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	cooperative.c:100: bitmap_for_Thread = 0b00000000;
	mov	_bitmap_for_Thread,#0x00
;	cooperative.c:101: saved_SP_Thread0 = 0x3F;
	mov	_saved_SP_Thread0,#0x3f
;	cooperative.c:102: saved_SP_Thread1 = 0x4F;
	mov	_saved_SP_Thread1,#0x4f
;	cooperative.c:103: saved_SP_Thread2 = 0x5F;
	mov	_saved_SP_Thread2,#0x5f
;	cooperative.c:104: saved_SP_Thread3 = 0x6F;
	mov	_saved_SP_Thread3,#0x6f
;	cooperative.c:106: CurrentThreadID = ThreadCreate(main);
	mov	dptr,#_main
	lcall	_ThreadCreate
	mov	_CurrentThreadID,dpl
;	cooperative.c:107: RESTORESTATE;
	mov	a,_CurrentThreadID
	jnz	00108$
	mov	_SP,_saved_SP_Thread0
	sjmp	00109$
00108$:
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00105$
	mov	_SP,_saved_SP_Thread1
	sjmp	00109$
00105$:
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00102$
	mov	_SP,_saved_SP_Thread2
	sjmp	00109$
00102$:
	mov	_SP,_saved_SP_Thread3
00109$:
	POP PSW 
	POP DPH 
	POP DPL 
	POP B 
	POP ACC 
;	cooperative.c:108: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ThreadCreate'
;------------------------------------------------------------
;fp                        Allocated to registers 
;------------------------------------------------------------
;	cooperative.c:116: ThreadID ThreadCreate(FunctionPtr fp) {
;	-----------------------------------------
;	 function ThreadCreate
;	-----------------------------------------
_ThreadCreate:
;	cooperative.c:122: if(bitmap_for_Thread == 0b00001111){// 0x0F){
	mov	a,#0x0f
	cjne	a,_bitmap_for_Thread,00102$
;	cooperative.c:123: return -1;
	mov	dpl,#0xff
	ret
00102$:
;	cooperative.c:165: if((bitmap_for_Thread & 0b00000001) == 0b00000000){
	mov	a,_bitmap_for_Thread
	jb	acc.0,00112$
;	cooperative.c:167: bitmap_for_Thread = (bitmap_for_Thread | 0b00000001);
	orl	_bitmap_for_Thread,#0x01
;	cooperative.c:168: created_ThreadID = 0;
	mov	_created_ThreadID,#0x00
;	cooperative.c:169: created_Thread_SP = 0x3F;
	mov	_created_Thread_SP,#0x3f
	sjmp	00113$
00112$:
;	cooperative.c:170: }else if((bitmap_for_Thread & 0x02) == 0x00){
	mov	a,_bitmap_for_Thread
	jb	acc.1,00109$
;	cooperative.c:172: bitmap_for_Thread = bitmap_for_Thread | 0x02;
	orl	_bitmap_for_Thread,#0x02
;	cooperative.c:173: created_ThreadID = 1;
	mov	_created_ThreadID,#0x01
;	cooperative.c:174: created_Thread_SP = 0x4F;
	mov	_created_Thread_SP,#0x4f
	sjmp	00113$
00109$:
;	cooperative.c:175: }else if((bitmap_for_Thread & 0x04) == 0x00){
	mov	a,_bitmap_for_Thread
	jb	acc.2,00106$
;	cooperative.c:177: bitmap_for_Thread = bitmap_for_Thread | 0x04;
	orl	_bitmap_for_Thread,#0x04
;	cooperative.c:178: created_ThreadID = 2;
	mov	_created_ThreadID,#0x02
;	cooperative.c:179: created_Thread_SP = 0x5F;
	mov	_created_Thread_SP,#0x5f
	sjmp	00113$
00106$:
;	cooperative.c:180: }else if((bitmap_for_Thread & 0x08) == 0x00){
	mov	a,_bitmap_for_Thread
	jb	acc.3,00113$
;	cooperative.c:182: bitmap_for_Thread = bitmap_for_Thread | 0x08;
	orl	_bitmap_for_Thread,#0x08
;	cooperative.c:183: created_ThreadID = 3;
	mov	_created_ThreadID,#0x03
;	cooperative.c:184: created_Thread_SP = 0x6F;
	mov	_created_Thread_SP,#0x6f
00113$:
;	cooperative.c:187: temp_for_SP = SP;
	mov	_temp_for_SP,_SP
;	cooperative.c:188: SP = created_Thread_SP;
	mov	_SP,_created_Thread_SP
;	cooperative.c:199: __endasm;
	PUSH	DPL
	PUSH	DPH
;	cooperative.c:208: __endasm;
	CLR	A
	PUSH	ACC
	PUSH	ACC
	PUSH	ACC
	PUSH	ACC
;	cooperative.c:210: if(created_ThreadID == 0){
	mov	a,_created_ThreadID
;	cooperative.c:211: PSW = 0b00000000;
	jnz	00121$
	mov	_PSW,a
;	cooperative.c:216: __endasm;
	PUSH	PSW
;	cooperative.c:218: saved_SP_Thread0 = SP;
	mov	_saved_SP_Thread0,_SP
	sjmp	00122$
00121$:
;	cooperative.c:219: }else if(created_ThreadID == 1){
	mov	a,#0x01
	cjne	a,_created_ThreadID,00118$
;	cooperative.c:220: PSW = 0b00001000;
	mov	_PSW,#0x08
;	cooperative.c:225: __endasm;
	PUSH	PSW
;	cooperative.c:227: saved_SP_Thread1 = SP;
	mov	_saved_SP_Thread1,_SP
	sjmp	00122$
00118$:
;	cooperative.c:228: }else if(created_ThreadID == 2){
	mov	a,#0x02
	cjne	a,_created_ThreadID,00115$
;	cooperative.c:229: PSW = 0b00010000;
	mov	_PSW,#0x10
;	cooperative.c:234: __endasm;
	PUSH	PSW
;	cooperative.c:236: saved_SP_Thread2 = SP;
	mov	_saved_SP_Thread2,_SP
	sjmp	00122$
00115$:
;	cooperative.c:238: PSW = 0b00011000;
	mov	_PSW,#0x18
;	cooperative.c:243: __endasm;
	PUSH	PSW
;	cooperative.c:245: saved_SP_Thread3 = SP;
	mov	_saved_SP_Thread3,_SP
00122$:
;	cooperative.c:248: SP = temp_for_SP;
	mov	_SP,_temp_for_SP
;	cooperative.c:255: return created_ThreadID;
	mov	dpl,_created_ThreadID
;	cooperative.c:256: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ThreadYield'
;------------------------------------------------------------
;	cooperative.c:266: void ThreadYield(void) {
;	-----------------------------------------
;	 function ThreadYield
;	-----------------------------------------
_ThreadYield:
;	cooperative.c:267: SAVESTATE;
	PUSH ACC 
	PUSH B 
	PUSH DPL 
	PUSH DPH 
	PUSH PSW 
	mov	a,_CurrentThreadID
	jnz	00108$
	mov	_saved_SP_Thread0,_SP
	sjmp	00127$
00108$:
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00105$
	mov	_saved_SP_Thread1,_SP
	sjmp	00127$
00105$:
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00102$
	mov	_saved_SP_Thread2,_SP
	sjmp	00127$
00102$:
	mov	_saved_SP_Thread3,_SP
;	cooperative.c:268: do {
00127$:
;	cooperative.c:279: if(CurrentThreadID == 0){
	mov	a,_CurrentThreadID
	jnz	00125$
;	cooperative.c:280: CurrentThreadID = 1;
	mov	_CurrentThreadID,#0x01
;	cooperative.c:281: if((bitmap_for_Thread & 0x02) != 0){ // test if free
	mov	a,_bitmap_for_Thread
	jnb	acc.1,00127$
;	cooperative.c:283: break;
	sjmp	00129$
00125$:
;	cooperative.c:285: }else if(CurrentThreadID == 1){
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00122$
;	cooperative.c:286: CurrentThreadID = 2;
	mov	_CurrentThreadID,#0x02
;	cooperative.c:287: if((bitmap_for_Thread & 0x04) != 0){ // test if free
	mov	a,_bitmap_for_Thread
	jnb	acc.2,00127$
;	cooperative.c:289: break;
	sjmp	00129$
00122$:
;	cooperative.c:291: }else if(CurrentThreadID == 2){
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00119$
;	cooperative.c:292: CurrentThreadID = 3;
	mov	_CurrentThreadID,#0x03
;	cooperative.c:293: if((bitmap_for_Thread & 0x08) != 0){ // test if free
	mov	a,_bitmap_for_Thread
	jnb	acc.3,00127$
;	cooperative.c:295: break;
	sjmp	00129$
00119$:
;	cooperative.c:298: CurrentThreadID = 0;
	mov	_CurrentThreadID,#0x00
;	cooperative.c:299: if((bitmap_for_Thread & 0x01) != 0){ // test if free
	mov	a,_bitmap_for_Thread
	jnb	acc.0,00127$
;	cooperative.c:306: } while (1);
00129$:
;	cooperative.c:307: RESTORESTATE;
	mov	a,_CurrentThreadID
	jnz	00137$
	mov	_SP,_saved_SP_Thread0
	sjmp	00138$
00137$:
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00134$
	mov	_SP,_saved_SP_Thread1
	sjmp	00138$
00134$:
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00131$
	mov	_SP,_saved_SP_Thread2
	sjmp	00138$
00131$:
	mov	_SP,_saved_SP_Thread3
00138$:
	POP PSW 
	POP DPH 
	POP DPL 
	POP B 
	POP ACC 
;	cooperative.c:308: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ThreadExit'
;------------------------------------------------------------
;	cooperative.c:316: void ThreadExit(void) {
;	-----------------------------------------
;	 function ThreadExit
;	-----------------------------------------
_ThreadExit:
;	cooperative.c:323: if(CurrentThreadID == 0){ // 1111 1110
	mov	a,_CurrentThreadID
	jnz	00110$
;	cooperative.c:324: bitmap_for_Thread = bitmap_for_Thread & 0b11111110; // 0xFF;
	anl	_bitmap_for_Thread,#0xfe
	sjmp	00129$
00110$:
;	cooperative.c:325: }else if(CurrentThreadID == 1){ // 1111 1101
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00107$
;	cooperative.c:326: bitmap_for_Thread = bitmap_for_Thread & 0b11111101; // 0xFE;
	anl	_bitmap_for_Thread,#0xfd
	sjmp	00129$
00107$:
;	cooperative.c:327: }else if(CurrentThreadID == 2){ // 1111 1011
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00104$
;	cooperative.c:328: bitmap_for_Thread = bitmap_for_Thread & 0b11111011; // 0xFB;
	anl	_bitmap_for_Thread,#0xfb
	sjmp	00129$
00104$:
;	cooperative.c:329: }else if(CurrentThreadID == 3){ // 1111 0111
	mov	a,#0x03
	cjne	a,_CurrentThreadID,00129$
;	cooperative.c:330: bitmap_for_Thread = bitmap_for_Thread & 0b11110111; // 0xF7;
	anl	_bitmap_for_Thread,#0xf7
;	cooperative.c:332: do {
00129$:
;	cooperative.c:333: if(CurrentThreadID == 0){
	mov	a,_CurrentThreadID
;	cooperative.c:334: CurrentThreadID = 1;
;	cooperative.c:335: if((bitmap_for_Thread & 0x02) != 0x02){ // test if free
	jnz	00127$
	mov	_CurrentThreadID,#0x01
	mov	r6,_bitmap_for_Thread
	anl	ar6,#0x02
	mov	r7,#0x00
;	cooperative.c:336: break;
	cjne	r6,#0x02,00131$
	cjne	r7,#0x00,00131$
	sjmp	00129$
00127$:
;	cooperative.c:338: }else if(CurrentThreadID == 1){
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00124$
;	cooperative.c:339: CurrentThreadID = 2;
	mov	_CurrentThreadID,#0x02
;	cooperative.c:340: if((bitmap_for_Thread & 0x04) != 0x04){ // test if free
	mov	r6,_bitmap_for_Thread
	anl	ar6,#0x04
	mov	r7,#0x00
;	cooperative.c:341: break;
	cjne	r6,#0x04,00131$
	cjne	r7,#0x00,00131$
	sjmp	00129$
00124$:
;	cooperative.c:343: }else if(CurrentThreadID == 2){
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00121$
;	cooperative.c:344: CurrentThreadID = 3;
	mov	_CurrentThreadID,#0x03
;	cooperative.c:345: if((bitmap_for_Thread & 0x08) != 0x08){ // test if free
	mov	r6,_bitmap_for_Thread
	anl	ar6,#0x08
	mov	r7,#0x00
;	cooperative.c:346: break;
	cjne	r6,#0x08,00131$
	cjne	r7,#0x00,00131$
	sjmp	00129$
00121$:
;	cooperative.c:349: CurrentThreadID = 0;
	mov	_CurrentThreadID,#0x00
;	cooperative.c:350: if((bitmap_for_Thread & 0x01) != 0x01){ // test if free
	mov	r6,_bitmap_for_Thread
	anl	ar6,#0x01
	mov	r7,#0x00
	cjne	r6,#0x01,00214$
	cjne	r7,#0x00,00214$
	sjmp	00129$
00214$:
;	cooperative.c:355: } while (1);
00131$:
;	cooperative.c:356: RESTORESTATE;
	mov	a,_CurrentThreadID
	jnz	00139$
	mov	_SP,_saved_SP_Thread0
	sjmp	00140$
00139$:
	mov	a,#0x01
	cjne	a,_CurrentThreadID,00136$
	mov	_SP,_saved_SP_Thread1
	sjmp	00140$
00136$:
	mov	a,#0x02
	cjne	a,_CurrentThreadID,00133$
	mov	_SP,_saved_SP_Thread2
	sjmp	00140$
00133$:
	mov	_SP,_saved_SP_Thread3
00140$:
	POP PSW 
	POP DPH 
	POP DPL 
	POP B 
	POP ACC 
;	cooperative.c:357: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
