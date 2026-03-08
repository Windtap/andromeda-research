__int64 __fastcall VBoxGuest_RTStrGetCpInternal(unsigned __int8 *a1)
{
  unsigned __int8 *v2; // [rsp+0h] [rbp-10h] BYREF
  unsigned int v3; // [rsp+Ch] [rbp-4h] BYREF

  v2 = a1;
  VBoxGuest_RTStrGetCpExInternal(&v2, (int *)&v3);
  return v3;
}
