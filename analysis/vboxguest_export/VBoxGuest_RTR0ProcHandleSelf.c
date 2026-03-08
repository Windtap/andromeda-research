__int64 VBoxGuest_RTR0ProcHandleSelf()
{
  return *(int *)(__readgsqword((unsigned int)&current_task) + 1940);
}
