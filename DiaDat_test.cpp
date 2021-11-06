#include <iostream>

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "DiaDat_file.h"

int debug_level_param = 99;

static void test_sin_s8(void)
{
  try {
      printf("Testing data file writing ...\n");
      DiaDat_File *file = new DiaDat_File("demo2.dat", e_DiaDatFileType_Write);
      file->createImpliciteTimeChannel(0.01);
      int8_t sin_s8;
      int16_t sin_s16;
      file->createChannel("sin_s8", e_DiaDat_ChannelType_s8, &sin_s8);
      file->createChannel("sin_s16", e_DiaDat_ChannelType_s16, &sin_s16);
      int32_t sin_s32;
      file->createChannel("sin_s32", &sin_s32);
      uint8_t sin_u8;
      file->createChannel("sin_u8", &sin_u8);
      uint16_t sin_u16;
      file->createChannel("sin_u16", &sin_u16);
      uint32_t sin_u32;
      file->createChannel("sin_u32", &sin_u32);
      double sin_r64;
      file->createChannel("sin_r64", &sin_r64);
      double sin_r32;
      file->createChannel("sin_r32", &sin_r32);
      int i;
      file->createChannel("i", e_DiaDat_ChannelType_s32, &i);
      for (i = 0; i < 2000; i++)
      {
          sin_s8 = (int8_t)(sin(i * 2 * 3.1415/23.23) * 111);
          sin_u8 = (uint8_t)((sin(i * 2 * 3.1415/24.23) + 1) * 111);
          sin_s16 = (int16_t)(sin(i * 2 * 3.1415/34.23) * 3333);
          sin_u16 = (uint16_t)((sin(i * 2 * 3.1415/25.23) + 1) * 3333);
          sin_s32 = (int32_t)(sin(i * 2 * 3.1415/29.23) * 77777);
          sin_u32 = (uint32_t)((sin(i * 2 * 3.1415/26.23) + 1) * 77777);
          sin_r64 = sin(i * 2 * 3.1415/27.23) * i / 200;
          sin_r32 = sin(i * 2 * 3.1415/28.23) * (2000 - i) / 150;
          file->step();
      }
      file->close();
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  } catch(std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }
}

static void test_sin_u8(void)
{
  try {
      printf("Testing data file writing ...\n");
      DiaDat_File *file = new DiaDat_File("demo3.dat", e_DiaDatFileType_Write);
      file->createImpliciteTimeChannel(0.01);
      uint8_t sin_u8;
      file->createChannel("sin_u8", &sin_u8);
      int i;
      for (i = 0; i < 2000; i++)
      {
          sin_u8 = (uint8_t)((sin(i * 2 * 3.1415/24.23) + 1) * 111);
          file->step();
      }
      file->close();
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  } catch(std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }
}

int main(int argc, const char **argv)
{
  printf("argc=%d argv[0]=%s!\n", argc, argv[0]);
  try {
      printf("Testing data file writing ...\n");
      DiaDat_File *file = new DiaDat_File();
      file->create("demo1.dat");
      file->createImpliciteTimeChannel(0.01);
      uint8_t sin_u8 = 1;
      file->createChannel("sin_u8", e_DiaDat_ChannelType_u8, &sin_u8);
      uint8_t cos_u8 = 2;
      file->createChannel("cos_u8", &cos_u8);
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
      file->createChannel("cos_s8", &cos_s8);
      int16_t sin_s16 = 258;
      file->createChannel("sin_s16", e_DiaDat_ChannelType_s16, &sin_s16);
      int16_t cos_s16 = -259;
      file->createChannel("cos_s16", &cos_s16);
      uint16_t sin_u16 = 333;
      file->createChannel("sin_u16", e_DiaDat_ChannelType_u16, &sin_u16);
      uint16_t cos_u16 = 444;
      file->createChannel("cos_u16", &cos_u16);
      int32_t sin_s32 = 65537;
      file->createChannel("sin_s32", e_DiaDat_ChannelType_s32, &sin_s32);
      int32_t cos_s32 = -1111;
      file->createChannel("cos_s32", &cos_s32);
      uint32_t sin_u32 = 65538;
      file->createChannel("sin_u32", e_DiaDat_ChannelType_u32, &sin_u32);
      uint32_t cos_u32 = 1e6;
      file->createChannel("cos_u32", &cos_u32);
      float sin_r32 = 1.5;
      file->createChannel("sin_r32", e_DiaDat_ChannelType_r32, &sin_r32);
      float cos_r32 = 2.2;
      file->createChannel("cos_r32", &cos_r32);
      double sin_r64 = 5.5;
      file->createChannel("sin_r64", e_DiaDat_ChannelType_r64, &sin_r64);
      double cos_r64 = 6.2;
      file->createChannel("cos_r64", &cos_r64);
      file->step();
      sin_u8 = 5;
      cos_u8 = 7;
      sin_s8 = -9;
      cos_s8 = -17;
      sin_s16 = -1000;
      cos_s16 = 2222;
      sin_u16 = 555;
      cos_u16 = 666;
      sin_s32 = -2222;
      cos_s32 = 129000;
      sin_u32 = 1e7;
      cos_u32 = 1e8;
      sin_r32 = 3.3;
      cos_r32 = 4.4;
      sin_r64 = 7.7;
      cos_r64 = -8.8;
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
      file->connectVar("sin_u16", &sin_u16);
      file->connectVar("cos_u16", &cos_u16);
      file->connectVar("sin_s32", &sin_s32);
      file->connectVar("cos_s32", &cos_s32);
      file->connectVar("sin_u32", &sin_u32);
      file->connectVar("cos_u32", &cos_u32);
      file->connectVar("sin_r32", &sin_r32);
      file->connectVar("cos_r32", &cos_r32);
      file->connectVar("sin_r64", &sin_r64);
      file->connectVar("cos_r64", &cos_r64);
      file->step();
      assert(sin_u8 == 1);
      assert(cos_u8 == 2);
      assert(sin_s8 == 3);
      assert(cos_s8 == -3);
      assert(sin_s16 == 258);
      assert(cos_s16 == -259);
      assert(sin_u16 == 333);
      assert(cos_u16 == 444);
      assert(sin_s32 == 65537);
      assert(cos_s32 == -1111);
      assert(sin_u32 == 65538);
      assert(cos_u32 == 1e6);
      assert(fabs(sin_r32 - 1.5) < 1e-6);
      assert(fabs(cos_r32 - 2.2) < 1e-6);
      assert(fabs(sin_r64 - 5.5) < 1e-6);
      assert(fabs(cos_r64 - 6.2) < 1e-6);
      file->step();
      assert(sin_u8 == 5);
      assert(cos_u8 == 7);
      assert(sin_s8 == -9);
      assert(cos_s8 == -17);
      assert(sin_s16 == -1000);
      assert(cos_s16 == 2222);
      assert(sin_u16 == 555);
      assert(cos_u16 == 666);
      assert(sin_s32 == -2222);
      assert(cos_s32 == 129000);
      assert(sin_u32 == 1e7);
      assert(cos_u32 == 1e8);
      assert(fabs(sin_r32 - 3.3) < 1e-6);
      assert(fabs(cos_r32 - 4.4) < 1e-6);
      assert(fabs(sin_r64 - 7.7) < 1e-6);
      assert(fabs(cos_r64 - -8.8) < 1e-6);
      file->close();
  } catch (const char* msg) {
      std::cerr << msg << std::endl;
  } catch(std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }
  test_sin_s8();
  test_sin_u8();
  printf("Testing is done!\n");
  return 0;
}
