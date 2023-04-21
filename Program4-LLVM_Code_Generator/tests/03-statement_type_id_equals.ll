target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 2, i32* %t1
  %t2 = alloca float
  store float 0x4002666660000000, float* %t2
  %t3 = alloca i8
  store i8 97, i8* %t3
  %t4 = alloca i32
  store i32 2, i32* %t4
  %t5 = load i32, i32 *%t4
  %t6 = sitofp i32 %t5 to float
  store float %t6, float* %t2
  %t7 = load float, float *%t2
  %t8 = fptosi float %t7 to i32
  ret i32 %t8
}
