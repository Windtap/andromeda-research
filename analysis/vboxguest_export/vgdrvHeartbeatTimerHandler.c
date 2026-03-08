__int64 __fastcall vgdrvHeartbeatTimerHandler(__int64 a1, __int64 a2)
{
  __int64 result; // rax

  if ( a2 )
  {
    if ( *(_QWORD *)(a2 + 656) )
      return VbglR0GRPerform();
  }
  return result;
}
