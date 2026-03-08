__int64 VBoxGuest_RTR0MemUserCopyTo()
{
  return copy_to_user() != 0 ? 0xFFFFFFDA : 0;
}
