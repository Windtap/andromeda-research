void __noreturn VBoxGuest_RTR0AssertPanicSystem()
{
  panic("%s%s", VBoxGuest_g_szRTAssertMsg1, VBoxGuest_g_szRTAssertMsg2);
}
