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
      uint8_t sin_u8 = 1;
      file->createChannel("sin_u8", e_DiaDat_ChannelType_u8, &sin_u8);
      uint8_t cos_u8 = 2;
      file->createChannel("cos_u8", e_DiaDat_ChannelType_u8, &cos_u8);
      try {
          file->createChannel("sin_u8", e_DiaDat_ChannelType_u8);
          std::cerr << "Error - duplicated channel is created!" << std::endl;
          return 1;
      } catch (const char* msg) {
          /* good result - ok */
      }
      int8_t sin_s8 = 3;
      file->createChannel("sin_s8", e_DiaDat_ChannelType_s8, &sin_s8);
      int8_t cos_s8 = -3;
      file->createChannel("cos_s8", e_DiaDat_ChannelType_s8, &cos_s8);
      file->set_dT(0.01);
      file->step();
      file->close();

      file = new DiaDat_File("demo1.dat");
      file->close();
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  }
  return 0;
}
