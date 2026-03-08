unsigned __int64 *__fastcall VBoxGuest_RTAvlPVRemoveBestFit(unsigned __int64 **a1, unsigned __int64 a2, char a3)
{
  unsigned __int64 *v3; // rax

  v3 = VBoxGuest_RTAvlPVGetBestFit(a1, a2, a3);
  if ( v3 )
    return VBoxGuest_RTAvlPVRemove(a1, *v3);
  else
    return 0;
}
