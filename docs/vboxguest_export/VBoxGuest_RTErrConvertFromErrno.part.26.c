__int64 __fastcall VBoxGuest_RTErrConvertFromErrno_part_26(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // ebp
  __int64 DefaultInstance; // rax
  double v12; // xmm4_8
  double v13; // xmm5_8
  __int64 v14; // rax
  double v15; // xmm4_8
  double v16; // xmm5_8

  switch ( a1 )
  {
    case 1u:
    case 0xDu:
      v9 = -38;
      break;
    case 2u:
      v9 = -102;
      break;
    case 3u:
    case 0xAu:
      v9 = -50;
      break;
    case 4u:
    case 0x55u:
      v9 = -39;
      break;
    case 5u:
    case 6u:
      v9 = -250;
      break;
    case 7u:
    case 0x4Bu:
      v9 = -42;
      break;
    case 8u:
      v9 = -608;
      break;
    case 9u:
    case 0x4Du:
      v9 = -4;
      break;
    case 0xBu:
      v9 = -52;
      break;
    case 0xCu:
      v9 = -8;
      break;
    case 0xEu:
      v9 = -6;
      break;
    case 0x10u:
      v9 = -138;
      break;
    case 0x11u:
      v9 = -105;
      break;
    case 0x12u:
      v9 = -119;
      break;
    case 0x13u:
    case 0x26u:
      v9 = -37;
      break;
    case 0x14u:
      v9 = -103;
      break;
    case 0x15u:
      v9 = -127;
      break;
    case 0x16u:
    case 0x21u:
    case 0x22u:
      v9 = -2;
      break;
    case 0x17u:
    case 0x18u:
      v9 = -106;
      break;
    case 0x19u:
      v9 = -36;
      break;
    case 0x1Au:
      v9 = -114;
      break;
    case 0x1Bu:
      v9 = -128;
      break;
    case 0x1Cu:
    case 0x7Au:
      v9 = -152;
      break;
    case 0x1Du:
      v9 = -109;
      break;
    case 0x1Eu:
      v9 = -113;
      break;
    case 0x20u:
      v9 = -301;
      break;
    case 0x23u:
      v9 = -365;
      break;
    case 0x24u:
      v9 = -120;
      break;
    case 0x25u:
      v9 = -115;
      break;
    case 0x27u:
      v9 = -125;
      break;
    case 0x28u:
      v9 = -156;
      break;
    case 0x3Du:
      v9 = -304;
      break;
    case 0x40u:
      v9 = -405;
      break;
    case 0x47u:
      v9 = -466;
      break;
    case 0x4Cu:
      v9 = -406;
      break;
    case 0x54u:
      v9 = -58;
      break;
    case 0x58u:
      v9 = -438;
      break;
    case 0x59u:
      v9 = -439;
      break;
    case 0x5Au:
      v9 = -440;
      break;
    case 0x5Bu:
      v9 = -441;
      break;
    case 0x5Cu:
      v9 = -442;
      break;
    case 0x5Du:
      v9 = -443;
      break;
    case 0x5Eu:
      v9 = -444;
      break;
    case 0x5Fu:
      v9 = -445;
      break;
    case 0x60u:
      v9 = -446;
      break;
    case 0x61u:
      v9 = -447;
      break;
    case 0x62u:
      v9 = -448;
      break;
    case 0x63u:
      v9 = -449;
      break;
    case 0x64u:
      v9 = -450;
      break;
    case 0x65u:
      v9 = -451;
      break;
    case 0x66u:
      v9 = -452;
      break;
    case 0x67u:
      v9 = -453;
      break;
    case 0x68u:
      v9 = -454;
      break;
    case 0x69u:
      v9 = -455;
      break;
    case 0x6Au:
      v9 = -456;
      break;
    case 0x6Bu:
      v9 = -457;
      break;
    case 0x6Cu:
      v9 = -458;
      break;
    case 0x6Du:
      v9 = -459;
      break;
    case 0x6Eu:
      v9 = -40;
      break;
    case 0x6Fu:
      v9 = -461;
      break;
    case 0x70u:
      v9 = -464;
      break;
    case 0x71u:
      v9 = -465;
      break;
    case 0x72u:
      v9 = -437;
      break;
    case 0x73u:
      v9 = -436;
      break;
    case 0x74u:
      v9 = -147;
      break;
    case 0x7Bu:
      v9 = -121;
      break;
    case 0x7Cu:
      v9 = -122;
      break;
    default:
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x110010u);
      if ( DefaultInstance )
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          0x11u,
          "AssertLogRel %s(%d) %s: %s\n",
          a2,
          a3,
          a4,
          a5,
          v12,
          v13,
          a8,
          a9,
          "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/common/err/RTErrConvertFromErrno.c",
          452,
          "VBoxGuest_RTErrConvertFromErrno",
          0);
      v9 = -35;
      v14 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x110010u);
      if ( v14 )
        VBoxGuest_RTLogLoggerEx(v14, 16, 0x11u, "Unhandled error code %d\n", a2, a3, a4, a5, v15, v16, a8, a9, a1);
      break;
  }
  return v9;
}
