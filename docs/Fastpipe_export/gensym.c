int __fastcall gensym(char *a1)
{
  int result; // eax

  result = sprintf(a1, "goldfish_sync:gensym:%llu", gensym_ctr);
  ++gensym_ctr;
  return result;
}
