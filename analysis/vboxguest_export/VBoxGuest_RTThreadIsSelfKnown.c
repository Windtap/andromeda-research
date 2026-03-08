bool VBoxGuest_RTThreadIsSelfKnown()
{
  bool result; // al

  result = 0;
  if ( g_frtThreadInitialized )
    return VBoxGuest_RTThreadSelf() != 0;
  return result;
}
