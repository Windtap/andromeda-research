_BOOL8 __fastcall VBoxGuest_RTStrIsValidEncoding(unsigned __int8 *a1)
{
  return (int)VBoxGuest_RTStrValidateEncodingEx(a1, 0xFFFFFFFFFFFFFFFFLL, 0) >= 0;
}
