int *__fastcall vbglR0HGCMHandleAlloc(__int64 a1, __int64 a2)
{
  int v2; // eax
  int *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // rdi
  int *v6; // rbx
  unsigned int v8; // [rsp+4h] [rbp-Ch]

  v2 = VBoxGuest_RTSemFastMutexRequest(g_hMtxHGCMHandleData);
  if ( v2 < 0 )
  {
    v8 = v2;
    VBoxGuest_RTAssertMsg1Weak(
      "RT_SUCCESS(rc)",
      96,
      "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibHGCM.c",
      "vbglR0HandleHeapEnter");
    VBoxGuest_RTAssertMsg2Weak("Failed to request handle heap mutex, rc = %Rrc\n", v8);
    VBoxGuest_RTAssertShouldPanic();
    __debugbreak();
  }
  v3 = g_aHGCMHandleData;
  v4 = 0;
  while ( *v3 )
  {
    v4 = (unsigned int)(v4 + 1);
    v3 += 10;
    if ( (_DWORD)v4 == 64 )
    {
      VBoxGuest_RTSemFastMutexRelease(g_hMtxHGCMHandleData, a2, v3);
LABEL_8:
      VBoxGuest_RTAssertMsg1Weak(
        "p != NULL",
        128,
        "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibHGCM.c",
        "vbglR0HGCMHandleAlloc");
      VBoxGuest_RTAssertMsg2Weak("Not enough HGCM handles.\n");
      VBoxGuest_RTAssertShouldPanic();
      __debugbreak();
    }
  }
  v5 = g_hMtxHGCMHandleData;
  v6 = &g_aHGCMHandleData[10 * v4];
  *v6 = 1;
  VBoxGuest_RTSemFastMutexRelease(v5, a2, v3);
  if ( !v6 )
    goto LABEL_8;
  return v6;
}
