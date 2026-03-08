char __fastcall VBoxGuest_RTErrConvertToErrno(int a1)
{
  char result; // al

  if ( a1 >= 0 )
    return 0;
  if ( a1 == -250 )
    return 5;
  if ( a1 > -250 )
  {
    if ( a1 == -105 )
      return 17;
    if ( a1 > -105 )
    {
      if ( a1 == -39 )
        return 4;
      if ( a1 > -39 )
      {
        if ( a1 == -12 )
          return 38;
        if ( a1 > -12 )
        {
          if ( a1 == -6 )
            return 14;
          if ( a1 <= -6 )
          {
            result = 12;
            if ( a1 == -8 )
              return result;
          }
          else
          {
            result = 9;
            if ( a1 == -4 )
              return result;
            result = 22;
            if ( a1 == -2 )
              return result;
          }
          return 71;
        }
        if ( a1 == -37 )
          return 38;
        result = 1;
        if ( a1 < -37 )
          return result;
        result = 25;
        if ( a1 == -36 )
          return result;
        return 71;
      }
      if ( a1 == -52 )
        return 11;
      if ( a1 > -52 )
      {
        if ( a1 == -42 )
          return 7;
        result = 110;
        if ( a1 == -40 )
          return result;
        result = 3;
        if ( a1 == -50 )
          return result;
        return 71;
      }
      result = 2;
      if ( a1 == -102 )
        return result;
      result = 84;
      if ( a1 == -58 )
        return result;
      if ( a1 != -103 )
        return 71;
    }
    else
    {
      if ( a1 == -122 )
        return 124;
      if ( a1 > -122 )
      {
        if ( a1 == -115 )
          return 37;
        if ( a1 <= -115 )
        {
          if ( a1 == -120 )
            return 36;
          result = 123;
          if ( a1 < -120 )
            return result;
          result = 18;
          if ( a1 == -119 )
            return result;
        }
        else
        {
          if ( a1 == -113 )
            return 30;
          if ( a1 < -113 )
            return 26;
          result = 29;
          if ( a1 == -109 )
            return result;
          result = 23;
          if ( a1 == -106 )
            return result;
        }
        return 71;
      }
      if ( a1 == -128 )
        return 27;
      if ( a1 <= -128 )
      {
        if ( a1 == -152 )
          return 28;
        result = 16;
        if ( a1 != -138 )
        {
          result = 40;
          if ( a1 != -156 )
            return 71;
        }
        return result;
      }
      if ( a1 != -126 )
      {
        result = 21;
        if ( a1 < -126 )
          return result;
        result = 39;
        if ( a1 == -125 )
          return result;
        return 71;
      }
    }
    return 20;
  }
  if ( a1 == -447 )
    return 97;
  if ( a1 > -447 )
  {
    if ( a1 == -439 )
      return 89;
    if ( a1 <= -439 )
    {
      if ( a1 == -443 )
        return 93;
      if ( a1 > -443 )
      {
        if ( a1 == -441 )
          return 91;
        else
          return 2 * (a1 <= -441) + 90;
      }
      else if ( a1 == -445 )
      {
        return 95;
      }
      else
      {
        return 2 * (a1 <= -445) + 94;
      }
    }
    if ( a1 == -406 )
      return 76;
    if ( a1 > -406 )
    {
      if ( a1 == -365 )
        return 35;
      if ( a1 <= -365 )
      {
        result = 64;
        if ( a1 == -405 )
          return result;
      }
      else
      {
        result = 61;
        if ( a1 == -304 )
          return result;
        result = 32;
        if ( a1 == -301 )
          return result;
      }
      return 71;
    }
    if ( a1 == -437 )
      return 114;
    result = 88;
    if ( a1 >= -437 )
    {
      result = 115;
      if ( a1 != -436 )
        return 71;
    }
  }
  else
  {
    if ( a1 == -456 )
      return 106;
    if ( a1 > -456 )
    {
      if ( a1 == -452 )
        return 102;
      if ( a1 <= -452 )
      {
        if ( a1 == -454 )
          return 104;
        else
          return 2 * (a1 <= -454) + 103;
      }
      else if ( a1 == -450 )
      {
        return 100;
      }
      else if ( a1 < -450 )
      {
        return 101;
      }
      else
      {
        result = 99;
        if ( a1 != -449 )
          return 98;
      }
      return result;
    }
    if ( a1 == -461 )
      return 111;
    if ( a1 <= -461 )
    {
      if ( a1 == -465 )
        return 113;
      result = 112;
      if ( a1 == -464 )
        return result;
      result = 8;
      if ( a1 == -608 )
        return result;
      return 71;
    }
    if ( a1 == -458 )
      return 108;
    result = 107;
    if ( a1 <= -458 )
    {
      result = 109;
      if ( a1 != -459 )
        return 71;
    }
  }
  return result;
}
