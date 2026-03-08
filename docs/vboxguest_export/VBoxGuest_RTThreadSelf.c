unsigned __int64 *VBoxGuest_RTThreadSelf()
{
  return rtThreadGetByNative(__readgsqword((unsigned int)&current_task));
}
