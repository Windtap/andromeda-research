__int64 VbglR0TerminatePrimary()
{
  __int64 result; // rax

  result = VbglR0PhysHeapTerminate();
  g_vbgldata = 0;
  return result;
}
