/*
 * types.h - Definició de tipus i estructures de dades
 */

#ifndef __TYPES_H__
#define __TYPES_H__

/** System types definition **/
/*****************************/

typedef unsigned char       Byte;
typedef unsigned short int  Word;
typedef unsigned long       DWord;

#define highWord(address) (Word)(((address) >> 16) & 0xFFFF)
#define lowWord(address) (Word)((address) & 0xFFFF)
#define midByte(address) (Byte)(((address) >> 16) & 0xFF)
#define highByte(address) (Byte)(((address) >> (16 + 8)) & 0xFF)
#define high4Bits(limit) (Byte)(((limit) >> 16) & 0x0F)

typedef struct  /* Segment Descriptor */
{
  Word  limit;
  Word  lowBase;
  Byte  midBase;
  Byte  flags1;
  Byte  flags2;
  Byte  highBase;
} Descriptor;     /* R1: pg. 3-11, 4-3 */

typedef struct /* Gate */
{
  Word  lowOffset;
  Word  segmentSelector;
  Word  flags;
  Word  highOffset;
} Gate;     /* R1: pg. 5-11 */

typedef struct              /* TASK STATE SEGMENT      */
{                           /*                         */
  Word  PreviousTaskLink;   /* 0          R1: pg. 6-5  */
  Word  none1;              /*                         */
  DWord esp0;               /* 4  \                    */
  Word  ss0;                /* 8  |                    */
  Word  none2;              /*    |                    */
  DWord esp1;               /* 12 |  Stack pointers    */
  Word  ss1;                /* 16 |-    for each       */
  Word  none3;              /*    |  privilege level   */
  DWord esp2;               /* 20 |                    */
  Word  ss2;                /*    |                    */
  Word  none4;              /* 24/                     */
  DWord cr3;                /* 28\                     */
  DWord eip;                /* 32 |                    */
  DWord eFlags;             /* 36 |                    */
  DWord eax;                /* 40 |                    */
  DWord ecx;                /* 44 |                    */
  DWord edx;                /* 48 |                    */
  DWord ebx;                /* 52 |                    */
  DWord esp;                /* 56 |                    */
  DWord ebp;                /* 60 |                    */
  DWord esi;                /* 64 |                    */
  DWord edi;                /* 68 |- Saved registers   */
  Word  es;                 /* 72 |                    */
  Word  none5;              /*    |                    */
  Word  cs;                 /* 76 |                    */
  Word  none6;              /*    |                    */
  Word  ss;                 /* 80 |                    */
  Word  none7;              /*    |                    */
  Word  ds;                 /* 84 |                    */
  Word  none8;              /*    |                    */
  Word  fs;                 /* 88 |                    */
  Word  none9;              /*    |                    */
  Word  gs;                 /* 92 |                    */
  Word  none10;             /*   /                     */
  Word  LDTSegmentSelector; /* 96                      */
  Word  none11;             /*     The offset in the   */
  Word  debugTrap;          /* 100 TSS Segment to the  */
  Word  IOMapBaseAddress;   /* 102 io permision bitmap */
} TSS; /* size = 104 B + i/o permission bitmap and     */
       /* interrupt redirection bitmap (R1 pg 6.6)     */

/** Registers: **/
/****************/
typedef struct
{
  Word  limit __attribute__ ((packed));
  DWord base  __attribute__ ((packed));
} Register; /* GDTR, IDTR */
/*                                            */
/*  /--------------------------------------\  */
/* |      Base Address       |     Limit    | */
/*  \--------------------------------------/  */
/* 47                       16            0   */
/*    */
  ----------I\EUS: 2       */
  Word  none8;              /*    |                    */
  Word  fs;                 /* 88 |                  | A nonA#def=$BXSHARE/BIOS-bochs-latest
megsssssssssssssssssssiI _emegsssss    /*      | A nonA#def=$BXSHARE/BIOS-b}    g=$Bac3I y.S - Entry point to system mode from user mode
 */

#include  /* 16 |-    for each       */
  Word  none3;              /*    |  privilege level   */
  DWord esp2;               /* 20 |                    */
  Word  ss2;  d  ss2;  d Pm>1e level   */� /* 6    e, nIordIOS-/
  W) ;

#endif /*zeo**                     /rdIOS /*/    ) < 0)    0d */
 ?S3    */
  Word  gs;          |uupts, at
! int 0xS   *  Word  debugTrap;    
  Word  LDTSegment /
  DWn0 s  0   */
/*  b-                                                                   ustar   alumne                          alumne(ap: en   /*    |  privilege level   */
  DWord esp2;               /* 20 |                    */
  Word  ss2;rd  g R@}}9        rd  ss2;rd  g gnterrupti ss2;rd  g gnterrupti ss2;rd  g gnterrupti ss2;rd  g gnterrupti ss2;+   ;+   ;+   ;+     >i__KERNEL                | A nonA#def=$BXSHARE/BIOS-bochs-latest
megsssssssssssssssssssiI _emegsssss    /*      | A nonA#drrupti ss2;rd  g gnterrupti ss2;+   ;+   ;+   ;+     >i__KERNEL                | A nonA#def=$BXSHARE/BIOS-bochs-latest
megsssssssssssssssssssiI _emegsssss    /*      | A nonA#drrupti ss2;rd  g gnterrupti ss2;+     >i__KERNEL     |    /v+1111111rd  g gnCgp
no_Aded big kernpt.h     Ii ss2;+     srnpt.h     Ii ss2;+     srnpt.h     Ii ss2;+     s
typ    ni ss2;+     srnpt.h    word  h     Ii ss2;+     s
typ    n9.h            _,13e lo     Wor    r,   s
typ    nI   ns   *///////NITSEG

! ZEUS: Ejecutamos estn             nI   3s gs;A(U-2.4P*:3        v /*    |  privilege level   */
  DWord esp2;               /* 20 |                    */
  Word  ss2;  d  ss2;  d Pm>1e level   */� /* 6    e, nIordIOS-/
  W) ;

#endif /*zeo**                     /rdIOS /*/    ) < 0)    0d */
 ?S3    */
  Word  gs;         |*                     /rdIOS /*/    ) < 0)    0d */
 ?S3    *
 0d */
 ?S3 .,0x9	! g /rdIOS /*/    E////////////////////   */
  Word  gh    word  h     Ii ss2;+     s
typ    n9.h 1�_7+2;+eTthe lo  >i__KERNEL      s
typ    n9.h   ap;      terrupt redirection bitmap (R1 pg 6L -|n bitmap (R1 pu    d/    E///       n9.h    a//////////itmap (R1 pu    d/    E///       n9.h    a//////////itmap (R1 pu    d/    E///itd  non             r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\rd         r4\re is %d kB0T38s4a4\rd////l4\rd r4\rd         r4\re is %d kB0T38s4a4\rd////l4\rd r4\rd         r4Sding4d        //   tput: a /* e   \rd r4\rigsssssss (normal