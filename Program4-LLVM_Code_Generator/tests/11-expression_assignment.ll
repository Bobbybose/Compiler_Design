target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  %t2 = alloca float
  store float 0x4008CCCCC0000000, float* %t2
  %t3 = load float, float *%t2
  %t4 = fptosi float %t3 to i32
  store i32 %t4, i32* %t1
  %t5 = load i32, i32 *%t1
  ret i32 %t5
}
