__int64 goldfish_sync_init()
{
  _mutex_init(&g_mutex_lock_ioctl, "&g_mutex_lock_ioctl", &s_uNameIndex);
  misc_register(&goldfish_sync_device);
  printk(byte_4360);
  return 0;
}
