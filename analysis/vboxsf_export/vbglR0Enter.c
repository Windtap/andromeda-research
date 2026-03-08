__int64 vbglR0Enter()
{
  unsigned int v0; // ebx

  if ( g_vbgldata == 2 )
    return 0;
  v0 = -3300;
  if ( g_vbgldata == 1 )
  {
    vbglR0QueryDriverInfo();
    if ( g_vbgldata == 2 )
      return 0;
  }
  return v0;
}
