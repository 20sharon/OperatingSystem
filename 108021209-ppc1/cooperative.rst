                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.9.0 #11195 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module cooperative
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _Bootstrap
                                     12 	.globl _main
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _temp_for_SP
                                    110 	.globl _created_Thread_SP
                                    111 	.globl _created_ThreadID
                                    112 	.globl _CurrentThreadID
                                    113 	.globl _bitmap_for_Thread
                                    114 	.globl _saved_SP_Thread3
                                    115 	.globl _saved_SP_Thread2
                                    116 	.globl _saved_SP_Thread1
                                    117 	.globl _saved_SP_Thread0
                                    118 	.globl _ThreadCreate
                                    119 	.globl _ThreadYield
                                    120 	.globl _ThreadExit
                                    121 ;--------------------------------------------------------
                                    122 ; special function registers
                                    123 ;--------------------------------------------------------
                                    124 	.area RSEG    (ABS,DATA)
      000000                        125 	.org 0x0000
                           000080   126 _P0	=	0x0080
                           000081   127 _SP	=	0x0081
                           000082   128 _DPL	=	0x0082
                           000083   129 _DPH	=	0x0083
                           000087   130 _PCON	=	0x0087
                           000088   131 _TCON	=	0x0088
                           000089   132 _TMOD	=	0x0089
                           00008A   133 _TL0	=	0x008a
                           00008B   134 _TL1	=	0x008b
                           00008C   135 _TH0	=	0x008c
                           00008D   136 _TH1	=	0x008d
                           000090   137 _P1	=	0x0090
                           000098   138 _SCON	=	0x0098
                           000099   139 _SBUF	=	0x0099
                           0000A0   140 _P2	=	0x00a0
                           0000A8   141 _IE	=	0x00a8
                           0000B0   142 _P3	=	0x00b0
                           0000B8   143 _IP	=	0x00b8
                           0000D0   144 _PSW	=	0x00d0
                           0000E0   145 _ACC	=	0x00e0
                           0000F0   146 _B	=	0x00f0
                                    147 ;--------------------------------------------------------
                                    148 ; special function bits
                                    149 ;--------------------------------------------------------
                                    150 	.area RSEG    (ABS,DATA)
      000000                        151 	.org 0x0000
                           000080   152 _P0_0	=	0x0080
                           000081   153 _P0_1	=	0x0081
                           000082   154 _P0_2	=	0x0082
                           000083   155 _P0_3	=	0x0083
                           000084   156 _P0_4	=	0x0084
                           000085   157 _P0_5	=	0x0085
                           000086   158 _P0_6	=	0x0086
                           000087   159 _P0_7	=	0x0087
                           000088   160 _IT0	=	0x0088
                           000089   161 _IE0	=	0x0089
                           00008A   162 _IT1	=	0x008a
                           00008B   163 _IE1	=	0x008b
                           00008C   164 _TR0	=	0x008c
                           00008D   165 _TF0	=	0x008d
                           00008E   166 _TR1	=	0x008e
                           00008F   167 _TF1	=	0x008f
                           000090   168 _P1_0	=	0x0090
                           000091   169 _P1_1	=	0x0091
                           000092   170 _P1_2	=	0x0092
                           000093   171 _P1_3	=	0x0093
                           000094   172 _P1_4	=	0x0094
                           000095   173 _P1_5	=	0x0095
                           000096   174 _P1_6	=	0x0096
                           000097   175 _P1_7	=	0x0097
                           000098   176 _RI	=	0x0098
                           000099   177 _TI	=	0x0099
                           00009A   178 _RB8	=	0x009a
                           00009B   179 _TB8	=	0x009b
                           00009C   180 _REN	=	0x009c
                           00009D   181 _SM2	=	0x009d
                           00009E   182 _SM1	=	0x009e
                           00009F   183 _SM0	=	0x009f
                           0000A0   184 _P2_0	=	0x00a0
                           0000A1   185 _P2_1	=	0x00a1
                           0000A2   186 _P2_2	=	0x00a2
                           0000A3   187 _P2_3	=	0x00a3
                           0000A4   188 _P2_4	=	0x00a4
                           0000A5   189 _P2_5	=	0x00a5
                           0000A6   190 _P2_6	=	0x00a6
                           0000A7   191 _P2_7	=	0x00a7
                           0000A8   192 _EX0	=	0x00a8
                           0000A9   193 _ET0	=	0x00a9
                           0000AA   194 _EX1	=	0x00aa
                           0000AB   195 _ET1	=	0x00ab
                           0000AC   196 _ES	=	0x00ac
                           0000AF   197 _EA	=	0x00af
                           0000B0   198 _P3_0	=	0x00b0
                           0000B1   199 _P3_1	=	0x00b1
                           0000B2   200 _P3_2	=	0x00b2
                           0000B3   201 _P3_3	=	0x00b3
                           0000B4   202 _P3_4	=	0x00b4
                           0000B5   203 _P3_5	=	0x00b5
                           0000B6   204 _P3_6	=	0x00b6
                           0000B7   205 _P3_7	=	0x00b7
                           0000B0   206 _RXD	=	0x00b0
                           0000B1   207 _TXD	=	0x00b1
                           0000B2   208 _INT0	=	0x00b2
                           0000B3   209 _INT1	=	0x00b3
                           0000B4   210 _T0	=	0x00b4
                           0000B5   211 _T1	=	0x00b5
                           0000B6   212 _WR	=	0x00b6
                           0000B7   213 _RD	=	0x00b7
                           0000B8   214 _PX0	=	0x00b8
                           0000B9   215 _PT0	=	0x00b9
                           0000BA   216 _PX1	=	0x00ba
                           0000BB   217 _PT1	=	0x00bb
                           0000BC   218 _PS	=	0x00bc
                           0000D0   219 _P	=	0x00d0
                           0000D1   220 _F1	=	0x00d1
                           0000D2   221 _OV	=	0x00d2
                           0000D3   222 _RS0	=	0x00d3
                           0000D4   223 _RS1	=	0x00d4
                           0000D5   224 _F0	=	0x00d5
                           0000D6   225 _AC	=	0x00d6
                           0000D7   226 _CY	=	0x00d7
                                    227 ;--------------------------------------------------------
                                    228 ; overlayable register banks
                                    229 ;--------------------------------------------------------
                                    230 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        231 	.ds 8
                                    232 ;--------------------------------------------------------
                                    233 ; internal ram data
                                    234 ;--------------------------------------------------------
                                    235 	.area DSEG    (DATA)
                           000030   236 _saved_SP_Thread0	=	0x0030
                           000031   237 _saved_SP_Thread1	=	0x0031
                           000032   238 _saved_SP_Thread2	=	0x0032
                           000033   239 _saved_SP_Thread3	=	0x0033
                           000034   240 _bitmap_for_Thread	=	0x0034
                           000035   241 _CurrentThreadID	=	0x0035
                           000020   242 _created_ThreadID	=	0x0020
                           000021   243 _created_Thread_SP	=	0x0021
                           000022   244 _temp_for_SP	=	0x0022
                                    245 ;--------------------------------------------------------
                                    246 ; overlayable items in internal ram 
                                    247 ;--------------------------------------------------------
                                    248 	.area	OSEG    (OVR,DATA)
                                    249 ;--------------------------------------------------------
                                    250 ; indirectly addressable internal ram data
                                    251 ;--------------------------------------------------------
                                    252 	.area ISEG    (DATA)
                                    253 ;--------------------------------------------------------
                                    254 ; absolute internal ram data
                                    255 ;--------------------------------------------------------
                                    256 	.area IABS    (ABS,DATA)
                                    257 	.area IABS    (ABS,DATA)
                                    258 ;--------------------------------------------------------
                                    259 ; bit data
                                    260 ;--------------------------------------------------------
                                    261 	.area BSEG    (BIT)
                                    262 ;--------------------------------------------------------
                                    263 ; paged external ram data
                                    264 ;--------------------------------------------------------
                                    265 	.area PSEG    (PAG,XDATA)
                                    266 ;--------------------------------------------------------
                                    267 ; external ram data
                                    268 ;--------------------------------------------------------
                                    269 	.area XSEG    (XDATA)
                                    270 ;--------------------------------------------------------
                                    271 ; absolute external ram data
                                    272 ;--------------------------------------------------------
                                    273 	.area XABS    (ABS,XDATA)
                                    274 ;--------------------------------------------------------
                                    275 ; external initialized ram data
                                    276 ;--------------------------------------------------------
                                    277 	.area XISEG   (XDATA)
                                    278 	.area HOME    (CODE)
                                    279 	.area GSINIT0 (CODE)
                                    280 	.area GSINIT1 (CODE)
                                    281 	.area GSINIT2 (CODE)
                                    282 	.area GSINIT3 (CODE)
                                    283 	.area GSINIT4 (CODE)
                                    284 	.area GSINIT5 (CODE)
                                    285 	.area GSINIT  (CODE)
                                    286 	.area GSFINAL (CODE)
                                    287 	.area CSEG    (CODE)
                                    288 ;--------------------------------------------------------
                                    289 ; global & static initialisations
                                    290 ;--------------------------------------------------------
                                    291 	.area HOME    (CODE)
                                    292 	.area GSINIT  (CODE)
                                    293 	.area GSFINAL (CODE)
                                    294 	.area GSINIT  (CODE)
                                    295 ;--------------------------------------------------------
                                    296 ; Home
                                    297 ;--------------------------------------------------------
                                    298 	.area HOME    (CODE)
                                    299 	.area HOME    (CODE)
                                    300 ;--------------------------------------------------------
                                    301 ; code
                                    302 ;--------------------------------------------------------
                                    303 	.area CSEG    (CODE)
                                    304 ;------------------------------------------------------------
                                    305 ;Allocation info for local variables in function 'Bootstrap'
                                    306 ;------------------------------------------------------------
                                    307 ;	cooperative.c:87: void Bootstrap(void) {
                                    308 ;	-----------------------------------------
                                    309 ;	 function Bootstrap
                                    310 ;	-----------------------------------------
      000062                        311 _Bootstrap:
                           000007   312 	ar7 = 0x07
                           000006   313 	ar6 = 0x06
                           000005   314 	ar5 = 0x05
                           000004   315 	ar4 = 0x04
                           000003   316 	ar3 = 0x03
                           000002   317 	ar2 = 0x02
                           000001   318 	ar1 = 0x01
                           000000   319 	ar0 = 0x00
                                    320 ;	cooperative.c:100: bitmap_for_Thread = 0b00000000;
      000062 75 34 00         [24]  321 	mov	_bitmap_for_Thread,#0x00
                                    322 ;	cooperative.c:101: saved_SP_Thread0 = 0x3F;
      000065 75 30 3F         [24]  323 	mov	_saved_SP_Thread0,#0x3f
                                    324 ;	cooperative.c:102: saved_SP_Thread1 = 0x4F;
      000068 75 31 4F         [24]  325 	mov	_saved_SP_Thread1,#0x4f
                                    326 ;	cooperative.c:103: saved_SP_Thread2 = 0x5F;
      00006B 75 32 5F         [24]  327 	mov	_saved_SP_Thread2,#0x5f
                                    328 ;	cooperative.c:104: saved_SP_Thread3 = 0x6F;
      00006E 75 33 6F         [24]  329 	mov	_saved_SP_Thread3,#0x6f
                                    330 ;	cooperative.c:106: CurrentThreadID = ThreadCreate(main);
      000071 90 00 4C         [24]  331 	mov	dptr,#_main
      000074 12 00 A5         [24]  332 	lcall	_ThreadCreate
      000077 85 82 35         [24]  333 	mov	_CurrentThreadID,dpl
                                    334 ;	cooperative.c:107: RESTORESTATE;
      00007A E5 35            [12]  335 	mov	a,_CurrentThreadID
      00007C 70 05            [24]  336 	jnz	00108$
      00007E 85 30 81         [24]  337 	mov	_SP,_saved_SP_Thread0
      000081 80 17            [24]  338 	sjmp	00109$
      000083                        339 00108$:
      000083 74 01            [12]  340 	mov	a,#0x01
      000085 B5 35 05         [24]  341 	cjne	a,_CurrentThreadID,00105$
      000088 85 31 81         [24]  342 	mov	_SP,_saved_SP_Thread1
      00008B 80 0D            [24]  343 	sjmp	00109$
      00008D                        344 00105$:
      00008D 74 02            [12]  345 	mov	a,#0x02
      00008F B5 35 05         [24]  346 	cjne	a,_CurrentThreadID,00102$
      000092 85 32 81         [24]  347 	mov	_SP,_saved_SP_Thread2
      000095 80 03            [24]  348 	sjmp	00109$
      000097                        349 00102$:
      000097 85 33 81         [24]  350 	mov	_SP,_saved_SP_Thread3
      00009A                        351 00109$:
      00009A D0 D0            [24]  352 	POP PSW 
      00009C D0 83            [24]  353 	POP DPH 
      00009E D0 82            [24]  354 	POP DPL 
      0000A0 D0 F0            [24]  355 	POP B 
      0000A2 D0 E0            [24]  356 	POP ACC 
                                    357 ;	cooperative.c:108: }
      0000A4 22               [24]  358 	ret
                                    359 ;------------------------------------------------------------
                                    360 ;Allocation info for local variables in function 'ThreadCreate'
                                    361 ;------------------------------------------------------------
                                    362 ;fp                        Allocated to registers 
                                    363 ;------------------------------------------------------------
                                    364 ;	cooperative.c:116: ThreadID ThreadCreate(FunctionPtr fp) {
                                    365 ;	-----------------------------------------
                                    366 ;	 function ThreadCreate
                                    367 ;	-----------------------------------------
      0000A5                        368 _ThreadCreate:
                                    369 ;	cooperative.c:122: if(bitmap_for_Thread == 0b00001111){// 0x0F){
      0000A5 74 0F            [12]  370 	mov	a,#0x0f
      0000A7 B5 34 04         [24]  371 	cjne	a,_bitmap_for_Thread,00102$
                                    372 ;	cooperative.c:123: return -1;
      0000AA 75 82 FF         [24]  373 	mov	dpl,#0xff
      0000AD 22               [24]  374 	ret
      0000AE                        375 00102$:
                                    376 ;	cooperative.c:165: if((bitmap_for_Thread & 0b00000001) == 0b00000000){
      0000AE E5 34            [12]  377 	mov	a,_bitmap_for_Thread
      0000B0 20 E0 0B         [24]  378 	jb	acc.0,00112$
                                    379 ;	cooperative.c:167: bitmap_for_Thread = (bitmap_for_Thread | 0b00000001);
      0000B3 43 34 01         [24]  380 	orl	_bitmap_for_Thread,#0x01
                                    381 ;	cooperative.c:168: created_ThreadID = 0;
      0000B6 75 20 00         [24]  382 	mov	_created_ThreadID,#0x00
                                    383 ;	cooperative.c:169: created_Thread_SP = 0x3F;
      0000B9 75 21 3F         [24]  384 	mov	_created_Thread_SP,#0x3f
      0000BC 80 2E            [24]  385 	sjmp	00113$
      0000BE                        386 00112$:
                                    387 ;	cooperative.c:170: }else if((bitmap_for_Thread & 0x02) == 0x00){
      0000BE E5 34            [12]  388 	mov	a,_bitmap_for_Thread
      0000C0 20 E1 0B         [24]  389 	jb	acc.1,00109$
                                    390 ;	cooperative.c:172: bitmap_for_Thread = bitmap_for_Thread | 0x02;
      0000C3 43 34 02         [24]  391 	orl	_bitmap_for_Thread,#0x02
                                    392 ;	cooperative.c:173: created_ThreadID = 1;
      0000C6 75 20 01         [24]  393 	mov	_created_ThreadID,#0x01
                                    394 ;	cooperative.c:174: created_Thread_SP = 0x4F;
      0000C9 75 21 4F         [24]  395 	mov	_created_Thread_SP,#0x4f
      0000CC 80 1E            [24]  396 	sjmp	00113$
      0000CE                        397 00109$:
                                    398 ;	cooperative.c:175: }else if((bitmap_for_Thread & 0x04) == 0x00){
      0000CE E5 34            [12]  399 	mov	a,_bitmap_for_Thread
      0000D0 20 E2 0B         [24]  400 	jb	acc.2,00106$
                                    401 ;	cooperative.c:177: bitmap_for_Thread = bitmap_for_Thread | 0x04;
      0000D3 43 34 04         [24]  402 	orl	_bitmap_for_Thread,#0x04
                                    403 ;	cooperative.c:178: created_ThreadID = 2;
      0000D6 75 20 02         [24]  404 	mov	_created_ThreadID,#0x02
                                    405 ;	cooperative.c:179: created_Thread_SP = 0x5F;
      0000D9 75 21 5F         [24]  406 	mov	_created_Thread_SP,#0x5f
      0000DC 80 0E            [24]  407 	sjmp	00113$
      0000DE                        408 00106$:
                                    409 ;	cooperative.c:180: }else if((bitmap_for_Thread & 0x08) == 0x00){
      0000DE E5 34            [12]  410 	mov	a,_bitmap_for_Thread
      0000E0 20 E3 09         [24]  411 	jb	acc.3,00113$
                                    412 ;	cooperative.c:182: bitmap_for_Thread = bitmap_for_Thread | 0x08;
      0000E3 43 34 08         [24]  413 	orl	_bitmap_for_Thread,#0x08
                                    414 ;	cooperative.c:183: created_ThreadID = 3;
      0000E6 75 20 03         [24]  415 	mov	_created_ThreadID,#0x03
                                    416 ;	cooperative.c:184: created_Thread_SP = 0x6F;
      0000E9 75 21 6F         [24]  417 	mov	_created_Thread_SP,#0x6f
      0000EC                        418 00113$:
                                    419 ;	cooperative.c:187: temp_for_SP = SP;
      0000EC 85 81 22         [24]  420 	mov	_temp_for_SP,_SP
                                    421 ;	cooperative.c:188: SP = created_Thread_SP;
      0000EF 85 21 81         [24]  422 	mov	_SP,_created_Thread_SP
                                    423 ;	cooperative.c:199: __endasm;
      0000F2 C0 82            [24]  424 	PUSH	DPL
      0000F4 C0 83            [24]  425 	PUSH	DPH
                                    426 ;	cooperative.c:208: __endasm;
      0000F6 E4               [12]  427 	CLR	A
      0000F7 C0 E0            [24]  428 	PUSH	ACC
      0000F9 C0 E0            [24]  429 	PUSH	ACC
      0000FB C0 E0            [24]  430 	PUSH	ACC
      0000FD C0 E0            [24]  431 	PUSH	ACC
                                    432 ;	cooperative.c:210: if(created_ThreadID == 0){
      0000FF E5 20            [12]  433 	mov	a,_created_ThreadID
                                    434 ;	cooperative.c:211: PSW = 0b00000000;
      000101 70 09            [24]  435 	jnz	00121$
      000103 F5 D0            [12]  436 	mov	_PSW,a
                                    437 ;	cooperative.c:216: __endasm;
      000105 C0 D0            [24]  438 	PUSH	PSW
                                    439 ;	cooperative.c:218: saved_SP_Thread0 = SP;
      000107 85 81 30         [24]  440 	mov	_saved_SP_Thread0,_SP
      00010A 80 26            [24]  441 	sjmp	00122$
      00010C                        442 00121$:
                                    443 ;	cooperative.c:219: }else if(created_ThreadID == 1){
      00010C 74 01            [12]  444 	mov	a,#0x01
      00010E B5 20 0A         [24]  445 	cjne	a,_created_ThreadID,00118$
                                    446 ;	cooperative.c:220: PSW = 0b00001000;
      000111 75 D0 08         [24]  447 	mov	_PSW,#0x08
                                    448 ;	cooperative.c:225: __endasm;
      000114 C0 D0            [24]  449 	PUSH	PSW
                                    450 ;	cooperative.c:227: saved_SP_Thread1 = SP;
      000116 85 81 31         [24]  451 	mov	_saved_SP_Thread1,_SP
      000119 80 17            [24]  452 	sjmp	00122$
      00011B                        453 00118$:
                                    454 ;	cooperative.c:228: }else if(created_ThreadID == 2){
      00011B 74 02            [12]  455 	mov	a,#0x02
      00011D B5 20 0A         [24]  456 	cjne	a,_created_ThreadID,00115$
                                    457 ;	cooperative.c:229: PSW = 0b00010000;
      000120 75 D0 10         [24]  458 	mov	_PSW,#0x10
                                    459 ;	cooperative.c:234: __endasm;
      000123 C0 D0            [24]  460 	PUSH	PSW
                                    461 ;	cooperative.c:236: saved_SP_Thread2 = SP;
      000125 85 81 32         [24]  462 	mov	_saved_SP_Thread2,_SP
      000128 80 08            [24]  463 	sjmp	00122$
      00012A                        464 00115$:
                                    465 ;	cooperative.c:238: PSW = 0b00011000;
      00012A 75 D0 18         [24]  466 	mov	_PSW,#0x18
                                    467 ;	cooperative.c:243: __endasm;
      00012D C0 D0            [24]  468 	PUSH	PSW
                                    469 ;	cooperative.c:245: saved_SP_Thread3 = SP;
      00012F 85 81 33         [24]  470 	mov	_saved_SP_Thread3,_SP
      000132                        471 00122$:
                                    472 ;	cooperative.c:248: SP = temp_for_SP;
      000132 85 22 81         [24]  473 	mov	_SP,_temp_for_SP
                                    474 ;	cooperative.c:255: return created_ThreadID;
      000135 85 20 82         [24]  475 	mov	dpl,_created_ThreadID
                                    476 ;	cooperative.c:256: }
      000138 22               [24]  477 	ret
                                    478 ;------------------------------------------------------------
                                    479 ;Allocation info for local variables in function 'ThreadYield'
                                    480 ;------------------------------------------------------------
                                    481 ;	cooperative.c:266: void ThreadYield(void) {
                                    482 ;	-----------------------------------------
                                    483 ;	 function ThreadYield
                                    484 ;	-----------------------------------------
      000139                        485 _ThreadYield:
                                    486 ;	cooperative.c:267: SAVESTATE;
      000139 C0 E0            [24]  487 	PUSH ACC 
      00013B C0 F0            [24]  488 	PUSH B 
      00013D C0 82            [24]  489 	PUSH DPL 
      00013F C0 83            [24]  490 	PUSH DPH 
      000141 C0 D0            [24]  491 	PUSH PSW 
      000143 E5 35            [12]  492 	mov	a,_CurrentThreadID
      000145 70 05            [24]  493 	jnz	00108$
      000147 85 81 30         [24]  494 	mov	_saved_SP_Thread0,_SP
      00014A 80 17            [24]  495 	sjmp	00127$
      00014C                        496 00108$:
      00014C 74 01            [12]  497 	mov	a,#0x01
      00014E B5 35 05         [24]  498 	cjne	a,_CurrentThreadID,00105$
      000151 85 81 31         [24]  499 	mov	_saved_SP_Thread1,_SP
      000154 80 0D            [24]  500 	sjmp	00127$
      000156                        501 00105$:
      000156 74 02            [12]  502 	mov	a,#0x02
      000158 B5 35 05         [24]  503 	cjne	a,_CurrentThreadID,00102$
      00015B 85 81 32         [24]  504 	mov	_saved_SP_Thread2,_SP
      00015E 80 03            [24]  505 	sjmp	00127$
      000160                        506 00102$:
      000160 85 81 33         [24]  507 	mov	_saved_SP_Thread3,_SP
                                    508 ;	cooperative.c:268: do {
      000163                        509 00127$:
                                    510 ;	cooperative.c:279: if(CurrentThreadID == 0){
      000163 E5 35            [12]  511 	mov	a,_CurrentThreadID
      000165 70 0A            [24]  512 	jnz	00125$
                                    513 ;	cooperative.c:280: CurrentThreadID = 1;
      000167 75 35 01         [24]  514 	mov	_CurrentThreadID,#0x01
                                    515 ;	cooperative.c:281: if((bitmap_for_Thread & 0x02) != 0){ // test if free
      00016A E5 34            [12]  516 	mov	a,_bitmap_for_Thread
      00016C 30 E1 F4         [24]  517 	jnb	acc.1,00127$
                                    518 ;	cooperative.c:283: break;
      00016F 80 26            [24]  519 	sjmp	00129$
      000171                        520 00125$:
                                    521 ;	cooperative.c:285: }else if(CurrentThreadID == 1){
      000171 74 01            [12]  522 	mov	a,#0x01
      000173 B5 35 0A         [24]  523 	cjne	a,_CurrentThreadID,00122$
                                    524 ;	cooperative.c:286: CurrentThreadID = 2;
      000176 75 35 02         [24]  525 	mov	_CurrentThreadID,#0x02
                                    526 ;	cooperative.c:287: if((bitmap_for_Thread & 0x04) != 0){ // test if free
      000179 E5 34            [12]  527 	mov	a,_bitmap_for_Thread
      00017B 30 E2 E5         [24]  528 	jnb	acc.2,00127$
                                    529 ;	cooperative.c:289: break;
      00017E 80 17            [24]  530 	sjmp	00129$
      000180                        531 00122$:
                                    532 ;	cooperative.c:291: }else if(CurrentThreadID == 2){
      000180 74 02            [12]  533 	mov	a,#0x02
      000182 B5 35 0A         [24]  534 	cjne	a,_CurrentThreadID,00119$
                                    535 ;	cooperative.c:292: CurrentThreadID = 3;
      000185 75 35 03         [24]  536 	mov	_CurrentThreadID,#0x03
                                    537 ;	cooperative.c:293: if((bitmap_for_Thread & 0x08) != 0){ // test if free
      000188 E5 34            [12]  538 	mov	a,_bitmap_for_Thread
      00018A 30 E3 D6         [24]  539 	jnb	acc.3,00127$
                                    540 ;	cooperative.c:295: break;
      00018D 80 08            [24]  541 	sjmp	00129$
      00018F                        542 00119$:
                                    543 ;	cooperative.c:298: CurrentThreadID = 0;
      00018F 75 35 00         [24]  544 	mov	_CurrentThreadID,#0x00
                                    545 ;	cooperative.c:299: if((bitmap_for_Thread & 0x01) != 0){ // test if free
      000192 E5 34            [12]  546 	mov	a,_bitmap_for_Thread
      000194 30 E0 CC         [24]  547 	jnb	acc.0,00127$
                                    548 ;	cooperative.c:306: } while (1);
      000197                        549 00129$:
                                    550 ;	cooperative.c:307: RESTORESTATE;
      000197 E5 35            [12]  551 	mov	a,_CurrentThreadID
      000199 70 05            [24]  552 	jnz	00137$
      00019B 85 30 81         [24]  553 	mov	_SP,_saved_SP_Thread0
      00019E 80 17            [24]  554 	sjmp	00138$
      0001A0                        555 00137$:
      0001A0 74 01            [12]  556 	mov	a,#0x01
      0001A2 B5 35 05         [24]  557 	cjne	a,_CurrentThreadID,00134$
      0001A5 85 31 81         [24]  558 	mov	_SP,_saved_SP_Thread1
      0001A8 80 0D            [24]  559 	sjmp	00138$
      0001AA                        560 00134$:
      0001AA 74 02            [12]  561 	mov	a,#0x02
      0001AC B5 35 05         [24]  562 	cjne	a,_CurrentThreadID,00131$
      0001AF 85 32 81         [24]  563 	mov	_SP,_saved_SP_Thread2
      0001B2 80 03            [24]  564 	sjmp	00138$
      0001B4                        565 00131$:
      0001B4 85 33 81         [24]  566 	mov	_SP,_saved_SP_Thread3
      0001B7                        567 00138$:
      0001B7 D0 D0            [24]  568 	POP PSW 
      0001B9 D0 83            [24]  569 	POP DPH 
      0001BB D0 82            [24]  570 	POP DPL 
      0001BD D0 F0            [24]  571 	POP B 
      0001BF D0 E0            [24]  572 	POP ACC 
                                    573 ;	cooperative.c:308: }
      0001C1 22               [24]  574 	ret
                                    575 ;------------------------------------------------------------
                                    576 ;Allocation info for local variables in function 'ThreadExit'
                                    577 ;------------------------------------------------------------
                                    578 ;	cooperative.c:316: void ThreadExit(void) {
                                    579 ;	-----------------------------------------
                                    580 ;	 function ThreadExit
                                    581 ;	-----------------------------------------
      0001C2                        582 _ThreadExit:
                                    583 ;	cooperative.c:323: if(CurrentThreadID == 0){ // 1111 1110
      0001C2 E5 35            [12]  584 	mov	a,_CurrentThreadID
      0001C4 70 05            [24]  585 	jnz	00110$
                                    586 ;	cooperative.c:324: bitmap_for_Thread = bitmap_for_Thread & 0b11111110; // 0xFF;
      0001C6 53 34 FE         [24]  587 	anl	_bitmap_for_Thread,#0xfe
      0001C9 80 1C            [24]  588 	sjmp	00129$
      0001CB                        589 00110$:
                                    590 ;	cooperative.c:325: }else if(CurrentThreadID == 1){ // 1111 1101
      0001CB 74 01            [12]  591 	mov	a,#0x01
      0001CD B5 35 05         [24]  592 	cjne	a,_CurrentThreadID,00107$
                                    593 ;	cooperative.c:326: bitmap_for_Thread = bitmap_for_Thread & 0b11111101; // 0xFE;
      0001D0 53 34 FD         [24]  594 	anl	_bitmap_for_Thread,#0xfd
      0001D3 80 12            [24]  595 	sjmp	00129$
      0001D5                        596 00107$:
                                    597 ;	cooperative.c:327: }else if(CurrentThreadID == 2){ // 1111 1011
      0001D5 74 02            [12]  598 	mov	a,#0x02
      0001D7 B5 35 05         [24]  599 	cjne	a,_CurrentThreadID,00104$
                                    600 ;	cooperative.c:328: bitmap_for_Thread = bitmap_for_Thread & 0b11111011; // 0xFB;
      0001DA 53 34 FB         [24]  601 	anl	_bitmap_for_Thread,#0xfb
      0001DD 80 08            [24]  602 	sjmp	00129$
      0001DF                        603 00104$:
                                    604 ;	cooperative.c:329: }else if(CurrentThreadID == 3){ // 1111 0111
      0001DF 74 03            [12]  605 	mov	a,#0x03
      0001E1 B5 35 03         [24]  606 	cjne	a,_CurrentThreadID,00129$
                                    607 ;	cooperative.c:330: bitmap_for_Thread = bitmap_for_Thread & 0b11110111; // 0xF7;
      0001E4 53 34 F7         [24]  608 	anl	_bitmap_for_Thread,#0xf7
                                    609 ;	cooperative.c:332: do {
      0001E7                        610 00129$:
                                    611 ;	cooperative.c:333: if(CurrentThreadID == 0){
      0001E7 E5 35            [12]  612 	mov	a,_CurrentThreadID
                                    613 ;	cooperative.c:334: CurrentThreadID = 1;
                                    614 ;	cooperative.c:335: if((bitmap_for_Thread & 0x02) != 0x02){ // test if free
      0001E9 70 12            [24]  615 	jnz	00127$
      0001EB 75 35 01         [24]  616 	mov	_CurrentThreadID,#0x01
      0001EE AE 34            [24]  617 	mov	r6,_bitmap_for_Thread
      0001F0 53 06 02         [24]  618 	anl	ar6,#0x02
      0001F3 7F 00            [12]  619 	mov	r7,#0x00
                                    620 ;	cooperative.c:336: break;
      0001F5 BE 02 45         [24]  621 	cjne	r6,#0x02,00131$
      0001F8 BF 00 42         [24]  622 	cjne	r7,#0x00,00131$
      0001FB 80 EA            [24]  623 	sjmp	00129$
      0001FD                        624 00127$:
                                    625 ;	cooperative.c:338: }else if(CurrentThreadID == 1){
      0001FD 74 01            [12]  626 	mov	a,#0x01
      0001FF B5 35 12         [24]  627 	cjne	a,_CurrentThreadID,00124$
                                    628 ;	cooperative.c:339: CurrentThreadID = 2;
      000202 75 35 02         [24]  629 	mov	_CurrentThreadID,#0x02
                                    630 ;	cooperative.c:340: if((bitmap_for_Thread & 0x04) != 0x04){ // test if free
      000205 AE 34            [24]  631 	mov	r6,_bitmap_for_Thread
      000207 53 06 04         [24]  632 	anl	ar6,#0x04
      00020A 7F 00            [12]  633 	mov	r7,#0x00
                                    634 ;	cooperative.c:341: break;
      00020C BE 04 2E         [24]  635 	cjne	r6,#0x04,00131$
      00020F BF 00 2B         [24]  636 	cjne	r7,#0x00,00131$
      000212 80 D3            [24]  637 	sjmp	00129$
      000214                        638 00124$:
                                    639 ;	cooperative.c:343: }else if(CurrentThreadID == 2){
      000214 74 02            [12]  640 	mov	a,#0x02
      000216 B5 35 12         [24]  641 	cjne	a,_CurrentThreadID,00121$
                                    642 ;	cooperative.c:344: CurrentThreadID = 3;
      000219 75 35 03         [24]  643 	mov	_CurrentThreadID,#0x03
                                    644 ;	cooperative.c:345: if((bitmap_for_Thread & 0x08) != 0x08){ // test if free
      00021C AE 34            [24]  645 	mov	r6,_bitmap_for_Thread
      00021E 53 06 08         [24]  646 	anl	ar6,#0x08
      000221 7F 00            [12]  647 	mov	r7,#0x00
                                    648 ;	cooperative.c:346: break;
      000223 BE 08 17         [24]  649 	cjne	r6,#0x08,00131$
      000226 BF 00 14         [24]  650 	cjne	r7,#0x00,00131$
      000229 80 BC            [24]  651 	sjmp	00129$
      00022B                        652 00121$:
                                    653 ;	cooperative.c:349: CurrentThreadID = 0;
      00022B 75 35 00         [24]  654 	mov	_CurrentThreadID,#0x00
                                    655 ;	cooperative.c:350: if((bitmap_for_Thread & 0x01) != 0x01){ // test if free
      00022E AE 34            [24]  656 	mov	r6,_bitmap_for_Thread
      000230 53 06 01         [24]  657 	anl	ar6,#0x01
      000233 7F 00            [12]  658 	mov	r7,#0x00
      000235 BE 01 05         [24]  659 	cjne	r6,#0x01,00214$
      000238 BF 00 02         [24]  660 	cjne	r7,#0x00,00214$
      00023B 80 AA            [24]  661 	sjmp	00129$
      00023D                        662 00214$:
                                    663 ;	cooperative.c:355: } while (1);
      00023D                        664 00131$:
                                    665 ;	cooperative.c:356: RESTORESTATE;
      00023D E5 35            [12]  666 	mov	a,_CurrentThreadID
      00023F 70 05            [24]  667 	jnz	00139$
      000241 85 30 81         [24]  668 	mov	_SP,_saved_SP_Thread0
      000244 80 17            [24]  669 	sjmp	00140$
      000246                        670 00139$:
      000246 74 01            [12]  671 	mov	a,#0x01
      000248 B5 35 05         [24]  672 	cjne	a,_CurrentThreadID,00136$
      00024B 85 31 81         [24]  673 	mov	_SP,_saved_SP_Thread1
      00024E 80 0D            [24]  674 	sjmp	00140$
      000250                        675 00136$:
      000250 74 02            [12]  676 	mov	a,#0x02
      000252 B5 35 05         [24]  677 	cjne	a,_CurrentThreadID,00133$
      000255 85 32 81         [24]  678 	mov	_SP,_saved_SP_Thread2
      000258 80 03            [24]  679 	sjmp	00140$
      00025A                        680 00133$:
      00025A 85 33 81         [24]  681 	mov	_SP,_saved_SP_Thread3
      00025D                        682 00140$:
      00025D D0 D0            [24]  683 	POP PSW 
      00025F D0 83            [24]  684 	POP DPH 
      000261 D0 82            [24]  685 	POP DPL 
      000263 D0 F0            [24]  686 	POP B 
      000265 D0 E0            [24]  687 	POP ACC 
                                    688 ;	cooperative.c:357: }
      000267 22               [24]  689 	ret
                                    690 	.area CSEG    (CODE)
                                    691 	.area CONST   (CODE)
                                    692 	.area XINIT   (CODE)
                                    693 	.area CABS    (ABS,CODE)
