target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = mul i32 2, 3
  %t2 = alloca i32
  store i32 %t1, i32* %t2
  %t3 = alloca float
  store float 0x4008CCCCC0000000, float* %t3
  %t4 = load i32, i32 *%t2
  %t5 = load float, float *%t3
  %t6 = sitofp i32 %t4 to float
  %t7 = fadd float %t6, %t5
  %t8 = fptosi float %t7 to i32
  %t9 = alloca i32
  store i32 %t8, i32* %t9
  %t10 = load i32, i32 *%t9
  ret i32 %t10
}
