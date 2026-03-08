__int64 __fastcall vgdrvLinuxPoll(__int64 a1, void (__fastcall **a2)(__int64, void *, _QWORD))
{
  unsigned int v2; // ebx

  v2 = 65;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 208) + 296LL) == dword_309FC )
    v2 = 0;
  if ( a2 && *a2 )
    (*a2)(a1, &g_PollEventQueue, a2);
  return v2;
}
