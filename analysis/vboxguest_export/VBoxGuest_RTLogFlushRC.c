__int64 __fastcall VBoxGuest_RTLogFlushRC(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // rbx
  __int64 result; // rax
  __int64 v12; // rdi
  unsigned __int64 v13; // rdx
  __int64 v14; // rdi

  v10 = a1;
  if ( !a1 )
  {
    result = VBoxGuest_RTLogDefaultInstance();
    v10 = result;
    if ( !result )
    {
      *(_DWORD *)(a2 + 0x8000) = 0;
      return result;
    }
  }
  if ( *(_DWORD *)(v10 + 49152) || (result = *(unsigned int *)(a2 + 0x8000), (_DWORD)result) )
  {
    result = *(_QWORD *)(v10 + 49168);
    if ( *(_DWORD *)result == 11 && *(_DWORD *)(result + 4) == 120 )
    {
      v12 = *(_QWORD *)(result + 8);
      if ( !v12 || (result = VBoxGuest_RTSemSpinMutexRequest(v12), (int)result >= 0) )
      {
        v13 = *(unsigned int *)(a2 + 0x8000);
        if ( (_DWORD)v13 )
        {
          rtLogOutput_part_13(v10, (char *)a2, v13);
          *(_BYTE *)(v10 + *(unsigned int *)(v10 + 49152)) = 0;
          *(_DWORD *)(a2 + 0x8000) = 0;
          result = *(_QWORD *)(v10 + 49168);
          v14 = *(_QWORD *)(result + 8);
          if ( v14 )
            return VBoxGuest_RTSemSpinMutexRelease(v14, a3, a4, a5, a6, a7, a8, a9, a10);
        }
        else
        {
          result = *(_QWORD *)(v10 + 49168);
          v14 = *(_QWORD *)(result + 8);
          if ( v14 )
            return VBoxGuest_RTSemSpinMutexRelease(v14, a3, a4, a5, a6, a7, a8, a9, a10);
        }
      }
    }
  }
  return result;
}
