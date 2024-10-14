//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 14-Oct-2024 17:08:46
//

// Include Files
#include "pencode_core.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : const boolean_T d[128]
//                double n
//                boolean_T x[128]
// Return Type  : void
//
void pencode_core(const boolean_T d[128], double n, boolean_T x[128])
{
  int i;
  std::copy(&d[0], &d[128], &x[0]);
  i = static_cast<int>(n);
  for (int b_i{0}; b_i < i; b_i++) {
    double B;
    int i1;
    B = rt_powd_snf(2.0, (n - (static_cast<double>(b_i) + 1.0)) + 1.0);
    i1 = static_cast<int>(
        rt_powd_snf(2.0, (static_cast<double>(b_i) + 1.0) - 1.0));
    for (int j{0}; j < i1; j++) {
      double base;
      int i2;
      base = ((static_cast<double>(j) + 1.0) - 1.0) * B;
      i2 = static_cast<int>(B / 2.0);
      for (int l{0}; l < i2; l++) {
        int b_x;
        int x_tmp;
        x_tmp = static_cast<int>(base + (static_cast<double>(l) + 1.0)) - 1;
        b_x = x[x_tmp] + x[static_cast<int>((base + B / 2.0) +
                                            (static_cast<double>(l) + 1.0)) -
                           1];
        if (b_x == 0) {
          b_x = 0;
        } else {
          b_x = static_cast<int>(std::fmod(static_cast<double>(b_x), 2.0));
        }
        x[x_tmp] = (b_x != 0.0);
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
