bool __fastcall VBoxGuest_RTAssertSetQuiet(char a1)
{
  char v1; // di

  v1 = g_fQuiet;
  g_fQuiet = a1;
  return v1 != 0;
}
