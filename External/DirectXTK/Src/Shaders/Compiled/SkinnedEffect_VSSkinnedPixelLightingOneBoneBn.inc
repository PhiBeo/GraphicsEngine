#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float   xyz 
// TEXCOORD                 0   xy          2     NONE   float   xy  
// BLENDINDICES             0   xyzw        3     NONE    uint   x   
// BLENDWEIGHT              0   xyzw        4     NONE   float   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
// TEXCOORD                 1   xyzw        1     NONE   float   xyzw
// TEXCOORD                 2   xyz         2     NONE   float   xyz 
// COLOR                    0   xyzw        3     NONE   float   xyzw
// SV_Position              0   xyzw        4      POS   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0       242  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c242                            Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
    def c243, 2, -1, 3, 0
    def c244, 0, 1, 0, 0
    dcl_texcoord v0  // vin<0,1,2,3>
    dcl_texcoord1 v1  // vin<4,5,6>
    dcl_texcoord2 v2  // vin<7,8>
    dcl_texcoord3 v3  // vin<9,10,11,12>
    dcl_texcoord4 v4  // vin<13,14,15,16>

#line 15 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Skinning.fxh"
    mul r0.x, v3.x, c243.z
    mova a0.x, r0.x
    mul r0, v4.x, c26[a0.x]  // ::skinning<0,3,6,9>

#line 18
    dp4 r1.x, v0, r0  // Skin::vin<0>

#line 15
    mul r2, v4.x, c27[a0.x]  // ::skinning<1,4,7,10>
    mul r3, v4.x, c28[a0.x]  // ::skinning<2,5,8,11>

#line 18
    dp4 r1.y, v0, r2  // Skin::vin<1>
    dp4 r1.z, v0, r3  // Skin::vin<2>

#line 82 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Lighting.fxh"
    mov r1.w, v0.w
    dp4 oPos.z, r1, c24  // ::VSSkinnedPixelLightingOneBoneBn<15>
    dp4 oT1.x, r1, c15  // ::VSSkinnedPixelLightingOneBoneBn<2>
    dp4 oT1.y, r1, c16  // ::VSSkinnedPixelLightingOneBoneBn<3>
    dp4 oT1.z, r1, c17  // ::VSSkinnedPixelLightingOneBoneBn<4>

#line 11 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Utilities.fxh"
    mad r4.xyz, v1, c243.x, c243.y  // ::BiasX2<0,1,2>

#line 19 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Skinning.fxh"
    dp3 r0.x, r4, r0  // ::Skin<0>
    dp3 r0.y, r4, r2  // ::Skin<1>
    dp3 r0.z, r4, r3  // ::Skin<2>

#line 84 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Lighting.fxh"
    dp3 r2.x, r0, c19
    dp3 r2.y, r0, c20
    dp3 r2.z, r0, c21
    dp3 r0.x, r2, r2
    rsq r0.x, r0.x
    mul oT2.xyz, r0.x, r2  // ::VSSkinnedPixelLightingOneBoneBn<6,7,8>

#line 11 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Common.fxh"
    dp4 r0.x, r1, c14
    max r0.x, r0.x, c243.w
    min oT1.w, r0.x, -c243.y  // ::VSSkinnedPixelLightingOneBoneBn<5>

#line 82 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Lighting.fxh"
    dp4 r0.x, r1, c22  // ::vout<0>
    dp4 r0.y, r1, c23  // ::vout<1>
    dp4 r0.z, r1, c25  // ::vout<3>

#line 249 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\SkinnedEffect.fx"
    mad oPos.xy, r0.z, c242, r0  // ::VSSkinnedPixelLightingOneBoneBn<13,14>
    mov oPos.w, r0.z  // ::VSSkinnedPixelLightingOneBoneBn<16>

#line 255
    mov oT0.xy, v2  // ::VSSkinnedPixelLightingOneBoneBn<0,1>

#line 260
    mov r0.xy, c244
    mad oT3, c0.w, r0.xxxy, r0.yyyx  // ::VSSkinnedPixelLightingOneBoneBn<9,10,11,12>

