//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 18-Oct-2024 13:24:02
//

// Include Files
#include "pencode_core.h"
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const boolean_T d[128]
//                int n
//                boolean_T x[128]
// Return Type  : void
//
void pencode_core(const boolean_T d[128], int n, boolean_T x[128])
{
  int c_qY;
  std::copy(&d[0], &d[128], &x[0]);
  for (int i{0}; i < n; i++) {
    int B;
    int b_qY;
    int nB;
    int q1;
    int qY;
    if ((n >= 0) && (i + 1 < n - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((n < 0) && (i + 1 > n - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = (n - i) - 1;
    }
    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }
    b_qY = qY;
    if (qY < 0) {
      b_qY = 0;
    }
    if (qY > 30) {
      B = MAX_int32_T;
    } else {
      B = static_cast<int>(1U << static_cast<unsigned int>(b_qY));
    }
    if (i + 1 < -2147483647) {
      qY = MIN_int32_T;
    } else {
      qY = i;
    }
    b_qY = qY;
    if (qY < 0) {
      b_qY = 0;
    }
    if (qY > 30) {
      nB = MAX_int32_T;
    } else {
      nB = static_cast<int>(1U << static_cast<unsigned int>(b_qY));
    }
    q1 = static_cast<int>(std::round(static_cast<double>(B) / 2.0));
    for (int j{0}; j < nB; j++) {
      long b_i;
      b_i = static_cast<long>(j) * B;
      if (b_i > 2147483647L) {
        b_i = 2147483647L;
      } else if (b_i < -2147483648L) {
        b_i = -2147483648L;
      }
      if (q1 - 1 >= 0) {
        if ((static_cast<int>(b_i) < 0) &&
            (q1 < MIN_int32_T - static_cast<int>(b_i))) {
          c_qY = MIN_int32_T;
        } else if ((static_cast<int>(b_i) > 0) &&
                   (q1 > MAX_int32_T - static_cast<int>(b_i))) {
          c_qY = MAX_int32_T;
        } else {
          c_qY = static_cast<int>(b_i) + q1;
        }
      }
      for (int l{0}; l < q1; l++) {
        boolean_T b;
        b = ((static_cast<int>(b_i) < 0) &&
             (l + 1 < MIN_int32_T - static_cast<int>(b_i)));
        if (b) {
          qY = MIN_int32_T;
        } else if ((static_cast<int>(b_i) > 0) &&
                   (l + 1 > MAX_int32_T - static_cast<int>(b_i))) {
          qY = MAX_int32_T;
        } else {
          qY = (static_cast<int>(b_i) + l) + 1;
        }
        if ((c_qY < 0) && (l + 1 < MIN_int32_T - c_qY)) {
          b_qY = MIN_int32_T;
        } else if ((c_qY > 0) && (l + 1 > MAX_int32_T - c_qY)) {
          b_qY = MAX_int32_T;
        } else {
          b_qY = (c_qY + l) + 1;
        }
        b_qY = x[qY - 1] + x[b_qY - 1];
        if (b) {
          qY = MIN_int32_T;
        } else if ((static_cast<int>(b_i) > 0) &&
                   (l + 1 > MAX_int32_T - static_cast<int>(b_i))) {
          qY = MAX_int32_T;
        } else {
          qY = (static_cast<int>(b_i) + l) + 1;
        }
        if (b_qY == 0) {
          b_qY = 0;
        } else {
          b_qY = static_cast<int>(std::fmod(static_cast<double>(b_qY), 2.0));
        }
        x[qY - 1] = (b_qY != 0.0);
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
