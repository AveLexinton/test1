#ifdef __TESTCOUT_H__
#define __TESTCOUT_H__
#ifdef __DEBUG
#include <iostream>
#include <fstream>
#define LOG(val) {std::cout<<val;}
#define LOGF(val, filename) {ofstream ofile(filename,std::ios::app);ofile<<val;ofile.close();}
#else
#define LOG(val)
#define LOGF(val, filename)
#endif
#endif
