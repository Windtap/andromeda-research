void __fastcall vbglR0HGCMHandleFree(__int64 a1, __int64 a2)
{
  int v3; // eax
  __int64 v4; // rdx
  __int64 v5; // rdi
  unsigned int v6; // [rsp+4h] [rbp-Ch]

  if ( a1 )
  {
    v3 = VBoxGuest_RTSemFastMutexRequest(g_hMtxHGCMHandleData);
    if ( v3 < 0 )
    {
      v6 = v3;
      VBoxGuest_RTAssertMsg1Weak(
        "RT_SUCCESS(rc)",
        96,
        "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibHGCM.c",
        "vbglR0HandleHeapEnter");
      VBoxGuest_RTAssertMsg2Weak("Failed to request handle heap mutex, rc = %Rrc\n", v6);
      VBoxGuest_RTAssertShouldPanic();
      __debugbreak();
    }
    if ( !*(_DWORD *)a1 )
    {
      VBoxGuest_RTAssertMsg1Weak(
        "pHandle->fAllocated",
        140,
        "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibHGCM.c",
        "vbglR0HGCMHandleFree");
      VBoxGuest_RTAssertMsg2Weak("Freeing not allocated handle.\n");
      VBoxGuest_RTAssertShouldPanic();
      __debugbreak();
    }
    *(_QWORD *)a1 = 0;
    *(_QWORD *)(a1 + 8) = 0;
    v5 = g_hMtxHGCMHandleData;
    *(_QWORD *)(a1 + 16) = 0;
    *(_QWORD *)(a1 + 24) = 0;
    *(_QWORD *)(a1 + 32) = 0;
    VBoxGuest_RTSemFastMutexRelease(v5, a2, v4);
  }
}
