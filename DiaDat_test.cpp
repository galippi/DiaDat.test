#include <iostream>

#include <stdio.h>

#include "DiaDat_file.h"

int debug_level_param = 99;

int main(int argc, const char **argv)
{
  printf("argc=%d argv[0]=%s!\n", argc, argv[0]);
  try {
      DiaDat_File *file = new DiaDat_File();
      file->create("demo1.dat");
      file->createChannel("sin_u8", e_DiaDat_ChannelType_u8);
      file->createChannel("cos_u8", e_DiaDat_ChannelType_u8);
      try {
          file->createChannel("sin_u8", e_DiaDat_ChannelType_u8);
          std::cerr << "Error - duplicated channel is created!" << std::endl;
          return 1;
      } catch (const char* msg) {
          /* good result - ok */
      }
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  }
  return 0;
}
