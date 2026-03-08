int __fastcall rtThreadNativeSetPriority(__int64 a1, int a2)
{
  int v2; // ebx
  int result; // eax
  struct sched_param param; // [rsp+4h] [rbp-14h] BYREF

  param.__sched_priority = 0;
  switch ( a2 )
  {
    case 1:
      v2 = 3;
      goto LABEL_3;
    case 2:
      v2 = 2;
      goto LABEL_3;
    case 3:
      v2 = 1;
      goto LABEL_3;
    case 4:
    case 5:
    case 6:
      v2 = 0;
      goto LABEL_3;
    case 7:
    case 8:
      v2 = -1;
      goto LABEL_3;
    case 9:
      v2 = -2;
LABEL_3:
      if ( !sched_setscheduler(__readgsqword((unsigned int)&current_task), 0, &param) )
        goto LABEL_4;
      goto LABEL_9;
    case 10:
      param.__sched_priority = 1;
      v2 = -12;
      goto LABEL_8;
    case 11:
      param.__sched_priority = 50;
      v2 = -19;
LABEL_8:
      result = sched_setscheduler(__readgsqword((unsigned int)&current_task), 1, &param);
      if ( result )
      {
LABEL_9:
        param.__sched_priority = 0;
        sched_setscheduler(__readgsqword((unsigned int)&current_task), 0, &param);
LABEL_4:
        set_user_nice(__readgsqword((unsigned int)&current_task), v2);
        result = 0;
      }
      break;
    default:
      result = -2;
      break;
  }
  return result;
}
