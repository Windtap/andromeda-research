// Alternative name is 'fini'
__int64 cleanup_module()
{
  unregister_filesystem(&g_vboxsf_fs_type);
  VbglR0SfDisconnect((__int64)&g_SfClient);
  return VbglR0SfTerm();
}
