bool __fastcall VBoxGuest_RTAssertSetMayPanic(char a1)
{
  char v1; // di

  v1 = g_fMayPanic;
  g_fMayPanic = a1;
  return v1 != 0;
}
