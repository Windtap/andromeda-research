unsigned __int64 VBoxGuest_RTThreadNativeSelf()
{
  return __readgsqword((unsigned int)&current_task);
}
