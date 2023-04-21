target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 2, i32* %t1
  %t2 = alloca float
  store float 0x4008CCCCC0000000, float* %t2
  %t3 = alloca i8
  store i8 97, i8* %t3
  %t4 = alloca i32
  %t5 = alloca i32
  %t6 = load i32, i32 *%t1
  %t7 = load i8, i8 *%t3
  %t8 = sext i8 %t7 to i32
  %t9 = add i32 %t6, %t8
  store i32 %t9, i32* %t4
  %t10 = load i32, i32 *%t4
  %t11 = load float, float *%t2
  %t12 = sitofp i32 %t10 to float
  %t13 = fsub float %t12, %t11
  %t14 = fptosi float %t13 to i32
  store i32 %t14, i32* %t5
  %t15 = load i32, i32 *%t5
  %t16 = load i32, i32 *%t1
  %t17 = mul i32 %t15, %t16
  store i32 %t17, i32* %t5
  %t18 = load i32, i32 *%t5
  %t19 = load i32, i32 *%t1
  %t20 = sdiv i32 %t18, %t19
  store i32 %t20, i32* %t5
  %t21 = load i32, i32 *%t5
  ret i32 %t21
}
