target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @main() {
  %t1 = alloca i32
  store i32 16, i32* %t1
  %t2 = load i32, i32 *%t1
  %t3 = sdiv i32 %t2, 2
  ret i32 %t3
}
