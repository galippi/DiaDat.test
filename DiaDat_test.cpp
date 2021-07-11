#include <iostream>

#include <stdio.h>
#include <assert.h>

#include "DiaDat_file.h"

int debug_level_param = 99;

int main(int argc, const char **argv)
{
  printf("argc=%d argv[0]=%s!\n", argc, argv[0]);
  try {
      printf("Testing data file writing ...\n");
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
      int16_t sin_s16 = 258;
      file->createChannel("sin_s16", e_DiaDat_ChannelType_s16, &sin_s16);
      int16_t cos_s16 = -259;
      file->createChannel("cos_s16", e_DiaDat_ChannelType_s16, &cos_s16);
      file->set_dT(0.01);
      file->step();
      sin_u8 = 5;
      cos_u8 = 7;
      sin_s8 = -9;
      cos_s8 = -17;
      sin_s16 = -1000;
      cos_s16 = 2222;
      file->step();
      file->close();

      printf("Testing data file reading ...\n");
      file = new DiaDat_File("demo1.dat");
      file->connectVar("sin_u8", &sin_u8);
      file->connectVar("cos_u8", &cos_u8);
      file->connectVar("sin_s8", &sin_s8);
      file->connectVar("cos_s8", &cos_s8);
      file->connectVar("sin_s16", &sin_s16);
      file->connectVar("cos_s16", &cos_s16);
      file->step();
      assert(sin_u8 == 1);
      assert(cos_u8 == 2);
      assert(sin_s8 == 3);
      assert(cos_s8 == -3);
      assert(sin_s16 == 258);
      assert(cos_s16 == -259);
      file->step();
      assert(sin_u8 == 5);
      assert(cos_u8 == 7);
      assert(sin_s8 == -9);
      assert(cos_s8 == -17);
      assert(sin_s16 == -1000);
      assert(cos_s16 == 2222);
      file->close();
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  } catch(std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }
  printf("Testing is done!\n");
  return 0;
}
