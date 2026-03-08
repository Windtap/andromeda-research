__int64 __fastcall vbsf_write_begin(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        __int64 a6,
        __int64 a7)
{
  if ( (unsigned __int64)s_cCalls_46525++ <= 0xF )
  {
    printk("vboxsf: Unexpected call to vbsf_write_begin(pos=%#llx len=%#x flags=%#x)! Please report.\n", a3);
    VBoxGuest_RTLogBackdoorPrintf(
      "vboxsf: Unexpected call to vbsf_write_begin(pos=%#llx len=%#x flags=%#x)!  Please report.\n",
      a3,
      a4,
      a5);
    warn_slowpath_null("/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/regops.c", 3750);
  }
  return simple_write_begin(a1, a2, a3, a4);
}
