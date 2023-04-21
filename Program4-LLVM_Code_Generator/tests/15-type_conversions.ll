target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 1, i32* %t1
  %t2 = alloca float
  store float 0x4000CCCCC0000000, float* %t2
  %t3 = alloca i8
  store i8 97, i8* %t3
  %t4 = load i32, i32 *%t1
  %t5 = load float, float *%t2
  %t6 = sitofp i32 %t4 to float
  %t7 = fadd float %t6, %t5
  %t8 = fptosi float %t7 to i32
  %t9 = alloca i32
  store i32 %t8, i32* %t9
  %t10 = load float, float *%t2
  %t11 = load i32, i32 *%t1
  %t12 = sitofp i32 %t11 to float
  %t13 = fadd float %t10, %t12
  %t14 = fptosi float %t13 to i32
  store i32 %t14, i32* %t9
  %t15 = load i8, i8 *%t3
  %t16 = load float, float *%t2
  %t17 = sitofp i8 %t15 to float
  %t18 = fadd float %t17, %t16
  %t19 = alloca float
  store float %t18, float* %t19
  %t20 = load float, float *%t19
  %t21 = load i32, i32 *%t1
  %t22 = sitofp i32 %t21 to float
  %t23 = fsub float %t20, %t22
  %t24 = fptosi float %t23 to i8
  %t25 = alloca i8
  store i8 %t24, i8* %t25
  %t26 = load i8, i8 *%t25
  %t27 = load i32, i32 *%t1
  %t28 = sext i8 %t26 to i32
  %t29 = add i32 %t28, %t27
  %t30 = trunc i32 %t29 to i8
  %t31 = alloca i8
  store i8 %t30, i8* %t31
  %t32 = load i8, i8 *%t31
  %t33 = sext i8 %t32 to i32
  ret i32 %t33
}
