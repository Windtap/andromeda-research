__int64 VBoxGuest_RTR0MemUserCopyFrom()
{
  return copy_from_user() != 0 ? 0xFFFFFFDA : 0;
}
