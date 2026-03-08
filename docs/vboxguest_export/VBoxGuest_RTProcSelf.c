__int64 VBoxGuest_RTProcSelf()
{
  return *(unsigned int *)(__readgsqword((unsigned int)&current_task) + 1940);
}
