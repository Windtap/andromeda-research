unsigned __int64 *__fastcall VBoxGuest_RTAvlPVGetBestFit(unsigned __int64 **a1, unsigned __int64 a2, char a3)
{
  unsigned __int64 *result; // rax
  unsigned __int64 *v4; // rcx
  bool v5; // cc
  unsigned __int64 *v6; // rdx
  unsigned __int64 *v7; // rdx

  result = *a1;
  if ( *a1 )
  {
    v4 = 0;
    if ( a3 )
    {
      v5 = *result <= a2;
      if ( *result != a2 )
      {
        do
        {
          if ( v5 )
          {
            v6 = (unsigned __int64 *)result[2];
            if ( !v6 )
              return v4;
          }
          else
          {
            v6 = (unsigned __int64 *)result[1];
            if ( !v6 )
              return result;
            v4 = result;
          }
          result = v6;
          v5 = *v6 <= a2;
        }
        while ( *v6 != a2 );
      }
    }
    else
    {
      while ( *result != a2 )
      {
        if ( a2 < *result )
        {
          v7 = (unsigned __int64 *)result[1];
          if ( !v7 )
            return v4;
        }
        else
        {
          v7 = (unsigned __int64 *)result[2];
          if ( !v7 )
            return result;
          v4 = result;
        }
        result = v7;
      }
    }
  }
  return result;
}
