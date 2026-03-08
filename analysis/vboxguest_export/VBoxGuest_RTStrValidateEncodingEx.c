__int64 __fastcall VBoxGuest_RTStrValidateEncodingEx(unsigned __int8 *a1, unsigned __int64 a2, int a3)
{
  char v3; // bl
  __int64 result; // rax
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // [rsp+0h] [rbp-20h] BYREF
  _QWORD v7[3]; // [rsp+8h] [rbp-18h] BYREF

  v3 = a3;
  if ( (a3 & 0xFFFFFFFC) != 0 )
    return 4294967294LL;
  result = rtUtf8Length(a1, a2, v7, &v6);
  if ( (int)result >= 0 )
  {
    if ( (v3 & 2) != 0 )
    {
      if ( (v3 & 1) != 0 )
        v5 = v6 + 1;
      else
        v5 = v6;
      result = 0;
      if ( a2 == v5 )
        return result;
      result = 4294944895LL;
      if ( a2 > v5 )
        return result;
    }
    else if ( (v3 & 1) == 0 || a2 > v6 )
    {
      return result;
    }
    return 4294967255LL;
  }
  return result;
}
