__int64 __fastcall VbglR0HGCMCallRaw(__int64 a1, __int64 a2, unsigned int a3)
{
  if ( a3 < 16 * (unsigned __int64)*(unsigned __int16 *)(a2 + 38) + 40 )
  {
    VBoxGuest_RTAssertMsg1Weak(
      "cbData >= sizeof(VBGLIOCHGCMCALL) + pData->cParms * sizeof(HGCMFunctionParameter)",
      212,
      "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibHGCM.c",
      "VbglR0HGCMCallRaw");
    VBoxGuest_RTAssertMsg2Weak(
      "cbData = %d, cParms = %d (calculated size %d)\n",
      a3,
      *(unsigned __int16 *)(a2 + 38),
      40 * (*(unsigned __int16 *)(a2 + 38) + 1));
    VBoxGuest_RTAssertShouldPanic();
    __debugbreak();
  }
  return VbglR0IdcCallRaw(a1 + 8, (a3 << 16) | 0xC0005607, a2, a3);
}
