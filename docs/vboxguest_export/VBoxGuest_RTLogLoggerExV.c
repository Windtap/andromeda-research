__int64 __fastcall VBoxGuest_RTLogLoggerExV(
        __int64 a1,
        int a2,
        unsigned int a3,
        _BYTE *a4,
        __int64 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v17; // rbx
  __int64 result; // rax
  __int64 v19; // rdx
  __int64 v20; // rdi
  __int64 v21; // rdi
  int v22; // ebp
  __int64 v23; // rdx
  unsigned __int64 v24; // rsi
  int v25; // ebx
  unsigned __int64 v26; // rax
  int v27; // ebx
  int v28; // eax
  int v29; // edx
  unsigned int *v30; // rcx
  unsigned int v31; // edi
  __int64 v32; // rcx
  unsigned int v33; // esi
  unsigned int *v34; // rdx
  unsigned int v35; // r15d
  __int64 v36; // rdx
  __int64 v37; // r9
  _DWORD v38[2]; // [rsp+10h] [rbp-90h] BYREF
  __int64 v39; // [rsp+18h] [rbp-88h]
  _BYTE v40[128]; // [rsp+20h] [rbp-80h] BYREF

  v17 = a1;
  if ( a1 || (result = VBoxGuest_RTLogDefaultInstance(), (v17 = result) != 0) )
  {
    if ( a3 != -1 && a3 >= *(_DWORD *)(v17 + 49184) )
      a3 = 0;
    result = *(unsigned int *)(v17 + 49160);
    if ( (result & 1) == 0
      && *(_DWORD *)(v17 + 49164)
      && a4
      && *a4
      && (a3 == -1 || (a2 | 1) == ((a2 | 1) & *(_DWORD *)(v17 + 4LL * a3 + 49188))) )
    {
      v19 = *(_QWORD *)(v17 + 49168);
      if ( *(_DWORD *)v19 == 11 && *(_DWORD *)(v19 + 4) == 120 )
      {
        v20 = *(_QWORD *)(v19 + 8);
        if ( !v20 )
          goto LABEL_16;
        if ( (int)VBoxGuest_RTSemSpinMutexRequest(v20) >= 0 )
        {
          LODWORD(result) = *(_DWORD *)(v17 + 49160);
LABEL_16:
          if ( (result & 0x400) != 0
            && a3 < *(_DWORD *)(v17 + 49184)
            && (*(_BYTE *)(v17 + 4LL * a3 + 49191) & 0x40) != 0
            && (v30 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(v17 + 49168) + 56LL) + 4LL * a3),
                v31 = *v30 + 1,
                *v30 = v31,
                v32 = *(_QWORD *)(v17 + 49168),
                v33 = *(_DWORD *)(v32 + 64),
                v31 >= v33) )
          {
            v34 = (unsigned int *)(*(_QWORD *)(v32 + 56) + 4LL * a3);
            v35 = *v34;
            if ( v33 >= *v34 )
            {
              rtlogLoggerExVLocked(v17, a2, a3, (__int64)a4, a5);
              v36 = *(_QWORD *)(*(_QWORD *)(v17 + 49168) + 48LL);
              if ( v36 && (v37 = *(_QWORD *)(v36 + 8LL * a3)) != 0 )
                rtlogLoggerExFLocked(
                  v17,
                  a2,
                  a3,
                  (unsigned int)"%u messages from group %s (#%u), muting it.\n",
                  v35,
                  v37);
              else
                rtlogLoggerExFLocked(v17, a2, a3, (unsigned int)"%u messages from group #%u, muting it.\n", v35, a3);
            }
            else
            {
              *v34 = v35 - 1;
            }
          }
          else
          {
            rtlogLoggerExVLocked(v17, a2, a3, (__int64)a4, a5);
          }
          result = *(_QWORD *)(v17 + 49168);
          v21 = *(_QWORD *)(result + 8);
          if ( v21 )
            return VBoxGuest_RTSemSpinMutexRelease(v21, a6, a7, a8, a9, a10, a11, a12, a13);
          return result;
        }
      }
      result = *(unsigned int *)(v17 + 49164);
      if ( (result & 0xFFFFFFFE) != 0 )
      {
        v22 = *(_DWORD *)(v17 + 49160);
        v38[1] = *(_DWORD *)(v17 + 49164);
        v23 = *(_QWORD *)(v17 + 49168);
        v38[0] = 2;
        qmemcpy(v40, "[F", 2);
        v39 = v23;
        if ( (v22 & 0x20000) != 0 )
        {
          v24 = (unsigned int)VBoxGuest_RTProcSelf();
          v25 = v38[0] + 1;
          v40[v38[0]] = 32;
          v38[0] = VBoxGuest_RTStrFormatNumber(&v40[v25], v24, 0x10u, 8, 0, 4) + v25;
        }
        if ( (v22 & 0x400000) != 0 )
        {
          v26 = VBoxGuest_RTThreadNativeSelf();
          v27 = v38[0] + 1;
          v40[v38[0]] = 32;
          v38[0] = VBoxGuest_RTStrFormatNumber(&v40[v27], v26, 0x10u, 16, 0, 4) + v27;
        }
        v28 = v38[0];
        v29 = v38[0];
        v40[v38[0]] = 93;
        v38[0] = v29 + 2;
        v40[v28 + 1] = 32;
        return VBoxGuest_RTStrFormatV(
                 (__int64 (*)(__int64, const char *, ...))rtR0LogLoggerExFallbackOutput,
                 (__int64)v38,
                 (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
                 0,
                 (__int64)a4,
                 a5);
      }
    }
  }
  return result;
}
