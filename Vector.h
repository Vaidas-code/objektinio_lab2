#pragma once
#ifndef HEADER_FILE_2_H
#define HEADER_FILE_2_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <numeric>
#include <limits>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <chrono> 
#include <filesystem>
#include <sstream>
#include <io.h>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <sys/stat.h>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::vector;
using std::fixed;
using std::numeric_limits;
using std::streamsize;
using std::swap;
using std::numeric_limits;
using std::streamsize;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::sort;
using std::runtime_error;
using std::bad_alloc;
using std::bad_cast;
using std::bad_typeid;
using std::bad_exception;
using std::runtime_error;
using std::domain_error;
using std::invalid_argument;
using std::length_error;
using std::out_of_range;
using std::overflow_error;
using std::range_error;
using std::underflow_error;
using std::exception;
using std::getline;
using std::stringstream;
using std::ofstream;
using std::to_string;
using std::remove;
using std::move;
using std::deque;
using std::list;


#ifdef _WIN32
#include <io.h> 
#define access    _access_s
#else
#include <unistd.h>
#endif
#endif