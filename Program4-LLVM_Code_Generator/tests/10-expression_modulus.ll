target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 2, i32* %t1
  %t2 = alloca i8
  store i8 103, i8* %t2
  %t3 = load i8, i8 *%t2
  %t4 = load i32, i32 *%t1
  %t5 = sext i8 %t3 to i32
  %t6 = srem i32 %t5, %t4
  %t7 = alloca i32
  store i32 %t6, i32* %t7
  %t8 = load i32, i32 *%t7
  ret i32 %t8
}
