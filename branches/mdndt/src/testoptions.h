/*
 * This file contains the definitions and function declarations to
 * handle various tests.
 *
 * Jakub S�awi�ski 2006-06-24
 * jeremian@poczta.fm
 */

#ifndef _JS_TESTOPTIONS_H
#define _JS_TESTOPTIONS_H

#include "web100srv.h"

#define TEST_MID (1L << 0)
#define TEST_C2S (1L << 1)
#define TEST_S2C (1L << 2)

#define TOPT_ENABLED 1

typedef struct testoptions {
  int multiple;
  
  int midopt;
  int midsockfd;
  int midsockport;
  
  int c2sopt;
  int c2ssockfd;
  int c2ssockport;
  
  int s2copt;
  int s2csockfd;
  int s2csockport;
} TestOptions;

int initialize_tests(int ctlsockfd, TestOptions* options, int conn_options);
int test_mid(int ctlsockfd, web100_agent* agent, TestOptions* options, double* s2c2spd);
int test_c2s(int ctlsockfd, web100_agent* agent, TestOptions* options, double* c2sspd,
    int set_buff, int window, int autotune, int mon_pipe1[2], char* device, int limit,
    int record_reverse, int count_vars, char spds[4][256], int* spd_index);
int test_s2c(int ctlsockfd, web100_agent* agent, TestOptions* options, double* s2cspd, int set_buff,
    int window, int autotune, int mon_pipe2[2], char* device, int limit, int experimental,
    char* logname, char spds[4][256], int* spd_index, int count_vars);

#endif
