__int64 __fastcall VBoxGuest_RTSemEventWaitNoResume(__int64 a1, unsigned int a2)
{
  if ( a2 == -1 )
    return VBoxGuest_RTSemEventWaitEx(a1, 48, 0);
  else
    return VBoxGuest_RTSemEventWaitEx(a1, 41, a2);
}
