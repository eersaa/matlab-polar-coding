//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 15-Oct-2024 09:53:02
//

// Include Files
#include "pencode_core.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const boolean_T d[128]
//                unsigned int n
//                boolean_T x[128]
// Return Type  : void
//
void pencode_core(const boolean_T d[128], unsigned int n, boolean_T x[128])
{
  int i;
  std::copy(&d[0], &d[128], &x[0]);
  i = static_cast<int>(n);
  for (int b_i{0}; b_i < i; b_i++) {
    unsigned int B;
    int i1;
    unsigned int qY;
    qY = (n - static_cast<unsigned int>(b_i)) - 1U;
    if (qY > n) {
      qY = 0U;
    }
    if (qY + 1U > 31U) {
      B = MAX_uint32_T;
    } else {
      B = 1U << (qY + 1U);
    }
    if (static_cast<unsigned int>(b_i) > 31U) {
      i1 = -1;
    } else {
      i1 = static_cast<int>(1U << static_cast<unsigned int>(b_i));
    }
    for (int j{0}; j < i1; j++) {
      unsigned long u;
      int i2;
      unsigned int u1;
      u = static_cast<unsigned long>(j) * B;
      if (u > 4294967295UL) {
        u = 4294967295UL;
      }
      u1 = static_cast<unsigned int>(std::round(static_cast<double>(B) / 2.0));
      i2 = static_cast<int>(u1);
      for (int l{0}; l < i2; l++) {
        unsigned int b_qY;
        int b_x;
        unsigned int c_qY;
        unsigned int qY_tmp;
        qY_tmp =
            (static_cast<unsigned int>(u) + static_cast<unsigned int>(l)) + 1U;
        qY = qY_tmp;
        if (qY_tmp < static_cast<unsigned int>(u)) {
          qY = MAX_uint32_T;
        }
        b_qY = static_cast<unsigned int>(u) + u1;
        if (b_qY < static_cast<unsigned int>(u)) {
          b_qY = MAX_uint32_T;
        }
        c_qY = (b_qY + static_cast<unsigned int>(l)) + 1U;
        if (c_qY < b_qY) {
          c_qY = MAX_uint32_T;
        }
        b_x = x[static_cast<int>(qY) - 1] + x[static_cast<int>(c_qY) - 1];
        if (qY_tmp < static_cast<unsigned int>(u)) {
          qY_tmp = MAX_uint32_T;
        }
        if (b_x == 0) {
          b_x = 0;
        } else {
          b_x = static_cast<int>(std::fmod(static_cast<double>(b_x), 2.0));
        }
        x[static_cast<int>(qY_tmp) - 1] = (b_x != 0.0);
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
