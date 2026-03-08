// attributes: thunk
unsigned __int64 *__fastcall VBoxGuest_RTThreadFromNative(unsigned __int64 a1)
{
  return rtThreadGetByNative(a1);
}
