__int64 __fastcall VBoxGuest_RTLogFlushToLogger(
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
  __int64 v11; // rbx
  __int64 result; // rax
  __int64 v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rdi
  unsigned __int64 v16; // rdx
  __int64 v17; // rdi
  __int64 v18; // rdi
  __int64 v19; // rdi

  v11 = a2;
  if ( a2 || (result = VBoxGuest_RTLogDefaultInstance(), (v11 = result) != 0) )
  {
    if ( !*(_DWORD *)(a1 + 49152) )
    {
      result = *(unsigned int *)(v11 + 49152);
      if ( !(_DWORD)result )
        return result;
    }
    result = *(_QWORD *)(v11 + 49168);
    if ( *(_DWORD *)result != 11 )
      return result;
    if ( *(_DWORD *)(result + 4) != 120 )
      return result;
    v13 = *(_QWORD *)(result + 8);
    if ( v13 )
    {
      result = VBoxGuest_RTSemSpinMutexRequest(v13);
      if ( (int)result < 0 )
        return result;
    }
    v14 = *(_QWORD *)(a1 + 49168);
    if ( *(_DWORD *)v14 == 11 && *(_DWORD *)(v14 + 4) == 120 )
    {
      v15 = *(_QWORD *)(v14 + 8);
      if ( !v15 || (int)VBoxGuest_RTSemSpinMutexRequest(v15) >= 0 )
      {
        v16 = *(unsigned int *)(a1 + 49152);
        if ( (_DWORD)v16 )
        {
          rtLogOutput_part_13(v11, (char *)a1, v16);
          *(_BYTE *)(v11 + *(unsigned int *)(v11 + 49152)) = 0;
          *(_DWORD *)(a1 + 49152) = 0;
        }
        v17 = *(_QWORD *)(*(_QWORD *)(a1 + 49168) + 8LL);
        if ( v17 )
          VBoxGuest_RTSemSpinMutexRelease(v17, a3, a4, a5, a6, a7, a8, a9, a10);
      }
    }
    result = *(_QWORD *)(v11 + 49168);
    v18 = *(_QWORD *)(result + 8);
    if ( !v18 )
      return result;
    return VBoxGuest_RTSemSpinMutexRelease(v18, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  if ( *(_DWORD *)(a1 + 49152) )
  {
    result = *(_QWORD *)(a1 + 49168);
    if ( *(_DWORD *)result == 11 && *(_DWORD *)(result + 4) == 120 )
    {
      v19 = *(_QWORD *)(result + 8);
      if ( v19 )
      {
        result = VBoxGuest_RTSemSpinMutexRequest(v19);
        if ( (int)result < 0 )
          return result;
        result = *(_QWORD *)(a1 + 49168);
      }
      *(_DWORD *)(a1 + 49152) = 0;
      v18 = *(_QWORD *)(result + 8);
      if ( v18 )
        return VBoxGuest_RTSemSpinMutexRelease(v18, a3, a4, a5, a6, a7, a8, a9, a10);
    }
  }
  return result;
}
