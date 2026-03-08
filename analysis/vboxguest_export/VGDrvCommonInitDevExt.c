__int64 __fastcall VGDrvCommonInitDevExt(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6)
{
  __int64 result; // rax
  unsigned int v11; // [rsp+4h] [rbp-34h]

  result = VGDrvCommonInitDevExtFundament(a1);
  if ( (int)result >= 0 )
  {
    result = VGDrvCommonInitDevExtResources(a1, a2, a3, a4, a5, a6);
    if ( (int)result < 0 )
    {
      v11 = result;
      VGDrvCommonDeleteDevExtFundament(a1);
      return v11;
    }
  }
  return result;
}
