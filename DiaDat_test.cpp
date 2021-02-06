#include <iostream>

#include <stdio.h>

#include "DiaDat_file.h"

int main(int argc, const char **argv)
{
  printf("argc=%d argv[0]=%s!\n", argc, argv[0]);
  try {
      DiaDat_File *file = new DiaDat_File();
      file->create("demo1.dat");
      file->createChannel("sin_u8", e_DiaDat_ChannelType_u8);
      file->createChannel("cos_u8", e_DiaDat_ChannelType_u8);
      file->createChannel("sin_u8", e_DiaDat_ChannelType_u8);
      //file->createChannel("sin_s8", e_DiaDat_ChannelType_s8);
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  }
  return 0;
}