// approximately 34 instruction slots used
vs_4_0
dcl_constantbuffer CB0[242], dynamicIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xy
dcl_input v3.x
dcl_input v4.x
dcl_output o0.xy
dcl_output o1.xyzw
dcl_output o2.xyz
dcl_output o3.xyzw
dcl_output_siv o4.xyzw, position
dcl_temps 5
mov o0.xy, v2.xyxx
imul null, r0.x, v3.x, l(3)
mul r1.xyzw, v4.xxxx, cb0[r0.x + 26].xyzw
dp4 r2.x, v0.xyzw, r1.xyzw
mul r3.xyzw, v4.xxxx, cb0[r0.x + 27].xyzw
mul r0.xyzw, v4.xxxx, cb0[r0.x + 28].xyzw
dp4 r2.y, v0.xyzw, r3.xyzw
dp4 r2.z, v0.xyzw, r0.xyzw
mov r2.w, v0.w
dp4 o1.x, r2.xyzw, cb0[15].xyzw
dp4 o1.y, r2.xyzw, cb0[16].xyzw
dp4 o1.z, r2.xyzw, cb0[17].xyzw
dp4_sat o1.w, r2.xyzw, cb0[14].xyzw
mad r4.xyz, v1.xyzx, l(2.000000, 2.000000, 2.000000, 0.000000), l(-1.000000, -1.000000, -1.000000, 0.000000)
dp3 r1.x, r4.xyzx, r1.xyzx
dp3 r1.y, r4.xyzx, r3.xyzx
dp3 r1.z, r4.xyzx, r0.xyzx
dp3 r0.x, r1.xyzx, cb0[19].xyzx
dp3 r0.y, r1.xyzx, cb0[20].xyzx
dp3 r0.z, r1.xyzx, cb0[21].xyzx
dp3 r0.w, r0.xyzx, r0.xyzx
rsq r0.w, r0.w
mul o2.xyz, r0.wwww, r0.xyzx
mov o3.xyz, l(1.000000,1.000000,1.000000,0)
mov o3.w, cb0[0].w
dp4 o4.x, r2.xyzw, cb0[22].xyzw
dp4 o4.y, r2.xyzw, cb0[23].xyzw
dp4 o4.z, r2.xyzw, cb0[24].xyzw
dp4 o4.w, r2.xyzw, cb0[25].xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE SkinnedEffect_VSSkinnedPixelLightingOneBoneBn[] =
{
     68,  88,  66,  67, 226, 152, 
    160, 126, 218,  30, 127,  47, 
    101, 132,  83, 242, 227,  95, 
    161, 181,   1,   0,   0,   0, 
    220,  15,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
     72,  10,   0,   0, 120,  14, 
      0,   0,  56,  15,   0,   0, 
     65, 111, 110,  57,  16,  10, 
      0,   0,  16,  10,   0,   0, 
      0,   2, 254, 255, 220,   9, 
      0,   0,  52,   0,   0,   0, 
      1,   0,  36,   0,   0,   0, 
     48,   0,   0,   0,  48,   0, 
      0,   0,  36,   0,   1,   0, 
     48,   0,   0,   0,   0,   0, 
    242,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 242,   0, 
      0,   2, 254, 255, 254, 255, 
    209,   1,  68,  66,  85,  71, 
     40,   0,   0,   0,  24,   7, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  16,   2, 
      0,   0,  41,   0,   0,   0, 
     36,   2,   0,   0,   7,   0, 
      0,   0, 140,   6,   0,   0, 
    188,   3,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92,  76,  67,  73,  95,  86, 
     97, 110,  99, 111, 117, 118, 
    101, 114,  45,  68,  87,  97, 
    105, 110, 101,  92, 115, 111, 
    117, 114,  99, 101,  92, 114, 
    101, 112, 111, 115,  92,  83, 
    117, 109,  69, 110, 103, 105, 
    110, 101,  92,  69, 120, 116, 
    101, 114, 110,  97, 108,  92, 
     68, 105, 114, 101,  99, 116, 
     88,  84,  75,  92, 115, 114, 
     99,  92,  83, 104,  97, 100, 
    101, 114, 115,  92,  83, 107, 
    105, 110, 110, 105, 110, 103, 
     46, 102, 120, 104,   0,  67, 
     58,  92,  85, 115, 101, 114, 
    115,  92,  76,  67,  73,  95, 
     86,  97, 110,  99, 111, 117, 
    118, 101, 114,  45,  68,  87, 
     97, 105, 110, 101,  92, 115, 
    111, 117, 114,  99, 101,  92, 
    114, 101, 112, 111, 115,  92, 
     83, 117, 109,  69, 110, 103, 
    105, 110, 101,  92,  69, 120, 
    116, 101, 114, 110,  97, 108, 
     92,  68, 105, 114, 101,  99, 
    116,  88,  84,  75,  92, 115, 
    114,  99,  92,  83, 104,  97, 
    100, 101, 114, 115,  92,  76, 
    105, 103, 104, 116, 105, 110, 
    103,  46, 102, 120, 104,   0, 
     67,  58,  92,  85, 115, 101, 
    114, 115,  92,  76,  67,  73, 
     95,  86,  97, 110,  99, 111, 
    117, 118, 101, 114,  45,  68, 
     87,  97, 105, 110, 101,  92, 
    115, 111, 117, 114,  99, 101, 
     92, 114, 101, 112, 111, 115, 
     92,  83, 117, 109,  69, 110, 
    103, 105, 110, 101,  92,  69, 
    120, 116, 101, 114, 110,  97, 
    108,  92,  68, 105, 114, 101, 
     99, 116,  88,  84,  75,  92, 
    115, 114,  99,  92,  83, 104, 
     97, 100, 101, 114, 115,  92, 
     85, 116, 105, 108, 105, 116, 
    105, 101, 115,  46, 102, 120, 
    104,   0,  67,  58,  92,  85, 
    115, 101, 114, 115,  92,  76, 
     67,  73,  95,  86,  97, 110, 
     99, 111, 117, 118, 101, 114, 
     45,  68,  87,  97, 105, 110, 
    101,  92, 115, 111, 117, 114, 
     99, 101,  92, 114, 101, 112, 
    111, 115,  92,  83, 117, 109, 
     69, 110, 103, 105, 110, 101, 
     92,  69, 120, 116, 101, 114, 
    110,  97, 108,  92,  68, 105, 
    114, 101,  99, 116,  88,  84, 
     75,  92, 115, 114,  99,  92, 
     83, 104,  97, 100, 101, 114, 
    115,  92,  67, 111, 109, 109, 
    111, 110,  46, 102, 120, 104, 
      0,  67,  58,  92,  85, 115, 
    101, 114, 115,  92,  76,  67, 
     73,  95,  86,  97, 110,  99, 
    111, 117, 118, 101, 114,  45, 
     68,  87,  97, 105, 110, 101, 
     92, 115, 111, 117, 114,  99, 
    101,  92, 114, 101, 112, 111, 
    115,  92,  83, 117, 109,  69, 
    110, 103, 105, 110, 101,  92, 
     69, 120, 116, 101, 114, 110, 
     97, 108,  92,  68, 105, 114, 
    101,  99, 116,  88,  84,  75, 
     92, 115, 114,  99,  92,  83, 
    104,  97, 100, 101, 114, 115, 
     92,  83, 107, 105, 110, 110, 
    101, 100,  69, 102, 102, 101, 
     99, 116,  46, 102, 120,   0, 
     40,   0,   0,   0, 137,   0, 
      0,   0, 234,   0,   0,   0, 
     76,   1,   0,   0, 171,   1, 
      0,   0,   0,   0, 255, 255, 
     76,   7,   0,   0,   0,   0, 
    255, 255, 100,   7,   0,   0, 
      0,   0, 255, 255, 124,   7, 
      0,   0,   0,   0, 255, 255, 
    136,   7,   0,   0,   0,   0, 
    255, 255, 148,   7,   0,   0, 
      0,   0, 255, 255, 160,   7, 
      0,   0,   0,   0, 255, 255, 
    172,   7,   0,   0,  15,   0, 
      0,   0, 184,   7,   0,   0, 
     15,   0,   0,   0, 200,   7, 
      0,   0,  15,   0,   0,   0, 
    212,   7,   0,   0,  18,   0, 
      0,   0, 232,   7,   0,   0, 
     15,   0,   0,   0, 248,   7, 
      0,   0,  15,   0,   0,   0, 
     12,   8,   0,   0,  18,   0, 
      0,   0,  32,   8,   0,   0, 
     18,   0,   0,   0,  48,   8, 
      0,   0,  82,   0,   1,   0, 
     64,   8,   0,   0,  82,   0, 
      1,   0,  76,   8,   0,   0, 
     83,   0,   1,   0,  92,   8, 
      0,   0,  83,   0,   1,   0, 
    108,   8,   0,   0,  83,   0, 
      1,   0, 124,   8,   0,   0, 
     11,   0,   2,   0, 140,   8, 
      0,   0,  19,   0,   0,   0, 
    160,   8,   0,   0,  19,   0, 
      0,   0, 176,   8,   0,   0, 
     19,   0,   0,   0, 192,   8, 
      0,   0,  84,   0,   1,   0, 
    208,   8,   0,   0,  84,   0, 
      1,   0, 224,   8,   0,   0, 
     84,   0,   1,   0, 240,   8, 
      0,   0,  84,   0,   1,   0, 
      0,   9,   0,   0,  84,   0, 
      1,   0,  16,   9,   0,   0, 
     84,   0,   1,   0,  28,   9, 
      0,   0,  11,   0,   3,   0, 
     44,   9,   0,   0,  11,   0, 
      3,   0,  60,   9,   0,   0, 
     11,   0,   3,   0,  76,   9, 
      0,   0,  82,   0,   1,   0, 
     92,   9,   0,   0,  82,   0, 
      1,   0, 108,   9,   0,   0, 
     82,   0,   1,   0, 124,   9, 
      0,   0, 249,   0,   4,   0, 
    140,   9,   0,   0, 249,   0, 
      4,   0, 160,   9,   0,   0, 
    255,   0,   4,   0, 172,   9, 
      0,   0,   4,   1,   4,   0, 
    184,   9,   0,   0,   4,   1, 
      4,   0, 196,   9,   0,   0, 
     66, 105,  97, 115,  88,  50, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     20,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     83, 107, 105, 110,   0, 171, 
    171, 171,  21,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  22,   0,   0,   0, 
    255, 255,   1,   0, 255, 255, 
    255, 255,  23,   0,   0,   0, 
    255, 255, 255, 255,   2,   0, 
    255, 255,  86,  83,  83, 107, 
    105, 110, 110, 101, 100,  80, 
    105, 120, 101, 108,  76, 105, 
    103, 104, 116, 105, 110, 103, 
     79, 110, 101,  66, 111, 110, 
    101,  66, 110,   0,  84, 101, 
    120,  67, 111, 111, 114, 100, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  80, 111, 115, 105, 
    116, 105, 111, 110,  87,  83, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     78, 111, 114, 109,  97, 108, 
     87,  83,   0, 171, 171, 171, 
      1,   0,   3,   0,   1,   0, 
      3,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  68, 105, 
    102, 102, 117, 115, 101,   0, 
     80, 111, 115, 105, 116, 105, 
    111, 110,  80,  83,   0, 171, 
    220,   3,   0,   0, 232,   3, 
      0,   0, 248,   3,   0,   0, 
      4,   4,   0,   0,  20,   4, 
      0,   0,  32,   4,   0,   0, 
     48,   4,   0,   0,   4,   4, 
      0,   0,  56,   4,   0,   0, 
      4,   4,   0,   0,   5,   0, 
      0,   0,   1,   0,  17,   0, 
      1,   0,   5,   0,  68,   4, 
      0,   0,  16,   0,   0,   0, 
    255, 255, 255, 255,  15,   0, 
    255, 255,  17,   0,   0,   0, 
      2,   0, 255, 255, 255, 255, 
    255, 255,  18,   0,   0,   0, 
    255, 255,   3,   0, 255, 255, 
    255, 255,  19,   0,   0,   0, 
    255, 255, 255, 255,   4,   0, 
    255, 255,  29,   0,   0,   0, 
      6,   0,   7,   0,   8,   0, 
    255, 255,  32,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      5,   0,  36,   0,   0,   0, 
     13,   0,  14,   0, 255, 255, 
    255, 255,  37,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     16,   0,  38,   0,   0,   0, 
      0,   0,   1,   0, 255, 255, 
    255, 255,  40,   0,   0,   0, 
      9,   0,  10,   0,  11,   0, 
     12,   0, 115, 107, 105, 110, 
    110, 105, 110, 103,   0, 171, 
    171, 171,   3,   0,   3,   0, 
      4,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   0,   0, 
      3,   0,   6,   0,   9,   0, 
     11,   0,   0,   0,   1,   0, 
      4,   0,   7,   0,  10,   0, 
     12,   0,   0,   0,   2,   0, 
      5,   0,   8,   0,  11,   0, 
    118, 105, 110,   0,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0,  78, 111, 114, 109,  97, 
    108,   0,  73, 110, 100, 105, 
     99, 101, 115,   0,   1,   0, 
      2,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  87, 101, 105, 103, 
    104, 116, 115,   0,  56,   5, 
      0,   0,   4,   4,   0,   0, 
     65,   5,   0,   0,  32,   4, 
      0,   0, 220,   3,   0,   0, 
    232,   3,   0,   0,  72,   5, 
      0,   0,  80,   5,   0,   0, 
     96,   5,   0,   0,   4,   4, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  17,   0,   1,   0, 
      5,   0, 104,   5,   0,   0, 
     10,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     13,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     14,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
      2,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      3,   0,   0,   0,   4,   0, 
      5,   0,   6,   0, 255, 255, 
      4,   0,   0,   0,   7,   0, 
      8,   0, 255, 255, 255, 255, 
      5,   0,   0,   0,   9,   0, 
     10,   0,  11,   0,  12,   0, 
      6,   0,   0,   0,  13,   0, 
     14,   0,  15,   0,  16,   0, 
    118, 111, 117, 116,   0,  80, 
    111, 115,  95, 112, 115,   0, 
     80, 111, 115,  95, 119, 115, 
      0,  78, 111, 114, 109,  97, 
    108,  95, 119, 115,   0,  70, 
    111, 103,  70,  97,  99, 116, 
    111, 114,   0, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   5,   6,   0,   0, 
      4,   4,   0,   0,  12,   6, 
      0,   0,  32,   4,   0,   0, 
     19,   6,   0,   0,  32,   4, 
      0,   0,  29,   6,   0,   0, 
     40,   6,   0,   0,   5,   0, 
      0,   0,   1,   0,  11,   0, 
      1,   0,   4,   0,  56,   6, 
      0,   0,  33,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  34,   0,   0,   0, 
    255, 255,   1,   0, 255, 255, 
    255, 255,  35,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
    255, 255,   0,   0,   0,   0, 
    108,   3,   0,   0, 116,   3, 
      0,   0,   1,   0,   0,   0, 
    132,   3,   0,   0,   0,   0, 
      0,   0, 144,   3,   0,   0, 
    116,   3,   0,   0,   3,   0, 
      0,   0, 152,   3,   0,   0, 
      0,   0,   0,   0, 188,   3, 
      0,   0, 108,   4,   0,   0, 
     10,   0,   0,   0, 124,   4, 
      0,   0,   0,   0,   0,   0, 
    244,   4,   0,   0,   0,   5, 
      0,   0,   3,   0,   0,   0, 
     16,   5,   0,   0, 144,   3, 
      0,   0,  52,   5,   0,   0, 
    144,   5,   0,   0,   3,   0, 
      0,   0, 160,   5,   0,   0, 
    188,   3,   0,   0,  52,   5, 
      0,   0, 144,   5,   0,   0, 
      5,   0,   0,   0, 196,   5, 
      0,   0,   0,   0,   0,   0, 
      0,   6,   0,   0,  88,   6, 
      0,   0,   3,   0,   0,   0, 
    104,   6,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  81,   0,   0,   5, 
    243,   0,  15, 160,   0,   0, 
      0,  64,   0,   0, 128, 191, 
      0,   0,  64,  64,   0,   0, 
      0,   0,  81,   0,   0,   5, 
    244,   0,  15, 160,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      5,   0,   0, 128,   0,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   1, 128,   1,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   2, 128,   2,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   3, 128,   3,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   4, 128,   4,   0, 
     15, 144,   5,   0,   0,   3, 
      0,   0,   1, 128,   3,   0, 
      0, 144, 243,   0, 170, 160, 
     46,   0,   0,   2,   0,   0, 
      1, 176,   0,   0,   0, 128, 
      5,   0,   0,   4,   0,   0, 
     15, 128,   4,   0,   0, 144, 
     26,  32, 228, 160,   0,   0, 
      0, 176,   9,   0,   0,   3, 
      1,   0,   1, 128,   0,   0, 
    228, 144,   0,   0, 228, 128, 
      5,   0,   0,   4,   2,   0, 
     15, 128,   4,   0,   0, 144, 
     27,  32, 228, 160,   0,   0, 
      0, 176,   5,   0,   0,   4, 
      3,   0,  15, 128,   4,   0, 
      0, 144,  28,  32, 228, 160, 
      0,   0,   0, 176,   9,   0, 
      0,   3,   1,   0,   2, 128, 
      0,   0, 228, 144,   2,   0, 
    228, 128,   9,   0,   0,   3, 
      1,   0,   4, 128,   0,   0, 
    228, 144,   3,   0, 228, 128, 
      1,   0,   0,   2,   1,   0, 
      8, 128,   0,   0, 255, 144, 
      9,   0,   0,   3,   0,   0, 
      4, 192,   1,   0, 228, 128, 
     24,   0, 228, 160,   9,   0, 
      0,   3,   1,   0,   1, 224, 
      1,   0, 228, 128,  15,   0, 
    228, 160,   9,   0,   0,   3, 
      1,   0,   2, 224,   1,   0, 
    228, 128,  16,   0, 228, 160, 
      9,   0,   0,   3,   1,   0, 
      4, 224,   1,   0, 228, 128, 
     17,   0, 228, 160,   4,   0, 
      0,   4,   4,   0,   7, 128, 
      1,   0, 228, 144, 243,   0, 
      0, 160, 243,   0,  85, 160, 
      8,   0,   0,   3,   0,   0, 
      1, 128,   4,   0, 228, 128, 
      0,   0, 228, 128,   8,   0, 
      0,   3,   0,   0,   2, 128, 
      4,   0, 228, 128,   2,   0, 
    228, 128,   8,   0,   0,   3, 
      0,   0,   4, 128,   4,   0, 
    228, 128,   3,   0, 228, 128, 
      8,   0,   0,   3,   2,   0, 
      1, 128,   0,   0, 228, 128, 
     19,   0, 228, 160,   8,   0, 
      0,   3,   2,   0,   2, 128, 
      0,   0, 228, 128,  20,   0, 
    228, 160,   8,   0,   0,   3, 
      2,   0,   4, 128,   0,   0, 
    228, 128,  21,   0, 228, 160, 
      8,   0,   0,   3,   0,   0, 
      1, 128,   2,   0, 228, 128, 
      2,   0, 228, 128,   7,   0, 
      0,   2,   0,   0,   1, 128, 
      0,   0,   0, 128,   5,   0, 
      0,   3,   2,   0,   7, 224, 
      0,   0,   0, 128,   2,   0, 
    228, 128,   9,   0,   0,   3, 
      0,   0,   1, 128,   1,   0, 
    228, 128,  14,   0, 228, 160, 
     11,   0,   0,   3,   0,   0, 
      1, 128,   0,   0,   0, 128, 
    243,   0, 255, 160,  10,   0, 
      0,   3,   1,   0,   8, 224, 
      0,   0,   0, 128, 243,   0, 
     85, 161,   9,   0,   0,   3, 
      0,   0,   1, 128,   1,   0, 
    228, 128,  22,   0, 228, 160, 
      9,   0,   0,   3,   0,   0, 
      2, 128,   1,   0, 228, 128, 
     23,   0, 228, 160,   9,   0, 
      0,   3,   0,   0,   4, 128, 
      1,   0, 228, 128,  25,   0, 
    228, 160,   4,   0,   0,   4, 
      0,   0,   3, 192,   0,   0, 
    170, 128, 242,   0, 228, 160, 
      0,   0, 228, 128,   1,   0, 
      0,   2,   0,   0,   8, 192, 
      0,   0, 170, 128,   1,   0, 
      0,   2,   0,   0,   3, 224, 
      2,   0, 228, 144,   1,   0, 
      0,   2,   0,   0,   3, 128, 
    244,   0, 228, 160,   4,   0, 
      0,   4,   3,   0,  15, 224, 
      0,   0, 255, 160,   0,   0, 
     64, 128,   0,   0,  21, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82,  40,   4,   0,   0, 
     64,   0,   1,   0,  10,   1, 
      0,   0,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0, 242,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   1,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   2,   0,   0,   0, 
     95,   0,   0,   3,  18,  16, 
     16,   0,   3,   0,   0,   0, 
     95,   0,   0,   3,  18,  16, 
     16,   0,   4,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   0,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   3,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   4,   0,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   2,   5,   0,   0,   0, 
     54,   0,   0,   5,  50,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   2,   0, 
      0,   0,  38,   0,   0,   8, 
      0, 208,   0,   0,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      3,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      1,   0,   0,   0,   6,  16, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,  26,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   7, 
     18,   0,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     56,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
      6,  16,  16,   0,   4,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,  27,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,   6,  16, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,  28,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   7, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     17,   0,   0,   7,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,   0,  16,   0, 
      2,   0,   0,   0,  58,  16, 
     16,   0,   0,   0,   0,   0, 
     17,   0,   0,   8,  18,  32, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  17,   0,   0,   8, 
     34,  32,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,  17,   0, 
      0,   8,  66,  32,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  17,   0,   0,   0, 
     17,  32,   0,   8, 130,  32, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  50,   0,   0,  15, 
    114,   0,  16,   0,   4,   0, 
      0,   0,  70,  18,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128, 191,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
      0,   0,  16,   0,   0,   7, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     16,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  16,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  16,   0,   0,   8, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     19,   0,   0,   0,  16,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,  20,   0,   0,   0, 
     16,   0,   0,   8,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     68,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    114,  32,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   8, 114,  32, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,  54,   0,   0,   6, 
    130,  32,  16,   0,   3,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,   8, 
     18,  32,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     22,   0,   0,   0,  17,   0, 
      0,   8,  34,  32,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  23,   0,   0,   0, 
     17,   0,   0,   8,  66,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  24,   0, 
      0,   0,  17,   0,   0,   8, 
    130,  32,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     25,   0,   0,   0,  62,   0, 
      0,   1,  73,  83,  71,  78, 
    184,   0,   0,   0,   5,   0, 
      0,   0,   8,   0,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,  15,   0,   0, 
    140,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   7,   0,   0, 
    147,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
    156,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,  15,   1,   0,   0, 
    169,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,  15,   1,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     78,  79,  82,  77,  65,  76, 
      0,  84,  69,  88,  67,  79, 
     79,  82,  68,   0,  66,  76, 
     69,  78,  68,  73,  78,  68, 
     73,  67,  69,  83,   0,  66, 
     76,  69,  78,  68,  87,  69, 
     73,  71,  72,  84,   0, 171, 
    171, 171,  79,  83,  71,  78, 
    156,   0,   0,   0,   5,   0, 
      0,   0,   8,   0,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,  12,   0,   0, 
    128,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,   0,   0,   0, 
    128,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   8,   0,   0, 
    137,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,   0,   0,   0, 
    143,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   4,   0, 
      0,   0,  15,   0,   0,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  67,  79,  76, 
     79,  82,   0,  83,  86,  95, 
     80, 111, 115, 105, 116, 105, 
    111, 110,   0, 171
};
