//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pencode_core.cpp
//
// MATLAB Coder version            : 24.1
// C/C++ source code generated on  : 22-Oct-2024 17:27:08
//

// Include Files
#include "pencode_core.h"

// Function Definitions
//
// Arguments    : const boolean_T d[128]
//                boolean_T x[128]
// Return Type  : void
//
void pencode_core(const boolean_T d[128], boolean_T x[128])
{
  for (int i{0}; i < 128; i++) {
    x[i] = d[i];
  }
  for (int i{0}; i < 7; i++) {
    int B;
    int nB;
    int q_tmp;
    unsigned int u;
    B = static_cast<int>(1U << static_cast<unsigned int>(7 - i));
    nB = static_cast<int>(1U << static_cast<unsigned int>(i));
    q_tmp = static_cast<int>(static_cast<unsigned int>(B) >> 1);
    u = static_cast<unsigned int>(B) - (static_cast<unsigned int>(q_tmp) << 1);
    for (int j{0}; j < nB; j++) {
      int base;
      int q;
      base = j * B - 1;
      q = q_tmp;
      if (u > 0U) {
        q = static_cast<int>(static_cast<unsigned int>(q_tmp) + 1U);
      }
      for (int l{0}; l < q; l++) {
        int b_q;
        int x_tmp;
        b_q = q_tmp;
        if (u > 0U) {
          b_q = static_cast<int>(static_cast<unsigned int>(q_tmp) + 1U);
        }
        x_tmp = (base + l) + 1;
        b_q = x[x_tmp] + x[((base + b_q) + l) + 1];
        x[x_tmp] = (b_q - ((b_q / 2) << 1) != 0);
      }
    }
  }
}

//
// File trailer for pencode_core.cpp
//
// [EOF]
//
