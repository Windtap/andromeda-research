__int64 __fastcall VBoxGuest_RTSemEventMultiWait(__int64 a1, unsigned int a2)
{
  if ( a2 == -1 )
    return VBoxGuest_RTSemEventMultiWaitEx(a1, 80, 0);
  else
    return VBoxGuest_RTSemEventMultiWaitEx(a1, 73, a2);
}
