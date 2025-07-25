#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// COLOR                    1   xyzw        1     NONE   float   xyz 
// TEXCOORD                 0   xy          2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pin<0,1,2,3>
    dcl t1  // pin<4,5,6,7>
    dcl t2.xy  // pin<8,9>
    dcl_2d s0

#line 350 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\SkinnedEffect.fx"
    texld r0, t2, s0
    mul r0, r0, t0  // ::color<0,1,2,3>

#line 23 "C:\Users\LCI_Vancouver-DWaine\source\repos\SumEngine\External\DirectXTK\src\Shaders\Common.fxh"
    mad r0.xyz, t1, r0.w, r0  // AddSpecular::color<0,1,2>
    mov oC0, r0  // ::PSSkinnedVertexLightingNoFog<0,1,2,3>

// approximately 4 instruction slots used (1 texture, 3 arithmetic)
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v0.xyzw
dcl_input_ps linear v1.xyz
dcl_input_ps linear v2.xy
dcl_output o0.xyzw
dcl_temps 1
sample r0.xyzw, v2.xyxx, t0.xyzw, s0
mul r0.xyzw, r0.xyzw, v0.xyzw
mad o0.xyz, v1.xyzx, r0.wwww, r0.xyzx
mov o0.w, r0.w
ret 
// Approximately 0 instruction slots used
#endif

const BYTE SkinnedEffect_PSSkinnedVertexLightingNoFog[] =
{
     68,  88,  66,  67, 230, 170, 
    191, 120,  99,  12, 210, 228, 
    122, 195, 211,  19, 192,  19, 
    155, 171,   1,   0,   0,   0, 
    252,   4,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    128,   3,   0,   0,  96,   4, 
      0,   0, 200,   4,   0,   0, 
     65, 111, 110,  57,  72,   3, 
      0,   0,  72,   3,   0,   0, 
      0,   2, 255, 255,  32,   3, 
      0,   0,  40,   0,   0,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   0,   0,  40,   0, 
      1,   0,  36,   0,   0,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    169,   0,  68,  66,  85,  71, 
     40,   0,   0,   0, 120,   2, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 236,   0, 
      0,   0,   8,   0,   0,   0, 
    244,   0,   0,   0,   4,   0, 
      0,   0,  40,   2,   0,   0, 
     52,   1,   0,   0,  67,  58, 
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
    105, 110, 110, 101, 100,  69, 
    102, 102, 101,  99, 116,  46, 
    102, 120,   0,  67,  58,  92, 
     85, 115, 101, 114, 115,  92, 
     76,  67,  73,  95,  86,  97, 
    110,  99, 111, 117, 118, 101, 
    114,  45,  68,  87,  97, 105, 
    110, 101,  92, 115, 111, 117, 
    114,  99, 101,  92, 114, 101, 
    112, 111, 115,  92,  83, 117, 
    109,  69, 110, 103, 105, 110, 
    101,  92,  69, 120, 116, 101, 
    114, 110,  97, 108,  92,  68, 
    105, 114, 101,  99, 116,  88, 
     84,  75,  92, 115, 114,  99, 
     92,  83, 104,  97, 100, 101, 
    114, 115,  92,  67, 111, 109, 
    109, 111, 110,  46, 102, 120, 
    104,   0,  40,   0,   0,   0, 
    141,   0,   0,   0,   0,   0, 
    255, 255, 172,   2,   0,   0, 
      0,   0, 255, 255, 184,   2, 
      0,   0,   0,   0, 255, 255, 
    196,   2,   0,   0,   0,   0, 
    255, 255, 208,   2,   0,   0, 
     94,   1,   0,   0, 220,   2, 
      0,   0,  94,   1,   0,   0, 
    236,   2,   0,   0,  23,   0, 
      1,   0, 252,   2,   0,   0, 
     23,   0,   1,   0,  16,   3, 
      0,   0,  80,  83,  83, 107, 
    105, 110, 110, 101, 100,  86, 
    101, 114, 116, 101, 120,  76, 
    105, 103, 104, 116, 105, 110, 
    103,  78, 111,  70, 111, 103, 
      0, 171, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,  65, 100, 100,  83, 
    112, 101,  99, 117, 108,  97, 
    114,   0,  99, 111, 108, 111, 
    114,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,   5,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0, 112, 105, 110,   0, 
     68, 105, 102, 102, 117, 115, 
    101,   0,  83, 112, 101,  99, 
    117, 108,  97, 114,   0,  84, 
    101, 120,  67, 111, 111, 114, 
    100,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 176,   1,   0,   0, 
    132,   1,   0,   0, 184,   1, 
      0,   0, 132,   1,   0,   0, 
    193,   1,   0,   0, 204,   1, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  10,   0,   1,   0, 
      3,   0, 220,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      1,   0,   0,   0,   4,   0, 
      5,   0,   6,   0,   7,   0, 
      2,   0,   0,   0,   8,   0, 
      9,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  52,   1, 
      0,   0,  84,   1,   0,   0, 
      1,   0,   0,   0, 100,   1, 
      0,   0, 112,   1,   0,   0, 
    124,   1,   0,   0, 132,   1, 
      0,   0,   1,   0,   0,   0, 
    148,   1,   0,   0,   0,   0, 
      0,   0, 124,   1,   0,   0, 
    132,   1,   0,   0,   1,   0, 
      0,   0, 160,   1,   0,   0, 
     52,   1,   0,   0, 172,   1, 
      0,   0, 244,   1,   0,   0, 
      3,   0,   0,   0,   4,   2, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   1,   0,  15, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   2,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   2,   0, 228, 176, 
      0,   8, 228, 160,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   0,   0, 
    228, 176,   4,   0,   0,   4, 
      0,   0,   7, 128,   1,   0, 
    228, 176,   0,   0, 255, 128, 
      0,   0, 228, 128,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      0,   0, 228, 128, 255, 255, 
      0,   0,  83,  72,  68,  82, 
    216,   0,   0,   0,  64,   0, 
      0,   0,  54,   0,   0,   0, 
     90,   0,   0,   3,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   0,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3, 242,  16,  16,   0, 
      0,   0,   0,   0,  98,  16, 
      0,   3, 114,  16,  16,   0, 
      1,   0,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   1,   0,   0,   0, 
     69,   0,   0,   9, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  16,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,   9, 114,  32,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  73,  83, 
     71,  78,  96,   0,   0,   0, 
      3,   0,   0,   0,   8,   0, 
      0,   0,  80,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,  15, 
      0,   0,  80,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   7, 
      0,   0,  86,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};
