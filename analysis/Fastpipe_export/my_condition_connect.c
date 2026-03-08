bool __fastcall my_condition_connect(int *a1)
{
  __int64 v1; // rdx
  bool result; // al

  v1 = 48LL * *a1;
  result = 1;
  if ( !*(_DWORD *)(g_pPipeMem + v1 + 24) )
    return a1[1] != *(_DWORD *)(g_pPipeMem + v1 + 44);
  return result;
}
