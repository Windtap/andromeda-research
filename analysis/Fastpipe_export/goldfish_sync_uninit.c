__int64 goldfish_sync_uninit()
{
  misc_deregister(&goldfish_sync_device);
  return 0;
}
