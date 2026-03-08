size_t __fastcall strbufoutput(__int64 a1, _BYTE *a2, size_t a3)
{
  size_t v3; // rax
  _BYTE *v4; // rcx
  size_t v5; // rbx

  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(_BYTE **)a1;
  if ( a3 > v3 )
    a3 = *(_QWORD *)(a1 + 8);
  v5 = a3;
  if ( a3 )
  {
    *(_QWORD *)(a1 + 8) = v3 - a3;
    switch ( a3 )
    {
      case 1uLL:
        goto LABEL_12;
      case 2uLL:
        goto LABEL_11;
      case 3uLL:
        goto LABEL_10;
      case 4uLL:
        goto LABEL_9;
      case 5uLL:
        goto LABEL_8;
      case 6uLL:
        goto LABEL_7;
      case 7uLL:
        goto LABEL_6;
      case 8uLL:
        v4[7] = a2[7];
LABEL_6:
        v4[6] = a2[6];
LABEL_7:
        v4[5] = a2[5];
LABEL_8:
        v4[4] = a2[4];
LABEL_9:
        v4[3] = a2[3];
LABEL_10:
        v4[2] = a2[2];
LABEL_11:
        v4[1] = a2[1];
LABEL_12:
        *v4 = *a2;
        break;
      default:
        v4 = memcpy(v4, a2, a3);
        break;
    }
    v4 += v5;
    *(_QWORD *)a1 = v4;
  }
  *v4 = 0;
  return v5;
}
