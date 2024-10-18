//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 18-Oct-2024 15:36:52
//

// Include Files
#include "pencode_core.h"

// Function Definitions
//
// Arguments    : const boolean_T d[128]
//                int n
//                boolean_T x[128]
// Return Type  : void
//
void pencode_core(const boolean_T d[128], int n, boolean_T x[128])
{
  for (int i{0}; i < 128; i++) {
    x[i] = d[i];
  }
  for (int i{0}; i < n; i++) {
    int B;
    int b;
    int nB;
    b = n - i;
    if (b > 30) {
      B = MAX_int32_T;
    } else {
      B = static_cast<int>(1U << static_cast<unsigned int>(b));
    }
    if (i > 30) {
      nB = MAX_int32_T;
    } else {
      nB = static_cast<int>(1U << static_cast<unsigned int>(i));
    }
    for (int j{0}; j < nB; j++) {
      int b_i;
      int base;
      unsigned int q;
      unsigned int q_tmp;
      unsigned int x_tmp;
      base = j * B - 1;
      if (B >= 0) {
        x_tmp = static_cast<unsigned int>(B);
      } else if (B == MIN_int32_T) {
        x_tmp = 2147483648U;
      } else {
        x_tmp = static_cast<unsigned int>(-B);
      }
      q_tmp = x_tmp >> 1;
      q = q_tmp;
      x_tmp -= q_tmp << 1;
      if (x_tmp > 0U) {
        q = q_tmp + 1U;
      }
      b_i = static_cast<int>(q);
      if (B < 0) {
        b_i = -static_cast<int>(q);
      }
      for (int l{0}; l < b_i; l++) {
        int b_x_tmp;
        q = q_tmp;
        if (x_tmp > 0U) {
          q = q_tmp + 1U;
        }
        b = static_cast<int>(q);
        if (B < 0) {
          b = -static_cast<int>(q);
        }
        b_x_tmp = (base + l) + 1;
        b = x[b_x_tmp] + x[((base + b) + l) + 1];
        x[b_x_tmp] = (b - ((b / 2) << 1) != 0);
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
